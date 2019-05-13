/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include <stdlib.h>
#include <stdio.h>

int8 speedLeft = 0;
int8 speedRight = 0;

typedef enum motor {
    LEFT_WHEEL,
    RIGHT_WHEEL
} motor;
/*
If there is a connection then it takes the right and left speed
and stores it in the GATT database under the correct characteristic
*/
void updateSpeed(){
    if(CyBle_GetState() != CYBLE_STATE_CONNECTED)
        return;
    CYBLE_GATTS_HANDLE_VALUE_NTF_T tempHandle;
    
    tempHandle.attrHandle = CYBLE_MOTOR_MOTORLEFT_CHAR_HANDLE;
    tempHandle.value.val = (uint8 *)&speedLeft;
    tempHandle.value.len = 1;
    CyBle_GattsWriteAttributeValue(&tempHandle, 0, &cyBle_connHandle, CYBLE_GATT_DB_LOCALLY_INITIATED);
    
    tempHandle.attrHandle = CYBLE_MOTOR_MOTORRIGHT_CHAR_HANDLE;
    tempHandle.value.val = (uint8 *)&speedRight;
    tempHandle.value.len = 1;
    CyBle_GattsWriteAttributeValue(&tempHandle, 0, &cyBle_connHandle, CYBLE_GATT_DB_LOCALLY_INITIATED);
    
}
/*
Called by the BLE stack handle when there is a write in the MotorLeft or MotorRight
characteristic
*/
void setSpeed(motor m, int speed){
    
    int dir;

    //printf("%d\n",speed);
    if(speed>=100) //100% -> speed limit
        speed = 100;
    if(speed<=-100)
        speed = -100;
    
    if(speed>=0)
        dir = 1;
    else
        dir = 0;
    
    IN1_Write(dir);
    IN2_Write(!dir);
    IN3_Write(dir);
    IN4_Write(!dir);
    
    switch(m){
        case LEFT_WHEEL:
            LEFT_MOTOR_WriteCompare(speed);
            speedLeft = speed;
        break;
        case RIGHT_WHEEL:
            RIGHT_MOTOR_WriteCompare(speed);
            speedRight = speed;
        break;
    }
    updateSpeed();
}

void BleCallBack(uint32 event, void* eventParam){
    
    CYBLE_GATTS_WRITE_REQ_PARAM_T *wrReqParam;
    
    switch(event)
    {
        case CYBLE_EVT_STACK_ON:
        case CYBLE_EVT_GAP_DEVICE_DISCONNECTED:
            CyBle_GappStartAdvertisement(CYBLE_ADVERTISING_FAST);
            setSpeed(LEFT_WHEEL, 0);
            setSpeed(RIGHT_WHEEL, 0);
            updateSpeed();
            LED_PWM_Start();
        break;
            
        case CYBLE_EVT_GAP_DEVICE_CONNECTED:
        case CYBLE_EVT_GATT_CONNECT_IND:
            setSpeed(LEFT_WHEEL, 0);
            setSpeed(RIGHT_WHEEL, 0);
            updateSpeed();
            LED_PWM_Stop();
        break;
            
        case CYBLE_EVT_GATTS_WRITE_REQ:
            wrReqParam = (CYBLE_GATTS_WRITE_REQ_PARAM_T *) eventParam;
            
            if(wrReqParam->handleValPair.attrHandle == CYBLE_MOTOR_MOTORLEFT_CHAR_HANDLE)
                setSpeed(LEFT_WHEEL, (int8)wrReqParam->handleValPair.value.val[0]);
                

            if(wrReqParam->handleValPair.attrHandle == CYBLE_MOTOR_MOTORRIGHT_CHAR_HANDLE)
                setSpeed(RIGHT_WHEEL, (int8)wrReqParam->handleValPair.value.val[0]);               
            
            CyBle_GattsWriteRsp(cyBle_connHandle);
        break;
            
        default:
        break;
    }
    
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    //Start the motor's PWM
    LEFT_MOTOR_Start();
    RIGHT_MOTOR_Start();
    
    //Initialize speed of each wheel to 0
    setSpeed(LEFT_WHEEL, 0);
    setSpeed(RIGHT_WHEEL, 0);

    //Start the BLE
    CyBle_Start(BleCallBack);

    for(;;)
    {
        CyBle_ProcessEvents();
    }
}

/* [] END OF FILE */

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


int8 roombaMode = 0;//1->Roomba mode || 0 -> manual
int8 vacio = 0; // 1-> vacio detectado || 0 -> vacio no detectado

float dist = 0.0;
int16 i = 0;

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

void updateMode(){
    if(CyBle_GetState() != CYBLE_STATE_CONNECTED)
        return;
    CYBLE_GATTS_HANDLE_VALUE_NTF_T tempHandle;
    
    tempHandle.attrHandle = CYBLE_MOTOR_ROOMBA_CHAR_HANDLE;
    tempHandle.value.val = (uint8 *)&roombaMode;
    tempHandle.value.len = 1;
    CyBle_GattsWriteAttributeValue(&tempHandle, 0, &cyBle_connHandle, CYBLE_GATT_DB_LOCALLY_INITIATED);
}


/*
Called by the BLE stack handle when there is a write in the MotorLeft or MotorRight
characteristic
*/
void setSpeed(motor m, int speed){
    
    int dir;

    if(speed>=100) //100% -> speed limit
        speed = 100;
    if(speed<=-100)
        speed = -100;
    
    if(speed>=0)
        dir = 0;
    else
        dir = 1;
     
    switch(m){
        case LEFT_WHEEL:
            IN1_Write(dir);
            IN2_Write(!dir);
            LEFT_MOTOR_WriteCompare(speed);
            speedLeft = speed;
  
        break;
        case RIGHT_WHEEL:
            IN3_Write(dir);
            IN4_Write(!dir);
            RIGHT_MOTOR_WriteCompare(speed);
            speedRight = speed;
        break;
    }
    updateSpeed();
}
void setMode(int value){
    roombaMode = value;
}
void BleCallBack(uint32 event, void* eventParam){
    
    CYBLE_GATTS_WRITE_REQ_PARAM_T *wrReqParam;
    
    switch(event)
    {
        case CYBLE_EVT_STACK_ON:
        case CYBLE_EVT_GAP_DEVICE_DISCONNECTED:
            CyBle_GappStartAdvertisement(CYBLE_ADVERTISING_FAST);
            BLE_PWM_Start();        
            ROOMBA_PWM_Stop();
            LEFT_MOTOR_WriteCompare(0);
            RIGHT_MOTOR_WriteCompare(0);
        break;
         
        case CYBLE_EVT_GAP_DEVICE_CONNECTED:
        case CYBLE_EVT_GATT_CONNECT_IND:
            updateSpeed();
            BLE_PWM_Stop();          
        break;
          
        case CYBLE_EVT_GATTS_WRITE_CMD_REQ:
        case CYBLE_EVT_GATTS_WRITE_REQ:
            wrReqParam = (CYBLE_GATTS_WRITE_REQ_PARAM_T *) eventParam;
            if(wrReqParam->handleValPair.attrHandle == CYBLE_MOTOR_MOTORLEFT_CHAR_HANDLE)
                setSpeed(LEFT_WHEEL, (int8)wrReqParam->handleValPair.value.val[0]);
                

            if(wrReqParam->handleValPair.attrHandle == CYBLE_MOTOR_MOTORRIGHT_CHAR_HANDLE)
                setSpeed(RIGHT_WHEEL, (int8)wrReqParam->handleValPair.value.val[0]); 
                
            if(wrReqParam->handleValPair.attrHandle == CYBLE_MOTOR_ROOMBA_CHAR_HANDLE)
                setMode((int8)wrReqParam->handleValPair.value.val[0]);
            
            
            CyBle_GattsWriteRsp(cyBle_connHandle);
        break;
            
        default:
        break;
    }
    
}
//Interrupt distancia
CY_ISR(Timer_sensor_isr_sensor_handler)
{ 
    Timer_sensor_ClearInterrupt(Timer_sensor_INTR_MASK_CC_MATCH);
    i = Timer_sensor_ReadCounter();
    dist = i /58.0;
}

////////////////////////////////////////////////////////////////
///                  Matriz                                   //
////////////////////////////////////////////////////////////////

const char A[8] = {0x3c,0x72,0xf9,0xe5,0xe5,0xf9,0x72,0x3c};           //Automatico
const char M[8] = {0x09, 0x39, 0x57, 0xF6, 0xF6, 0x57, 0x39, 0x09};         //Manual

 void borra_matriz_LED(void){
        
    SPIM_WriteTxData(0x0100);
    CyDelay(1);
    SPIM_WriteTxData(0x0200);
    CyDelay(1);
    SPIM_WriteTxData(0x0300);
    CyDelay(1);
    SPIM_WriteTxData(0x0400);
    CyDelay(1);
    SPIM_WriteTxData(0x0500);
    CyDelay(1);
    SPIM_WriteTxData(0x0600);
    CyDelay(1);
    SPIM_WriteTxData(0x0700);
    CyDelay(1);
    SPIM_WriteTxData(0x0800);
    CyDelay(1);
}

void escribe_matriz_LED(const char img[]){
    int i;
    SPIM_WriteTxData(0x0100|img[0]);
    CyDelay(1);
    SPIM_WriteTxData(0x0200|img[1]);
    CyDelay(1);
    SPIM_WriteTxData(0x0300|img[2]);
    CyDelay(1);
    SPIM_WriteTxData(0x0400|img[3]);
    CyDelay(1);
    SPIM_WriteTxData(0x0500|img[4]);
    CyDelay(1);
    SPIM_WriteTxData(0x0600|img[5]);
    CyDelay(1);
    SPIM_WriteTxData(0x0700|img[6]);
    CyDelay(1);
    SPIM_WriteTxData(0x0800|img[7]);
    CyDelay(1);

}
void inicializaMatriz(){
    SPIM_Start();
    SPIM_WriteTxData(0x0C01);
    CyDelay(1);
    SPIM_WriteTxData(0x0B07);
    CyDelay(1);
    SPIM_WriteTxData(0x0900);
    CyDelay(1);
    SPIM_WriteTxData(0x0A0B);
    CyDelay(1);
    SPIM_WriteTxData(0x0F00);
    CyDelay(1);
}
/////////////////////////
//Movement in roomba mode
////////////////////////////
void movimiento (uint dir) {
    if (dir == 0){
        
        IN1_Write(0);
        IN2_Write(1);
        IN3_Write(0);
        IN4_Write(1);
      
        LEFT_MOTOR_WriteCompare(30);
        RIGHT_MOTOR_WriteCompare(30);
    }
    if (dir == 1){ // izq
        
        IN1_Write(0);
        IN2_Write(1);
        IN3_Write(1);
        IN4_Write(0);
        
        LEFT_MOTOR_WriteCompare(50);
        RIGHT_MOTOR_WriteCompare(50);
       /* LEFT_MOTOR_WriteCompare(0);
                RIGHT_MOTOR_WriteCompare(0);
                
                CyDelay(1000);
                IN1_Write(1);
                IN2_Write(0);
                IN3_Write(1);
                IN4_Write(0);
                
                LEFT_MOTOR_WriteCompare(50);
                RIGHT_MOTOR_WriteCompare(50);
                
                CyDelay(500);
                IN1_Write(0);
                IN2_Write(1);
                IN3_Write(1);
                IN4_Write(0);
                
                LEFT_MOTOR_WriteCompare(50);
                RIGHT_MOTOR_WriteCompare(50);
                
                CyDelay(500);*/
        }
}
int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    isr_StartEx(Timer_sensor_isr_sensor_handler);
    Timer_sensor_Start();
    
    //Start the motor's PWM
    LEFT_MOTOR_Start();
    RIGHT_MOTOR_Start();
    
    //Initialize speed of each wheel to 0
    setSpeed(LEFT_WHEEL, 0);
    setSpeed(RIGHT_WHEEL, 0);
    
    //Initialize Matrix
    inicializaMatriz();

    //Start the BLE
    CyBle_Start(BleCallBack);
    
        
    for(;;)
    {
       vacio = Linea_Read();

    
       if(roombaMode != 0){//Roomba mode
            ROOMBA_PWM_Start();
            //Matriz
            borra_matriz_LED();
            escribe_matriz_LED(A);
            
            
            Trigger_Write(1); 							
    		CyDelayUs(10);									
    		Trigger_Write(0);
            
            if(vacio>0){
                LEFT_MOTOR_WriteCompare(0);
                RIGHT_MOTOR_WriteCompare(0);
                
                CyDelay(1000);
                IN1_Write(1);
                IN2_Write(0);
                IN3_Write(1);
                IN4_Write(0);
                
                LEFT_MOTOR_WriteCompare(40);
                RIGHT_MOTOR_WriteCompare(40);
                
                CyDelay(500);
                IN1_Write(0);
                IN2_Write(1);
                IN3_Write(1);
                IN4_Write(0);
                
                LEFT_MOTOR_WriteCompare(35);
                RIGHT_MOTOR_WriteCompare(35);
                
                CyDelay(500);
            }
    		else if (dist < 15) {
                movimiento(1);
                //ROOMBA_PWM_Start();
            }
            else {
                movimiento(0);
                //ROOMBA_PWM_Start();
            }

 
                
            
        }
        else{//Manual mode
            ROOMBA_PWM_Stop();
            //Matriz
            borra_matriz_LED();
            escribe_matriz_LED(M);
        }
            
        
        CyBle_ProcessEvents();
        CyBle_EnterLPM(CYBLE_BLESS_DEEPSLEEP);
    }
}

/* [] END OF FILE */

/*******************************************************************************
* File Name: LEFT_MOTOR_PM.c
* Version 3.30
*
* Description:
*  This file provides the power management source code to API for the
*  PWM.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "LEFT_MOTOR.h"

static LEFT_MOTOR_backupStruct LEFT_MOTOR_backup;


/*******************************************************************************
* Function Name: LEFT_MOTOR_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  LEFT_MOTOR_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void LEFT_MOTOR_SaveConfig(void) 
{

    #if(!LEFT_MOTOR_UsingFixedFunction)
        #if(!LEFT_MOTOR_PWMModeIsCenterAligned)
            LEFT_MOTOR_backup.PWMPeriod = LEFT_MOTOR_ReadPeriod();
        #endif /* (!LEFT_MOTOR_PWMModeIsCenterAligned) */
        LEFT_MOTOR_backup.PWMUdb = LEFT_MOTOR_ReadCounter();
        #if (LEFT_MOTOR_UseStatus)
            LEFT_MOTOR_backup.InterruptMaskValue = LEFT_MOTOR_STATUS_MASK;
        #endif /* (LEFT_MOTOR_UseStatus) */

        #if(LEFT_MOTOR_DeadBandMode == LEFT_MOTOR__B_PWM__DBM_256_CLOCKS || \
            LEFT_MOTOR_DeadBandMode == LEFT_MOTOR__B_PWM__DBM_2_4_CLOCKS)
            LEFT_MOTOR_backup.PWMdeadBandValue = LEFT_MOTOR_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(LEFT_MOTOR_KillModeMinTime)
             LEFT_MOTOR_backup.PWMKillCounterPeriod = LEFT_MOTOR_ReadKillTime();
        #endif /* (LEFT_MOTOR_KillModeMinTime) */

        #if(LEFT_MOTOR_UseControl)
            LEFT_MOTOR_backup.PWMControlRegister = LEFT_MOTOR_ReadControlRegister();
        #endif /* (LEFT_MOTOR_UseControl) */
    #endif  /* (!LEFT_MOTOR_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: LEFT_MOTOR_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  LEFT_MOTOR_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void LEFT_MOTOR_RestoreConfig(void) 
{
        #if(!LEFT_MOTOR_UsingFixedFunction)
            #if(!LEFT_MOTOR_PWMModeIsCenterAligned)
                LEFT_MOTOR_WritePeriod(LEFT_MOTOR_backup.PWMPeriod);
            #endif /* (!LEFT_MOTOR_PWMModeIsCenterAligned) */

            LEFT_MOTOR_WriteCounter(LEFT_MOTOR_backup.PWMUdb);

            #if (LEFT_MOTOR_UseStatus)
                LEFT_MOTOR_STATUS_MASK = LEFT_MOTOR_backup.InterruptMaskValue;
            #endif /* (LEFT_MOTOR_UseStatus) */

            #if(LEFT_MOTOR_DeadBandMode == LEFT_MOTOR__B_PWM__DBM_256_CLOCKS || \
                LEFT_MOTOR_DeadBandMode == LEFT_MOTOR__B_PWM__DBM_2_4_CLOCKS)
                LEFT_MOTOR_WriteDeadTime(LEFT_MOTOR_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(LEFT_MOTOR_KillModeMinTime)
                LEFT_MOTOR_WriteKillTime(LEFT_MOTOR_backup.PWMKillCounterPeriod);
            #endif /* (LEFT_MOTOR_KillModeMinTime) */

            #if(LEFT_MOTOR_UseControl)
                LEFT_MOTOR_WriteControlRegister(LEFT_MOTOR_backup.PWMControlRegister);
            #endif /* (LEFT_MOTOR_UseControl) */
        #endif  /* (!LEFT_MOTOR_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: LEFT_MOTOR_Sleep
********************************************************************************
*
* Summary:
*  Disables block's operation and saves the user configuration. Should be called
*  just prior to entering sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  LEFT_MOTOR_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void LEFT_MOTOR_Sleep(void) 
{
    #if(LEFT_MOTOR_UseControl)
        if(LEFT_MOTOR_CTRL_ENABLE == (LEFT_MOTOR_CONTROL & LEFT_MOTOR_CTRL_ENABLE))
        {
            /*Component is enabled */
            LEFT_MOTOR_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            LEFT_MOTOR_backup.PWMEnableState = 0u;
        }
    #endif /* (LEFT_MOTOR_UseControl) */

    /* Stop component */
    LEFT_MOTOR_Stop();

    /* Save registers configuration */
    LEFT_MOTOR_SaveConfig();
}


/*******************************************************************************
* Function Name: LEFT_MOTOR_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration. Should be called just after
*  awaking from sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  LEFT_MOTOR_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void LEFT_MOTOR_Wakeup(void) 
{
     /* Restore registers values */
    LEFT_MOTOR_RestoreConfig();

    if(LEFT_MOTOR_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        LEFT_MOTOR_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */

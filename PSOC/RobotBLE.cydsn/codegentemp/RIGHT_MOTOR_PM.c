/*******************************************************************************
* File Name: RIGHT_MOTOR_PM.c
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

#include "RIGHT_MOTOR.h"

static RIGHT_MOTOR_backupStruct RIGHT_MOTOR_backup;


/*******************************************************************************
* Function Name: RIGHT_MOTOR_SaveConfig
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
*  RIGHT_MOTOR_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void RIGHT_MOTOR_SaveConfig(void) 
{

    #if(!RIGHT_MOTOR_UsingFixedFunction)
        #if(!RIGHT_MOTOR_PWMModeIsCenterAligned)
            RIGHT_MOTOR_backup.PWMPeriod = RIGHT_MOTOR_ReadPeriod();
        #endif /* (!RIGHT_MOTOR_PWMModeIsCenterAligned) */
        RIGHT_MOTOR_backup.PWMUdb = RIGHT_MOTOR_ReadCounter();
        #if (RIGHT_MOTOR_UseStatus)
            RIGHT_MOTOR_backup.InterruptMaskValue = RIGHT_MOTOR_STATUS_MASK;
        #endif /* (RIGHT_MOTOR_UseStatus) */

        #if(RIGHT_MOTOR_DeadBandMode == RIGHT_MOTOR__B_PWM__DBM_256_CLOCKS || \
            RIGHT_MOTOR_DeadBandMode == RIGHT_MOTOR__B_PWM__DBM_2_4_CLOCKS)
            RIGHT_MOTOR_backup.PWMdeadBandValue = RIGHT_MOTOR_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(RIGHT_MOTOR_KillModeMinTime)
             RIGHT_MOTOR_backup.PWMKillCounterPeriod = RIGHT_MOTOR_ReadKillTime();
        #endif /* (RIGHT_MOTOR_KillModeMinTime) */

        #if(RIGHT_MOTOR_UseControl)
            RIGHT_MOTOR_backup.PWMControlRegister = RIGHT_MOTOR_ReadControlRegister();
        #endif /* (RIGHT_MOTOR_UseControl) */
    #endif  /* (!RIGHT_MOTOR_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: RIGHT_MOTOR_RestoreConfig
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
*  RIGHT_MOTOR_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void RIGHT_MOTOR_RestoreConfig(void) 
{
        #if(!RIGHT_MOTOR_UsingFixedFunction)
            #if(!RIGHT_MOTOR_PWMModeIsCenterAligned)
                RIGHT_MOTOR_WritePeriod(RIGHT_MOTOR_backup.PWMPeriod);
            #endif /* (!RIGHT_MOTOR_PWMModeIsCenterAligned) */

            RIGHT_MOTOR_WriteCounter(RIGHT_MOTOR_backup.PWMUdb);

            #if (RIGHT_MOTOR_UseStatus)
                RIGHT_MOTOR_STATUS_MASK = RIGHT_MOTOR_backup.InterruptMaskValue;
            #endif /* (RIGHT_MOTOR_UseStatus) */

            #if(RIGHT_MOTOR_DeadBandMode == RIGHT_MOTOR__B_PWM__DBM_256_CLOCKS || \
                RIGHT_MOTOR_DeadBandMode == RIGHT_MOTOR__B_PWM__DBM_2_4_CLOCKS)
                RIGHT_MOTOR_WriteDeadTime(RIGHT_MOTOR_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(RIGHT_MOTOR_KillModeMinTime)
                RIGHT_MOTOR_WriteKillTime(RIGHT_MOTOR_backup.PWMKillCounterPeriod);
            #endif /* (RIGHT_MOTOR_KillModeMinTime) */

            #if(RIGHT_MOTOR_UseControl)
                RIGHT_MOTOR_WriteControlRegister(RIGHT_MOTOR_backup.PWMControlRegister);
            #endif /* (RIGHT_MOTOR_UseControl) */
        #endif  /* (!RIGHT_MOTOR_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: RIGHT_MOTOR_Sleep
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
*  RIGHT_MOTOR_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void RIGHT_MOTOR_Sleep(void) 
{
    #if(RIGHT_MOTOR_UseControl)
        if(RIGHT_MOTOR_CTRL_ENABLE == (RIGHT_MOTOR_CONTROL & RIGHT_MOTOR_CTRL_ENABLE))
        {
            /*Component is enabled */
            RIGHT_MOTOR_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            RIGHT_MOTOR_backup.PWMEnableState = 0u;
        }
    #endif /* (RIGHT_MOTOR_UseControl) */

    /* Stop component */
    RIGHT_MOTOR_Stop();

    /* Save registers configuration */
    RIGHT_MOTOR_SaveConfig();
}


/*******************************************************************************
* Function Name: RIGHT_MOTOR_Wakeup
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
*  RIGHT_MOTOR_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void RIGHT_MOTOR_Wakeup(void) 
{
     /* Restore registers values */
    RIGHT_MOTOR_RestoreConfig();

    if(RIGHT_MOTOR_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        RIGHT_MOTOR_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */

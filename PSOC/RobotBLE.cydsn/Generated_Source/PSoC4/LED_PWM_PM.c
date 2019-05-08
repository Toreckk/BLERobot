/*******************************************************************************
* File Name: LED_PWM_PM.c
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

#include "LED_PWM.h"

static LED_PWM_backupStruct LED_PWM_backup;


/*******************************************************************************
* Function Name: LED_PWM_SaveConfig
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
*  LED_PWM_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void LED_PWM_SaveConfig(void) 
{

    #if(!LED_PWM_UsingFixedFunction)
        #if(!LED_PWM_PWMModeIsCenterAligned)
            LED_PWM_backup.PWMPeriod = LED_PWM_ReadPeriod();
        #endif /* (!LED_PWM_PWMModeIsCenterAligned) */
        LED_PWM_backup.PWMUdb = LED_PWM_ReadCounter();
        #if (LED_PWM_UseStatus)
            LED_PWM_backup.InterruptMaskValue = LED_PWM_STATUS_MASK;
        #endif /* (LED_PWM_UseStatus) */

        #if(LED_PWM_DeadBandMode == LED_PWM__B_PWM__DBM_256_CLOCKS || \
            LED_PWM_DeadBandMode == LED_PWM__B_PWM__DBM_2_4_CLOCKS)
            LED_PWM_backup.PWMdeadBandValue = LED_PWM_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(LED_PWM_KillModeMinTime)
             LED_PWM_backup.PWMKillCounterPeriod = LED_PWM_ReadKillTime();
        #endif /* (LED_PWM_KillModeMinTime) */

        #if(LED_PWM_UseControl)
            LED_PWM_backup.PWMControlRegister = LED_PWM_ReadControlRegister();
        #endif /* (LED_PWM_UseControl) */
    #endif  /* (!LED_PWM_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: LED_PWM_RestoreConfig
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
*  LED_PWM_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void LED_PWM_RestoreConfig(void) 
{
        #if(!LED_PWM_UsingFixedFunction)
            #if(!LED_PWM_PWMModeIsCenterAligned)
                LED_PWM_WritePeriod(LED_PWM_backup.PWMPeriod);
            #endif /* (!LED_PWM_PWMModeIsCenterAligned) */

            LED_PWM_WriteCounter(LED_PWM_backup.PWMUdb);

            #if (LED_PWM_UseStatus)
                LED_PWM_STATUS_MASK = LED_PWM_backup.InterruptMaskValue;
            #endif /* (LED_PWM_UseStatus) */

            #if(LED_PWM_DeadBandMode == LED_PWM__B_PWM__DBM_256_CLOCKS || \
                LED_PWM_DeadBandMode == LED_PWM__B_PWM__DBM_2_4_CLOCKS)
                LED_PWM_WriteDeadTime(LED_PWM_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(LED_PWM_KillModeMinTime)
                LED_PWM_WriteKillTime(LED_PWM_backup.PWMKillCounterPeriod);
            #endif /* (LED_PWM_KillModeMinTime) */

            #if(LED_PWM_UseControl)
                LED_PWM_WriteControlRegister(LED_PWM_backup.PWMControlRegister);
            #endif /* (LED_PWM_UseControl) */
        #endif  /* (!LED_PWM_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: LED_PWM_Sleep
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
*  LED_PWM_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void LED_PWM_Sleep(void) 
{
    #if(LED_PWM_UseControl)
        if(LED_PWM_CTRL_ENABLE == (LED_PWM_CONTROL & LED_PWM_CTRL_ENABLE))
        {
            /*Component is enabled */
            LED_PWM_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            LED_PWM_backup.PWMEnableState = 0u;
        }
    #endif /* (LED_PWM_UseControl) */

    /* Stop component */
    LED_PWM_Stop();

    /* Save registers configuration */
    LED_PWM_SaveConfig();
}


/*******************************************************************************
* Function Name: LED_PWM_Wakeup
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
*  LED_PWM_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void LED_PWM_Wakeup(void) 
{
     /* Restore registers values */
    LED_PWM_RestoreConfig();

    if(LED_PWM_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        LED_PWM_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */

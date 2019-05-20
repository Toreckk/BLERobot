/*******************************************************************************
* File Name: LEFT_MOTOR_PM.c
* Version 2.10
*
* Description:
*  This file contains the setup, control, and status commands to support
*  the component operations in the low power mode.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "LEFT_MOTOR.h"

static LEFT_MOTOR_BACKUP_STRUCT LEFT_MOTOR_backup;


/*******************************************************************************
* Function Name: LEFT_MOTOR_SaveConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to save here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void LEFT_MOTOR_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: LEFT_MOTOR_Sleep
********************************************************************************
*
* Summary:
*  Stops the component operation and saves the user configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void LEFT_MOTOR_Sleep(void)
{
    if(0u != (LEFT_MOTOR_BLOCK_CONTROL_REG & LEFT_MOTOR_MASK))
    {
        LEFT_MOTOR_backup.enableState = 1u;
    }
    else
    {
        LEFT_MOTOR_backup.enableState = 0u;
    }

    LEFT_MOTOR_Stop();
    LEFT_MOTOR_SaveConfig();
}


/*******************************************************************************
* Function Name: LEFT_MOTOR_RestoreConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to restore here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void LEFT_MOTOR_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: LEFT_MOTOR_Wakeup
********************************************************************************
*
* Summary:
*  Restores the user configuration and restores the enable state.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void LEFT_MOTOR_Wakeup(void)
{
    LEFT_MOTOR_RestoreConfig();

    if(0u != LEFT_MOTOR_backup.enableState)
    {
        LEFT_MOTOR_Enable();
    }
}


/* [] END OF FILE */

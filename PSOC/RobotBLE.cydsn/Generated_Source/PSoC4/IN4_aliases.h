/*******************************************************************************
* File Name: IN4.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_IN4_ALIASES_H) /* Pins IN4_ALIASES_H */
#define CY_PINS_IN4_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define IN4_0			(IN4__0__PC)
#define IN4_0_PS		(IN4__0__PS)
#define IN4_0_PC		(IN4__0__PC)
#define IN4_0_DR		(IN4__0__DR)
#define IN4_0_SHIFT	(IN4__0__SHIFT)
#define IN4_0_INTR	((uint16)((uint16)0x0003u << (IN4__0__SHIFT*2u)))

#define IN4_INTR_ALL	 ((uint16)(IN4_0_INTR))


#endif /* End Pins IN4_ALIASES_H */


/* [] END OF FILE */

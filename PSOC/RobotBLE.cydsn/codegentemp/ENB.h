/*******************************************************************************
* File Name: ENB.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_ENB_H) /* Pins ENB_H */
#define CY_PINS_ENB_H

#include "cytypes.h"
#include "cyfitter.h"
#include "ENB_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} ENB_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   ENB_Read(void);
void    ENB_Write(uint8 value);
uint8   ENB_ReadDataReg(void);
#if defined(ENB__PC) || (CY_PSOC4_4200L) 
    void    ENB_SetDriveMode(uint8 mode);
#endif
void    ENB_SetInterruptMode(uint16 position, uint16 mode);
uint8   ENB_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void ENB_Sleep(void); 
void ENB_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(ENB__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define ENB_DRIVE_MODE_BITS        (3)
    #define ENB_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - ENB_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the ENB_SetDriveMode() function.
         *  @{
         */
        #define ENB_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define ENB_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define ENB_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define ENB_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define ENB_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define ENB_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define ENB_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define ENB_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define ENB_MASK               ENB__MASK
#define ENB_SHIFT              ENB__SHIFT
#define ENB_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in ENB_SetInterruptMode() function.
     *  @{
     */
        #define ENB_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define ENB_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define ENB_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define ENB_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(ENB__SIO)
    #define ENB_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(ENB__PC) && (CY_PSOC4_4200L)
    #define ENB_USBIO_ENABLE               ((uint32)0x80000000u)
    #define ENB_USBIO_DISABLE              ((uint32)(~ENB_USBIO_ENABLE))
    #define ENB_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define ENB_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define ENB_USBIO_ENTER_SLEEP          ((uint32)((1u << ENB_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << ENB_USBIO_SUSPEND_DEL_SHIFT)))
    #define ENB_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << ENB_USBIO_SUSPEND_SHIFT)))
    #define ENB_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << ENB_USBIO_SUSPEND_DEL_SHIFT)))
    #define ENB_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(ENB__PC)
    /* Port Configuration */
    #define ENB_PC                 (* (reg32 *) ENB__PC)
#endif
/* Pin State */
#define ENB_PS                     (* (reg32 *) ENB__PS)
/* Data Register */
#define ENB_DR                     (* (reg32 *) ENB__DR)
/* Input Buffer Disable Override */
#define ENB_INP_DIS                (* (reg32 *) ENB__PC2)

/* Interrupt configuration Registers */
#define ENB_INTCFG                 (* (reg32 *) ENB__INTCFG)
#define ENB_INTSTAT                (* (reg32 *) ENB__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define ENB_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(ENB__SIO)
    #define ENB_SIO_REG            (* (reg32 *) ENB__SIO)
#endif /* (ENB__SIO_CFG) */

/* USBIO registers */
#if !defined(ENB__PC) && (CY_PSOC4_4200L)
    #define ENB_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define ENB_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define ENB_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define ENB_DRIVE_MODE_SHIFT       (0x00u)
#define ENB_DRIVE_MODE_MASK        (0x07u << ENB_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins ENB_H */


/* [] END OF FILE */

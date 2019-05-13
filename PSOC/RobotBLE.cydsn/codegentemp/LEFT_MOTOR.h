/*******************************************************************************
* File Name: LEFT_MOTOR.h
* Version 3.30
*
* Description:
*  Contains the prototypes and constants for the functions available to the
*  PWM user module.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_PWM_LEFT_MOTOR_H)
#define CY_PWM_LEFT_MOTOR_H

#include "cyfitter.h"
#include "cytypes.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */

extern uint8 LEFT_MOTOR_initVar;


/***************************************
* Conditional Compilation Parameters
***************************************/
#define LEFT_MOTOR_Resolution                     (8u)
#define LEFT_MOTOR_UsingFixedFunction             (0u)
#define LEFT_MOTOR_DeadBandMode                   (0u)
#define LEFT_MOTOR_KillModeMinTime                (0u)
#define LEFT_MOTOR_KillMode                       (0u)
#define LEFT_MOTOR_PWMMode                        (0u)
#define LEFT_MOTOR_PWMModeIsCenterAligned         (0u)
#define LEFT_MOTOR_DeadBandUsed                   (0u)
#define LEFT_MOTOR_DeadBand2_4                    (0u)

#if !defined(LEFT_MOTOR_PWMUDB_genblk8_stsreg__REMOVED)
    #define LEFT_MOTOR_UseStatus                  (1u)
#else
    #define LEFT_MOTOR_UseStatus                  (0u)
#endif /* !defined(LEFT_MOTOR_PWMUDB_genblk8_stsreg__REMOVED) */

#if !defined(LEFT_MOTOR_PWMUDB_genblk1_ctrlreg__REMOVED)
    #define LEFT_MOTOR_UseControl                 (1u)
#else
    #define LEFT_MOTOR_UseControl                 (0u)
#endif /* !defined(LEFT_MOTOR_PWMUDB_genblk1_ctrlreg__REMOVED) */

#define LEFT_MOTOR_UseOneCompareMode              (1u)
#define LEFT_MOTOR_MinimumKillTime                (1u)
#define LEFT_MOTOR_EnableMode                     (0u)

#define LEFT_MOTOR_CompareMode1SW                 (0u)
#define LEFT_MOTOR_CompareMode2SW                 (0u)

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component PWM_v3_30 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */

/* Use Kill Mode Enumerated Types */
#define LEFT_MOTOR__B_PWM__DISABLED 0
#define LEFT_MOTOR__B_PWM__ASYNCHRONOUS 1
#define LEFT_MOTOR__B_PWM__SINGLECYCLE 2
#define LEFT_MOTOR__B_PWM__LATCHED 3
#define LEFT_MOTOR__B_PWM__MINTIME 4


/* Use Dead Band Mode Enumerated Types */
#define LEFT_MOTOR__B_PWM__DBMDISABLED 0
#define LEFT_MOTOR__B_PWM__DBM_2_4_CLOCKS 1
#define LEFT_MOTOR__B_PWM__DBM_256_CLOCKS 2


/* Used PWM Mode Enumerated Types */
#define LEFT_MOTOR__B_PWM__ONE_OUTPUT 0
#define LEFT_MOTOR__B_PWM__TWO_OUTPUTS 1
#define LEFT_MOTOR__B_PWM__DUAL_EDGE 2
#define LEFT_MOTOR__B_PWM__CENTER_ALIGN 3
#define LEFT_MOTOR__B_PWM__DITHER 5
#define LEFT_MOTOR__B_PWM__HARDWARESELECT 4


/* Used PWM Compare Mode Enumerated Types */
#define LEFT_MOTOR__B_PWM__LESS_THAN 1
#define LEFT_MOTOR__B_PWM__LESS_THAN_OR_EQUAL 2
#define LEFT_MOTOR__B_PWM__GREATER_THAN 3
#define LEFT_MOTOR__B_PWM__GREATER_THAN_OR_EQUAL_TO 4
#define LEFT_MOTOR__B_PWM__EQUAL 0
#define LEFT_MOTOR__B_PWM__FIRMWARE 5



/***************************************
* Data Struct Definition
***************************************/


/**************************************************************************
 * Sleep Wakeup Backup structure for PWM Component
 *************************************************************************/
typedef struct
{

    uint8 PWMEnableState;

    #if(!LEFT_MOTOR_UsingFixedFunction)
        uint8 PWMUdb;               /* PWM Current Counter value  */
        #if(!LEFT_MOTOR_PWMModeIsCenterAligned)
            uint8 PWMPeriod;
        #endif /* (!LEFT_MOTOR_PWMModeIsCenterAligned) */
        #if (LEFT_MOTOR_UseStatus)
            uint8 InterruptMaskValue;   /* PWM Current Interrupt Mask */
        #endif /* (LEFT_MOTOR_UseStatus) */

        /* Backup for Deadband parameters */
        #if(LEFT_MOTOR_DeadBandMode == LEFT_MOTOR__B_PWM__DBM_256_CLOCKS || \
            LEFT_MOTOR_DeadBandMode == LEFT_MOTOR__B_PWM__DBM_2_4_CLOCKS)
            uint8 PWMdeadBandValue; /* Dead Band Counter Current Value */
        #endif /* deadband count is either 2-4 clocks or 256 clocks */

        /* Backup Kill Mode Counter*/
        #if(LEFT_MOTOR_KillModeMinTime)
            uint8 PWMKillCounterPeriod; /* Kill Mode period value */
        #endif /* (LEFT_MOTOR_KillModeMinTime) */

        /* Backup control register */
        #if(LEFT_MOTOR_UseControl)
            uint8 PWMControlRegister; /* PWM Control Register value */
        #endif /* (LEFT_MOTOR_UseControl) */

    #endif /* (!LEFT_MOTOR_UsingFixedFunction) */

}LEFT_MOTOR_backupStruct;


/***************************************
*        Function Prototypes
 **************************************/

void    LEFT_MOTOR_Start(void) ;
void    LEFT_MOTOR_Stop(void) ;

#if (LEFT_MOTOR_UseStatus || LEFT_MOTOR_UsingFixedFunction)
    void  LEFT_MOTOR_SetInterruptMode(uint8 interruptMode) ;
    uint8 LEFT_MOTOR_ReadStatusRegister(void) ;
#endif /* (LEFT_MOTOR_UseStatus || LEFT_MOTOR_UsingFixedFunction) */

#define LEFT_MOTOR_GetInterruptSource() LEFT_MOTOR_ReadStatusRegister()

#if (LEFT_MOTOR_UseControl)
    uint8 LEFT_MOTOR_ReadControlRegister(void) ;
    void  LEFT_MOTOR_WriteControlRegister(uint8 control)
          ;
#endif /* (LEFT_MOTOR_UseControl) */

#if (LEFT_MOTOR_UseOneCompareMode)
   #if (LEFT_MOTOR_CompareMode1SW)
       void    LEFT_MOTOR_SetCompareMode(uint8 comparemode)
               ;
   #endif /* (LEFT_MOTOR_CompareMode1SW) */
#else
    #if (LEFT_MOTOR_CompareMode1SW)
        void    LEFT_MOTOR_SetCompareMode1(uint8 comparemode)
                ;
    #endif /* (LEFT_MOTOR_CompareMode1SW) */
    #if (LEFT_MOTOR_CompareMode2SW)
        void    LEFT_MOTOR_SetCompareMode2(uint8 comparemode)
                ;
    #endif /* (LEFT_MOTOR_CompareMode2SW) */
#endif /* (LEFT_MOTOR_UseOneCompareMode) */

#if (!LEFT_MOTOR_UsingFixedFunction)
    uint8   LEFT_MOTOR_ReadCounter(void) ;
    uint8 LEFT_MOTOR_ReadCapture(void) ;

    #if (LEFT_MOTOR_UseStatus)
            void LEFT_MOTOR_ClearFIFO(void) ;
    #endif /* (LEFT_MOTOR_UseStatus) */

    void    LEFT_MOTOR_WriteCounter(uint8 counter)
            ;
#endif /* (!LEFT_MOTOR_UsingFixedFunction) */

void    LEFT_MOTOR_WritePeriod(uint8 period)
        ;
uint8 LEFT_MOTOR_ReadPeriod(void) ;

#if (LEFT_MOTOR_UseOneCompareMode)
    void    LEFT_MOTOR_WriteCompare(uint8 compare)
            ;
    uint8 LEFT_MOTOR_ReadCompare(void) ;
#else
    void    LEFT_MOTOR_WriteCompare1(uint8 compare)
            ;
    uint8 LEFT_MOTOR_ReadCompare1(void) ;
    void    LEFT_MOTOR_WriteCompare2(uint8 compare)
            ;
    uint8 LEFT_MOTOR_ReadCompare2(void) ;
#endif /* (LEFT_MOTOR_UseOneCompareMode) */


#if (LEFT_MOTOR_DeadBandUsed)
    void    LEFT_MOTOR_WriteDeadTime(uint8 deadtime) ;
    uint8   LEFT_MOTOR_ReadDeadTime(void) ;
#endif /* (LEFT_MOTOR_DeadBandUsed) */

#if ( LEFT_MOTOR_KillModeMinTime)
    void LEFT_MOTOR_WriteKillTime(uint8 killtime) ;
    uint8 LEFT_MOTOR_ReadKillTime(void) ;
#endif /* ( LEFT_MOTOR_KillModeMinTime) */

void LEFT_MOTOR_Init(void) ;
void LEFT_MOTOR_Enable(void) ;
void LEFT_MOTOR_Sleep(void) ;
void LEFT_MOTOR_Wakeup(void) ;
void LEFT_MOTOR_SaveConfig(void) ;
void LEFT_MOTOR_RestoreConfig(void) ;


/***************************************
*         Initialization Values
**************************************/
#define LEFT_MOTOR_INIT_PERIOD_VALUE          (100u)
#define LEFT_MOTOR_INIT_COMPARE_VALUE1        (50u)
#define LEFT_MOTOR_INIT_COMPARE_VALUE2        (63u)
#define LEFT_MOTOR_INIT_INTERRUPTS_MODE       (uint8)(((uint8)(0u <<   \
                                                    LEFT_MOTOR_STATUS_TC_INT_EN_MASK_SHIFT)) | \
                                                    (uint8)((uint8)(0u <<  \
                                                    LEFT_MOTOR_STATUS_CMP2_INT_EN_MASK_SHIFT)) | \
                                                    (uint8)((uint8)(0u <<  \
                                                    LEFT_MOTOR_STATUS_CMP1_INT_EN_MASK_SHIFT )) | \
                                                    (uint8)((uint8)(0u <<  \
                                                    LEFT_MOTOR_STATUS_KILL_INT_EN_MASK_SHIFT )))
#define LEFT_MOTOR_DEFAULT_COMPARE2_MODE      (uint8)((uint8)1u <<  LEFT_MOTOR_CTRL_CMPMODE2_SHIFT)
#define LEFT_MOTOR_DEFAULT_COMPARE1_MODE      (uint8)((uint8)1u <<  LEFT_MOTOR_CTRL_CMPMODE1_SHIFT)
#define LEFT_MOTOR_INIT_DEAD_TIME             (1u)


/********************************
*         Registers
******************************** */

#if (LEFT_MOTOR_UsingFixedFunction)
   #define LEFT_MOTOR_PERIOD_LSB              (*(reg16 *) LEFT_MOTOR_PWMHW__PER0)
   #define LEFT_MOTOR_PERIOD_LSB_PTR          ( (reg16 *) LEFT_MOTOR_PWMHW__PER0)
   #define LEFT_MOTOR_COMPARE1_LSB            (*(reg16 *) LEFT_MOTOR_PWMHW__CNT_CMP0)
   #define LEFT_MOTOR_COMPARE1_LSB_PTR        ( (reg16 *) LEFT_MOTOR_PWMHW__CNT_CMP0)
   #define LEFT_MOTOR_COMPARE2_LSB            (0x00u)
   #define LEFT_MOTOR_COMPARE2_LSB_PTR        (0x00u)
   #define LEFT_MOTOR_COUNTER_LSB             (*(reg16 *) LEFT_MOTOR_PWMHW__CNT_CMP0)
   #define LEFT_MOTOR_COUNTER_LSB_PTR         ( (reg16 *) LEFT_MOTOR_PWMHW__CNT_CMP0)
   #define LEFT_MOTOR_CAPTURE_LSB             (*(reg16 *) LEFT_MOTOR_PWMHW__CAP0)
   #define LEFT_MOTOR_CAPTURE_LSB_PTR         ( (reg16 *) LEFT_MOTOR_PWMHW__CAP0)
   #define LEFT_MOTOR_RT1                     (*(reg8 *)  LEFT_MOTOR_PWMHW__RT1)
   #define LEFT_MOTOR_RT1_PTR                 ( (reg8 *)  LEFT_MOTOR_PWMHW__RT1)

#else
   #if (LEFT_MOTOR_Resolution == 8u) /* 8bit - PWM */

       #if(LEFT_MOTOR_PWMModeIsCenterAligned)
           #define LEFT_MOTOR_PERIOD_LSB      (*(reg8 *)  LEFT_MOTOR_PWMUDB_sP8_pwmdp_u0__D1_REG)
           #define LEFT_MOTOR_PERIOD_LSB_PTR  ((reg8 *)   LEFT_MOTOR_PWMUDB_sP8_pwmdp_u0__D1_REG)
       #else
           #define LEFT_MOTOR_PERIOD_LSB      (*(reg8 *)  LEFT_MOTOR_PWMUDB_sP8_pwmdp_u0__F0_REG)
           #define LEFT_MOTOR_PERIOD_LSB_PTR  ((reg8 *)   LEFT_MOTOR_PWMUDB_sP8_pwmdp_u0__F0_REG)
       #endif /* (LEFT_MOTOR_PWMModeIsCenterAligned) */

       #define LEFT_MOTOR_COMPARE1_LSB        (*(reg8 *)  LEFT_MOTOR_PWMUDB_sP8_pwmdp_u0__D0_REG)
       #define LEFT_MOTOR_COMPARE1_LSB_PTR    ((reg8 *)   LEFT_MOTOR_PWMUDB_sP8_pwmdp_u0__D0_REG)
       #define LEFT_MOTOR_COMPARE2_LSB        (*(reg8 *)  LEFT_MOTOR_PWMUDB_sP8_pwmdp_u0__D1_REG)
       #define LEFT_MOTOR_COMPARE2_LSB_PTR    ((reg8 *)   LEFT_MOTOR_PWMUDB_sP8_pwmdp_u0__D1_REG)
       #define LEFT_MOTOR_COUNTERCAP_LSB      (*(reg8 *)  LEFT_MOTOR_PWMUDB_sP8_pwmdp_u0__A1_REG)
       #define LEFT_MOTOR_COUNTERCAP_LSB_PTR  ((reg8 *)   LEFT_MOTOR_PWMUDB_sP8_pwmdp_u0__A1_REG)
       #define LEFT_MOTOR_COUNTER_LSB         (*(reg8 *)  LEFT_MOTOR_PWMUDB_sP8_pwmdp_u0__A0_REG)
       #define LEFT_MOTOR_COUNTER_LSB_PTR     ((reg8 *)   LEFT_MOTOR_PWMUDB_sP8_pwmdp_u0__A0_REG)
       #define LEFT_MOTOR_CAPTURE_LSB         (*(reg8 *)  LEFT_MOTOR_PWMUDB_sP8_pwmdp_u0__F1_REG)
       #define LEFT_MOTOR_CAPTURE_LSB_PTR     ((reg8 *)   LEFT_MOTOR_PWMUDB_sP8_pwmdp_u0__F1_REG)

   #else
        #if(CY_PSOC3) /* 8-bit address space */
            #if(LEFT_MOTOR_PWMModeIsCenterAligned)
               #define LEFT_MOTOR_PERIOD_LSB      (*(reg16 *) LEFT_MOTOR_PWMUDB_sP8_pwmdp_u0__D1_REG)
               #define LEFT_MOTOR_PERIOD_LSB_PTR  ((reg16 *)  LEFT_MOTOR_PWMUDB_sP8_pwmdp_u0__D1_REG)
            #else
               #define LEFT_MOTOR_PERIOD_LSB      (*(reg16 *) LEFT_MOTOR_PWMUDB_sP8_pwmdp_u0__F0_REG)
               #define LEFT_MOTOR_PERIOD_LSB_PTR  ((reg16 *)  LEFT_MOTOR_PWMUDB_sP8_pwmdp_u0__F0_REG)
            #endif /* (LEFT_MOTOR_PWMModeIsCenterAligned) */

            #define LEFT_MOTOR_COMPARE1_LSB       (*(reg16 *) LEFT_MOTOR_PWMUDB_sP8_pwmdp_u0__D0_REG)
            #define LEFT_MOTOR_COMPARE1_LSB_PTR   ((reg16 *)  LEFT_MOTOR_PWMUDB_sP8_pwmdp_u0__D0_REG)
            #define LEFT_MOTOR_COMPARE2_LSB       (*(reg16 *) LEFT_MOTOR_PWMUDB_sP8_pwmdp_u0__D1_REG)
            #define LEFT_MOTOR_COMPARE2_LSB_PTR   ((reg16 *)  LEFT_MOTOR_PWMUDB_sP8_pwmdp_u0__D1_REG)
            #define LEFT_MOTOR_COUNTERCAP_LSB     (*(reg16 *) LEFT_MOTOR_PWMUDB_sP8_pwmdp_u0__A1_REG)
            #define LEFT_MOTOR_COUNTERCAP_LSB_PTR ((reg16 *)  LEFT_MOTOR_PWMUDB_sP8_pwmdp_u0__A1_REG)
            #define LEFT_MOTOR_COUNTER_LSB        (*(reg16 *) LEFT_MOTOR_PWMUDB_sP8_pwmdp_u0__A0_REG)
            #define LEFT_MOTOR_COUNTER_LSB_PTR    ((reg16 *)  LEFT_MOTOR_PWMUDB_sP8_pwmdp_u0__A0_REG)
            #define LEFT_MOTOR_CAPTURE_LSB        (*(reg16 *) LEFT_MOTOR_PWMUDB_sP8_pwmdp_u0__F1_REG)
            #define LEFT_MOTOR_CAPTURE_LSB_PTR    ((reg16 *)  LEFT_MOTOR_PWMUDB_sP8_pwmdp_u0__F1_REG)
        #else
            #if(LEFT_MOTOR_PWMModeIsCenterAligned)
               #define LEFT_MOTOR_PERIOD_LSB      (*(reg16 *) LEFT_MOTOR_PWMUDB_sP8_pwmdp_u0__16BIT_D1_REG)
               #define LEFT_MOTOR_PERIOD_LSB_PTR  ((reg16 *)  LEFT_MOTOR_PWMUDB_sP8_pwmdp_u0__16BIT_D1_REG)
            #else
               #define LEFT_MOTOR_PERIOD_LSB      (*(reg16 *) LEFT_MOTOR_PWMUDB_sP8_pwmdp_u0__16BIT_F0_REG)
               #define LEFT_MOTOR_PERIOD_LSB_PTR  ((reg16 *)  LEFT_MOTOR_PWMUDB_sP8_pwmdp_u0__16BIT_F0_REG)
            #endif /* (LEFT_MOTOR_PWMModeIsCenterAligned) */

            #define LEFT_MOTOR_COMPARE1_LSB       (*(reg16 *) LEFT_MOTOR_PWMUDB_sP8_pwmdp_u0__16BIT_D0_REG)
            #define LEFT_MOTOR_COMPARE1_LSB_PTR   ((reg16 *)  LEFT_MOTOR_PWMUDB_sP8_pwmdp_u0__16BIT_D0_REG)
            #define LEFT_MOTOR_COMPARE2_LSB       (*(reg16 *) LEFT_MOTOR_PWMUDB_sP8_pwmdp_u0__16BIT_D1_REG)
            #define LEFT_MOTOR_COMPARE2_LSB_PTR   ((reg16 *)  LEFT_MOTOR_PWMUDB_sP8_pwmdp_u0__16BIT_D1_REG)
            #define LEFT_MOTOR_COUNTERCAP_LSB     (*(reg16 *) LEFT_MOTOR_PWMUDB_sP8_pwmdp_u0__16BIT_A1_REG)
            #define LEFT_MOTOR_COUNTERCAP_LSB_PTR ((reg16 *)  LEFT_MOTOR_PWMUDB_sP8_pwmdp_u0__16BIT_A1_REG)
            #define LEFT_MOTOR_COUNTER_LSB        (*(reg16 *) LEFT_MOTOR_PWMUDB_sP8_pwmdp_u0__16BIT_A0_REG)
            #define LEFT_MOTOR_COUNTER_LSB_PTR    ((reg16 *)  LEFT_MOTOR_PWMUDB_sP8_pwmdp_u0__16BIT_A0_REG)
            #define LEFT_MOTOR_CAPTURE_LSB        (*(reg16 *) LEFT_MOTOR_PWMUDB_sP8_pwmdp_u0__16BIT_F1_REG)
            #define LEFT_MOTOR_CAPTURE_LSB_PTR    ((reg16 *)  LEFT_MOTOR_PWMUDB_sP8_pwmdp_u0__16BIT_F1_REG)
        #endif /* (CY_PSOC3) */

       #define LEFT_MOTOR_AUX_CONTROLDP1          (*(reg8 *)  LEFT_MOTOR_PWMUDB_sP8_pwmdp_u1__DP_AUX_CTL_REG)
       #define LEFT_MOTOR_AUX_CONTROLDP1_PTR      ((reg8 *)   LEFT_MOTOR_PWMUDB_sP8_pwmdp_u1__DP_AUX_CTL_REG)

   #endif /* (LEFT_MOTOR_Resolution == 8) */

   #define LEFT_MOTOR_COUNTERCAP_LSB_PTR_8BIT ( (reg8 *)  LEFT_MOTOR_PWMUDB_sP8_pwmdp_u0__A1_REG)
   #define LEFT_MOTOR_AUX_CONTROLDP0          (*(reg8 *)  LEFT_MOTOR_PWMUDB_sP8_pwmdp_u0__DP_AUX_CTL_REG)
   #define LEFT_MOTOR_AUX_CONTROLDP0_PTR      ((reg8 *)   LEFT_MOTOR_PWMUDB_sP8_pwmdp_u0__DP_AUX_CTL_REG)

#endif /* (LEFT_MOTOR_UsingFixedFunction) */

#if(LEFT_MOTOR_KillModeMinTime )
    #define LEFT_MOTOR_KILLMODEMINTIME        (*(reg8 *)  LEFT_MOTOR_PWMUDB_sKM_killmodecounterdp_u0__D0_REG)
    #define LEFT_MOTOR_KILLMODEMINTIME_PTR    ((reg8 *)   LEFT_MOTOR_PWMUDB_sKM_killmodecounterdp_u0__D0_REG)
    /* Fixed Function Block has no Kill Mode parameters because it is Asynchronous only */
#endif /* (LEFT_MOTOR_KillModeMinTime ) */

#if(LEFT_MOTOR_DeadBandMode == LEFT_MOTOR__B_PWM__DBM_256_CLOCKS)
    #define LEFT_MOTOR_DEADBAND_COUNT         (*(reg8 *)  LEFT_MOTOR_PWMUDB_sDB255_deadbandcounterdp_u0__D0_REG)
    #define LEFT_MOTOR_DEADBAND_COUNT_PTR     ((reg8 *)   LEFT_MOTOR_PWMUDB_sDB255_deadbandcounterdp_u0__D0_REG)
    #define LEFT_MOTOR_DEADBAND_LSB_PTR       ((reg8 *)   LEFT_MOTOR_PWMUDB_sDB255_deadbandcounterdp_u0__A0_REG)
    #define LEFT_MOTOR_DEADBAND_LSB           (*(reg8 *)  LEFT_MOTOR_PWMUDB_sDB255_deadbandcounterdp_u0__A0_REG)
#elif(LEFT_MOTOR_DeadBandMode == LEFT_MOTOR__B_PWM__DBM_2_4_CLOCKS)
    
    /* In Fixed Function Block these bits are in the control blocks control register */
    #if (LEFT_MOTOR_UsingFixedFunction)
        #define LEFT_MOTOR_DEADBAND_COUNT         (*(reg8 *)  LEFT_MOTOR_PWMHW__CFG0)
        #define LEFT_MOTOR_DEADBAND_COUNT_PTR     ((reg8 *)   LEFT_MOTOR_PWMHW__CFG0)
        #define LEFT_MOTOR_DEADBAND_COUNT_MASK    (uint8)((uint8)0x03u << LEFT_MOTOR_DEADBAND_COUNT_SHIFT)

        /* As defined by the Register Map as DEADBAND_PERIOD[1:0] in CFG0 */
        #define LEFT_MOTOR_DEADBAND_COUNT_SHIFT   (0x06u)
    #else
        /* Lower two bits of the added control register define the count 1-3 */
        #define LEFT_MOTOR_DEADBAND_COUNT         (*(reg8 *)  LEFT_MOTOR_PWMUDB_genblk7_dbctrlreg__CONTROL_REG)
        #define LEFT_MOTOR_DEADBAND_COUNT_PTR     ((reg8 *)   LEFT_MOTOR_PWMUDB_genblk7_dbctrlreg__CONTROL_REG)
        #define LEFT_MOTOR_DEADBAND_COUNT_MASK    (uint8)((uint8)0x03u << LEFT_MOTOR_DEADBAND_COUNT_SHIFT)

        /* As defined by the verilog implementation of the Control Register */
        #define LEFT_MOTOR_DEADBAND_COUNT_SHIFT   (0x00u)
    #endif /* (LEFT_MOTOR_UsingFixedFunction) */
#endif /* (LEFT_MOTOR_DeadBandMode == LEFT_MOTOR__B_PWM__DBM_256_CLOCKS) */



#if (LEFT_MOTOR_UsingFixedFunction)
    #define LEFT_MOTOR_STATUS                 (*(reg8 *) LEFT_MOTOR_PWMHW__SR0)
    #define LEFT_MOTOR_STATUS_PTR             ((reg8 *) LEFT_MOTOR_PWMHW__SR0)
    #define LEFT_MOTOR_STATUS_MASK            (*(reg8 *) LEFT_MOTOR_PWMHW__SR0)
    #define LEFT_MOTOR_STATUS_MASK_PTR        ((reg8 *) LEFT_MOTOR_PWMHW__SR0)
    #define LEFT_MOTOR_CONTROL                (*(reg8 *) LEFT_MOTOR_PWMHW__CFG0)
    #define LEFT_MOTOR_CONTROL_PTR            ((reg8 *) LEFT_MOTOR_PWMHW__CFG0)
    #define LEFT_MOTOR_CONTROL2               (*(reg8 *) LEFT_MOTOR_PWMHW__CFG1)
    #define LEFT_MOTOR_CONTROL3               (*(reg8 *) LEFT_MOTOR_PWMHW__CFG2)
    #define LEFT_MOTOR_GLOBAL_ENABLE          (*(reg8 *) LEFT_MOTOR_PWMHW__PM_ACT_CFG)
    #define LEFT_MOTOR_GLOBAL_ENABLE_PTR      ( (reg8 *) LEFT_MOTOR_PWMHW__PM_ACT_CFG)
    #define LEFT_MOTOR_GLOBAL_STBY_ENABLE     (*(reg8 *) LEFT_MOTOR_PWMHW__PM_STBY_CFG)
    #define LEFT_MOTOR_GLOBAL_STBY_ENABLE_PTR ( (reg8 *) LEFT_MOTOR_PWMHW__PM_STBY_CFG)


    /***********************************
    *          Constants
    ***********************************/

    /* Fixed Function Block Chosen */
    #define LEFT_MOTOR_BLOCK_EN_MASK          (LEFT_MOTOR_PWMHW__PM_ACT_MSK)
    #define LEFT_MOTOR_BLOCK_STBY_EN_MASK     (LEFT_MOTOR_PWMHW__PM_STBY_MSK)
    
    /* Control Register definitions */
    #define LEFT_MOTOR_CTRL_ENABLE_SHIFT      (0x00u)

    /* As defined by Register map as MODE_CFG bits in CFG2*/
    #define LEFT_MOTOR_CTRL_CMPMODE1_SHIFT    (0x04u)

    /* As defined by Register map */
    #define LEFT_MOTOR_CTRL_DEAD_TIME_SHIFT   (0x06u)  

    /* Fixed Function Block Only CFG register bit definitions */
    /*  Set to compare mode */
    #define LEFT_MOTOR_CFG0_MODE              (0x02u)   

    /* Enable the block to run */
    #define LEFT_MOTOR_CFG0_ENABLE            (0x01u)   
    
    /* As defined by Register map as DB bit in CFG0 */
    #define LEFT_MOTOR_CFG0_DB                (0x20u)   

    /* Control Register Bit Masks */
    #define LEFT_MOTOR_CTRL_ENABLE            (uint8)((uint8)0x01u << LEFT_MOTOR_CTRL_ENABLE_SHIFT)
    #define LEFT_MOTOR_CTRL_RESET             (uint8)((uint8)0x01u << LEFT_MOTOR_CTRL_RESET_SHIFT)
    #define LEFT_MOTOR_CTRL_CMPMODE2_MASK     (uint8)((uint8)0x07u << LEFT_MOTOR_CTRL_CMPMODE2_SHIFT)
    #define LEFT_MOTOR_CTRL_CMPMODE1_MASK     (uint8)((uint8)0x07u << LEFT_MOTOR_CTRL_CMPMODE1_SHIFT)

    /* Control2 Register Bit Masks */
    /* As defined in Register Map, Part of the TMRX_CFG1 register */
    #define LEFT_MOTOR_CTRL2_IRQ_SEL_SHIFT    (0x00u)
    #define LEFT_MOTOR_CTRL2_IRQ_SEL          (uint8)((uint8)0x01u << LEFT_MOTOR_CTRL2_IRQ_SEL_SHIFT)

    /* Status Register Bit Locations */
    /* As defined by Register map as TC in SR0 */
    #define LEFT_MOTOR_STATUS_TC_SHIFT        (0x07u)   
    
    /* As defined by the Register map as CAP_CMP in SR0 */
    #define LEFT_MOTOR_STATUS_CMP1_SHIFT      (0x06u)   

    /* Status Register Interrupt Enable Bit Locations */
    #define LEFT_MOTOR_STATUS_KILL_INT_EN_MASK_SHIFT          (0x00u)
    #define LEFT_MOTOR_STATUS_TC_INT_EN_MASK_SHIFT            (LEFT_MOTOR_STATUS_TC_SHIFT - 4u)
    #define LEFT_MOTOR_STATUS_CMP2_INT_EN_MASK_SHIFT          (0x00u)
    #define LEFT_MOTOR_STATUS_CMP1_INT_EN_MASK_SHIFT          (LEFT_MOTOR_STATUS_CMP1_SHIFT - 4u)

    /* Status Register Bit Masks */
    #define LEFT_MOTOR_STATUS_TC              (uint8)((uint8)0x01u << LEFT_MOTOR_STATUS_TC_SHIFT)
    #define LEFT_MOTOR_STATUS_CMP1            (uint8)((uint8)0x01u << LEFT_MOTOR_STATUS_CMP1_SHIFT)

    /* Status Register Interrupt Bit Masks */
    #define LEFT_MOTOR_STATUS_TC_INT_EN_MASK              (uint8)((uint8)LEFT_MOTOR_STATUS_TC >> 4u)
    #define LEFT_MOTOR_STATUS_CMP1_INT_EN_MASK            (uint8)((uint8)LEFT_MOTOR_STATUS_CMP1 >> 4u)

    /*RT1 Synch Constants */
    #define LEFT_MOTOR_RT1_SHIFT             (0x04u)

    /* Sync TC and CMP bit masks */
    #define LEFT_MOTOR_RT1_MASK              (uint8)((uint8)0x03u << LEFT_MOTOR_RT1_SHIFT)
    #define LEFT_MOTOR_SYNC                  (uint8)((uint8)0x03u << LEFT_MOTOR_RT1_SHIFT)
    #define LEFT_MOTOR_SYNCDSI_SHIFT         (0x00u)

    /* Sync all DSI inputs */
    #define LEFT_MOTOR_SYNCDSI_MASK          (uint8)((uint8)0x0Fu << LEFT_MOTOR_SYNCDSI_SHIFT)

    /* Sync all DSI inputs */
    #define LEFT_MOTOR_SYNCDSI_EN            (uint8)((uint8)0x0Fu << LEFT_MOTOR_SYNCDSI_SHIFT)


#else
    #define LEFT_MOTOR_STATUS                (*(reg8 *)   LEFT_MOTOR_PWMUDB_genblk8_stsreg__STATUS_REG )
    #define LEFT_MOTOR_STATUS_PTR            ((reg8 *)    LEFT_MOTOR_PWMUDB_genblk8_stsreg__STATUS_REG )
    #define LEFT_MOTOR_STATUS_MASK           (*(reg8 *)   LEFT_MOTOR_PWMUDB_genblk8_stsreg__MASK_REG)
    #define LEFT_MOTOR_STATUS_MASK_PTR       ((reg8 *)    LEFT_MOTOR_PWMUDB_genblk8_stsreg__MASK_REG)
    #define LEFT_MOTOR_STATUS_AUX_CTRL       (*(reg8 *)   LEFT_MOTOR_PWMUDB_genblk8_stsreg__STATUS_AUX_CTL_REG)
    #define LEFT_MOTOR_CONTROL               (*(reg8 *)   LEFT_MOTOR_PWMUDB_genblk1_ctrlreg__CONTROL_REG)
    #define LEFT_MOTOR_CONTROL_PTR           ((reg8 *)    LEFT_MOTOR_PWMUDB_genblk1_ctrlreg__CONTROL_REG)


    /***********************************
    *          Constants
    ***********************************/

    /* Control Register bit definitions */
    #define LEFT_MOTOR_CTRL_ENABLE_SHIFT      (0x07u)
    #define LEFT_MOTOR_CTRL_RESET_SHIFT       (0x06u)
    #define LEFT_MOTOR_CTRL_CMPMODE2_SHIFT    (0x03u)
    #define LEFT_MOTOR_CTRL_CMPMODE1_SHIFT    (0x00u)
    #define LEFT_MOTOR_CTRL_DEAD_TIME_SHIFT   (0x00u)   /* No Shift Needed for UDB block */
    
    /* Control Register Bit Masks */
    #define LEFT_MOTOR_CTRL_ENABLE            (uint8)((uint8)0x01u << LEFT_MOTOR_CTRL_ENABLE_SHIFT)
    #define LEFT_MOTOR_CTRL_RESET             (uint8)((uint8)0x01u << LEFT_MOTOR_CTRL_RESET_SHIFT)
    #define LEFT_MOTOR_CTRL_CMPMODE2_MASK     (uint8)((uint8)0x07u << LEFT_MOTOR_CTRL_CMPMODE2_SHIFT)
    #define LEFT_MOTOR_CTRL_CMPMODE1_MASK     (uint8)((uint8)0x07u << LEFT_MOTOR_CTRL_CMPMODE1_SHIFT)

    /* Status Register Bit Locations */
    #define LEFT_MOTOR_STATUS_KILL_SHIFT          (0x05u)
    #define LEFT_MOTOR_STATUS_FIFONEMPTY_SHIFT    (0x04u)
    #define LEFT_MOTOR_STATUS_FIFOFULL_SHIFT      (0x03u)
    #define LEFT_MOTOR_STATUS_TC_SHIFT            (0x02u)
    #define LEFT_MOTOR_STATUS_CMP2_SHIFT          (0x01u)
    #define LEFT_MOTOR_STATUS_CMP1_SHIFT          (0x00u)

    /* Status Register Interrupt Enable Bit Locations - UDB Status Interrupt Mask match Status Bit Locations*/
    #define LEFT_MOTOR_STATUS_KILL_INT_EN_MASK_SHIFT          (LEFT_MOTOR_STATUS_KILL_SHIFT)
    #define LEFT_MOTOR_STATUS_FIFONEMPTY_INT_EN_MASK_SHIFT    (LEFT_MOTOR_STATUS_FIFONEMPTY_SHIFT)
    #define LEFT_MOTOR_STATUS_FIFOFULL_INT_EN_MASK_SHIFT      (LEFT_MOTOR_STATUS_FIFOFULL_SHIFT)
    #define LEFT_MOTOR_STATUS_TC_INT_EN_MASK_SHIFT            (LEFT_MOTOR_STATUS_TC_SHIFT)
    #define LEFT_MOTOR_STATUS_CMP2_INT_EN_MASK_SHIFT          (LEFT_MOTOR_STATUS_CMP2_SHIFT)
    #define LEFT_MOTOR_STATUS_CMP1_INT_EN_MASK_SHIFT          (LEFT_MOTOR_STATUS_CMP1_SHIFT)

    /* Status Register Bit Masks */
    #define LEFT_MOTOR_STATUS_KILL            (uint8)((uint8)0x00u << LEFT_MOTOR_STATUS_KILL_SHIFT )
    #define LEFT_MOTOR_STATUS_FIFOFULL        (uint8)((uint8)0x01u << LEFT_MOTOR_STATUS_FIFOFULL_SHIFT)
    #define LEFT_MOTOR_STATUS_FIFONEMPTY      (uint8)((uint8)0x01u << LEFT_MOTOR_STATUS_FIFONEMPTY_SHIFT)
    #define LEFT_MOTOR_STATUS_TC              (uint8)((uint8)0x01u << LEFT_MOTOR_STATUS_TC_SHIFT)
    #define LEFT_MOTOR_STATUS_CMP2            (uint8)((uint8)0x01u << LEFT_MOTOR_STATUS_CMP2_SHIFT)
    #define LEFT_MOTOR_STATUS_CMP1            (uint8)((uint8)0x01u << LEFT_MOTOR_STATUS_CMP1_SHIFT)

    /* Status Register Interrupt Bit Masks  - UDB Status Interrupt Mask match Status Bit Locations */
    #define LEFT_MOTOR_STATUS_KILL_INT_EN_MASK            (LEFT_MOTOR_STATUS_KILL)
    #define LEFT_MOTOR_STATUS_FIFOFULL_INT_EN_MASK        (LEFT_MOTOR_STATUS_FIFOFULL)
    #define LEFT_MOTOR_STATUS_FIFONEMPTY_INT_EN_MASK      (LEFT_MOTOR_STATUS_FIFONEMPTY)
    #define LEFT_MOTOR_STATUS_TC_INT_EN_MASK              (LEFT_MOTOR_STATUS_TC)
    #define LEFT_MOTOR_STATUS_CMP2_INT_EN_MASK            (LEFT_MOTOR_STATUS_CMP2)
    #define LEFT_MOTOR_STATUS_CMP1_INT_EN_MASK            (LEFT_MOTOR_STATUS_CMP1)

    /* Datapath Auxillary Control Register bit definitions */
    #define LEFT_MOTOR_AUX_CTRL_FIFO0_CLR         (0x01u)
    #define LEFT_MOTOR_AUX_CTRL_FIFO1_CLR         (0x02u)
    #define LEFT_MOTOR_AUX_CTRL_FIFO0_LVL         (0x04u)
    #define LEFT_MOTOR_AUX_CTRL_FIFO1_LVL         (0x08u)
    #define LEFT_MOTOR_STATUS_ACTL_INT_EN_MASK    (0x10u) /* As defined for the ACTL Register */
#endif /* LEFT_MOTOR_UsingFixedFunction */

#endif  /* CY_PWM_LEFT_MOTOR_H */


/* [] END OF FILE */

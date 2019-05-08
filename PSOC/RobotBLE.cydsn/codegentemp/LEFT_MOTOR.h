/*******************************************************************************
* File Name: LEFT_MOTOR.h
* Version 2.10
*
* Description:
*  This file provides constants and parameter values for the LEFT_MOTOR
*  component.
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

#if !defined(CY_TCPWM_LEFT_MOTOR_H)
#define CY_TCPWM_LEFT_MOTOR_H


#include "CyLib.h"
#include "cytypes.h"
#include "cyfitter.h"


/*******************************************************************************
* Internal Type defines
*******************************************************************************/

/* Structure to save state before go to sleep */
typedef struct
{
    uint8  enableState;
} LEFT_MOTOR_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  LEFT_MOTOR_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define LEFT_MOTOR_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define LEFT_MOTOR_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define LEFT_MOTOR_CONFIG                         (7lu)

/* Quad Mode */
/* Parameters */
#define LEFT_MOTOR_QUAD_ENCODING_MODES            (0lu)
#define LEFT_MOTOR_QUAD_AUTO_START                (1lu)

/* Signal modes */
#define LEFT_MOTOR_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define LEFT_MOTOR_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define LEFT_MOTOR_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define LEFT_MOTOR_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define LEFT_MOTOR_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define LEFT_MOTOR_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define LEFT_MOTOR_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define LEFT_MOTOR_TC_RUN_MODE                    (0lu)
#define LEFT_MOTOR_TC_COUNTER_MODE                (0lu)
#define LEFT_MOTOR_TC_COMP_CAP_MODE               (2lu)
#define LEFT_MOTOR_TC_PRESCALER                   (0lu)

/* Signal modes */
#define LEFT_MOTOR_TC_RELOAD_SIGNAL_MODE          (0lu)
#define LEFT_MOTOR_TC_COUNT_SIGNAL_MODE           (3lu)
#define LEFT_MOTOR_TC_START_SIGNAL_MODE           (0lu)
#define LEFT_MOTOR_TC_STOP_SIGNAL_MODE            (0lu)
#define LEFT_MOTOR_TC_CAPTURE_SIGNAL_MODE         (0lu)

/* Signal present */
#define LEFT_MOTOR_TC_RELOAD_SIGNAL_PRESENT       (0lu)
#define LEFT_MOTOR_TC_COUNT_SIGNAL_PRESENT        (0lu)
#define LEFT_MOTOR_TC_START_SIGNAL_PRESENT        (0lu)
#define LEFT_MOTOR_TC_STOP_SIGNAL_PRESENT         (0lu)
#define LEFT_MOTOR_TC_CAPTURE_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define LEFT_MOTOR_TC_INTERRUPT_MASK              (1lu)

/* PWM Mode */
/* Parameters */
#define LEFT_MOTOR_PWM_KILL_EVENT                 (0lu)
#define LEFT_MOTOR_PWM_STOP_EVENT                 (0lu)
#define LEFT_MOTOR_PWM_MODE                       (4lu)
#define LEFT_MOTOR_PWM_OUT_N_INVERT               (0lu)
#define LEFT_MOTOR_PWM_OUT_INVERT                 (0lu)
#define LEFT_MOTOR_PWM_ALIGN                      (0lu)
#define LEFT_MOTOR_PWM_RUN_MODE                   (0lu)
#define LEFT_MOTOR_PWM_DEAD_TIME_CYCLE            (0lu)
#define LEFT_MOTOR_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define LEFT_MOTOR_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define LEFT_MOTOR_PWM_COUNT_SIGNAL_MODE          (3lu)
#define LEFT_MOTOR_PWM_START_SIGNAL_MODE          (0lu)
#define LEFT_MOTOR_PWM_STOP_SIGNAL_MODE           (0lu)
#define LEFT_MOTOR_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define LEFT_MOTOR_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define LEFT_MOTOR_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define LEFT_MOTOR_PWM_START_SIGNAL_PRESENT       (0lu)
#define LEFT_MOTOR_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define LEFT_MOTOR_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define LEFT_MOTOR_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define LEFT_MOTOR_TC_PERIOD_VALUE                (65535lu)
#define LEFT_MOTOR_TC_COMPARE_VALUE               (65535lu)
#define LEFT_MOTOR_TC_COMPARE_BUF_VALUE           (65535lu)
#define LEFT_MOTOR_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define LEFT_MOTOR_PWM_PERIOD_VALUE               (100lu)
#define LEFT_MOTOR_PWM_PERIOD_BUF_VALUE           (65535lu)
#define LEFT_MOTOR_PWM_PERIOD_SWAP                (0lu)
#define LEFT_MOTOR_PWM_COMPARE_VALUE              (50lu)
#define LEFT_MOTOR_PWM_COMPARE_BUF_VALUE          (65535lu)
#define LEFT_MOTOR_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define LEFT_MOTOR__LEFT 0
#define LEFT_MOTOR__RIGHT 1
#define LEFT_MOTOR__CENTER 2
#define LEFT_MOTOR__ASYMMETRIC 3

#define LEFT_MOTOR__X1 0
#define LEFT_MOTOR__X2 1
#define LEFT_MOTOR__X4 2

#define LEFT_MOTOR__PWM 4
#define LEFT_MOTOR__PWM_DT 5
#define LEFT_MOTOR__PWM_PR 6

#define LEFT_MOTOR__INVERSE 1
#define LEFT_MOTOR__DIRECT 0

#define LEFT_MOTOR__CAPTURE 2
#define LEFT_MOTOR__COMPARE 0

#define LEFT_MOTOR__TRIG_LEVEL 3
#define LEFT_MOTOR__TRIG_RISING 0
#define LEFT_MOTOR__TRIG_FALLING 1
#define LEFT_MOTOR__TRIG_BOTH 2

#define LEFT_MOTOR__INTR_MASK_TC 1
#define LEFT_MOTOR__INTR_MASK_CC_MATCH 2
#define LEFT_MOTOR__INTR_MASK_NONE 0
#define LEFT_MOTOR__INTR_MASK_TC_CC 3

#define LEFT_MOTOR__UNCONFIG 8
#define LEFT_MOTOR__TIMER 1
#define LEFT_MOTOR__QUAD 3
#define LEFT_MOTOR__PWM_SEL 7

#define LEFT_MOTOR__COUNT_UP 0
#define LEFT_MOTOR__COUNT_DOWN 1
#define LEFT_MOTOR__COUNT_UPDOWN0 2
#define LEFT_MOTOR__COUNT_UPDOWN1 3


/* Prescaler */
#define LEFT_MOTOR_PRESCALE_DIVBY1                ((uint32)(0u << LEFT_MOTOR_PRESCALER_SHIFT))
#define LEFT_MOTOR_PRESCALE_DIVBY2                ((uint32)(1u << LEFT_MOTOR_PRESCALER_SHIFT))
#define LEFT_MOTOR_PRESCALE_DIVBY4                ((uint32)(2u << LEFT_MOTOR_PRESCALER_SHIFT))
#define LEFT_MOTOR_PRESCALE_DIVBY8                ((uint32)(3u << LEFT_MOTOR_PRESCALER_SHIFT))
#define LEFT_MOTOR_PRESCALE_DIVBY16               ((uint32)(4u << LEFT_MOTOR_PRESCALER_SHIFT))
#define LEFT_MOTOR_PRESCALE_DIVBY32               ((uint32)(5u << LEFT_MOTOR_PRESCALER_SHIFT))
#define LEFT_MOTOR_PRESCALE_DIVBY64               ((uint32)(6u << LEFT_MOTOR_PRESCALER_SHIFT))
#define LEFT_MOTOR_PRESCALE_DIVBY128              ((uint32)(7u << LEFT_MOTOR_PRESCALER_SHIFT))

/* TCPWM set modes */
#define LEFT_MOTOR_MODE_TIMER_COMPARE             ((uint32)(LEFT_MOTOR__COMPARE         <<  \
                                                                  LEFT_MOTOR_MODE_SHIFT))
#define LEFT_MOTOR_MODE_TIMER_CAPTURE             ((uint32)(LEFT_MOTOR__CAPTURE         <<  \
                                                                  LEFT_MOTOR_MODE_SHIFT))
#define LEFT_MOTOR_MODE_QUAD                      ((uint32)(LEFT_MOTOR__QUAD            <<  \
                                                                  LEFT_MOTOR_MODE_SHIFT))
#define LEFT_MOTOR_MODE_PWM                       ((uint32)(LEFT_MOTOR__PWM             <<  \
                                                                  LEFT_MOTOR_MODE_SHIFT))
#define LEFT_MOTOR_MODE_PWM_DT                    ((uint32)(LEFT_MOTOR__PWM_DT          <<  \
                                                                  LEFT_MOTOR_MODE_SHIFT))
#define LEFT_MOTOR_MODE_PWM_PR                    ((uint32)(LEFT_MOTOR__PWM_PR          <<  \
                                                                  LEFT_MOTOR_MODE_SHIFT))

/* Quad Modes */
#define LEFT_MOTOR_MODE_X1                        ((uint32)(LEFT_MOTOR__X1              <<  \
                                                                  LEFT_MOTOR_QUAD_MODE_SHIFT))
#define LEFT_MOTOR_MODE_X2                        ((uint32)(LEFT_MOTOR__X2              <<  \
                                                                  LEFT_MOTOR_QUAD_MODE_SHIFT))
#define LEFT_MOTOR_MODE_X4                        ((uint32)(LEFT_MOTOR__X4              <<  \
                                                                  LEFT_MOTOR_QUAD_MODE_SHIFT))

/* Counter modes */
#define LEFT_MOTOR_COUNT_UP                       ((uint32)(LEFT_MOTOR__COUNT_UP        <<  \
                                                                  LEFT_MOTOR_UPDOWN_SHIFT))
#define LEFT_MOTOR_COUNT_DOWN                     ((uint32)(LEFT_MOTOR__COUNT_DOWN      <<  \
                                                                  LEFT_MOTOR_UPDOWN_SHIFT))
#define LEFT_MOTOR_COUNT_UPDOWN0                  ((uint32)(LEFT_MOTOR__COUNT_UPDOWN0   <<  \
                                                                  LEFT_MOTOR_UPDOWN_SHIFT))
#define LEFT_MOTOR_COUNT_UPDOWN1                  ((uint32)(LEFT_MOTOR__COUNT_UPDOWN1   <<  \
                                                                  LEFT_MOTOR_UPDOWN_SHIFT))

/* PWM output invert */
#define LEFT_MOTOR_INVERT_LINE                    ((uint32)(LEFT_MOTOR__INVERSE         <<  \
                                                                  LEFT_MOTOR_INV_OUT_SHIFT))
#define LEFT_MOTOR_INVERT_LINE_N                  ((uint32)(LEFT_MOTOR__INVERSE         <<  \
                                                                  LEFT_MOTOR_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define LEFT_MOTOR_TRIG_RISING                    ((uint32)LEFT_MOTOR__TRIG_RISING)
#define LEFT_MOTOR_TRIG_FALLING                   ((uint32)LEFT_MOTOR__TRIG_FALLING)
#define LEFT_MOTOR_TRIG_BOTH                      ((uint32)LEFT_MOTOR__TRIG_BOTH)
#define LEFT_MOTOR_TRIG_LEVEL                     ((uint32)LEFT_MOTOR__TRIG_LEVEL)

/* Interrupt mask */
#define LEFT_MOTOR_INTR_MASK_TC                   ((uint32)LEFT_MOTOR__INTR_MASK_TC)
#define LEFT_MOTOR_INTR_MASK_CC_MATCH             ((uint32)LEFT_MOTOR__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define LEFT_MOTOR_CC_MATCH_SET                   (0x00u)
#define LEFT_MOTOR_CC_MATCH_CLEAR                 (0x01u)
#define LEFT_MOTOR_CC_MATCH_INVERT                (0x02u)
#define LEFT_MOTOR_CC_MATCH_NO_CHANGE             (0x03u)
#define LEFT_MOTOR_OVERLOW_SET                    (0x00u)
#define LEFT_MOTOR_OVERLOW_CLEAR                  (0x04u)
#define LEFT_MOTOR_OVERLOW_INVERT                 (0x08u)
#define LEFT_MOTOR_OVERLOW_NO_CHANGE              (0x0Cu)
#define LEFT_MOTOR_UNDERFLOW_SET                  (0x00u)
#define LEFT_MOTOR_UNDERFLOW_CLEAR                (0x10u)
#define LEFT_MOTOR_UNDERFLOW_INVERT               (0x20u)
#define LEFT_MOTOR_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define LEFT_MOTOR_PWM_MODE_LEFT                  (LEFT_MOTOR_CC_MATCH_CLEAR        |   \
                                                         LEFT_MOTOR_OVERLOW_SET           |   \
                                                         LEFT_MOTOR_UNDERFLOW_NO_CHANGE)
#define LEFT_MOTOR_PWM_MODE_RIGHT                 (LEFT_MOTOR_CC_MATCH_SET          |   \
                                                         LEFT_MOTOR_OVERLOW_NO_CHANGE     |   \
                                                         LEFT_MOTOR_UNDERFLOW_CLEAR)
#define LEFT_MOTOR_PWM_MODE_ASYM                  (LEFT_MOTOR_CC_MATCH_INVERT       |   \
                                                         LEFT_MOTOR_OVERLOW_SET           |   \
                                                         LEFT_MOTOR_UNDERFLOW_CLEAR)

#if (LEFT_MOTOR_CY_TCPWM_V2)
    #if(LEFT_MOTOR_CY_TCPWM_4000)
        #define LEFT_MOTOR_PWM_MODE_CENTER                (LEFT_MOTOR_CC_MATCH_INVERT       |   \
                                                                 LEFT_MOTOR_OVERLOW_NO_CHANGE     |   \
                                                                 LEFT_MOTOR_UNDERFLOW_CLEAR)
    #else
        #define LEFT_MOTOR_PWM_MODE_CENTER                (LEFT_MOTOR_CC_MATCH_INVERT       |   \
                                                                 LEFT_MOTOR_OVERLOW_SET           |   \
                                                                 LEFT_MOTOR_UNDERFLOW_CLEAR)
    #endif /* (LEFT_MOTOR_CY_TCPWM_4000) */
#else
    #define LEFT_MOTOR_PWM_MODE_CENTER                (LEFT_MOTOR_CC_MATCH_INVERT       |   \
                                                             LEFT_MOTOR_OVERLOW_NO_CHANGE     |   \
                                                             LEFT_MOTOR_UNDERFLOW_CLEAR)
#endif /* (LEFT_MOTOR_CY_TCPWM_NEW) */

/* Command operations without condition */
#define LEFT_MOTOR_CMD_CAPTURE                    (0u)
#define LEFT_MOTOR_CMD_RELOAD                     (8u)
#define LEFT_MOTOR_CMD_STOP                       (16u)
#define LEFT_MOTOR_CMD_START                      (24u)

/* Status */
#define LEFT_MOTOR_STATUS_DOWN                    (1u)
#define LEFT_MOTOR_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   LEFT_MOTOR_Init(void);
void   LEFT_MOTOR_Enable(void);
void   LEFT_MOTOR_Start(void);
void   LEFT_MOTOR_Stop(void);

void   LEFT_MOTOR_SetMode(uint32 mode);
void   LEFT_MOTOR_SetCounterMode(uint32 counterMode);
void   LEFT_MOTOR_SetPWMMode(uint32 modeMask);
void   LEFT_MOTOR_SetQDMode(uint32 qdMode);

void   LEFT_MOTOR_SetPrescaler(uint32 prescaler);
void   LEFT_MOTOR_TriggerCommand(uint32 mask, uint32 command);
void   LEFT_MOTOR_SetOneShot(uint32 oneShotEnable);
uint32 LEFT_MOTOR_ReadStatus(void);

void   LEFT_MOTOR_SetPWMSyncKill(uint32 syncKillEnable);
void   LEFT_MOTOR_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   LEFT_MOTOR_SetPWMDeadTime(uint32 deadTime);
void   LEFT_MOTOR_SetPWMInvert(uint32 mask);

void   LEFT_MOTOR_SetInterruptMode(uint32 interruptMask);
uint32 LEFT_MOTOR_GetInterruptSourceMasked(void);
uint32 LEFT_MOTOR_GetInterruptSource(void);
void   LEFT_MOTOR_ClearInterrupt(uint32 interruptMask);
void   LEFT_MOTOR_SetInterrupt(uint32 interruptMask);

void   LEFT_MOTOR_WriteCounter(uint32 count);
uint32 LEFT_MOTOR_ReadCounter(void);

uint32 LEFT_MOTOR_ReadCapture(void);
uint32 LEFT_MOTOR_ReadCaptureBuf(void);

void   LEFT_MOTOR_WritePeriod(uint32 period);
uint32 LEFT_MOTOR_ReadPeriod(void);
void   LEFT_MOTOR_WritePeriodBuf(uint32 periodBuf);
uint32 LEFT_MOTOR_ReadPeriodBuf(void);

void   LEFT_MOTOR_WriteCompare(uint32 compare);
uint32 LEFT_MOTOR_ReadCompare(void);
void   LEFT_MOTOR_WriteCompareBuf(uint32 compareBuf);
uint32 LEFT_MOTOR_ReadCompareBuf(void);

void   LEFT_MOTOR_SetPeriodSwap(uint32 swapEnable);
void   LEFT_MOTOR_SetCompareSwap(uint32 swapEnable);

void   LEFT_MOTOR_SetCaptureMode(uint32 triggerMode);
void   LEFT_MOTOR_SetReloadMode(uint32 triggerMode);
void   LEFT_MOTOR_SetStartMode(uint32 triggerMode);
void   LEFT_MOTOR_SetStopMode(uint32 triggerMode);
void   LEFT_MOTOR_SetCountMode(uint32 triggerMode);

void   LEFT_MOTOR_SaveConfig(void);
void   LEFT_MOTOR_RestoreConfig(void);
void   LEFT_MOTOR_Sleep(void);
void   LEFT_MOTOR_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define LEFT_MOTOR_BLOCK_CONTROL_REG              (*(reg32 *) LEFT_MOTOR_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define LEFT_MOTOR_BLOCK_CONTROL_PTR              ( (reg32 *) LEFT_MOTOR_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define LEFT_MOTOR_COMMAND_REG                    (*(reg32 *) LEFT_MOTOR_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define LEFT_MOTOR_COMMAND_PTR                    ( (reg32 *) LEFT_MOTOR_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define LEFT_MOTOR_INTRRUPT_CAUSE_REG             (*(reg32 *) LEFT_MOTOR_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define LEFT_MOTOR_INTRRUPT_CAUSE_PTR             ( (reg32 *) LEFT_MOTOR_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define LEFT_MOTOR_CONTROL_REG                    (*(reg32 *) LEFT_MOTOR_cy_m0s8_tcpwm_1__CTRL )
#define LEFT_MOTOR_CONTROL_PTR                    ( (reg32 *) LEFT_MOTOR_cy_m0s8_tcpwm_1__CTRL )
#define LEFT_MOTOR_STATUS_REG                     (*(reg32 *) LEFT_MOTOR_cy_m0s8_tcpwm_1__STATUS )
#define LEFT_MOTOR_STATUS_PTR                     ( (reg32 *) LEFT_MOTOR_cy_m0s8_tcpwm_1__STATUS )
#define LEFT_MOTOR_COUNTER_REG                    (*(reg32 *) LEFT_MOTOR_cy_m0s8_tcpwm_1__COUNTER )
#define LEFT_MOTOR_COUNTER_PTR                    ( (reg32 *) LEFT_MOTOR_cy_m0s8_tcpwm_1__COUNTER )
#define LEFT_MOTOR_COMP_CAP_REG                   (*(reg32 *) LEFT_MOTOR_cy_m0s8_tcpwm_1__CC )
#define LEFT_MOTOR_COMP_CAP_PTR                   ( (reg32 *) LEFT_MOTOR_cy_m0s8_tcpwm_1__CC )
#define LEFT_MOTOR_COMP_CAP_BUF_REG               (*(reg32 *) LEFT_MOTOR_cy_m0s8_tcpwm_1__CC_BUFF )
#define LEFT_MOTOR_COMP_CAP_BUF_PTR               ( (reg32 *) LEFT_MOTOR_cy_m0s8_tcpwm_1__CC_BUFF )
#define LEFT_MOTOR_PERIOD_REG                     (*(reg32 *) LEFT_MOTOR_cy_m0s8_tcpwm_1__PERIOD )
#define LEFT_MOTOR_PERIOD_PTR                     ( (reg32 *) LEFT_MOTOR_cy_m0s8_tcpwm_1__PERIOD )
#define LEFT_MOTOR_PERIOD_BUF_REG                 (*(reg32 *) LEFT_MOTOR_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define LEFT_MOTOR_PERIOD_BUF_PTR                 ( (reg32 *) LEFT_MOTOR_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define LEFT_MOTOR_TRIG_CONTROL0_REG              (*(reg32 *) LEFT_MOTOR_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define LEFT_MOTOR_TRIG_CONTROL0_PTR              ( (reg32 *) LEFT_MOTOR_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define LEFT_MOTOR_TRIG_CONTROL1_REG              (*(reg32 *) LEFT_MOTOR_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define LEFT_MOTOR_TRIG_CONTROL1_PTR              ( (reg32 *) LEFT_MOTOR_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define LEFT_MOTOR_TRIG_CONTROL2_REG              (*(reg32 *) LEFT_MOTOR_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define LEFT_MOTOR_TRIG_CONTROL2_PTR              ( (reg32 *) LEFT_MOTOR_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define LEFT_MOTOR_INTERRUPT_REQ_REG              (*(reg32 *) LEFT_MOTOR_cy_m0s8_tcpwm_1__INTR )
#define LEFT_MOTOR_INTERRUPT_REQ_PTR              ( (reg32 *) LEFT_MOTOR_cy_m0s8_tcpwm_1__INTR )
#define LEFT_MOTOR_INTERRUPT_SET_REG              (*(reg32 *) LEFT_MOTOR_cy_m0s8_tcpwm_1__INTR_SET )
#define LEFT_MOTOR_INTERRUPT_SET_PTR              ( (reg32 *) LEFT_MOTOR_cy_m0s8_tcpwm_1__INTR_SET )
#define LEFT_MOTOR_INTERRUPT_MASK_REG             (*(reg32 *) LEFT_MOTOR_cy_m0s8_tcpwm_1__INTR_MASK )
#define LEFT_MOTOR_INTERRUPT_MASK_PTR             ( (reg32 *) LEFT_MOTOR_cy_m0s8_tcpwm_1__INTR_MASK )
#define LEFT_MOTOR_INTERRUPT_MASKED_REG           (*(reg32 *) LEFT_MOTOR_cy_m0s8_tcpwm_1__INTR_MASKED )
#define LEFT_MOTOR_INTERRUPT_MASKED_PTR           ( (reg32 *) LEFT_MOTOR_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define LEFT_MOTOR_MASK                           ((uint32)LEFT_MOTOR_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define LEFT_MOTOR_RELOAD_CC_SHIFT                (0u)
#define LEFT_MOTOR_RELOAD_PERIOD_SHIFT            (1u)
#define LEFT_MOTOR_PWM_SYNC_KILL_SHIFT            (2u)
#define LEFT_MOTOR_PWM_STOP_KILL_SHIFT            (3u)
#define LEFT_MOTOR_PRESCALER_SHIFT                (8u)
#define LEFT_MOTOR_UPDOWN_SHIFT                   (16u)
#define LEFT_MOTOR_ONESHOT_SHIFT                  (18u)
#define LEFT_MOTOR_QUAD_MODE_SHIFT                (20u)
#define LEFT_MOTOR_INV_OUT_SHIFT                  (20u)
#define LEFT_MOTOR_INV_COMPL_OUT_SHIFT            (21u)
#define LEFT_MOTOR_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define LEFT_MOTOR_RELOAD_CC_MASK                 ((uint32)(LEFT_MOTOR_1BIT_MASK        <<  \
                                                                            LEFT_MOTOR_RELOAD_CC_SHIFT))
#define LEFT_MOTOR_RELOAD_PERIOD_MASK             ((uint32)(LEFT_MOTOR_1BIT_MASK        <<  \
                                                                            LEFT_MOTOR_RELOAD_PERIOD_SHIFT))
#define LEFT_MOTOR_PWM_SYNC_KILL_MASK             ((uint32)(LEFT_MOTOR_1BIT_MASK        <<  \
                                                                            LEFT_MOTOR_PWM_SYNC_KILL_SHIFT))
#define LEFT_MOTOR_PWM_STOP_KILL_MASK             ((uint32)(LEFT_MOTOR_1BIT_MASK        <<  \
                                                                            LEFT_MOTOR_PWM_STOP_KILL_SHIFT))
#define LEFT_MOTOR_PRESCALER_MASK                 ((uint32)(LEFT_MOTOR_8BIT_MASK        <<  \
                                                                            LEFT_MOTOR_PRESCALER_SHIFT))
#define LEFT_MOTOR_UPDOWN_MASK                    ((uint32)(LEFT_MOTOR_2BIT_MASK        <<  \
                                                                            LEFT_MOTOR_UPDOWN_SHIFT))
#define LEFT_MOTOR_ONESHOT_MASK                   ((uint32)(LEFT_MOTOR_1BIT_MASK        <<  \
                                                                            LEFT_MOTOR_ONESHOT_SHIFT))
#define LEFT_MOTOR_QUAD_MODE_MASK                 ((uint32)(LEFT_MOTOR_3BIT_MASK        <<  \
                                                                            LEFT_MOTOR_QUAD_MODE_SHIFT))
#define LEFT_MOTOR_INV_OUT_MASK                   ((uint32)(LEFT_MOTOR_2BIT_MASK        <<  \
                                                                            LEFT_MOTOR_INV_OUT_SHIFT))
#define LEFT_MOTOR_MODE_MASK                      ((uint32)(LEFT_MOTOR_3BIT_MASK        <<  \
                                                                            LEFT_MOTOR_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define LEFT_MOTOR_CAPTURE_SHIFT                  (0u)
#define LEFT_MOTOR_COUNT_SHIFT                    (2u)
#define LEFT_MOTOR_RELOAD_SHIFT                   (4u)
#define LEFT_MOTOR_STOP_SHIFT                     (6u)
#define LEFT_MOTOR_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define LEFT_MOTOR_CAPTURE_MASK                   ((uint32)(LEFT_MOTOR_2BIT_MASK        <<  \
                                                                  LEFT_MOTOR_CAPTURE_SHIFT))
#define LEFT_MOTOR_COUNT_MASK                     ((uint32)(LEFT_MOTOR_2BIT_MASK        <<  \
                                                                  LEFT_MOTOR_COUNT_SHIFT))
#define LEFT_MOTOR_RELOAD_MASK                    ((uint32)(LEFT_MOTOR_2BIT_MASK        <<  \
                                                                  LEFT_MOTOR_RELOAD_SHIFT))
#define LEFT_MOTOR_STOP_MASK                      ((uint32)(LEFT_MOTOR_2BIT_MASK        <<  \
                                                                  LEFT_MOTOR_STOP_SHIFT))
#define LEFT_MOTOR_START_MASK                     ((uint32)(LEFT_MOTOR_2BIT_MASK        <<  \
                                                                  LEFT_MOTOR_START_SHIFT))

/* MASK */
#define LEFT_MOTOR_1BIT_MASK                      ((uint32)0x01u)
#define LEFT_MOTOR_2BIT_MASK                      ((uint32)0x03u)
#define LEFT_MOTOR_3BIT_MASK                      ((uint32)0x07u)
#define LEFT_MOTOR_6BIT_MASK                      ((uint32)0x3Fu)
#define LEFT_MOTOR_8BIT_MASK                      ((uint32)0xFFu)
#define LEFT_MOTOR_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define LEFT_MOTOR_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define LEFT_MOTOR_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(LEFT_MOTOR_QUAD_ENCODING_MODES     << LEFT_MOTOR_QUAD_MODE_SHIFT))       |\
         ((uint32)(LEFT_MOTOR_CONFIG                  << LEFT_MOTOR_MODE_SHIFT)))

#define LEFT_MOTOR_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(LEFT_MOTOR_PWM_STOP_EVENT          << LEFT_MOTOR_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(LEFT_MOTOR_PWM_OUT_INVERT          << LEFT_MOTOR_INV_OUT_SHIFT))         |\
         ((uint32)(LEFT_MOTOR_PWM_OUT_N_INVERT        << LEFT_MOTOR_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(LEFT_MOTOR_PWM_MODE                << LEFT_MOTOR_MODE_SHIFT)))

#define LEFT_MOTOR_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(LEFT_MOTOR_PWM_RUN_MODE         << LEFT_MOTOR_ONESHOT_SHIFT))
            
#define LEFT_MOTOR_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(LEFT_MOTOR_PWM_ALIGN            << LEFT_MOTOR_UPDOWN_SHIFT))

#define LEFT_MOTOR_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(LEFT_MOTOR_PWM_KILL_EVENT      << LEFT_MOTOR_PWM_SYNC_KILL_SHIFT))

#define LEFT_MOTOR_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(LEFT_MOTOR_PWM_DEAD_TIME_CYCLE  << LEFT_MOTOR_PRESCALER_SHIFT))

#define LEFT_MOTOR_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(LEFT_MOTOR_PWM_PRESCALER        << LEFT_MOTOR_PRESCALER_SHIFT))

#define LEFT_MOTOR_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(LEFT_MOTOR_TC_PRESCALER            << LEFT_MOTOR_PRESCALER_SHIFT))       |\
         ((uint32)(LEFT_MOTOR_TC_COUNTER_MODE         << LEFT_MOTOR_UPDOWN_SHIFT))          |\
         ((uint32)(LEFT_MOTOR_TC_RUN_MODE             << LEFT_MOTOR_ONESHOT_SHIFT))         |\
         ((uint32)(LEFT_MOTOR_TC_COMP_CAP_MODE        << LEFT_MOTOR_MODE_SHIFT)))
        
#define LEFT_MOTOR_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(LEFT_MOTOR_QUAD_PHIA_SIGNAL_MODE   << LEFT_MOTOR_COUNT_SHIFT))           |\
         ((uint32)(LEFT_MOTOR_QUAD_INDEX_SIGNAL_MODE  << LEFT_MOTOR_RELOAD_SHIFT))          |\
         ((uint32)(LEFT_MOTOR_QUAD_STOP_SIGNAL_MODE   << LEFT_MOTOR_STOP_SHIFT))            |\
         ((uint32)(LEFT_MOTOR_QUAD_PHIB_SIGNAL_MODE   << LEFT_MOTOR_START_SHIFT)))

#define LEFT_MOTOR_PWM_SIGNALS_MODES                                                              \
        (((uint32)(LEFT_MOTOR_PWM_SWITCH_SIGNAL_MODE  << LEFT_MOTOR_CAPTURE_SHIFT))         |\
         ((uint32)(LEFT_MOTOR_PWM_COUNT_SIGNAL_MODE   << LEFT_MOTOR_COUNT_SHIFT))           |\
         ((uint32)(LEFT_MOTOR_PWM_RELOAD_SIGNAL_MODE  << LEFT_MOTOR_RELOAD_SHIFT))          |\
         ((uint32)(LEFT_MOTOR_PWM_STOP_SIGNAL_MODE    << LEFT_MOTOR_STOP_SHIFT))            |\
         ((uint32)(LEFT_MOTOR_PWM_START_SIGNAL_MODE   << LEFT_MOTOR_START_SHIFT)))

#define LEFT_MOTOR_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(LEFT_MOTOR_TC_CAPTURE_SIGNAL_MODE  << LEFT_MOTOR_CAPTURE_SHIFT))         |\
         ((uint32)(LEFT_MOTOR_TC_COUNT_SIGNAL_MODE    << LEFT_MOTOR_COUNT_SHIFT))           |\
         ((uint32)(LEFT_MOTOR_TC_RELOAD_SIGNAL_MODE   << LEFT_MOTOR_RELOAD_SHIFT))          |\
         ((uint32)(LEFT_MOTOR_TC_STOP_SIGNAL_MODE     << LEFT_MOTOR_STOP_SHIFT))            |\
         ((uint32)(LEFT_MOTOR_TC_START_SIGNAL_MODE    << LEFT_MOTOR_START_SHIFT)))
        
#define LEFT_MOTOR_TIMER_UPDOWN_CNT_USED                                                          \
                ((LEFT_MOTOR__COUNT_UPDOWN0 == LEFT_MOTOR_TC_COUNTER_MODE)                  ||\
                 (LEFT_MOTOR__COUNT_UPDOWN1 == LEFT_MOTOR_TC_COUNTER_MODE))

#define LEFT_MOTOR_PWM_UPDOWN_CNT_USED                                                            \
                ((LEFT_MOTOR__CENTER == LEFT_MOTOR_PWM_ALIGN)                               ||\
                 (LEFT_MOTOR__ASYMMETRIC == LEFT_MOTOR_PWM_ALIGN))               
        
#define LEFT_MOTOR_PWM_PR_INIT_VALUE              (1u)
#define LEFT_MOTOR_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_LEFT_MOTOR_H */

/* [] END OF FILE */

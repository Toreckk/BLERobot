/*******************************************************************************
* File Name: RIGHT_MOTOR.h
* Version 2.10
*
* Description:
*  This file provides constants and parameter values for the RIGHT_MOTOR
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

#if !defined(CY_TCPWM_RIGHT_MOTOR_H)
#define CY_TCPWM_RIGHT_MOTOR_H


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
} RIGHT_MOTOR_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  RIGHT_MOTOR_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define RIGHT_MOTOR_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define RIGHT_MOTOR_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define RIGHT_MOTOR_CONFIG                         (7lu)

/* Quad Mode */
/* Parameters */
#define RIGHT_MOTOR_QUAD_ENCODING_MODES            (0lu)
#define RIGHT_MOTOR_QUAD_AUTO_START                (1lu)

/* Signal modes */
#define RIGHT_MOTOR_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define RIGHT_MOTOR_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define RIGHT_MOTOR_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define RIGHT_MOTOR_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define RIGHT_MOTOR_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define RIGHT_MOTOR_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define RIGHT_MOTOR_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define RIGHT_MOTOR_TC_RUN_MODE                    (0lu)
#define RIGHT_MOTOR_TC_COUNTER_MODE                (0lu)
#define RIGHT_MOTOR_TC_COMP_CAP_MODE               (2lu)
#define RIGHT_MOTOR_TC_PRESCALER                   (0lu)

/* Signal modes */
#define RIGHT_MOTOR_TC_RELOAD_SIGNAL_MODE          (0lu)
#define RIGHT_MOTOR_TC_COUNT_SIGNAL_MODE           (3lu)
#define RIGHT_MOTOR_TC_START_SIGNAL_MODE           (0lu)
#define RIGHT_MOTOR_TC_STOP_SIGNAL_MODE            (0lu)
#define RIGHT_MOTOR_TC_CAPTURE_SIGNAL_MODE         (0lu)

/* Signal present */
#define RIGHT_MOTOR_TC_RELOAD_SIGNAL_PRESENT       (0lu)
#define RIGHT_MOTOR_TC_COUNT_SIGNAL_PRESENT        (0lu)
#define RIGHT_MOTOR_TC_START_SIGNAL_PRESENT        (0lu)
#define RIGHT_MOTOR_TC_STOP_SIGNAL_PRESENT         (0lu)
#define RIGHT_MOTOR_TC_CAPTURE_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define RIGHT_MOTOR_TC_INTERRUPT_MASK              (1lu)

/* PWM Mode */
/* Parameters */
#define RIGHT_MOTOR_PWM_KILL_EVENT                 (0lu)
#define RIGHT_MOTOR_PWM_STOP_EVENT                 (0lu)
#define RIGHT_MOTOR_PWM_MODE                       (4lu)
#define RIGHT_MOTOR_PWM_OUT_N_INVERT               (0lu)
#define RIGHT_MOTOR_PWM_OUT_INVERT                 (0lu)
#define RIGHT_MOTOR_PWM_ALIGN                      (0lu)
#define RIGHT_MOTOR_PWM_RUN_MODE                   (0lu)
#define RIGHT_MOTOR_PWM_DEAD_TIME_CYCLE            (0lu)
#define RIGHT_MOTOR_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define RIGHT_MOTOR_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define RIGHT_MOTOR_PWM_COUNT_SIGNAL_MODE          (3lu)
#define RIGHT_MOTOR_PWM_START_SIGNAL_MODE          (0lu)
#define RIGHT_MOTOR_PWM_STOP_SIGNAL_MODE           (0lu)
#define RIGHT_MOTOR_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define RIGHT_MOTOR_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define RIGHT_MOTOR_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define RIGHT_MOTOR_PWM_START_SIGNAL_PRESENT       (0lu)
#define RIGHT_MOTOR_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define RIGHT_MOTOR_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define RIGHT_MOTOR_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define RIGHT_MOTOR_TC_PERIOD_VALUE                (65535lu)
#define RIGHT_MOTOR_TC_COMPARE_VALUE               (65535lu)
#define RIGHT_MOTOR_TC_COMPARE_BUF_VALUE           (65535lu)
#define RIGHT_MOTOR_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define RIGHT_MOTOR_PWM_PERIOD_VALUE               (100lu)
#define RIGHT_MOTOR_PWM_PERIOD_BUF_VALUE           (65535lu)
#define RIGHT_MOTOR_PWM_PERIOD_SWAP                (0lu)
#define RIGHT_MOTOR_PWM_COMPARE_VALUE              (50lu)
#define RIGHT_MOTOR_PWM_COMPARE_BUF_VALUE          (65535lu)
#define RIGHT_MOTOR_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define RIGHT_MOTOR__LEFT 0
#define RIGHT_MOTOR__RIGHT 1
#define RIGHT_MOTOR__CENTER 2
#define RIGHT_MOTOR__ASYMMETRIC 3

#define RIGHT_MOTOR__X1 0
#define RIGHT_MOTOR__X2 1
#define RIGHT_MOTOR__X4 2

#define RIGHT_MOTOR__PWM 4
#define RIGHT_MOTOR__PWM_DT 5
#define RIGHT_MOTOR__PWM_PR 6

#define RIGHT_MOTOR__INVERSE 1
#define RIGHT_MOTOR__DIRECT 0

#define RIGHT_MOTOR__CAPTURE 2
#define RIGHT_MOTOR__COMPARE 0

#define RIGHT_MOTOR__TRIG_LEVEL 3
#define RIGHT_MOTOR__TRIG_RISING 0
#define RIGHT_MOTOR__TRIG_FALLING 1
#define RIGHT_MOTOR__TRIG_BOTH 2

#define RIGHT_MOTOR__INTR_MASK_TC 1
#define RIGHT_MOTOR__INTR_MASK_CC_MATCH 2
#define RIGHT_MOTOR__INTR_MASK_NONE 0
#define RIGHT_MOTOR__INTR_MASK_TC_CC 3

#define RIGHT_MOTOR__UNCONFIG 8
#define RIGHT_MOTOR__TIMER 1
#define RIGHT_MOTOR__QUAD 3
#define RIGHT_MOTOR__PWM_SEL 7

#define RIGHT_MOTOR__COUNT_UP 0
#define RIGHT_MOTOR__COUNT_DOWN 1
#define RIGHT_MOTOR__COUNT_UPDOWN0 2
#define RIGHT_MOTOR__COUNT_UPDOWN1 3


/* Prescaler */
#define RIGHT_MOTOR_PRESCALE_DIVBY1                ((uint32)(0u << RIGHT_MOTOR_PRESCALER_SHIFT))
#define RIGHT_MOTOR_PRESCALE_DIVBY2                ((uint32)(1u << RIGHT_MOTOR_PRESCALER_SHIFT))
#define RIGHT_MOTOR_PRESCALE_DIVBY4                ((uint32)(2u << RIGHT_MOTOR_PRESCALER_SHIFT))
#define RIGHT_MOTOR_PRESCALE_DIVBY8                ((uint32)(3u << RIGHT_MOTOR_PRESCALER_SHIFT))
#define RIGHT_MOTOR_PRESCALE_DIVBY16               ((uint32)(4u << RIGHT_MOTOR_PRESCALER_SHIFT))
#define RIGHT_MOTOR_PRESCALE_DIVBY32               ((uint32)(5u << RIGHT_MOTOR_PRESCALER_SHIFT))
#define RIGHT_MOTOR_PRESCALE_DIVBY64               ((uint32)(6u << RIGHT_MOTOR_PRESCALER_SHIFT))
#define RIGHT_MOTOR_PRESCALE_DIVBY128              ((uint32)(7u << RIGHT_MOTOR_PRESCALER_SHIFT))

/* TCPWM set modes */
#define RIGHT_MOTOR_MODE_TIMER_COMPARE             ((uint32)(RIGHT_MOTOR__COMPARE         <<  \
                                                                  RIGHT_MOTOR_MODE_SHIFT))
#define RIGHT_MOTOR_MODE_TIMER_CAPTURE             ((uint32)(RIGHT_MOTOR__CAPTURE         <<  \
                                                                  RIGHT_MOTOR_MODE_SHIFT))
#define RIGHT_MOTOR_MODE_QUAD                      ((uint32)(RIGHT_MOTOR__QUAD            <<  \
                                                                  RIGHT_MOTOR_MODE_SHIFT))
#define RIGHT_MOTOR_MODE_PWM                       ((uint32)(RIGHT_MOTOR__PWM             <<  \
                                                                  RIGHT_MOTOR_MODE_SHIFT))
#define RIGHT_MOTOR_MODE_PWM_DT                    ((uint32)(RIGHT_MOTOR__PWM_DT          <<  \
                                                                  RIGHT_MOTOR_MODE_SHIFT))
#define RIGHT_MOTOR_MODE_PWM_PR                    ((uint32)(RIGHT_MOTOR__PWM_PR          <<  \
                                                                  RIGHT_MOTOR_MODE_SHIFT))

/* Quad Modes */
#define RIGHT_MOTOR_MODE_X1                        ((uint32)(RIGHT_MOTOR__X1              <<  \
                                                                  RIGHT_MOTOR_QUAD_MODE_SHIFT))
#define RIGHT_MOTOR_MODE_X2                        ((uint32)(RIGHT_MOTOR__X2              <<  \
                                                                  RIGHT_MOTOR_QUAD_MODE_SHIFT))
#define RIGHT_MOTOR_MODE_X4                        ((uint32)(RIGHT_MOTOR__X4              <<  \
                                                                  RIGHT_MOTOR_QUAD_MODE_SHIFT))

/* Counter modes */
#define RIGHT_MOTOR_COUNT_UP                       ((uint32)(RIGHT_MOTOR__COUNT_UP        <<  \
                                                                  RIGHT_MOTOR_UPDOWN_SHIFT))
#define RIGHT_MOTOR_COUNT_DOWN                     ((uint32)(RIGHT_MOTOR__COUNT_DOWN      <<  \
                                                                  RIGHT_MOTOR_UPDOWN_SHIFT))
#define RIGHT_MOTOR_COUNT_UPDOWN0                  ((uint32)(RIGHT_MOTOR__COUNT_UPDOWN0   <<  \
                                                                  RIGHT_MOTOR_UPDOWN_SHIFT))
#define RIGHT_MOTOR_COUNT_UPDOWN1                  ((uint32)(RIGHT_MOTOR__COUNT_UPDOWN1   <<  \
                                                                  RIGHT_MOTOR_UPDOWN_SHIFT))

/* PWM output invert */
#define RIGHT_MOTOR_INVERT_LINE                    ((uint32)(RIGHT_MOTOR__INVERSE         <<  \
                                                                  RIGHT_MOTOR_INV_OUT_SHIFT))
#define RIGHT_MOTOR_INVERT_LINE_N                  ((uint32)(RIGHT_MOTOR__INVERSE         <<  \
                                                                  RIGHT_MOTOR_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define RIGHT_MOTOR_TRIG_RISING                    ((uint32)RIGHT_MOTOR__TRIG_RISING)
#define RIGHT_MOTOR_TRIG_FALLING                   ((uint32)RIGHT_MOTOR__TRIG_FALLING)
#define RIGHT_MOTOR_TRIG_BOTH                      ((uint32)RIGHT_MOTOR__TRIG_BOTH)
#define RIGHT_MOTOR_TRIG_LEVEL                     ((uint32)RIGHT_MOTOR__TRIG_LEVEL)

/* Interrupt mask */
#define RIGHT_MOTOR_INTR_MASK_TC                   ((uint32)RIGHT_MOTOR__INTR_MASK_TC)
#define RIGHT_MOTOR_INTR_MASK_CC_MATCH             ((uint32)RIGHT_MOTOR__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define RIGHT_MOTOR_CC_MATCH_SET                   (0x00u)
#define RIGHT_MOTOR_CC_MATCH_CLEAR                 (0x01u)
#define RIGHT_MOTOR_CC_MATCH_INVERT                (0x02u)
#define RIGHT_MOTOR_CC_MATCH_NO_CHANGE             (0x03u)
#define RIGHT_MOTOR_OVERLOW_SET                    (0x00u)
#define RIGHT_MOTOR_OVERLOW_CLEAR                  (0x04u)
#define RIGHT_MOTOR_OVERLOW_INVERT                 (0x08u)
#define RIGHT_MOTOR_OVERLOW_NO_CHANGE              (0x0Cu)
#define RIGHT_MOTOR_UNDERFLOW_SET                  (0x00u)
#define RIGHT_MOTOR_UNDERFLOW_CLEAR                (0x10u)
#define RIGHT_MOTOR_UNDERFLOW_INVERT               (0x20u)
#define RIGHT_MOTOR_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define RIGHT_MOTOR_PWM_MODE_LEFT                  (RIGHT_MOTOR_CC_MATCH_CLEAR        |   \
                                                         RIGHT_MOTOR_OVERLOW_SET           |   \
                                                         RIGHT_MOTOR_UNDERFLOW_NO_CHANGE)
#define RIGHT_MOTOR_PWM_MODE_RIGHT                 (RIGHT_MOTOR_CC_MATCH_SET          |   \
                                                         RIGHT_MOTOR_OVERLOW_NO_CHANGE     |   \
                                                         RIGHT_MOTOR_UNDERFLOW_CLEAR)
#define RIGHT_MOTOR_PWM_MODE_ASYM                  (RIGHT_MOTOR_CC_MATCH_INVERT       |   \
                                                         RIGHT_MOTOR_OVERLOW_SET           |   \
                                                         RIGHT_MOTOR_UNDERFLOW_CLEAR)

#if (RIGHT_MOTOR_CY_TCPWM_V2)
    #if(RIGHT_MOTOR_CY_TCPWM_4000)
        #define RIGHT_MOTOR_PWM_MODE_CENTER                (RIGHT_MOTOR_CC_MATCH_INVERT       |   \
                                                                 RIGHT_MOTOR_OVERLOW_NO_CHANGE     |   \
                                                                 RIGHT_MOTOR_UNDERFLOW_CLEAR)
    #else
        #define RIGHT_MOTOR_PWM_MODE_CENTER                (RIGHT_MOTOR_CC_MATCH_INVERT       |   \
                                                                 RIGHT_MOTOR_OVERLOW_SET           |   \
                                                                 RIGHT_MOTOR_UNDERFLOW_CLEAR)
    #endif /* (RIGHT_MOTOR_CY_TCPWM_4000) */
#else
    #define RIGHT_MOTOR_PWM_MODE_CENTER                (RIGHT_MOTOR_CC_MATCH_INVERT       |   \
                                                             RIGHT_MOTOR_OVERLOW_NO_CHANGE     |   \
                                                             RIGHT_MOTOR_UNDERFLOW_CLEAR)
#endif /* (RIGHT_MOTOR_CY_TCPWM_NEW) */

/* Command operations without condition */
#define RIGHT_MOTOR_CMD_CAPTURE                    (0u)
#define RIGHT_MOTOR_CMD_RELOAD                     (8u)
#define RIGHT_MOTOR_CMD_STOP                       (16u)
#define RIGHT_MOTOR_CMD_START                      (24u)

/* Status */
#define RIGHT_MOTOR_STATUS_DOWN                    (1u)
#define RIGHT_MOTOR_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   RIGHT_MOTOR_Init(void);
void   RIGHT_MOTOR_Enable(void);
void   RIGHT_MOTOR_Start(void);
void   RIGHT_MOTOR_Stop(void);

void   RIGHT_MOTOR_SetMode(uint32 mode);
void   RIGHT_MOTOR_SetCounterMode(uint32 counterMode);
void   RIGHT_MOTOR_SetPWMMode(uint32 modeMask);
void   RIGHT_MOTOR_SetQDMode(uint32 qdMode);

void   RIGHT_MOTOR_SetPrescaler(uint32 prescaler);
void   RIGHT_MOTOR_TriggerCommand(uint32 mask, uint32 command);
void   RIGHT_MOTOR_SetOneShot(uint32 oneShotEnable);
uint32 RIGHT_MOTOR_ReadStatus(void);

void   RIGHT_MOTOR_SetPWMSyncKill(uint32 syncKillEnable);
void   RIGHT_MOTOR_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   RIGHT_MOTOR_SetPWMDeadTime(uint32 deadTime);
void   RIGHT_MOTOR_SetPWMInvert(uint32 mask);

void   RIGHT_MOTOR_SetInterruptMode(uint32 interruptMask);
uint32 RIGHT_MOTOR_GetInterruptSourceMasked(void);
uint32 RIGHT_MOTOR_GetInterruptSource(void);
void   RIGHT_MOTOR_ClearInterrupt(uint32 interruptMask);
void   RIGHT_MOTOR_SetInterrupt(uint32 interruptMask);

void   RIGHT_MOTOR_WriteCounter(uint32 count);
uint32 RIGHT_MOTOR_ReadCounter(void);

uint32 RIGHT_MOTOR_ReadCapture(void);
uint32 RIGHT_MOTOR_ReadCaptureBuf(void);

void   RIGHT_MOTOR_WritePeriod(uint32 period);
uint32 RIGHT_MOTOR_ReadPeriod(void);
void   RIGHT_MOTOR_WritePeriodBuf(uint32 periodBuf);
uint32 RIGHT_MOTOR_ReadPeriodBuf(void);

void   RIGHT_MOTOR_WriteCompare(uint32 compare);
uint32 RIGHT_MOTOR_ReadCompare(void);
void   RIGHT_MOTOR_WriteCompareBuf(uint32 compareBuf);
uint32 RIGHT_MOTOR_ReadCompareBuf(void);

void   RIGHT_MOTOR_SetPeriodSwap(uint32 swapEnable);
void   RIGHT_MOTOR_SetCompareSwap(uint32 swapEnable);

void   RIGHT_MOTOR_SetCaptureMode(uint32 triggerMode);
void   RIGHT_MOTOR_SetReloadMode(uint32 triggerMode);
void   RIGHT_MOTOR_SetStartMode(uint32 triggerMode);
void   RIGHT_MOTOR_SetStopMode(uint32 triggerMode);
void   RIGHT_MOTOR_SetCountMode(uint32 triggerMode);

void   RIGHT_MOTOR_SaveConfig(void);
void   RIGHT_MOTOR_RestoreConfig(void);
void   RIGHT_MOTOR_Sleep(void);
void   RIGHT_MOTOR_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define RIGHT_MOTOR_BLOCK_CONTROL_REG              (*(reg32 *) RIGHT_MOTOR_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define RIGHT_MOTOR_BLOCK_CONTROL_PTR              ( (reg32 *) RIGHT_MOTOR_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define RIGHT_MOTOR_COMMAND_REG                    (*(reg32 *) RIGHT_MOTOR_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define RIGHT_MOTOR_COMMAND_PTR                    ( (reg32 *) RIGHT_MOTOR_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define RIGHT_MOTOR_INTRRUPT_CAUSE_REG             (*(reg32 *) RIGHT_MOTOR_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define RIGHT_MOTOR_INTRRUPT_CAUSE_PTR             ( (reg32 *) RIGHT_MOTOR_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define RIGHT_MOTOR_CONTROL_REG                    (*(reg32 *) RIGHT_MOTOR_cy_m0s8_tcpwm_1__CTRL )
#define RIGHT_MOTOR_CONTROL_PTR                    ( (reg32 *) RIGHT_MOTOR_cy_m0s8_tcpwm_1__CTRL )
#define RIGHT_MOTOR_STATUS_REG                     (*(reg32 *) RIGHT_MOTOR_cy_m0s8_tcpwm_1__STATUS )
#define RIGHT_MOTOR_STATUS_PTR                     ( (reg32 *) RIGHT_MOTOR_cy_m0s8_tcpwm_1__STATUS )
#define RIGHT_MOTOR_COUNTER_REG                    (*(reg32 *) RIGHT_MOTOR_cy_m0s8_tcpwm_1__COUNTER )
#define RIGHT_MOTOR_COUNTER_PTR                    ( (reg32 *) RIGHT_MOTOR_cy_m0s8_tcpwm_1__COUNTER )
#define RIGHT_MOTOR_COMP_CAP_REG                   (*(reg32 *) RIGHT_MOTOR_cy_m0s8_tcpwm_1__CC )
#define RIGHT_MOTOR_COMP_CAP_PTR                   ( (reg32 *) RIGHT_MOTOR_cy_m0s8_tcpwm_1__CC )
#define RIGHT_MOTOR_COMP_CAP_BUF_REG               (*(reg32 *) RIGHT_MOTOR_cy_m0s8_tcpwm_1__CC_BUFF )
#define RIGHT_MOTOR_COMP_CAP_BUF_PTR               ( (reg32 *) RIGHT_MOTOR_cy_m0s8_tcpwm_1__CC_BUFF )
#define RIGHT_MOTOR_PERIOD_REG                     (*(reg32 *) RIGHT_MOTOR_cy_m0s8_tcpwm_1__PERIOD )
#define RIGHT_MOTOR_PERIOD_PTR                     ( (reg32 *) RIGHT_MOTOR_cy_m0s8_tcpwm_1__PERIOD )
#define RIGHT_MOTOR_PERIOD_BUF_REG                 (*(reg32 *) RIGHT_MOTOR_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define RIGHT_MOTOR_PERIOD_BUF_PTR                 ( (reg32 *) RIGHT_MOTOR_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define RIGHT_MOTOR_TRIG_CONTROL0_REG              (*(reg32 *) RIGHT_MOTOR_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define RIGHT_MOTOR_TRIG_CONTROL0_PTR              ( (reg32 *) RIGHT_MOTOR_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define RIGHT_MOTOR_TRIG_CONTROL1_REG              (*(reg32 *) RIGHT_MOTOR_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define RIGHT_MOTOR_TRIG_CONTROL1_PTR              ( (reg32 *) RIGHT_MOTOR_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define RIGHT_MOTOR_TRIG_CONTROL2_REG              (*(reg32 *) RIGHT_MOTOR_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define RIGHT_MOTOR_TRIG_CONTROL2_PTR              ( (reg32 *) RIGHT_MOTOR_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define RIGHT_MOTOR_INTERRUPT_REQ_REG              (*(reg32 *) RIGHT_MOTOR_cy_m0s8_tcpwm_1__INTR )
#define RIGHT_MOTOR_INTERRUPT_REQ_PTR              ( (reg32 *) RIGHT_MOTOR_cy_m0s8_tcpwm_1__INTR )
#define RIGHT_MOTOR_INTERRUPT_SET_REG              (*(reg32 *) RIGHT_MOTOR_cy_m0s8_tcpwm_1__INTR_SET )
#define RIGHT_MOTOR_INTERRUPT_SET_PTR              ( (reg32 *) RIGHT_MOTOR_cy_m0s8_tcpwm_1__INTR_SET )
#define RIGHT_MOTOR_INTERRUPT_MASK_REG             (*(reg32 *) RIGHT_MOTOR_cy_m0s8_tcpwm_1__INTR_MASK )
#define RIGHT_MOTOR_INTERRUPT_MASK_PTR             ( (reg32 *) RIGHT_MOTOR_cy_m0s8_tcpwm_1__INTR_MASK )
#define RIGHT_MOTOR_INTERRUPT_MASKED_REG           (*(reg32 *) RIGHT_MOTOR_cy_m0s8_tcpwm_1__INTR_MASKED )
#define RIGHT_MOTOR_INTERRUPT_MASKED_PTR           ( (reg32 *) RIGHT_MOTOR_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define RIGHT_MOTOR_MASK                           ((uint32)RIGHT_MOTOR_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define RIGHT_MOTOR_RELOAD_CC_SHIFT                (0u)
#define RIGHT_MOTOR_RELOAD_PERIOD_SHIFT            (1u)
#define RIGHT_MOTOR_PWM_SYNC_KILL_SHIFT            (2u)
#define RIGHT_MOTOR_PWM_STOP_KILL_SHIFT            (3u)
#define RIGHT_MOTOR_PRESCALER_SHIFT                (8u)
#define RIGHT_MOTOR_UPDOWN_SHIFT                   (16u)
#define RIGHT_MOTOR_ONESHOT_SHIFT                  (18u)
#define RIGHT_MOTOR_QUAD_MODE_SHIFT                (20u)
#define RIGHT_MOTOR_INV_OUT_SHIFT                  (20u)
#define RIGHT_MOTOR_INV_COMPL_OUT_SHIFT            (21u)
#define RIGHT_MOTOR_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define RIGHT_MOTOR_RELOAD_CC_MASK                 ((uint32)(RIGHT_MOTOR_1BIT_MASK        <<  \
                                                                            RIGHT_MOTOR_RELOAD_CC_SHIFT))
#define RIGHT_MOTOR_RELOAD_PERIOD_MASK             ((uint32)(RIGHT_MOTOR_1BIT_MASK        <<  \
                                                                            RIGHT_MOTOR_RELOAD_PERIOD_SHIFT))
#define RIGHT_MOTOR_PWM_SYNC_KILL_MASK             ((uint32)(RIGHT_MOTOR_1BIT_MASK        <<  \
                                                                            RIGHT_MOTOR_PWM_SYNC_KILL_SHIFT))
#define RIGHT_MOTOR_PWM_STOP_KILL_MASK             ((uint32)(RIGHT_MOTOR_1BIT_MASK        <<  \
                                                                            RIGHT_MOTOR_PWM_STOP_KILL_SHIFT))
#define RIGHT_MOTOR_PRESCALER_MASK                 ((uint32)(RIGHT_MOTOR_8BIT_MASK        <<  \
                                                                            RIGHT_MOTOR_PRESCALER_SHIFT))
#define RIGHT_MOTOR_UPDOWN_MASK                    ((uint32)(RIGHT_MOTOR_2BIT_MASK        <<  \
                                                                            RIGHT_MOTOR_UPDOWN_SHIFT))
#define RIGHT_MOTOR_ONESHOT_MASK                   ((uint32)(RIGHT_MOTOR_1BIT_MASK        <<  \
                                                                            RIGHT_MOTOR_ONESHOT_SHIFT))
#define RIGHT_MOTOR_QUAD_MODE_MASK                 ((uint32)(RIGHT_MOTOR_3BIT_MASK        <<  \
                                                                            RIGHT_MOTOR_QUAD_MODE_SHIFT))
#define RIGHT_MOTOR_INV_OUT_MASK                   ((uint32)(RIGHT_MOTOR_2BIT_MASK        <<  \
                                                                            RIGHT_MOTOR_INV_OUT_SHIFT))
#define RIGHT_MOTOR_MODE_MASK                      ((uint32)(RIGHT_MOTOR_3BIT_MASK        <<  \
                                                                            RIGHT_MOTOR_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define RIGHT_MOTOR_CAPTURE_SHIFT                  (0u)
#define RIGHT_MOTOR_COUNT_SHIFT                    (2u)
#define RIGHT_MOTOR_RELOAD_SHIFT                   (4u)
#define RIGHT_MOTOR_STOP_SHIFT                     (6u)
#define RIGHT_MOTOR_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define RIGHT_MOTOR_CAPTURE_MASK                   ((uint32)(RIGHT_MOTOR_2BIT_MASK        <<  \
                                                                  RIGHT_MOTOR_CAPTURE_SHIFT))
#define RIGHT_MOTOR_COUNT_MASK                     ((uint32)(RIGHT_MOTOR_2BIT_MASK        <<  \
                                                                  RIGHT_MOTOR_COUNT_SHIFT))
#define RIGHT_MOTOR_RELOAD_MASK                    ((uint32)(RIGHT_MOTOR_2BIT_MASK        <<  \
                                                                  RIGHT_MOTOR_RELOAD_SHIFT))
#define RIGHT_MOTOR_STOP_MASK                      ((uint32)(RIGHT_MOTOR_2BIT_MASK        <<  \
                                                                  RIGHT_MOTOR_STOP_SHIFT))
#define RIGHT_MOTOR_START_MASK                     ((uint32)(RIGHT_MOTOR_2BIT_MASK        <<  \
                                                                  RIGHT_MOTOR_START_SHIFT))

/* MASK */
#define RIGHT_MOTOR_1BIT_MASK                      ((uint32)0x01u)
#define RIGHT_MOTOR_2BIT_MASK                      ((uint32)0x03u)
#define RIGHT_MOTOR_3BIT_MASK                      ((uint32)0x07u)
#define RIGHT_MOTOR_6BIT_MASK                      ((uint32)0x3Fu)
#define RIGHT_MOTOR_8BIT_MASK                      ((uint32)0xFFu)
#define RIGHT_MOTOR_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define RIGHT_MOTOR_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define RIGHT_MOTOR_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(RIGHT_MOTOR_QUAD_ENCODING_MODES     << RIGHT_MOTOR_QUAD_MODE_SHIFT))       |\
         ((uint32)(RIGHT_MOTOR_CONFIG                  << RIGHT_MOTOR_MODE_SHIFT)))

#define RIGHT_MOTOR_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(RIGHT_MOTOR_PWM_STOP_EVENT          << RIGHT_MOTOR_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(RIGHT_MOTOR_PWM_OUT_INVERT          << RIGHT_MOTOR_INV_OUT_SHIFT))         |\
         ((uint32)(RIGHT_MOTOR_PWM_OUT_N_INVERT        << RIGHT_MOTOR_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(RIGHT_MOTOR_PWM_MODE                << RIGHT_MOTOR_MODE_SHIFT)))

#define RIGHT_MOTOR_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(RIGHT_MOTOR_PWM_RUN_MODE         << RIGHT_MOTOR_ONESHOT_SHIFT))
            
#define RIGHT_MOTOR_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(RIGHT_MOTOR_PWM_ALIGN            << RIGHT_MOTOR_UPDOWN_SHIFT))

#define RIGHT_MOTOR_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(RIGHT_MOTOR_PWM_KILL_EVENT      << RIGHT_MOTOR_PWM_SYNC_KILL_SHIFT))

#define RIGHT_MOTOR_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(RIGHT_MOTOR_PWM_DEAD_TIME_CYCLE  << RIGHT_MOTOR_PRESCALER_SHIFT))

#define RIGHT_MOTOR_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(RIGHT_MOTOR_PWM_PRESCALER        << RIGHT_MOTOR_PRESCALER_SHIFT))

#define RIGHT_MOTOR_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(RIGHT_MOTOR_TC_PRESCALER            << RIGHT_MOTOR_PRESCALER_SHIFT))       |\
         ((uint32)(RIGHT_MOTOR_TC_COUNTER_MODE         << RIGHT_MOTOR_UPDOWN_SHIFT))          |\
         ((uint32)(RIGHT_MOTOR_TC_RUN_MODE             << RIGHT_MOTOR_ONESHOT_SHIFT))         |\
         ((uint32)(RIGHT_MOTOR_TC_COMP_CAP_MODE        << RIGHT_MOTOR_MODE_SHIFT)))
        
#define RIGHT_MOTOR_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(RIGHT_MOTOR_QUAD_PHIA_SIGNAL_MODE   << RIGHT_MOTOR_COUNT_SHIFT))           |\
         ((uint32)(RIGHT_MOTOR_QUAD_INDEX_SIGNAL_MODE  << RIGHT_MOTOR_RELOAD_SHIFT))          |\
         ((uint32)(RIGHT_MOTOR_QUAD_STOP_SIGNAL_MODE   << RIGHT_MOTOR_STOP_SHIFT))            |\
         ((uint32)(RIGHT_MOTOR_QUAD_PHIB_SIGNAL_MODE   << RIGHT_MOTOR_START_SHIFT)))

#define RIGHT_MOTOR_PWM_SIGNALS_MODES                                                              \
        (((uint32)(RIGHT_MOTOR_PWM_SWITCH_SIGNAL_MODE  << RIGHT_MOTOR_CAPTURE_SHIFT))         |\
         ((uint32)(RIGHT_MOTOR_PWM_COUNT_SIGNAL_MODE   << RIGHT_MOTOR_COUNT_SHIFT))           |\
         ((uint32)(RIGHT_MOTOR_PWM_RELOAD_SIGNAL_MODE  << RIGHT_MOTOR_RELOAD_SHIFT))          |\
         ((uint32)(RIGHT_MOTOR_PWM_STOP_SIGNAL_MODE    << RIGHT_MOTOR_STOP_SHIFT))            |\
         ((uint32)(RIGHT_MOTOR_PWM_START_SIGNAL_MODE   << RIGHT_MOTOR_START_SHIFT)))

#define RIGHT_MOTOR_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(RIGHT_MOTOR_TC_CAPTURE_SIGNAL_MODE  << RIGHT_MOTOR_CAPTURE_SHIFT))         |\
         ((uint32)(RIGHT_MOTOR_TC_COUNT_SIGNAL_MODE    << RIGHT_MOTOR_COUNT_SHIFT))           |\
         ((uint32)(RIGHT_MOTOR_TC_RELOAD_SIGNAL_MODE   << RIGHT_MOTOR_RELOAD_SHIFT))          |\
         ((uint32)(RIGHT_MOTOR_TC_STOP_SIGNAL_MODE     << RIGHT_MOTOR_STOP_SHIFT))            |\
         ((uint32)(RIGHT_MOTOR_TC_START_SIGNAL_MODE    << RIGHT_MOTOR_START_SHIFT)))
        
#define RIGHT_MOTOR_TIMER_UPDOWN_CNT_USED                                                          \
                ((RIGHT_MOTOR__COUNT_UPDOWN0 == RIGHT_MOTOR_TC_COUNTER_MODE)                  ||\
                 (RIGHT_MOTOR__COUNT_UPDOWN1 == RIGHT_MOTOR_TC_COUNTER_MODE))

#define RIGHT_MOTOR_PWM_UPDOWN_CNT_USED                                                            \
                ((RIGHT_MOTOR__CENTER == RIGHT_MOTOR_PWM_ALIGN)                               ||\
                 (RIGHT_MOTOR__ASYMMETRIC == RIGHT_MOTOR_PWM_ALIGN))               
        
#define RIGHT_MOTOR_PWM_PR_INIT_VALUE              (1u)
#define RIGHT_MOTOR_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_RIGHT_MOTOR_H */

/* [] END OF FILE */

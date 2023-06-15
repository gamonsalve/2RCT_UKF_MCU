/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: SoC_Estimation_UKF_2RC_for_MCU.h
 *
 * Code generated for Simulink model 'SoC_Estimation_UKF_2RC_for_MCU'.
 *
 * Model version                  : 4.5
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu Jun 15 08:59:12 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SoC_Estimation_UKF_2RC_for_MCU_h_
#define RTW_HEADER_SoC_Estimation_UKF_2RC_for_MCU_h_
#ifndef SoC_Estimation_UKF_2RC_for_MCU_COMMON_INCLUDES_
#define SoC_Estimation_UKF_2RC_for_MCU_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                     /* SoC_Estimation_UKF_2RC_for_MCU_COMMON_INCLUDES_ */

#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "batteryStateFcn.h"
#include "batteryMeasurementFcn.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T P_f[9];                       /* '<S5>/DataStoreMemory - P' */
  real_T x[3];                         /* '<S5>/DataStoreMemory - x' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<Root>/Discrete-Time Integrator' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T current;                      /* '<Root>/current' */
  real_T voltage;                      /* '<Root>/voltage' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T SoCEstimatedUKF;              /* '<Root>/SoCEstimatedUKF' */
  real_T voltageEstimatedUKF;          /* '<Root>/voltageEstimatedUKF' */
  real_T SoCMeasuredUKF;               /* '<Root>/SoCMeasuredUKF' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;
};

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void SoC_Estimation_UKF_2RC_for_MCU_initialize(void);
extern void SoC_Estimation_UKF_2RC_for_MCU_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Scope3' : Unused code path elimination
 * Block '<Root>/Scope8' : Unused code path elimination
 * Block '<Root>/Scope17' : Unused code path elimination
 * Block '<S7>/RegisterSimulinkFcn' : Unused code path elimination
 * Block '<S8>/RegisterSimulinkFcn' : Unused code path elimination
 * Block '<S5>/checkMeasurementFcn1Signals' : Unused code path elimination
 * Block '<S5>/checkStateTransitionFcnSignals' : Unused code path elimination
 * Block '<Root>/Scope' : Unused code path elimination
 * Block '<Root>/Scope1' : Unused code path elimination
 * Block '<Root>/Scope10' : Unused code path elimination
 * Block '<Root>/Scope11' : Unused code path elimination
 * Block '<Root>/Scope12' : Unused code path elimination
 * Block '<Root>/Scope13' : Unused code path elimination
 * Block '<Root>/Scope14' : Unused code path elimination
 * Block '<Root>/Scope15' : Unused code path elimination
 * Block '<Root>/Scope16' : Unused code path elimination
 * Block '<Root>/Scope18' : Unused code path elimination
 * Block '<Root>/Scope2' : Unused code path elimination
 * Block '<Root>/Scope4' : Unused code path elimination
 * Block '<Root>/Scope5' : Unused code path elimination
 * Block '<Root>/Scope6' : Unused code path elimination
 * Block '<Root>/Scope7' : Unused code path elimination
 * Block '<Root>/Scope9' : Unused code path elimination
 * Block '<Root>/Rate Transition_Current' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition_Voltage' : Eliminated since input and output rates are identical
 * Block '<S5>/DataTypeConversion_Enable1' : Eliminate redundant data type conversion
 * Block '<S5>/DataTypeConversion_Q' : Eliminate redundant data type conversion
 * Block '<S5>/DataTypeConversion_R1' : Eliminate redundant data type conversion
 * Block '<S5>/DataTypeConversion_uMeas1' : Eliminate redundant data type conversion
 * Block '<S5>/DataTypeConversion_uState' : Eliminate redundant data type conversion
 * Block '<S5>/DataTypeConversion_y1' : Eliminate redundant data type conversion
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'SoC_Estimation_UKF_2RC_for_MCU'
 * '<S1>'   : 'SoC_Estimation_UKF_2RC_for_MCU/Subsystem'
 * '<S2>'   : 'SoC_Estimation_UKF_2RC_for_MCU/UKF'
 * '<S3>'   : 'SoC_Estimation_UKF_2RC_for_MCU/UKF/Simulink Function - Measurement Function'
 * '<S4>'   : 'SoC_Estimation_UKF_2RC_for_MCU/UKF/Simulink Function - State Transition Function'
 * '<S5>'   : 'SoC_Estimation_UKF_2RC_for_MCU/UKF/Unscented Kalman Filter for SOC Estimation'
 * '<S6>'   : 'SoC_Estimation_UKF_2RC_for_MCU/UKF/Simulink Function - State Transition Function/f(x,u)'
 * '<S7>'   : 'SoC_Estimation_UKF_2RC_for_MCU/UKF/Unscented Kalman Filter for SOC Estimation/Correct1'
 * '<S8>'   : 'SoC_Estimation_UKF_2RC_for_MCU/UKF/Unscented Kalman Filter for SOC Estimation/Predict'
 * '<S9>'   : 'SoC_Estimation_UKF_2RC_for_MCU/UKF/Unscented Kalman Filter for SOC Estimation/Subsystem'
 * '<S10>'  : 'SoC_Estimation_UKF_2RC_for_MCU/UKF/Unscented Kalman Filter for SOC Estimation/Correct1/Correct'
 * '<S11>'  : 'SoC_Estimation_UKF_2RC_for_MCU/UKF/Unscented Kalman Filter for SOC Estimation/Predict/Predict'
 * '<S12>'  : 'SoC_Estimation_UKF_2RC_for_MCU/UKF/Unscented Kalman Filter for SOC Estimation/Subsystem/MATLAB Function'
 */
#endif                        /* RTW_HEADER_SoC_Estimation_UKF_2RC_for_MCU_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

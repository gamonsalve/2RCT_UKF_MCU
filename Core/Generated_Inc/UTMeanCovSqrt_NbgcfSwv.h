/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: UTMeanCovSqrt_NbgcfSwv.h
 *
 * Code generated for Simulink model 'SoC_Estimation_UKF_2RC_for_MCU'.
 *
 * Model version                  : 4.3
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Jun 14 16:58:00 2023
 */

#ifndef RTW_HEADER_UTMeanCovSqrt_NbgcfSwv_h_
#define RTW_HEADER_UTMeanCovSqrt_NbgcfSwv_h_
#include "rtwtypes.h"

extern void UTMeanCovSqrt_NbgcfSwv(const real_T meanWeights[2], const real_T
  covWeights[2], real_T OOM, real_T Y1, real_T Y2[6], const real_T X1[3], real_T
  X2[18], real_T *Ymean, real_T *Sy, real_T Pxy[3]);

#endif                                /* RTW_HEADER_UTMeanCovSqrt_NbgcfSwv_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

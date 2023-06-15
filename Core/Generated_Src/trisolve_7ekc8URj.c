/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: trisolve_7ekc8URj.c
 *
 * Code generated for Simulink model 'SoC_Estimation_UKF_2RC_for_MCU'.
 *
 * Model version                  : 4.3
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Jun 14 16:58:00 2023
 */

#include "rtwtypes.h"
#include "trisolve_7ekc8URj.h"

/* Function for MATLAB Function: '<S7>/Correct' */
void trisolve_7ekc8URj(real_T A, real_T B_0[3])
{
  if (B_0[0] != 0.0) {
    B_0[0] /= A;
  }

  if (B_0[1] != 0.0) {
    B_0[1] /= A;
  }

  if (B_0[2] != 0.0) {
    B_0[2] /= A;
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

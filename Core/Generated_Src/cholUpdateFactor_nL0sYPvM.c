/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: cholUpdateFactor_nL0sYPvM.c
 *
 * Code generated for Simulink model 'SoC_Estimation_UKF_2RC_for_MCU'.
 *
 * Model version                  : 4.3
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Jun 14 16:58:00 2023
 */

#include "rtwtypes.h"
#include "cholUpdateFactor_nL0sYPvM.h"
#include <math.h>
#include "rotate_3AIOL9tK.h"
#include "rt_nonfinite.h"

/* Function for MATLAB Function: '<S7>/Correct' */
void cholUpdateFactor_nL0sYPvM(real_T *S, real_T U)
{
  real_T R;
  real_T alpha;
  real_T c;
  real_T nrmx;
  real_T s;
  int8_T p;
  R = *S;
  p = 0;
  if (*S == 0.0) {
    p = 2;
  } else {
    s = U / *S;
    nrmx = fabs(s);
    if (nrmx >= 1.0) {
      p = 1;
    } else {
      rotate_3AIOL9tK(sqrt(1.0 - nrmx * nrmx), s, &R, &c, &alpha);
      R = R * *S - c * 0.0;
    }
  }

  *S = R;
  if (p != 0) {
    s = R * R - U * U;
    if ((!rtIsInf(s)) && (!rtIsNaN(s))) {
      nrmx = 1.0;
      if (s != 0.0) {
        s = fabs(s);
      }
    } else {
      s = (rtNaN);
      nrmx = (rtNaN);
    }

    *S = nrmx * sqrt(s);
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

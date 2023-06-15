/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: xgerc_duqdQXG2.c
 *
 * Code generated for Simulink model 'SoC_Estimation_UKF_2RC_for_MCU'.
 *
 * Model version                  : 4.3
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Jun 14 16:58:00 2023
 */

#include "rtwtypes.h"
#include "xgerc_duqdQXG2.h"

/* Function for MATLAB Function: '<S7>/Correct' */
void xgerc_duqdQXG2(int32_T m, int32_T n, real_T alpha1, int32_T ix0, const
                    real_T y[3], real_T A[9], int32_T ia0)
{
  int32_T ijA;
  int32_T j;
  if (!(alpha1 == 0.0)) {
    int32_T jA;
    jA = ia0;
    for (j = 0; j < n; j++) {
      real_T temp;
      temp = y[j];
      if (temp != 0.0) {
        int32_T b;
        temp *= alpha1;
        b = m + jA;
        for (ijA = jA; ijA < b; ijA++) {
          A[ijA - 1] += A[((ix0 + ijA) - jA) - 1] * temp;
        }
      }

      jA += 3;
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

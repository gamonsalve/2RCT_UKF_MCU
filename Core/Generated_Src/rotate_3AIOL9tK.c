/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: rotate_3AIOL9tK.c
 *
 * Code generated for Simulink model 'SoC_Estimation_UKF_2RC_for_MCU'.
 *
 * Model version                  : 4.3
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Jun 14 16:58:00 2023
 */

#include "rtwtypes.h"
#include "rotate_3AIOL9tK.h"
#include <math.h>
#include "rt_hypotd_snf.h"

/* Function for MATLAB Function: '<S7>/Correct' */
void rotate_3AIOL9tK(real_T x, real_T y, real_T *c, real_T *s, real_T *r)
{
  real_T absx;
  real_T absy;
  absx = fabs(x);
  absy = fabs(y);
  if (absy == 0.0) {
    *c = 1.0;
    *s = 0.0;
    *r = x;
  } else if (absx == 0.0) {
    *c = 0.0;
    *s = 1.0;
    *r = y;
  } else {
    real_T rho;
    real_T xx;
    real_T yy;
    absy += absx;
    xx = x / absy;
    yy = y / absy;
    absx = fabs(xx);
    rho = rt_hypotd_snf(absx, fabs(yy));
    *c = absx / rho;
    xx /= absx;
    *s = xx * yy / rho;
    *r = rho * absy * xx;
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

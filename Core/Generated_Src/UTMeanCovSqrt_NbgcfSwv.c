/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: UTMeanCovSqrt_NbgcfSwv.c
 *
 * Code generated for Simulink model 'SoC_Estimation_UKF_2RC_for_MCU'.
 *
 * Model version                  : 4.3
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Jun 14 16:58:00 2023
 */

#include "rtwtypes.h"
#include "UTMeanCovSqrt_NbgcfSwv.h"
#include "rt_nonfinite.h"
#include <math.h>
#include "xnrm2_qRRhL8tE.h"
#include "rt_hypotd_snf.h"
#include "rotate_3AIOL9tK.h"
#include "cholUpdateFactor_nL0sYPvM.h"

/* Function for MATLAB Function: '<S7>/Correct' */
void UTMeanCovSqrt_NbgcfSwv(const real_T meanWeights[2], const real_T
  covWeights[2], real_T OOM, real_T Y1, real_T Y2[6], const real_T X1[3], real_T
  X2[18], real_T *Ymean, real_T *Sy, real_T Pxy[3])
{
  real_T A[6];
  real_T X2_0[3];
  real_T atmp;
  real_T covWeights_0;
  real_T covWeights_1;
  real_T signOOM;
  int32_T b_k;
  int32_T knt;
  *Ymean = Y1 * meanWeights[0];
  for (knt = 0; knt < 6; knt++) {
    *Ymean += Y2[knt] * meanWeights[1];
  }

  *Ymean *= OOM;
  Y1 -= *Ymean;
  for (knt = 0; knt < 6; knt++) {
    Y2[knt] -= *Ymean;
  }

  if (rtIsNaN(OOM)) {
    signOOM = (rtNaN);
  } else if (OOM < 0.0) {
    signOOM = -1.0;
  } else {
    signOOM = (OOM > 0.0);
  }

  covWeights_0 = signOOM * covWeights[0];
  covWeights_1 = signOOM * covWeights[1];
  OOM *= signOOM;
  signOOM = sqrt(covWeights_1);
  for (knt = 0; knt < 6; knt++) {
    A[knt] = signOOM * Y2[knt];
  }

  atmp = A[0];
  signOOM = xnrm2_qRRhL8tE(5, A, 2);
  if (signOOM != 0.0) {
    signOOM = rt_hypotd_snf(A[0], signOOM);
    if (A[0] >= 0.0) {
      signOOM = -signOOM;
    }

    if (fabs(signOOM) < 1.0020841800044864E-292) {
      knt = 0;
      do {
        knt++;
        for (b_k = 0; b_k < 5; b_k++) {
          A[b_k + 1] *= 9.9792015476736E+291;
        }

        signOOM *= 9.9792015476736E+291;
        atmp *= 9.9792015476736E+291;
      } while ((fabs(signOOM) < 1.0020841800044864E-292) && (knt < 20));

      signOOM = rt_hypotd_snf(atmp, xnrm2_qRRhL8tE(5, A, 2));
      if (atmp >= 0.0) {
        signOOM = -signOOM;
      }

      for (b_k = 0; b_k < knt; b_k++) {
        signOOM *= 1.0020841800044864E-292;
      }

      atmp = signOOM;
    } else {
      atmp = signOOM;
    }
  }

  if (rtIsNaN(covWeights_0)) {
    signOOM = (rtNaN);
  } else if (covWeights_0 < 0.0) {
    signOOM = -1.0;
  } else {
    signOOM = (covWeights_0 > 0.0);
  }

  if (signOOM == 1.0) {
    rotate_3AIOL9tK(atmp, Y1, &signOOM, &atmp, &covWeights_0);
    *Sy = sqrt(OOM) * covWeights_0;
  } else {
    signOOM = atmp;
    cholUpdateFactor_nL0sYPvM(&signOOM, Y1);
    *Sy = sqrt(OOM) * signOOM;
  }

  for (knt = 0; knt < 6; knt++) {
    X2[3 * knt] -= X1[0];
    b_k = 3 * knt + 1;
    X2[b_k] -= X1[1];
    b_k = 3 * knt + 2;
    X2[b_k] -= X1[2];
  }

  signOOM = covWeights_1 * OOM;
  for (knt = 0; knt < 3; knt++) {
    X2_0[knt] = 0.0;
    for (b_k = 0; b_k < 6; b_k++) {
      X2_0[knt] += X2[3 * b_k + knt] * Y2[b_k];
    }

    Pxy[knt] = X2_0[knt] * signOOM;
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

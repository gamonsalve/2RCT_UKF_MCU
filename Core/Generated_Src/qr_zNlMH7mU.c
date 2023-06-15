/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: qr_zNlMH7mU.c
 *
 * Code generated for Simulink model 'SoC_Estimation_UKF_2RC_for_MCU'.
 *
 * Model version                  : 4.3
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Jun 14 16:58:00 2023
 */

#include "rtwtypes.h"
#include "qr_zNlMH7mU.h"
#include <string.h>
#include "xnrm2_zhvkBxcX.h"
#include "rt_hypotd_snf.h"
#include <math.h>
#include "xgemv_4E6oVMBP.h"
#include "xgerc_duqdQXG2.h"

/* Function for MATLAB Function: '<S7>/Correct' */
void qr_zNlMH7mU(const real_T A[9], real_T Q[9], real_T R[9])
{
  real_T b_A[9];
  real_T tau[3];
  real_T work[3];
  int32_T b_coltop;
  int32_T b_lastv;
  int32_T coltop;
  int32_T exitg1;
  int32_T ii;
  int32_T itau;
  int32_T knt;
  boolean_T exitg2;
  memcpy(&b_A[0], &A[0], 9U * sizeof(real_T));
  tau[0] = 0.0;
  work[0] = 0.0;
  tau[1] = 0.0;
  work[1] = 0.0;
  tau[2] = 0.0;
  work[2] = 0.0;
  for (itau = 0; itau < 3; itau++) {
    ii = itau * 3 + itau;
    if (itau + 1 < 3) {
      real_T atmp;
      real_T beta1;
      atmp = b_A[ii];
      b_lastv = ii + 2;
      tau[itau] = 0.0;
      beta1 = xnrm2_zhvkBxcX(2 - itau, b_A, ii + 2);
      if (beta1 != 0.0) {
        beta1 = rt_hypotd_snf(b_A[ii], beta1);
        if (b_A[ii] >= 0.0) {
          beta1 = -beta1;
        }

        if (fabs(beta1) < 1.0020841800044864E-292) {
          knt = 0;
          b_coltop = (ii - itau) + 3;
          do {
            knt++;
            for (coltop = b_lastv; coltop <= b_coltop; coltop++) {
              b_A[coltop - 1] *= 9.9792015476736E+291;
            }

            beta1 *= 9.9792015476736E+291;
            atmp *= 9.9792015476736E+291;
          } while ((fabs(beta1) < 1.0020841800044864E-292) && (knt < 20));

          beta1 = rt_hypotd_snf(atmp, xnrm2_zhvkBxcX(2 - itau, b_A, ii + 2));
          if (atmp >= 0.0) {
            beta1 = -beta1;
          }

          tau[itau] = (beta1 - atmp) / beta1;
          atmp = 1.0 / (atmp - beta1);
          for (coltop = b_lastv; coltop <= b_coltop; coltop++) {
            b_A[coltop - 1] *= atmp;
          }

          for (b_lastv = 0; b_lastv < knt; b_lastv++) {
            beta1 *= 1.0020841800044864E-292;
          }

          atmp = beta1;
        } else {
          tau[itau] = (beta1 - b_A[ii]) / beta1;
          atmp = 1.0 / (b_A[ii] - beta1);
          knt = (ii - itau) + 3;
          for (b_coltop = b_lastv; b_coltop <= knt; b_coltop++) {
            b_A[b_coltop - 1] *= atmp;
          }

          atmp = beta1;
        }
      }

      b_A[ii] = atmp;
      beta1 = b_A[ii];
      b_A[ii] = 1.0;
      if (tau[itau] != 0.0) {
        b_lastv = 3 - itau;
        knt = (ii - itau) + 2;
        while ((b_lastv > 0) && (b_A[knt] == 0.0)) {
          b_lastv--;
          knt--;
        }

        knt = 2 - itau;
        exitg2 = false;
        while ((!exitg2) && (knt > 0)) {
          b_coltop = ((knt - 1) * 3 + ii) + 3;
          coltop = b_coltop;
          do {
            exitg1 = 0;
            if (coltop + 1 <= b_coltop + b_lastv) {
              if (b_A[coltop] != 0.0) {
                exitg1 = 1;
              } else {
                coltop++;
              }
            } else {
              knt--;
              exitg1 = 2;
            }
          } while (exitg1 == 0);

          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      } else {
        b_lastv = 0;
        knt = 0;
      }

      if (b_lastv > 0) {
        xgemv_4E6oVMBP(b_lastv, knt, b_A, ii + 4, b_A, ii + 1, work);
        xgerc_duqdQXG2(b_lastv, knt, -tau[itau], ii + 1, work, b_A, ii + 4);
      }

      b_A[ii] = beta1;
    } else {
      tau[2] = 0.0;
    }
  }

  for (itau = 0; itau < 3; itau++) {
    for (ii = 0; ii <= itau; ii++) {
      R[ii + 3 * itau] = b_A[3 * itau + ii];
    }

    for (ii = itau + 2; ii < 4; ii++) {
      R[(ii + 3 * itau) - 1] = 0.0;
    }

    work[itau] = 0.0;
  }

  for (ii = 2; ii >= 0; ii--) {
    b_lastv = (ii * 3 + ii) + 4;
    if (ii + 1 < 3) {
      b_A[b_lastv - 4] = 1.0;
      if (tau[ii] != 0.0) {
        knt = 3 - ii;
        b_coltop = b_lastv - ii;
        while ((knt > 0) && (b_A[b_coltop - 2] == 0.0)) {
          knt--;
          b_coltop--;
        }

        b_coltop = 2 - ii;
        exitg2 = false;
        while ((!exitg2) && (b_coltop > 0)) {
          coltop = (b_coltop - 1) * 3 + b_lastv;
          itau = coltop;
          do {
            exitg1 = 0;
            if (itau <= (coltop + knt) - 1) {
              if (b_A[itau - 1] != 0.0) {
                exitg1 = 1;
              } else {
                itau++;
              }
            } else {
              b_coltop--;
              exitg1 = 2;
            }
          } while (exitg1 == 0);

          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      } else {
        knt = 0;
        b_coltop = 0;
      }

      if (knt > 0) {
        xgemv_4E6oVMBP(knt, b_coltop, b_A, b_lastv, b_A, b_lastv - 3, work);
        xgerc_duqdQXG2(knt, b_coltop, -tau[ii], b_lastv - 3, work, b_A, b_lastv);
      }

      knt = (b_lastv - ii) - 1;
      for (b_coltop = b_lastv - 2; b_coltop <= knt; b_coltop++) {
        b_A[b_coltop - 1] *= -tau[ii];
      }
    }

    b_A[b_lastv - 4] = 1.0 - tau[ii];
    for (b_coltop = 0; b_coltop < ii; b_coltop++) {
      b_A[(b_lastv - b_coltop) - 5] = 0.0;
    }
  }

  for (itau = 0; itau < 3; itau++) {
    Q[3 * itau] = b_A[3 * itau];
    ii = 3 * itau + 1;
    Q[ii] = b_A[ii];
    ii = 3 * itau + 2;
    Q[ii] = b_A[ii];
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

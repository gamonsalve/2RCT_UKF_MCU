/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: SoC_Estimation_UKF_2RC_for_MCU.c
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

#include "SoC_Estimation_UKF_2RC_for_MCU.h"
#include "rtwtypes.h"
#include "trisolve_7ekc8URj.h"
#include <string.h>
#include <math.h>
#include "svd_iYqUPJsu.h"
#include "rt_nonfinite.h"
#include "rotate_3AIOL9tK.h"
#include "qr_zNlMH7mU.h"
#include "qr_cqxNMU1I.h"
#include "UTMeanCovSqrt_NbgcfSwv.h"
#include "xnrm2_zmdkvCDw.h"
#include "rt_hypotd_snf.h"
#include "look1_binlx.h"
#include "batteryMeasurementFcn.h"
#include "batteryStateFcn.h"

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;
extern const real_T rtCP_pooled_7B3mKLtOsXxB[8];
extern const real_T rtCP_pooled_9vFWbG2ExXGj[8];
extern const real_T rtCP_pooled_uPIwfQnD1MV9[8];
extern const real_T rtCP_pooled_Mb54Jt5w4x9H[8];
extern const real_T rtCP_pooled_rzZPkoUkRcLh[8];
extern const real_T rtCP_pooled_lSeHOqy4u1GL[8];
extern const real_T rtCP_pooled_5387vyPiNqIZ[8];
extern const real_T rtCP_pooled_6eW0tqTbqRvz[9];
extern const real_T rtCP_pooled_zluWpXtFX9wG[9];

#define rtCP_EmTable_tableData         rtCP_pooled_7B3mKLtOsXxB  /* Expression: FinalParameters.Em
                                                                  * Referenced by: '<S3>/Em Table'
                                                                  */
#define rtCP_EmTable_bp01Data          rtCP_pooled_9vFWbG2ExXGj  /* Expression: FinalParameters.SOC_LUT_REAL
                                                                  * Referenced by: '<S3>/Em Table'
                                                                  */
#define rtCP_R0Table_tableData         rtCP_pooled_uPIwfQnD1MV9  /* Expression: FinalParameters.R0
                                                                  * Referenced by: '<S3>/R0 Table'
                                                                  */
#define rtCP_R0Table_bp01Data          rtCP_pooled_9vFWbG2ExXGj  /* Expression: FinalParameters.SOC_LUT_REAL
                                                                  * Referenced by: '<S3>/R0 Table'
                                                                  */
#define rtCP_R1_tableData              rtCP_pooled_Mb54Jt5w4x9H  /* Expression: FinalParameters.R1
                                                                  * Referenced by: '<S4>/R1'
                                                                  */
#define rtCP_R1_bp01Data               rtCP_pooled_9vFWbG2ExXGj  /* Expression: FinalParameters.SOC_LUT_REAL
                                                                  * Referenced by: '<S4>/R1'
                                                                  */
#define rtCP_R2_tableData              rtCP_pooled_rzZPkoUkRcLh  /* Expression: FinalParameters.R2
                                                                  * Referenced by: '<S4>/R2'
                                                                  */
#define rtCP_R2_bp01Data               rtCP_pooled_9vFWbG2ExXGj  /* Expression: FinalParameters.SOC_LUT_REAL
                                                                  * Referenced by: '<S4>/R2'
                                                                  */
#define rtCP_tau1_tableData            rtCP_pooled_lSeHOqy4u1GL  /* Expression: FinalParameters.tau1
                                                                  * Referenced by: '<S4>/tau1'
                                                                  */
#define rtCP_tau1_bp01Data             rtCP_pooled_9vFWbG2ExXGj  /* Expression: FinalParameters.SOC_LUT_REAL
                                                                  * Referenced by: '<S4>/tau1'
                                                                  */
#define rtCP_tau2_tableData            rtCP_pooled_5387vyPiNqIZ  /* Expression: FinalParameters.tau2
                                                                  * Referenced by: '<S4>/tau2'
                                                                  */
#define rtCP_tau2_bp01Data             rtCP_pooled_9vFWbG2ExXGj  /* Expression: FinalParameters.SOC_LUT_REAL
                                                                  * Referenced by: '<S4>/tau2'
                                                                  */
#define rtCP_EmTable_tableData_o       rtCP_pooled_7B3mKLtOsXxB  /* Expression: FinalParameters.Em
                                                                  * Referenced by: '<S1>/Em Table'
                                                                  */
#define rtCP_EmTable_bp01Data_f        rtCP_pooled_9vFWbG2ExXGj  /* Expression: FinalParameters.SOC_LUT_REAL
                                                                  * Referenced by: '<S1>/Em Table'
                                                                  */
#define rtCP_R0Table_tableData_n       rtCP_pooled_uPIwfQnD1MV9  /* Expression: FinalParameters.R0
                                                                  * Referenced by: '<S1>/R0 Table'
                                                                  */
#define rtCP_R0Table_bp01Data_c        rtCP_pooled_9vFWbG2ExXGj  /* Expression: FinalParameters.SOC_LUT_REAL
                                                                  * Referenced by: '<S1>/R0 Table'
                                                                  */
#define rtCP_Q_Value                   rtCP_pooled_6eW0tqTbqRvz  /* Expression: p.Q
                                                                  * Referenced by: '<S5>/Q'
                                                                  */
#define rtCP_DataStoreMemoryP_InitialVa rtCP_pooled_zluWpXtFX9wG /* Expression: p.InitialCovariance
                                                                  * Referenced by: '<S5>/DataStoreMemory - P'
                                                                  */

/* Forward declaration for local functions */
static void UKFCorrectorAdditive_getPredict(real_T Rs, const real_T X1[3], const
  real_T S[9], real_T alpha, real_T beta, real_T kappa, real_T *Ymean, real_T
  Pxy[3], real_T *Sy);

/* Output and update for Simulink Function: '<S2>/Simulink Function - Measurement Function' */
real_T batteryMeasurementFcn(const real_T rtu_x[3])
{
  real_T rtb_Product;

  /* Saturate: '<S3>/Saturation' incorporates:
   *  SignalConversion generated from: '<S3>/x'
   */
  if (rtu_x[0] > 1.0) {
    rtb_Product = 1.0;
  } else if (rtu_x[0] < 0.0) {
    rtb_Product = 0.0;
  } else {
    rtb_Product = rtu_x[0];
  }

  /* End of Saturate: '<S3>/Saturation' */

  /* SignalConversion generated from: '<S3>/y' incorporates:
   *  Inport: '<Root>/current'
   *  Lookup_n-D: '<S3>/Em Table'
   *  Lookup_n-D: '<S3>/R0 Table'
   *  Product: '<S3>/Product'
   *  SignalConversion generated from: '<S3>/x'
   *  Sum: '<S3>/Add1'
   */
  return ((look1_binlx(rtb_Product, rtCP_EmTable_bp01Data,
                       rtCP_EmTable_tableData, 7U) - look1_binlx(rtb_Product,
            rtCP_R0Table_bp01Data, rtCP_R0Table_tableData, 7U) * rtU.current) -
          rtu_x[1]) - rtu_x[2];
}

/* Output and update for Simulink Function: '<S2>/Simulink Function - State Transition Function' */
void batteryStateFcn(const real_T rtu_x[3], real_T rty_xNext[3])
{
  real_T rtb_Saturation;
  real_T rtb_tau1;
  real_T rtb_tau2;

  /* Saturate: '<S4>/Saturation' incorporates:
   *  SignalConversion generated from: '<S4>/x'
   */
  if (rtu_x[0] > 1.0) {
    rtb_Saturation = 1.0;
  } else if (rtu_x[0] < 0.0) {
    rtb_Saturation = 0.0;
  } else {
    rtb_Saturation = rtu_x[0];
  }

  /* End of Saturate: '<S4>/Saturation' */

  /* Lookup_n-D: '<S4>/tau1' incorporates:
   *  Saturate: '<S4>/Saturation'
   */
  rtb_tau1 = look1_binlx(rtb_Saturation, rtCP_tau1_bp01Data, rtCP_tau1_tableData,
    7U);

  /* Lookup_n-D: '<S4>/tau2' incorporates:
   *  Saturate: '<S4>/Saturation'
   */
  rtb_tau2 = look1_binlx(rtb_Saturation, rtCP_tau2_bp01Data, rtCP_tau2_tableData,
    7U);

  /* MATLAB Function: '<S4>/f(x,u)' incorporates:
   *  Constant: '<S4>/Constant1'
   *  Inport: '<Root>/current'
   *  Lookup_n-D: '<S4>/R1'
   *  Lookup_n-D: '<S4>/R2'
   *  Saturate: '<S4>/Saturation'
   *  SignalConversion generated from: '<S4>/x'
   */
  rty_xNext[0] = -rtU.current / 18000.0;
  rty_xNext[1] = -1.0 / rtb_tau1 * rtu_x[1] + rtU.current / (rtb_tau1 /
    look1_binlx(rtb_Saturation, rtCP_R1_bp01Data, rtCP_R1_tableData, 7U));
  rty_xNext[2] = -1.0 / rtb_tau2 * rtu_x[2] + rtU.current / (rtb_tau2 /
    look1_binlx(rtb_Saturation, rtCP_R2_bp01Data, rtCP_R2_tableData, 7U));

  /* SignalConversion generated from: '<S4>/xNext' incorporates:
   *  Constant: '<S4>/Constant'
   *  Product: '<S4>/Product'
   *  SignalConversion generated from: '<S4>/x'
   *  Sum: '<S4>/Add'
   */
  rty_xNext[0] = rty_xNext[0] * 0.1 + rtu_x[0];
  rty_xNext[1] = rty_xNext[1] * 0.1 + rtu_x[1];
  rty_xNext[2] = rty_xNext[2] * 0.1 + rtu_x[2];
}

/* Function for MATLAB Function: '<S7>/Correct' */
static void UKFCorrectorAdditive_getPredict(real_T Rs, const real_T X1[3], const
  real_T S[9], real_T alpha, real_T beta, real_T kappa, real_T *Ymean, real_T
  Pxy[3], real_T *Sy)
{
  real_T X2[18];
  real_T Y2[6];
  real_T Y2_0[6];
  real_T Wcov[2];
  real_T Wmean[2];
  real_T Wmean_0;
  real_T beta1;
  int32_T X2_tmp;
  int32_T knt;
  beta1 = alpha * alpha;
  *Sy = (kappa + 3.0) * beta1;
  Wmean[0] = 1.0 - 3.0 / *Sy;
  Wmean[1] = 1.0 / (2.0 * *Sy);
  Wcov[0] = ((1.0 - beta1) + beta) + Wmean[0];
  Wcov[1] = Wmean[1];
  if (Wmean[0] != 0.0) {
    real_T Wcov_0;
    beta1 = Wmean[0];
    Wmean_0 = Wmean[0];
    Wmean[0] /= Wmean[0];
    Wcov[0] /= beta1;
    Wcov_0 = Wmean[1];
    Wmean[1] /= Wmean_0;
    Wcov[1] = Wcov_0 / beta1;
  } else {
    beta1 = 1.0;
  }

  *Sy = sqrt(*Sy);
  for (knt = 0; knt < 9; knt++) {
    Wmean_0 = *Sy * S[knt];
    X2[knt] = Wmean_0;
    X2[knt + 9] = -Wmean_0;
  }

  for (knt = 0; knt < 6; knt++) {
    X2[3 * knt] += X1[0];
    X2_tmp = 3 * knt + 1;
    X2[X2_tmp] += X1[1];
    X2_tmp = 3 * knt + 2;
    X2[X2_tmp] += X1[2];
  }

  for (knt = 0; knt < 6; knt++) {
    Y2[knt] = batteryMeasurementFcn(&X2[3 * knt]);
  }

  *Sy = batteryMeasurementFcn(X1);
  for (knt = 0; knt < 6; knt++) {
    Y2_0[knt] = (Y2[knt] - *Sy) + *Sy;
  }

  UTMeanCovSqrt_NbgcfSwv(Wmean, Wcov, beta1, *Sy, Y2_0, X1, X2, Ymean, &Wmean_0,
    Pxy);
  Wmean[0] = Wmean_0;
  Wmean[1] = Rs;
  *Sy = Wmean_0;
  beta1 = xnrm2_zmdkvCDw(1, Wmean, 2);
  if (beta1 != 0.0) {
    beta1 = rt_hypotd_snf(Wmean_0, beta1);
    if (Wmean_0 >= 0.0) {
      beta1 = -beta1;
    }

    if (fabs(beta1) < 1.0020841800044864E-292) {
      knt = 0;
      do {
        knt++;
        Wmean[1] *= 9.9792015476736E+291;
        beta1 *= 9.9792015476736E+291;
        *Sy *= 9.9792015476736E+291;
      } while ((fabs(beta1) < 1.0020841800044864E-292) && (knt < 20));

      beta1 = rt_hypotd_snf(*Sy, xnrm2_zmdkvCDw(1, Wmean, 2));
      if (*Sy >= 0.0) {
        beta1 = -beta1;
      }

      for (X2_tmp = 0; X2_tmp < knt; X2_tmp++) {
        beta1 *= 1.0020841800044864E-292;
      }

      *Sy = beta1;
    } else {
      *Sy = beta1;
    }
  }
}

/* Model step function */
void SoC_Estimation_UKF_2RC_for_MCU_step(void)
{
  real_T X2state[18];
  real_T Y2[18];
  real_T tmp[18];
  real_T Pxy_0[9];
  real_T R[9];
  real_T R_0[9];
  real_T Ss[9];
  real_T K[3];
  real_T Pxy[3];
  real_T b_c[3];
  real_T rtb_xNew[3];
  real_T s[3];
  real_T absxk;
  real_T nrmx;
  real_T rtb_Product;
  real_T scale;
  real_T temp;
  int32_T aoffset;
  int32_T b_j;
  int32_T i;
  int32_T iAcol;
  int8_T p;
  boolean_T errorCondition;

  /* Outputs for Enabled SubSystem: '<S5>/Correct1' incorporates:
   *  EnablePort: '<S7>/Enable'
   */
  /* MATLAB Function: '<S7>/Correct' incorporates:
   *  Constant: '<S5>/R1'
   *  DataStoreRead: '<S7>/Data Store ReadX'
   *  DataStoreWrite: '<S7>/Data Store WriteP'
   *  Inport: '<Root>/voltage'
   */
  batteryMeasurementFcn(rtDW.x);
  UKFCorrectorAdditive_getPredict(3.1622776601683795, rtDW.x, rtDW.P_f, 1.0, 2.0,
    0.0, &rtb_Product, Pxy, &temp);
  rtb_Product = rtU.voltage - rtb_Product;
  for (iAcol = 0; iAcol < 3; iAcol++) {
    R[3 * iAcol] = rtDW.P_f[iAcol];
    R[3 * iAcol + 1] = rtDW.P_f[iAcol + 3];
    R[3 * iAcol + 2] = rtDW.P_f[iAcol + 6];
    rtb_xNew[iAcol] = Pxy[iAcol];
  }

  trisolve_7ekc8URj(temp, rtb_xNew);
  K[0] = rtb_xNew[0];
  K[1] = rtb_xNew[1];
  K[2] = rtb_xNew[2];
  trisolve_7ekc8URj(temp, K);
  for (b_j = 0; b_j < 3; b_j++) {
    Pxy[b_j] = K[b_j] * temp;
    if (1 - b_j >= 0) {
      memset(&R[(b_j << 2) + 1], 0, (uint32_T)((1 - b_j) + 1) * sizeof(real_T));
    }
  }

  p = 0;
  errorCondition = (R[0] == 0.0);
  if (!errorCondition) {
    errorCondition = (R[4] == 0.0);
  }

  if (!errorCondition) {
    errorCondition = (R[8] == 0.0);
  }

  if (errorCondition) {
    p = 2;
  } else {
    rtb_xNew[0] = Pxy[0];
    rtb_xNew[1] = Pxy[1];
    rtb_xNew[2] = Pxy[2];
    for (i = 0; i < 3; i++) {
      iAcol = 3 * i;
      temp = rtb_xNew[i];
      for (b_j = 0; b_j < i; b_j++) {
        temp -= R[b_j + iAcol] * rtb_xNew[b_j];
      }

      rtb_xNew[i] = temp / R[i + iAcol];
    }

    scale = 3.3121686421112381E-170;
    absxk = fabs(rtb_xNew[0]);
    if (absxk > 3.3121686421112381E-170) {
      nrmx = 1.0;
      scale = absxk;
    } else {
      temp = absxk / 3.3121686421112381E-170;
      nrmx = temp * temp;
    }

    absxk = fabs(rtb_xNew[1]);
    if (absxk > scale) {
      temp = scale / absxk;
      nrmx = nrmx * temp * temp + 1.0;
      scale = absxk;
    } else {
      temp = absxk / scale;
      nrmx += temp * temp;
    }

    absxk = fabs(rtb_xNew[2]);
    if (absxk > scale) {
      temp = scale / absxk;
      nrmx = nrmx * temp * temp + 1.0;
      scale = absxk;
    } else {
      temp = absxk / scale;
      nrmx += temp * temp;
    }

    nrmx = scale * sqrt(nrmx);
    if (nrmx >= 1.0) {
      p = 1;
    } else {
      rotate_3AIOL9tK(sqrt(1.0 - nrmx * nrmx), rtb_xNew[2], &b_c[2], &s[2],
                      &temp);
      rtb_xNew[2] = 0.0;
      rotate_3AIOL9tK(temp, rtb_xNew[1], &b_c[1], &s[1], &temp);
      rtb_xNew[1] = 0.0;
      rotate_3AIOL9tK(temp, rtb_xNew[0], &b_c[0], &s[0], &temp);
      rtb_xNew[0] = 0.0;
      for (iAcol = 0; iAcol < 3; iAcol++) {
        for (i = iAcol + 1; i >= 1; i--) {
          temp = rtb_xNew[iAcol];
          aoffset = (3 * iAcol + i) - 1;
          scale = R[aoffset];
          absxk = s[i - 1];
          nrmx = b_c[i - 1];
          R[aoffset] = scale * nrmx - absxk * temp;
          rtb_xNew[iAcol] = nrmx * temp + scale * absxk;
        }
      }
    }
  }

  if (p != 0) {
    boolean_T exitg2;
    for (i = 0; i < 3; i++) {
      for (iAcol = 0; iAcol < 3; iAcol++) {
        b_j = 3 * iAcol + i;
        R_0[b_j] = 0.0;
        R_0[b_j] += R[3 * i] * R[3 * iAcol];
        R_0[b_j] += R[3 * i + 1] * R[3 * iAcol + 1];
        R_0[b_j] += R[3 * i + 2] * R[3 * iAcol + 2];
        Pxy_0[iAcol + 3 * i] = Pxy[iAcol] * Pxy[i];
      }
    }

    errorCondition = true;
    for (i = 0; i < 9; i++) {
      temp = R_0[i] - Pxy_0[i];
      if (errorCondition && (rtIsInf(temp) || rtIsNaN(temp))) {
        errorCondition = false;
      }

      Ss[i] = temp;
    }

    if (errorCondition) {
      svd_iYqUPJsu(Ss, Pxy_0, s, R_0);
    } else {
      s[0] = (rtNaN);
      s[1] = (rtNaN);
      s[2] = (rtNaN);
      for (i = 0; i < 9; i++) {
        R_0[i] = (rtNaN);
      }
    }

    memset(&Ss[0], 0, 9U * sizeof(real_T));
    Ss[0] = s[0];
    Ss[4] = s[1];
    Ss[8] = s[2];
    for (b_j = 0; b_j < 9; b_j++) {
      Ss[b_j] = sqrt(Ss[b_j]);
    }

    for (i = 0; i < 3; i++) {
      for (iAcol = 0; iAcol < 3; iAcol++) {
        b_j = 3 * iAcol + i;
        R[b_j] = 0.0;
        R[b_j] += Ss[3 * i] * R_0[iAcol];
        R[b_j] += Ss[3 * i + 1] * R_0[iAcol + 3];
        R[b_j] += Ss[3 * i + 2] * R_0[iAcol + 6];
      }
    }

    errorCondition = true;
    iAcol = 0;
    exitg2 = false;
    while ((!exitg2) && (iAcol < 3)) {
      int32_T exitg1;
      i = iAcol + 1;
      do {
        exitg1 = 0;
        if (i + 1 < 4) {
          if (!(R[3 * iAcol + i] == 0.0)) {
            errorCondition = false;
            exitg1 = 1;
          } else {
            i++;
          }
        } else {
          iAcol++;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }

    if (!errorCondition) {
      memcpy(&R_0[0], &R[0], 9U * sizeof(real_T));
      qr_zNlMH7mU(R_0, Pxy_0, R);
    }
  }

  for (i = 0; i < 3; i++) {
    rtDW.P_f[3 * i] = R[i];
    rtDW.P_f[3 * i + 1] = R[i + 3];
    rtDW.P_f[3 * i + 2] = R[i + 6];

    /* DataStoreWrite: '<S7>/Data Store WriteX' */
    rtDW.x[i] += K[i] * rtb_Product;
  }

  /* End of MATLAB Function: '<S7>/Correct' */
  /* End of Outputs for SubSystem: '<S5>/Correct1' */

  /* Saturate: '<Root>/Saturation' incorporates:
   *  DataStoreRead: '<S9>/Data Store Read'
   */
  if (rtDW.x[0] > 1.0) {
    /* Outport: '<Root>/SoCEstimatedUKF' */
    rtY.SoCEstimatedUKF = 1.0;
  } else if (rtDW.x[0] < 0.0) {
    /* Outport: '<Root>/SoCEstimatedUKF' */
    rtY.SoCEstimatedUKF = 0.0;
  } else {
    /* Outport: '<Root>/SoCEstimatedUKF' */
    rtY.SoCEstimatedUKF = rtDW.x[0];
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* Saturate: '<S1>/Saturation' incorporates:
   *  DataStoreRead: '<S9>/Data Store Read'
   */
  if (rtDW.x[0] > 1.0) {
    rtb_Product = 1.0;
  } else if (rtDW.x[0] < 0.0) {
    rtb_Product = 0.0;
  } else {
    rtb_Product = rtDW.x[0];
  }

  /* End of Saturate: '<S1>/Saturation' */

  /* Outport: '<Root>/voltageEstimatedUKF' incorporates:
   *  DataStoreRead: '<S9>/Data Store Read'
   *  Inport: '<Root>/current'
   *  Lookup_n-D: '<S1>/Em Table'
   *  Lookup_n-D: '<S1>/R0 Table'
   *  Product: '<S1>/Product'
   *  Sum: '<S1>/Add1'
   */
  rtY.voltageEstimatedUKF = ((look1_binlx(rtb_Product, rtCP_EmTable_bp01Data_f,
    rtCP_EmTable_tableData_o, 7U) - look1_binlx(rtb_Product,
    rtCP_R0Table_bp01Data_c, rtCP_R0Table_tableData_n, 7U) * rtU.current) -
    rtDW.x[1]) - rtDW.x[2];

  /* Outport: '<Root>/SoCMeasuredUKF' incorporates:
   *  DiscreteIntegrator: '<Root>/Discrete-Time Integrator'
   *  Gain: '<Root>/Convert to SOC1'
   */
  rtY.SoCMeasuredUKF = 0.2 * rtDW.DiscreteTimeIntegrator_DSTATE;

  /* Outputs for Atomic SubSystem: '<S5>/Predict' */
  /* MATLAB Function: '<S8>/Predict' incorporates:
   *  Constant: '<S5>/Q'
   *  DataStoreRead: '<S8>/Data Store ReadX'
   *  DataStoreWrite: '<S8>/Data Store WriteP'
   */
  batteryStateFcn(rtDW.x, b_c);
  for (i = 0; i < 9; i++) {
    temp = 1.7320508075688772 * rtDW.P_f[i];
    X2state[i] = temp;
    X2state[i + 9] = -temp;
  }

  for (i = 0; i < 6; i++) {
    X2state[3 * i] += rtDW.x[0];
    iAcol = 3 * i + 1;
    X2state[iAcol] += rtDW.x[1];
    iAcol = 3 * i + 2;
    X2state[iAcol] += rtDW.x[2];
  }

  for (i = 0; i < 6; i++) {
    batteryStateFcn(&X2state[3 * i], &Y2[3 * i]);
  }

  batteryStateFcn(rtDW.x, Pxy);
  rtb_xNew[0] = Pxy[0] * 0.0;
  rtb_xNew[1] = Pxy[1] * 0.0;
  rtb_xNew[2] = Pxy[2] * 0.0;
  for (i = 0; i < 6; i++) {
    rtb_xNew[0] += Y2[3 * i] * 0.16666666666666666;
    rtb_xNew[1] += Y2[3 * i + 1] * 0.16666666666666666;
    rtb_xNew[2] += Y2[3 * i + 2] * 0.16666666666666666;
  }

  rtb_Product = Pxy[0] - rtb_xNew[0];
  Pxy[0] = rtb_Product;
  Pxy[1] -= rtb_xNew[1];
  Pxy[2] -= rtb_xNew[2];
  for (i = 0; i < 6; i++) {
    Y2[3 * i] -= rtb_xNew[0];
    iAcol = 3 * i + 1;
    Y2[iAcol] -= rtb_xNew[1];
    iAcol = 3 * i + 2;
    Y2[iAcol] -= rtb_xNew[2];
  }

  for (i = 0; i < 3; i++) {
    for (iAcol = 0; iAcol < 6; iAcol++) {
      tmp[iAcol + 6 * i] = Y2[3 * iAcol + i] * 0.408248290463863;
    }
  }

  qr_cqxNMU1I(tmp, X2state, R);
  for (b_j = 0; b_j < 3; b_j++) {
    if (1 - b_j >= 0) {
      memset(&R[(b_j << 2) + 1], 0, (uint32_T)((1 - b_j) + 1) * sizeof(real_T));
    }

    b_c[b_j] = 0.0;
    K[b_j] = 0.0;
  }

  rotate_3AIOL9tK(R[0], rtb_Product, &b_c[0], &K[0], &R[0]);
  for (b_j = 0; b_j < 2; b_j++) {
    temp = Pxy[b_j + 1];
    for (i = 0; i <= b_j; i++) {
      absxk = b_c[i];
      nrmx = K[i];
      rtb_Product = nrmx * temp;
      aoffset = (b_j + 1) * 3 + i;
      scale = R[aoffset];
      temp = absxk * temp - scale * nrmx;
      R[aoffset] = scale * absxk + rtb_Product;
    }

    rotate_3AIOL9tK(R[(b_j + 3 * (b_j + 1)) + 1], temp, &b_c[b_j + 1], &K[b_j +
                    1], &R[(b_j + 3 * (b_j + 1)) + 1]);
  }

  for (i = 0; i < 3; i++) {
    R_0[3 * i] = R[i];
    R_0[3 * i + 1] = R[i + 3];
    R_0[3 * i + 2] = R[i + 6];
  }

  for (i = 0; i < 9; i++) {
    R[i] = R_0[i];
    Ss[i] = 0.0;
  }

  Ss[0] = 1.0;
  Ss[4] = 1.0;
  Ss[8] = 1.0;
  for (iAcol = 0; iAcol < 3; iAcol++) {
    b_j = iAcol * 3;
    for (i = 0; i < 3; i++) {
      aoffset = i * 3;
      R_0[b_j + i] = (R[aoffset + 1] * Ss[iAcol + 3] + R[aoffset] * Ss[iAcol]) +
        R[aoffset + 2] * Ss[iAcol + 6];
    }
  }

  for (i = 0; i < 3; i++) {
    Y2[6 * i] = R_0[3 * i];
    Y2[6 * i + 3] = rtCP_Q_Value[i];
    Y2[6 * i + 1] = R_0[3 * i + 1];
    Y2[6 * i + 4] = rtCP_Q_Value[i + 3];
    Y2[6 * i + 2] = R_0[3 * i + 2];
    Y2[6 * i + 5] = rtCP_Q_Value[i + 6];
  }

  qr_cqxNMU1I(Y2, X2state, R);
  for (i = 0; i < 3; i++) {
    rtDW.P_f[3 * i] = R[i];
    rtDW.P_f[3 * i + 1] = R[i + 3];
    rtDW.P_f[3 * i + 2] = R[i + 6];

    /* DataStoreWrite: '<S8>/Data Store WriteX' incorporates:
     *  DataStoreWrite: '<S8>/Data Store WriteP'
     */
    rtDW.x[i] = rtb_xNew[i];
  }

  /* End of MATLAB Function: '<S8>/Predict' */
  /* End of Outputs for SubSystem: '<S5>/Predict' */

  /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' incorporates:
   *  Gain: '<Root>/Convert to Ah1'
   *  Inport: '<Root>/current'
   */
  rtDW.DiscreteTimeIntegrator_DSTATE += -0.00027777777777777778 * rtU.current *
    0.1;
  if (rtDW.DiscreteTimeIntegrator_DSTATE >= 5.0) {
    rtDW.DiscreteTimeIntegrator_DSTATE = 5.0;
  } else if (rtDW.DiscreteTimeIntegrator_DSTATE <= 0.0) {
    rtDW.DiscreteTimeIntegrator_DSTATE = 0.0;
  }

  /* End of Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
}

/* Model initialize function */
void SoC_Estimation_UKF_2RC_for_MCU_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Start for DataStoreMemory: '<S5>/DataStoreMemory - P' */
  memcpy(&rtDW.P_f[0], &rtCP_DataStoreMemoryP_InitialVa[0], 9U * sizeof(real_T));

  /* Start for DataStoreMemory: '<S5>/DataStoreMemory - x' */
  rtDW.x[0] = 1.0;
  rtDW.x[1] = 0.0;
  rtDW.x[2] = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_DSTATE = 5.0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

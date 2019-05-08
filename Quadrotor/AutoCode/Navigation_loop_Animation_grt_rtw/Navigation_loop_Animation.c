/*
 * Navigation_loop_Animation.c
 *
 * Code generation for model "Navigation_loop_Animation".
 *
 * Model version              : 1.118
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Mon Nov 07 09:42:26 2016
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Navigation_loop_Animation.h"
#include "Navigation_loop_Animation_private.h"

/* Block signals (auto storage) */
B_Navigation_loop_Animation_T Navigation_loop_Animation_B;

/* Continuous states */
X_Navigation_loop_Animation_T Navigation_loop_Animation_X;

/* Block states (auto storage) */
DW_Navigation_loop_Animation_T Navigation_loop_Animation_DW;

/* Real-time model */
RT_MODEL_Navigation_loop_Anim_T Navigation_loop_Animation_M_;
RT_MODEL_Navigation_loop_Anim_T *const Navigation_loop_Animation_M =
  &Navigation_loop_Animation_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 14;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  Navigation_loop_Animation_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  Navigation_loop_Animation_output();
  Navigation_loop_Animation_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  Navigation_loop_Animation_output();
  Navigation_loop_Animation_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void Navigation_loop_Animation_output(void)
{
  /* local block i/o variables */
  real_T rtb_Gain4_a;
  real_T *lastU;
  real_T rtb_Sum_a;
  real_T rtb_Sum_e;
  real_T rtb_TrigonometricFunction_o;
  real_T rtb_Product2_jg;
  real_T rtb_Concatenate_idx_0;
  real_T rtb_Concatenate_o_idx_0;
  real_T rtb_Concatenate_k_idx_0;
  real_T rtb_Concatenate_k_idx_1;
  real_T rtb_Concatenate_o_idx_1;
  real_T rtb_Concatenate_o_idx_2;
  real_T rtb_Concatenate_k_idx_3;
  real_T rtb_Concatenate_o_idx_3;
  real_T rtb_Concatenate_k_idx_2;
  real_T rtb_Concatenate_idx_2;
  real_T rtb_Concatenate_idx_3;
  real_T rtb_Concatenate_idx_1;
  if (rtmIsMajorTimeStep(Navigation_loop_Animation_M)) {
    /* set solver stop time */
    if (!(Navigation_loop_Animation_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Navigation_loop_Animation_M->solverInfo,
                            ((Navigation_loop_Animation_M->Timing.clockTickH0 +
        1) * Navigation_loop_Animation_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Navigation_loop_Animation_M->solverInfo,
                            ((Navigation_loop_Animation_M->Timing.clockTick0 + 1)
        * Navigation_loop_Animation_M->Timing.stepSize0 +
        Navigation_loop_Animation_M->Timing.clockTickH0 *
        Navigation_loop_Animation_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Navigation_loop_Animation_M)) {
    Navigation_loop_Animation_M->Timing.t[0] = rtsiGetT
      (&Navigation_loop_Animation_M->solverInfo);
  }

  /* Gain: '<S17>/1//2' incorporates:
   *  Integrator: '<S2>/Integrator4'
   */
  rtb_Sum_a = Navigation_loop_Animation_P.u_Gain *
    Navigation_loop_Animation_X.Integrator4_CSTATE;

  /* Trigonometry: '<S17>/Trigonometric Function1' */
  rtb_Concatenate_idx_0 = cos(rtb_Sum_a);

  /* Trigonometry: '<S17>/Trigonometric Function' */
  rtb_Sum_a = sin(rtb_Sum_a);

  /* Product: '<S17>/Product' incorporates:
   *  Constant: '<S3>/Vr Roll Axes'
   */
  rtb_Concatenate_idx_1 = rtb_Sum_a *
    Navigation_loop_Animation_P.VrRollAxes_Value[0];
  rtb_Concatenate_idx_2 = rtb_Sum_a *
    Navigation_loop_Animation_P.VrRollAxes_Value[1];
  rtb_Concatenate_idx_3 = rtb_Sum_a *
    Navigation_loop_Animation_P.VrRollAxes_Value[2];

  /* Gain: '<S19>/1//2' incorporates:
   *  Integrator: '<S2>/Integrator5'
   */
  rtb_Sum_a = Navigation_loop_Animation_P.u_Gain_f *
    Navigation_loop_Animation_X.Integrator5_CSTATE;

  /* Trigonometry: '<S19>/Trigonometric Function1' */
  rtb_Concatenate_o_idx_0 = cos(rtb_Sum_a);

  /* Trigonometry: '<S19>/Trigonometric Function' */
  rtb_Sum_a = sin(rtb_Sum_a);

  /* Product: '<S19>/Product' incorporates:
   *  Constant: '<S3>/Vr Yaw Axes'
   */
  rtb_Concatenate_o_idx_1 = rtb_Sum_a *
    Navigation_loop_Animation_P.VrYawAxes_Value[0];
  rtb_Concatenate_o_idx_2 = rtb_Sum_a *
    Navigation_loop_Animation_P.VrYawAxes_Value[1];
  rtb_Concatenate_o_idx_3 = rtb_Sum_a *
    Navigation_loop_Animation_P.VrYawAxes_Value[2];

  /* Gain: '<S18>/1//2' incorporates:
   *  Integrator: '<S2>/Integrator3'
   */
  rtb_Sum_a = Navigation_loop_Animation_P.u_Gain_o *
    Navigation_loop_Animation_X.Integrator3_CSTATE;

  /* Trigonometry: '<S18>/Trigonometric Function1' */
  rtb_Concatenate_k_idx_0 = cos(rtb_Sum_a);

  /* Trigonometry: '<S18>/Trigonometric Function' */
  rtb_Sum_a = sin(rtb_Sum_a);

  /* Product: '<S18>/Product' incorporates:
   *  Constant: '<S3>/Vr Pitch Axes'
   */
  rtb_Concatenate_k_idx_1 = rtb_Sum_a *
    Navigation_loop_Animation_P.VrPitchAxes_Value[0];
  rtb_Concatenate_k_idx_2 = rtb_Sum_a *
    Navigation_loop_Animation_P.VrPitchAxes_Value[1];
  rtb_Concatenate_k_idx_3 = rtb_Sum_a *
    Navigation_loop_Animation_P.VrPitchAxes_Value[2];

  /* Sum: '<S21>/Sum' incorporates:
   *  Product: '<S21>/Product'
   *  Product: '<S21>/Product1'
   *  Product: '<S21>/Product2'
   *  Product: '<S21>/Product3'
   */
  rtb_Sum_a = ((rtb_Concatenate_o_idx_0 * rtb_Concatenate_k_idx_1 +
                rtb_Concatenate_o_idx_1 * rtb_Concatenate_k_idx_0) +
               rtb_Concatenate_o_idx_2 * rtb_Concatenate_k_idx_3) -
    rtb_Concatenate_o_idx_3 * rtb_Concatenate_k_idx_2;

  /* Sum: '<S20>/Sum' incorporates:
   *  Product: '<S20>/Product'
   *  Product: '<S20>/Product1'
   *  Product: '<S20>/Product2'
   *  Product: '<S20>/Product3'
   */
  rtb_Sum_e = ((rtb_Concatenate_o_idx_0 * rtb_Concatenate_k_idx_0 -
                rtb_Concatenate_o_idx_1 * rtb_Concatenate_k_idx_1) -
               rtb_Concatenate_o_idx_2 * rtb_Concatenate_k_idx_2) -
    rtb_Concatenate_o_idx_3 * rtb_Concatenate_k_idx_3;

  /* Sum: '<S23>/Sum' incorporates:
   *  Product: '<S23>/Product'
   *  Product: '<S23>/Product1'
   *  Product: '<S23>/Product2'
   *  Product: '<S23>/Product3'
   */
  rtb_TrigonometricFunction_o = ((rtb_Concatenate_o_idx_0 *
    rtb_Concatenate_k_idx_3 + rtb_Concatenate_o_idx_1 * rtb_Concatenate_k_idx_2)
    - rtb_Concatenate_o_idx_2 * rtb_Concatenate_k_idx_1) +
    rtb_Concatenate_o_idx_3 * rtb_Concatenate_k_idx_0;

  /* Product: '<S25>/Product2' */
  rtb_Product2_jg = rtb_Concatenate_idx_2 * rtb_TrigonometricFunction_o;

  /* Sum: '<S22>/Sum' incorporates:
   *  Product: '<S22>/Product'
   *  Product: '<S22>/Product1'
   *  Product: '<S22>/Product2'
   *  Product: '<S22>/Product3'
   */
  rtb_Concatenate_o_idx_0 = ((rtb_Concatenate_o_idx_0 * rtb_Concatenate_k_idx_2
    - rtb_Concatenate_o_idx_1 * rtb_Concatenate_k_idx_3) +
    rtb_Concatenate_o_idx_2 * rtb_Concatenate_k_idx_0) + rtb_Concatenate_o_idx_3
    * rtb_Concatenate_k_idx_1;

  /* Product: '<S25>/Product3' */
  rtb_Concatenate_o_idx_1 = rtb_Concatenate_idx_3 * rtb_Concatenate_o_idx_0;

  /* Product: '<S26>/Product' */
  rtb_Concatenate_o_idx_2 = rtb_Concatenate_idx_0 * rtb_Concatenate_o_idx_0;

  /* Product: '<S26>/Product1' */
  rtb_Concatenate_o_idx_3 = rtb_Concatenate_idx_1 * rtb_TrigonometricFunction_o;

  /* Product: '<S27>/Product' */
  rtb_Concatenate_k_idx_0 = rtb_Concatenate_idx_0 * rtb_TrigonometricFunction_o;

  /* Product: '<S27>/Product1' */
  rtb_Concatenate_k_idx_1 = rtb_Concatenate_idx_1 * rtb_Concatenate_o_idx_0;

  /* Sum: '<S24>/Sum' incorporates:
   *  Product: '<S24>/Product'
   *  Product: '<S24>/Product1'
   *  Product: '<S24>/Product2'
   *  Product: '<S24>/Product3'
   */
  rtb_Concatenate_o_idx_0 = ((rtb_Concatenate_idx_0 * rtb_Sum_e -
    rtb_Concatenate_idx_1 * rtb_Sum_a) - rtb_Concatenate_idx_2 *
    rtb_Concatenate_o_idx_0) - rtb_Concatenate_idx_3 *
    rtb_TrigonometricFunction_o;

  /* Trigonometry: '<S14>/Trigonometric Function2' */
  if (rtb_Concatenate_o_idx_0 > 1.0) {
    rtb_Concatenate_o_idx_0 = 1.0;
  } else {
    if (rtb_Concatenate_o_idx_0 < -1.0) {
      rtb_Concatenate_o_idx_0 = -1.0;
    }
  }

  rtb_Concatenate_o_idx_0 = acos(rtb_Concatenate_o_idx_0);

  /* End of Trigonometry: '<S14>/Trigonometric Function2' */

  /* Trigonometry: '<S14>/Trigonometric Function' */
  rtb_TrigonometricFunction_o = sin(rtb_Concatenate_o_idx_0);

  /* Product: '<S14>/Product' incorporates:
   *  Product: '<S25>/Product'
   *  Product: '<S25>/Product1'
   *  Product: '<S26>/Product2'
   *  Product: '<S26>/Product3'
   *  Product: '<S27>/Product2'
   *  Product: '<S27>/Product3'
   *  Sum: '<S25>/Sum'
   *  Sum: '<S26>/Sum'
   *  Sum: '<S27>/Sum'
   */
  Navigation_loop_Animation_B.Concatenate[0] = (((rtb_Concatenate_idx_0 *
    rtb_Sum_a + rtb_Concatenate_idx_1 * rtb_Sum_e) + rtb_Product2_jg) -
    rtb_Concatenate_o_idx_1) / rtb_TrigonometricFunction_o;
  Navigation_loop_Animation_B.Concatenate[1] = (((rtb_Concatenate_o_idx_2 -
    rtb_Concatenate_o_idx_3) + rtb_Concatenate_idx_2 * rtb_Sum_e) +
    rtb_Concatenate_idx_3 * rtb_Sum_a) / rtb_TrigonometricFunction_o;
  Navigation_loop_Animation_B.Concatenate[2] = (((rtb_Concatenate_k_idx_0 +
    rtb_Concatenate_k_idx_1) - rtb_Concatenate_idx_2 * rtb_Sum_a) +
    rtb_Concatenate_idx_3 * rtb_Sum_e) / rtb_TrigonometricFunction_o;

  /* Gain: '<S14>/2' */
  Navigation_loop_Animation_B.Concatenate[3] = Navigation_loop_Animation_P._Gain
    * rtb_Concatenate_o_idx_0;

  /* Integrator: '<Root>/Integrator' */
  Navigation_loop_Animation_B.Integrator =
    Navigation_loop_Animation_X.Integrator_CSTATE;

  /* Integrator: '<S2>/Integrator7' */
  Navigation_loop_Animation_B.Integrator7 =
    Navigation_loop_Animation_X.Integrator7_CSTATE;

  /* Gain: '<S1>/rad-->deg1' incorporates:
   *  Gain: '<Root>/Gain6'
   */
  Navigation_loop_Animation_B.raddeg1 = Navigation_loop_Animation_P.Gain6_Gain *
    Navigation_loop_Animation_B.Integrator7 *
    Navigation_loop_Animation_P.raddeg1_Gain;

  /* Integrator: '<Root>/Integrator1' */
  Navigation_loop_Animation_B.Integrator1 =
    Navigation_loop_Animation_X.Integrator1_CSTATE;

  /* Gain: '<S1>/rad-->deg' */
  Navigation_loop_Animation_B.raddeg = Navigation_loop_Animation_P.raddeg_Gain *
    Navigation_loop_Animation_B.Integrator1;
  if (rtmIsMajorTimeStep(Navigation_loop_Animation_M)) {
    /* SignalConversion: '<Root>/TmpSignal ConversionAtVR SinkInport2' */
    Navigation_loop_Animation_B.TmpSignalConversionAtVRSinkInpo[0] =
      Navigation_loop_Animation_B.Integrator;
    Navigation_loop_Animation_B.TmpSignalConversionAtVRSinkInpo[1] =
      Navigation_loop_Animation_B.raddeg1;
    Navigation_loop_Animation_B.TmpSignalConversionAtVRSinkInpo[2] =
      Navigation_loop_Animation_B.raddeg;
  }

  /* Gain: '<Root>/Gain2' incorporates:
   *  Integrator: '<S2>/Integrator4'
   */
  Navigation_loop_Animation_B.Gain2 = Navigation_loop_Animation_P.Gain2_Gain *
    Navigation_loop_Animation_X.Integrator4_CSTATE;

  /* Derivative: '<S5>/Derivative' incorporates:
   *  Constant: '<Root>/X_desired'
   */
  if ((Navigation_loop_Animation_DW.TimeStampA >=
       Navigation_loop_Animation_M->Timing.t[0]) &&
      (Navigation_loop_Animation_DW.TimeStampB >=
       Navigation_loop_Animation_M->Timing.t[0])) {
    Navigation_loop_Animation_B.Derivative = 0.0;
  } else {
    rtb_Sum_a = Navigation_loop_Animation_DW.TimeStampA;
    lastU = &Navigation_loop_Animation_DW.LastUAtTimeA;
    if (Navigation_loop_Animation_DW.TimeStampA <
        Navigation_loop_Animation_DW.TimeStampB) {
      if (Navigation_loop_Animation_DW.TimeStampB <
          Navigation_loop_Animation_M->Timing.t[0]) {
        rtb_Sum_a = Navigation_loop_Animation_DW.TimeStampB;
        lastU = &Navigation_loop_Animation_DW.LastUAtTimeB;
      }
    } else {
      if (Navigation_loop_Animation_DW.TimeStampA >=
          Navigation_loop_Animation_M->Timing.t[0]) {
        rtb_Sum_a = Navigation_loop_Animation_DW.TimeStampB;
        lastU = &Navigation_loop_Animation_DW.LastUAtTimeB;
      }
    }

    Navigation_loop_Animation_B.Derivative =
      (Navigation_loop_Animation_P.X_desired_Value - *lastU) /
      (Navigation_loop_Animation_M->Timing.t[0] - rtb_Sum_a);
  }

  /* End of Derivative: '<S5>/Derivative' */

  /* Derivative: '<S5>/Derivative2' */
  if ((Navigation_loop_Animation_DW.TimeStampA_a >=
       Navigation_loop_Animation_M->Timing.t[0]) &&
      (Navigation_loop_Animation_DW.TimeStampB_n >=
       Navigation_loop_Animation_M->Timing.t[0])) {
    rtb_Concatenate_o_idx_2 = 0.0;
  } else {
    rtb_Sum_a = Navigation_loop_Animation_DW.TimeStampA_a;
    lastU = &Navigation_loop_Animation_DW.LastUAtTimeA_p;
    if (Navigation_loop_Animation_DW.TimeStampA_a <
        Navigation_loop_Animation_DW.TimeStampB_n) {
      if (Navigation_loop_Animation_DW.TimeStampB_n <
          Navigation_loop_Animation_M->Timing.t[0]) {
        rtb_Sum_a = Navigation_loop_Animation_DW.TimeStampB_n;
        lastU = &Navigation_loop_Animation_DW.LastUAtTimeB_l;
      }
    } else {
      if (Navigation_loop_Animation_DW.TimeStampA_a >=
          Navigation_loop_Animation_M->Timing.t[0]) {
        rtb_Sum_a = Navigation_loop_Animation_DW.TimeStampB_n;
        lastU = &Navigation_loop_Animation_DW.LastUAtTimeB_l;
      }
    }

    rtb_Concatenate_o_idx_2 = (Navigation_loop_Animation_B.Derivative - *lastU) /
      (Navigation_loop_Animation_M->Timing.t[0] - rtb_Sum_a);
  }

  /* End of Derivative: '<S5>/Derivative2' */

  /* Derivative: '<S5>/Derivative5' */
  if ((Navigation_loop_Animation_DW.TimeStampA_j >=
       Navigation_loop_Animation_M->Timing.t[0]) &&
      (Navigation_loop_Animation_DW.TimeStampB_a >=
       Navigation_loop_Animation_M->Timing.t[0])) {
    rtb_Sum_e = 0.0;
  } else {
    rtb_Sum_a = Navigation_loop_Animation_DW.TimeStampA_j;
    lastU = &Navigation_loop_Animation_DW.LastUAtTimeA_g;
    if (Navigation_loop_Animation_DW.TimeStampA_j <
        Navigation_loop_Animation_DW.TimeStampB_a) {
      if (Navigation_loop_Animation_DW.TimeStampB_a <
          Navigation_loop_Animation_M->Timing.t[0]) {
        rtb_Sum_a = Navigation_loop_Animation_DW.TimeStampB_a;
        lastU = &Navigation_loop_Animation_DW.LastUAtTimeB_n;
      }
    } else {
      if (Navigation_loop_Animation_DW.TimeStampA_j >=
          Navigation_loop_Animation_M->Timing.t[0]) {
        rtb_Sum_a = Navigation_loop_Animation_DW.TimeStampB_a;
        lastU = &Navigation_loop_Animation_DW.LastUAtTimeB_n;
      }
    }

    rtb_Sum_e = (Navigation_loop_Animation_B.Integrator - *lastU) /
      (Navigation_loop_Animation_M->Timing.t[0] - rtb_Sum_a);
  }

  /* End of Derivative: '<S5>/Derivative5' */

  /* Sum: '<S5>/Subtract5' incorporates:
   *  Constant: '<Root>/X_desired'
   */
  Navigation_loop_Animation_B.Subtract5 =
    Navigation_loop_Animation_P.X_desired_Value -
    Navigation_loop_Animation_B.Integrator;

  /* Sum: '<S5>/Subtract2' incorporates:
   *  Gain: '<S5>/Gain2'
   *  Gain: '<S5>/Gain3'
   *  Gain: '<S5>/Gain6'
   *  Integrator: '<S5>/Integrator'
   *  Sum: '<S5>/Subtract'
   */
  rtb_Concatenate_o_idx_2 = (((Navigation_loop_Animation_B.Derivative -
    rtb_Sum_e) * Navigation_loop_Animation_P.kdx + rtb_Concatenate_o_idx_2) +
    Navigation_loop_Animation_P.kpx * Navigation_loop_Animation_B.Subtract5) +
    Navigation_loop_Animation_P.kix *
    Navigation_loop_Animation_X.Integrator_CSTATE_b;
  if (rtmIsMajorTimeStep(Navigation_loop_Animation_M)) {
    /* Fcn: '<S5>/Fcn1' incorporates:
     *  Constant: '<Root>/yaw_desired'
     */
    Navigation_loop_Animation_B.Fcn1 = cos
      (Navigation_loop_Animation_P.yaw_desired_Value);
  }

  /* Derivative: '<S5>/Derivative1' incorporates:
   *  Constant: '<Root>/Y_desired'
   */
  if ((Navigation_loop_Animation_DW.TimeStampA_c >=
       Navigation_loop_Animation_M->Timing.t[0]) &&
      (Navigation_loop_Animation_DW.TimeStampB_m >=
       Navigation_loop_Animation_M->Timing.t[0])) {
    Navigation_loop_Animation_B.Derivative1 = 0.0;
  } else {
    rtb_Sum_a = Navigation_loop_Animation_DW.TimeStampA_c;
    lastU = &Navigation_loop_Animation_DW.LastUAtTimeA_gt;
    if (Navigation_loop_Animation_DW.TimeStampA_c <
        Navigation_loop_Animation_DW.TimeStampB_m) {
      if (Navigation_loop_Animation_DW.TimeStampB_m <
          Navigation_loop_Animation_M->Timing.t[0]) {
        rtb_Sum_a = Navigation_loop_Animation_DW.TimeStampB_m;
        lastU = &Navigation_loop_Animation_DW.LastUAtTimeB_h;
      }
    } else {
      if (Navigation_loop_Animation_DW.TimeStampA_c >=
          Navigation_loop_Animation_M->Timing.t[0]) {
        rtb_Sum_a = Navigation_loop_Animation_DW.TimeStampB_m;
        lastU = &Navigation_loop_Animation_DW.LastUAtTimeB_h;
      }
    }

    Navigation_loop_Animation_B.Derivative1 =
      (Navigation_loop_Animation_P.Y_desired_Value - *lastU) /
      (Navigation_loop_Animation_M->Timing.t[0] - rtb_Sum_a);
  }

  /* End of Derivative: '<S5>/Derivative1' */

  /* Derivative: '<S5>/Derivative3' */
  if ((Navigation_loop_Animation_DW.TimeStampA_e >=
       Navigation_loop_Animation_M->Timing.t[0]) &&
      (Navigation_loop_Animation_DW.TimeStampB_ap >=
       Navigation_loop_Animation_M->Timing.t[0])) {
    rtb_Sum_e = 0.0;
  } else {
    rtb_Sum_a = Navigation_loop_Animation_DW.TimeStampA_e;
    lastU = &Navigation_loop_Animation_DW.LastUAtTimeA_d;
    if (Navigation_loop_Animation_DW.TimeStampA_e <
        Navigation_loop_Animation_DW.TimeStampB_ap) {
      if (Navigation_loop_Animation_DW.TimeStampB_ap <
          Navigation_loop_Animation_M->Timing.t[0]) {
        rtb_Sum_a = Navigation_loop_Animation_DW.TimeStampB_ap;
        lastU = &Navigation_loop_Animation_DW.LastUAtTimeB_f;
      }
    } else {
      if (Navigation_loop_Animation_DW.TimeStampA_e >=
          Navigation_loop_Animation_M->Timing.t[0]) {
        rtb_Sum_a = Navigation_loop_Animation_DW.TimeStampB_ap;
        lastU = &Navigation_loop_Animation_DW.LastUAtTimeB_f;
      }
    }

    rtb_Sum_e = (Navigation_loop_Animation_B.Derivative1 - *lastU) /
      (Navigation_loop_Animation_M->Timing.t[0] - rtb_Sum_a);
  }

  /* End of Derivative: '<S5>/Derivative3' */

  /* Derivative: '<S5>/Derivative4' */
  if ((Navigation_loop_Animation_DW.TimeStampA_ak >=
       Navigation_loop_Animation_M->Timing.t[0]) &&
      (Navigation_loop_Animation_DW.TimeStampB_nx >=
       Navigation_loop_Animation_M->Timing.t[0])) {
    rtb_Concatenate_o_idx_1 = 0.0;
  } else {
    rtb_Sum_a = Navigation_loop_Animation_DW.TimeStampA_ak;
    lastU = &Navigation_loop_Animation_DW.LastUAtTimeA_l;
    if (Navigation_loop_Animation_DW.TimeStampA_ak <
        Navigation_loop_Animation_DW.TimeStampB_nx) {
      if (Navigation_loop_Animation_DW.TimeStampB_nx <
          Navigation_loop_Animation_M->Timing.t[0]) {
        rtb_Sum_a = Navigation_loop_Animation_DW.TimeStampB_nx;
        lastU = &Navigation_loop_Animation_DW.LastUAtTimeB_n5;
      }
    } else {
      if (Navigation_loop_Animation_DW.TimeStampA_ak >=
          Navigation_loop_Animation_M->Timing.t[0]) {
        rtb_Sum_a = Navigation_loop_Animation_DW.TimeStampB_nx;
        lastU = &Navigation_loop_Animation_DW.LastUAtTimeB_n5;
      }
    }

    rtb_Concatenate_o_idx_1 = (Navigation_loop_Animation_B.Integrator1 - *lastU)
      / (Navigation_loop_Animation_M->Timing.t[0] - rtb_Sum_a);
  }

  /* End of Derivative: '<S5>/Derivative4' */

  /* Sum: '<S5>/Subtract4' incorporates:
   *  Constant: '<Root>/Y_desired'
   */
  Navigation_loop_Animation_B.Subtract4 =
    Navigation_loop_Animation_P.Y_desired_Value -
    Navigation_loop_Animation_B.Integrator1;

  /* Sum: '<S5>/Subtract3' incorporates:
   *  Gain: '<S5>/Gain4'
   *  Gain: '<S5>/Gain5'
   *  Gain: '<S5>/Gain7'
   *  Integrator: '<S5>/Integrator1'
   *  Sum: '<S5>/Subtract1'
   */
  rtb_Sum_e = (((Navigation_loop_Animation_B.Derivative1 -
                 rtb_Concatenate_o_idx_1) * Navigation_loop_Animation_P.kdy +
                rtb_Sum_e) + Navigation_loop_Animation_P.kpy *
               Navigation_loop_Animation_B.Subtract4) +
    Navigation_loop_Animation_P.kiy *
    Navigation_loop_Animation_X.Integrator1_CSTATE_n;
  if (rtmIsMajorTimeStep(Navigation_loop_Animation_M)) {
    /* Fcn: '<S5>/Fcn' incorporates:
     *  Constant: '<Root>/yaw_desired'
     */
    Navigation_loop_Animation_B.Fcn = sin
      (Navigation_loop_Animation_P.yaw_desired_Value);
  }

  /* Gain: '<S5>/Gain1' incorporates:
   *  Product: '<S5>/Product6'
   *  Product: '<S5>/Product7'
   *  Sum: '<S5>/Subtract6'
   */
  rtb_Concatenate_o_idx_1 = (rtb_Concatenate_o_idx_2 *
    Navigation_loop_Animation_B.Fcn1 + rtb_Sum_e *
    Navigation_loop_Animation_B.Fcn) * (1.0 / Navigation_loop_Animation_P.g);

  /* Saturate: '<Root>/Saturation1' */
  if (rtb_Concatenate_o_idx_1 > Navigation_loop_Animation_P.Saturation1_UpperSat)
  {
    rtb_Concatenate_o_idx_1 = Navigation_loop_Animation_P.Saturation1_UpperSat;
  } else {
    if (rtb_Concatenate_o_idx_1 <
        Navigation_loop_Animation_P.Saturation1_LowerSat) {
      rtb_Concatenate_o_idx_1 = Navigation_loop_Animation_P.Saturation1_LowerSat;
    }
  }

  /* End of Saturate: '<Root>/Saturation1' */

  /* Gain: '<Root>/Gain3' */
  Navigation_loop_Animation_B.Gain3 = Navigation_loop_Animation_P.Gain3_Gain *
    rtb_Concatenate_o_idx_1;
  if (rtmIsMajorTimeStep(Navigation_loop_Animation_M)) {
  }

  /* Gain: '<Root>/Gain' incorporates:
   *  Integrator: '<S2>/Integrator3'
   */
  Navigation_loop_Animation_B.Gain = Navigation_loop_Animation_P.Gain_Gain *
    Navigation_loop_Animation_X.Integrator3_CSTATE;

  /* Gain: '<S5>/Gain' incorporates:
   *  Product: '<S5>/Product4'
   *  Product: '<S5>/Product5'
   *  Sum: '<S5>/Subtract7'
   */
  rtb_Concatenate_o_idx_2 = (Navigation_loop_Animation_B.Fcn *
    rtb_Concatenate_o_idx_2 - Navigation_loop_Animation_B.Fcn1 * rtb_Sum_e) *
    (1.0 / Navigation_loop_Animation_P.g);

  /* Saturate: '<Root>/Saturation' */
  if (rtb_Concatenate_o_idx_2 > Navigation_loop_Animation_P.Saturation_UpperSat)
  {
    rtb_Concatenate_o_idx_2 = Navigation_loop_Animation_P.Saturation_UpperSat;
  } else {
    if (rtb_Concatenate_o_idx_2 <
        Navigation_loop_Animation_P.Saturation_LowerSat) {
      rtb_Concatenate_o_idx_2 = Navigation_loop_Animation_P.Saturation_LowerSat;
    }
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* Gain: '<Root>/Gain1' */
  Navigation_loop_Animation_B.Gain1 = Navigation_loop_Animation_P.Gain1_Gain *
    rtb_Concatenate_o_idx_2;
  if (rtmIsMajorTimeStep(Navigation_loop_Animation_M)) {
  }

  /* Gain: '<Root>/Gain5' incorporates:
   *  Integrator: '<S2>/Integrator5'
   */
  Navigation_loop_Animation_B.Gain5 = Navigation_loop_Animation_P.Gain5_Gain *
    Navigation_loop_Animation_X.Integrator5_CSTATE;
  if (rtmIsMajorTimeStep(Navigation_loop_Animation_M)) {
    /* Gain: '<Root>/Gain4' incorporates:
     *  Constant: '<Root>/yaw_desired'
     */
    rtb_Gain4_a = Navigation_loop_Animation_P.Gain4_Gain *
      Navigation_loop_Animation_P.yaw_desired_Value;
  }

  /* Integrator: '<S2>/Integrator' */
  Navigation_loop_Animation_B.roll_dot =
    Navigation_loop_Animation_X.Integrator_CSTATE_f;

  /* Integrator: '<S2>/Integrator1' */
  Navigation_loop_Animation_B.pitch_dot =
    Navigation_loop_Animation_X.Integrator1_CSTATE_p;

  /* Integrator: '<S2>/Integrator2' */
  Navigation_loop_Animation_B.yaw_dot =
    Navigation_loop_Animation_X.Integrator2_CSTATE;

  /* Integrator: '<S2>/Integrator6' */
  Navigation_loop_Animation_B.Integrator6 =
    Navigation_loop_Animation_X.Integrator6_CSTATE;

  /* Integrator: '<S2>/Integrator8' */
  Navigation_loop_Animation_B.Integrator8 =
    Navigation_loop_Animation_X.Integrator8_CSTATE;

  /* Integrator: '<S2>/Integrator9' */
  Navigation_loop_Animation_B.Integrator9 =
    Navigation_loop_Animation_X.Integrator9_CSTATE;

  /* MATLAB Function: '<S2>/MATLAB Function' incorporates:
   *  Integrator: '<S2>/Integrator3'
   *  Integrator: '<S2>/Integrator4'
   *  Integrator: '<S2>/Integrator5'
   */
  /* MATLAB Function 'Dynamic model/MATLAB Function': '<S7>:1' */
  /* '<S7>:1:2' */
  /* '<S7>:1:3' */
  /* '<S7>:1:4' */
  /* '<S7>:1:5' */
  /* '<S7>:1:6' */
  /* '<S7>:1:7' */
  rtb_Sum_a = sin(Navigation_loop_Animation_X.Integrator4_CSTATE);
  rtb_Sum_e = sin(Navigation_loop_Animation_X.Integrator3_CSTATE);
  rtb_TrigonometricFunction_o = cos
    (Navigation_loop_Animation_X.Integrator3_CSTATE);
  rtb_Product2_jg = sin(Navigation_loop_Animation_X.Integrator5_CSTATE);
  rtb_Concatenate_o_idx_0 = cos(Navigation_loop_Animation_X.Integrator5_CSTATE);
  if (rtmIsMajorTimeStep(Navigation_loop_Animation_M)) {
    /* Sum: '<S8>/Add6' incorporates:
     *  Constant: '<S6>/ineretia_yy'
     *  Constant: '<S6>/inertia_zz'
     */
    Navigation_loop_Animation_B.Add6 =
      Navigation_loop_Animation_P.ineretia_yy_Value -
      Navigation_loop_Animation_P.inertia_zz_Value;
  }

  /* Product: '<S8>/Divide4' incorporates:
   *  Constant: '<S6>/Arm_length_'
   *  Constant: '<S6>/inertia_xx'
   *  Gain: '<S4>/kdt'
   *  Gain: '<S4>/kpt'
   *  Integrator: '<S2>/Integrator4'
   *  Product: '<S8>/Product12'
   *  Product: '<S8>/Product13'
   *  Product: '<S8>/Product9'
   *  Sum: '<S4>/Add6'
   *  Sum: '<S4>/eTheta'
   *  Sum: '<S8>/Add3'
   */
  Navigation_loop_Animation_B.Divide4 = (((rtb_Concatenate_o_idx_1 -
    Navigation_loop_Animation_X.Integrator4_CSTATE) *
    Navigation_loop_Animation_P.kpt - Navigation_loop_Animation_P.kdt *
    Navigation_loop_Animation_B.pitch_dot) *
    Navigation_loop_Animation_P.Arm_length_Value +
    Navigation_loop_Animation_B.roll_dot * Navigation_loop_Animation_B.yaw_dot *
    Navigation_loop_Animation_B.Add6) /
    Navigation_loop_Animation_P.inertia_xx_Value;
  if (rtmIsMajorTimeStep(Navigation_loop_Animation_M)) {
    /* Sum: '<S9>/Add5' incorporates:
     *  Constant: '<S6>/inertia_xx'
     *  Constant: '<S6>/inertia_zz'
     */
    Navigation_loop_Animation_B.Add5 =
      Navigation_loop_Animation_P.inertia_zz_Value -
      Navigation_loop_Animation_P.inertia_xx_Value;
  }

  /* Product: '<S9>/Divide3' incorporates:
   *  Constant: '<S6>/Arm_length_'
   *  Constant: '<S6>/ineretia_yy'
   *  Gain: '<S4>/kdp'
   *  Gain: '<S4>/kpp'
   *  Integrator: '<S2>/Integrator3'
   *  Product: '<S9>/Product10'
   *  Product: '<S9>/Product11'
   *  Product: '<S9>/Product8'
   *  Sum: '<S4>/Add5'
   *  Sum: '<S4>/ePhi'
   *  Sum: '<S9>/Add2'
   */
  Navigation_loop_Animation_B.Divide3 = (((rtb_Concatenate_o_idx_2 -
    Navigation_loop_Animation_X.Integrator3_CSTATE) *
    Navigation_loop_Animation_P.kpp - Navigation_loop_Animation_P.kdp *
    Navigation_loop_Animation_B.roll_dot) *
    Navigation_loop_Animation_P.Arm_length_Value +
    Navigation_loop_Animation_B.pitch_dot * Navigation_loop_Animation_B.yaw_dot *
    Navigation_loop_Animation_B.Add5) /
    Navigation_loop_Animation_P.ineretia_yy_Value;

  /* Product: '<S4>/Divide' incorporates:
   *  Constant: '<Root>/Z_desired'
   *  Constant: '<S4>/Constant1'
   *  Gain: '<S4>/kdz'
   *  Gain: '<S4>/kpz'
   *  Gain: '<S4>/m'
   *  Integrator: '<S2>/Integrator3'
   *  Integrator: '<S2>/Integrator4'
   *  Product: '<S4>/Product'
   *  Sum: '<S4>/Add2'
   *  Sum: '<S4>/Add4'
   *  Sum: '<S4>/ez'
   *  Trigonometry: '<S4>/cos Phi'
   *  Trigonometry: '<S4>/cos Theta'
   */
  rtb_Concatenate_o_idx_2 = (((Navigation_loop_Animation_P.Z_desired_Value -
    Navigation_loop_Animation_B.Integrator7) * Navigation_loop_Animation_P.kpz -
    Navigation_loop_Animation_P.kdz * Navigation_loop_Animation_B.Integrator6) +
    Navigation_loop_Animation_P.Constant1_Value) *
    Navigation_loop_Animation_P.m_Gain / (cos
    (Navigation_loop_Animation_X.Integrator3_CSTATE) * cos
    (Navigation_loop_Animation_X.Integrator4_CSTATE));

  /* Product: '<S10>/Divide' incorporates:
   *  Constant: '<S6>/mass'
   *  Product: '<S10>/Product1'
   *  Product: '<S10>/Product2'
   *  Product: '<S10>/Product3'
   *  Sum: '<S10>/Add'
   */
  Navigation_loop_Animation_B.x_dot_dot = (rtb_Sum_a * rtb_Concatenate_o_idx_0 *
    rtb_TrigonometricFunction_o + rtb_Product2_jg * rtb_Sum_e) *
    rtb_Concatenate_o_idx_2 / Navigation_loop_Animation_P.mass_Value;

  /* Product: '<S11>/Divide1' incorporates:
   *  Constant: '<S6>/mass'
   *  Product: '<S11>/Product5'
   *  Product: '<S11>/Product6'
   *  Product: '<S11>/Product7'
   *  Sum: '<S11>/Add1'
   */
  Navigation_loop_Animation_B.y_dot_dot = (rtb_Product2_jg * rtb_Sum_a *
    rtb_TrigonometricFunction_o - rtb_Sum_e * rtb_Concatenate_o_idx_0) *
    rtb_Concatenate_o_idx_2 / Navigation_loop_Animation_P.mass_Value;
  if (rtmIsMajorTimeStep(Navigation_loop_Animation_M)) {
    /* Sum: '<S12>/Add8' incorporates:
     *  Constant: '<S6>/ineretia_yy'
     *  Constant: '<S6>/inertia_xx'
     */
    Navigation_loop_Animation_B.Add8 =
      Navigation_loop_Animation_P.inertia_xx_Value -
      Navigation_loop_Animation_P.ineretia_yy_Value;
  }

  /* Product: '<S12>/Divide5' incorporates:
   *  Constant: '<Root>/yaw_desired'
   *  Constant: '<S6>/inertia_zz'
   *  Gain: '<S4>/kdps'
   *  Gain: '<S4>/kpps'
   *  Integrator: '<S2>/Integrator5'
   *  Product: '<S12>/Product14'
   *  Product: '<S12>/Product15'
   *  Sum: '<S12>/Add7'
   *  Sum: '<S4>/Add7'
   *  Sum: '<S4>/ePsi'
   */
  Navigation_loop_Animation_B.Divide5 =
    (((Navigation_loop_Animation_P.yaw_desired_Value -
       Navigation_loop_Animation_X.Integrator5_CSTATE) *
      Navigation_loop_Animation_P.kpps - Navigation_loop_Animation_P.kdps *
      Navigation_loop_Animation_B.yaw_dot) +
     Navigation_loop_Animation_B.pitch_dot *
     Navigation_loop_Animation_B.roll_dot * Navigation_loop_Animation_B.Add8) /
    Navigation_loop_Animation_P.inertia_zz_Value;

  /* Sum: '<S13>/Add4' incorporates:
   *  Constant: '<S13>/u5'
   *  Constant: '<S6>/mass'
   *  Integrator: '<S2>/Integrator4'
   *  MATLAB Function: '<S2>/MATLAB Function'
   *  Product: '<S13>/Divide2'
   *  Product: '<S13>/Product'
   *  Product: '<S13>/Product4'
   */
  Navigation_loop_Animation_B.z_dot_dot = cos
    (Navigation_loop_Animation_X.Integrator4_CSTATE) *
    rtb_TrigonometricFunction_o * rtb_Concatenate_o_idx_2 /
    Navigation_loop_Animation_P.mass_Value -
    Navigation_loop_Animation_P.u5_Value;
}

/* Model update function */
void Navigation_loop_Animation_update(void)
{
  real_T *lastU;

  /* Update for Derivative: '<S5>/Derivative' incorporates:
   *  Constant: '<Root>/X_desired'
   */
  if (Navigation_loop_Animation_DW.TimeStampA == (rtInf)) {
    Navigation_loop_Animation_DW.TimeStampA =
      Navigation_loop_Animation_M->Timing.t[0];
    lastU = &Navigation_loop_Animation_DW.LastUAtTimeA;
  } else if (Navigation_loop_Animation_DW.TimeStampB == (rtInf)) {
    Navigation_loop_Animation_DW.TimeStampB =
      Navigation_loop_Animation_M->Timing.t[0];
    lastU = &Navigation_loop_Animation_DW.LastUAtTimeB;
  } else if (Navigation_loop_Animation_DW.TimeStampA <
             Navigation_loop_Animation_DW.TimeStampB) {
    Navigation_loop_Animation_DW.TimeStampA =
      Navigation_loop_Animation_M->Timing.t[0];
    lastU = &Navigation_loop_Animation_DW.LastUAtTimeA;
  } else {
    Navigation_loop_Animation_DW.TimeStampB =
      Navigation_loop_Animation_M->Timing.t[0];
    lastU = &Navigation_loop_Animation_DW.LastUAtTimeB;
  }

  *lastU = Navigation_loop_Animation_P.X_desired_Value;

  /* End of Update for Derivative: '<S5>/Derivative' */

  /* Update for Derivative: '<S5>/Derivative2' */
  if (Navigation_loop_Animation_DW.TimeStampA_a == (rtInf)) {
    Navigation_loop_Animation_DW.TimeStampA_a =
      Navigation_loop_Animation_M->Timing.t[0];
    lastU = &Navigation_loop_Animation_DW.LastUAtTimeA_p;
  } else if (Navigation_loop_Animation_DW.TimeStampB_n == (rtInf)) {
    Navigation_loop_Animation_DW.TimeStampB_n =
      Navigation_loop_Animation_M->Timing.t[0];
    lastU = &Navigation_loop_Animation_DW.LastUAtTimeB_l;
  } else if (Navigation_loop_Animation_DW.TimeStampA_a <
             Navigation_loop_Animation_DW.TimeStampB_n) {
    Navigation_loop_Animation_DW.TimeStampA_a =
      Navigation_loop_Animation_M->Timing.t[0];
    lastU = &Navigation_loop_Animation_DW.LastUAtTimeA_p;
  } else {
    Navigation_loop_Animation_DW.TimeStampB_n =
      Navigation_loop_Animation_M->Timing.t[0];
    lastU = &Navigation_loop_Animation_DW.LastUAtTimeB_l;
  }

  *lastU = Navigation_loop_Animation_B.Derivative;

  /* End of Update for Derivative: '<S5>/Derivative2' */

  /* Update for Derivative: '<S5>/Derivative5' */
  if (Navigation_loop_Animation_DW.TimeStampA_j == (rtInf)) {
    Navigation_loop_Animation_DW.TimeStampA_j =
      Navigation_loop_Animation_M->Timing.t[0];
    lastU = &Navigation_loop_Animation_DW.LastUAtTimeA_g;
  } else if (Navigation_loop_Animation_DW.TimeStampB_a == (rtInf)) {
    Navigation_loop_Animation_DW.TimeStampB_a =
      Navigation_loop_Animation_M->Timing.t[0];
    lastU = &Navigation_loop_Animation_DW.LastUAtTimeB_n;
  } else if (Navigation_loop_Animation_DW.TimeStampA_j <
             Navigation_loop_Animation_DW.TimeStampB_a) {
    Navigation_loop_Animation_DW.TimeStampA_j =
      Navigation_loop_Animation_M->Timing.t[0];
    lastU = &Navigation_loop_Animation_DW.LastUAtTimeA_g;
  } else {
    Navigation_loop_Animation_DW.TimeStampB_a =
      Navigation_loop_Animation_M->Timing.t[0];
    lastU = &Navigation_loop_Animation_DW.LastUAtTimeB_n;
  }

  *lastU = Navigation_loop_Animation_B.Integrator;

  /* End of Update for Derivative: '<S5>/Derivative5' */

  /* Update for Derivative: '<S5>/Derivative1' incorporates:
   *  Constant: '<Root>/Y_desired'
   */
  if (Navigation_loop_Animation_DW.TimeStampA_c == (rtInf)) {
    Navigation_loop_Animation_DW.TimeStampA_c =
      Navigation_loop_Animation_M->Timing.t[0];
    lastU = &Navigation_loop_Animation_DW.LastUAtTimeA_gt;
  } else if (Navigation_loop_Animation_DW.TimeStampB_m == (rtInf)) {
    Navigation_loop_Animation_DW.TimeStampB_m =
      Navigation_loop_Animation_M->Timing.t[0];
    lastU = &Navigation_loop_Animation_DW.LastUAtTimeB_h;
  } else if (Navigation_loop_Animation_DW.TimeStampA_c <
             Navigation_loop_Animation_DW.TimeStampB_m) {
    Navigation_loop_Animation_DW.TimeStampA_c =
      Navigation_loop_Animation_M->Timing.t[0];
    lastU = &Navigation_loop_Animation_DW.LastUAtTimeA_gt;
  } else {
    Navigation_loop_Animation_DW.TimeStampB_m =
      Navigation_loop_Animation_M->Timing.t[0];
    lastU = &Navigation_loop_Animation_DW.LastUAtTimeB_h;
  }

  *lastU = Navigation_loop_Animation_P.Y_desired_Value;

  /* End of Update for Derivative: '<S5>/Derivative1' */

  /* Update for Derivative: '<S5>/Derivative3' */
  if (Navigation_loop_Animation_DW.TimeStampA_e == (rtInf)) {
    Navigation_loop_Animation_DW.TimeStampA_e =
      Navigation_loop_Animation_M->Timing.t[0];
    lastU = &Navigation_loop_Animation_DW.LastUAtTimeA_d;
  } else if (Navigation_loop_Animation_DW.TimeStampB_ap == (rtInf)) {
    Navigation_loop_Animation_DW.TimeStampB_ap =
      Navigation_loop_Animation_M->Timing.t[0];
    lastU = &Navigation_loop_Animation_DW.LastUAtTimeB_f;
  } else if (Navigation_loop_Animation_DW.TimeStampA_e <
             Navigation_loop_Animation_DW.TimeStampB_ap) {
    Navigation_loop_Animation_DW.TimeStampA_e =
      Navigation_loop_Animation_M->Timing.t[0];
    lastU = &Navigation_loop_Animation_DW.LastUAtTimeA_d;
  } else {
    Navigation_loop_Animation_DW.TimeStampB_ap =
      Navigation_loop_Animation_M->Timing.t[0];
    lastU = &Navigation_loop_Animation_DW.LastUAtTimeB_f;
  }

  *lastU = Navigation_loop_Animation_B.Derivative1;

  /* End of Update for Derivative: '<S5>/Derivative3' */

  /* Update for Derivative: '<S5>/Derivative4' */
  if (Navigation_loop_Animation_DW.TimeStampA_ak == (rtInf)) {
    Navigation_loop_Animation_DW.TimeStampA_ak =
      Navigation_loop_Animation_M->Timing.t[0];
    lastU = &Navigation_loop_Animation_DW.LastUAtTimeA_l;
  } else if (Navigation_loop_Animation_DW.TimeStampB_nx == (rtInf)) {
    Navigation_loop_Animation_DW.TimeStampB_nx =
      Navigation_loop_Animation_M->Timing.t[0];
    lastU = &Navigation_loop_Animation_DW.LastUAtTimeB_n5;
  } else if (Navigation_loop_Animation_DW.TimeStampA_ak <
             Navigation_loop_Animation_DW.TimeStampB_nx) {
    Navigation_loop_Animation_DW.TimeStampA_ak =
      Navigation_loop_Animation_M->Timing.t[0];
    lastU = &Navigation_loop_Animation_DW.LastUAtTimeA_l;
  } else {
    Navigation_loop_Animation_DW.TimeStampB_nx =
      Navigation_loop_Animation_M->Timing.t[0];
    lastU = &Navigation_loop_Animation_DW.LastUAtTimeB_n5;
  }

  *lastU = Navigation_loop_Animation_B.Integrator1;

  /* End of Update for Derivative: '<S5>/Derivative4' */
  if (rtmIsMajorTimeStep(Navigation_loop_Animation_M)) {
    rt_ertODEUpdateContinuousStates(&Navigation_loop_Animation_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Navigation_loop_Animation_M->Timing.clockTick0)) {
    ++Navigation_loop_Animation_M->Timing.clockTickH0;
  }

  Navigation_loop_Animation_M->Timing.t[0] = rtsiGetSolverStopTime
    (&Navigation_loop_Animation_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.1s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Navigation_loop_Animation_M->Timing.clockTick1)) {
      ++Navigation_loop_Animation_M->Timing.clockTickH1;
    }

    Navigation_loop_Animation_M->Timing.t[1] =
      Navigation_loop_Animation_M->Timing.clockTick1 *
      Navigation_loop_Animation_M->Timing.stepSize1 +
      Navigation_loop_Animation_M->Timing.clockTickH1 *
      Navigation_loop_Animation_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void Navigation_loop_Animation_derivatives(void)
{
  XDot_Navigation_loop_Animatio_T *_rtXdot;
  _rtXdot = ((XDot_Navigation_loop_Animatio_T *)
             Navigation_loop_Animation_M->ModelData.derivs);

  /* Derivatives for Integrator: '<S2>/Integrator4' */
  _rtXdot->Integrator4_CSTATE = Navigation_loop_Animation_B.pitch_dot;

  /* Derivatives for Integrator: '<S2>/Integrator5' */
  _rtXdot->Integrator5_CSTATE = Navigation_loop_Animation_B.yaw_dot;

  /* Derivatives for Integrator: '<S2>/Integrator3' */
  _rtXdot->Integrator3_CSTATE = Navigation_loop_Animation_B.roll_dot;

  /* Derivatives for Integrator: '<Root>/Integrator' */
  _rtXdot->Integrator_CSTATE = Navigation_loop_Animation_B.Integrator8;

  /* Derivatives for Integrator: '<S2>/Integrator7' */
  _rtXdot->Integrator7_CSTATE = Navigation_loop_Animation_B.Integrator6;

  /* Derivatives for Integrator: '<Root>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = Navigation_loop_Animation_B.Integrator9;

  /* Derivatives for Integrator: '<S5>/Integrator' */
  _rtXdot->Integrator_CSTATE_b = Navigation_loop_Animation_B.Subtract5;

  /* Derivatives for Integrator: '<S5>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_n = Navigation_loop_Animation_B.Subtract4;

  /* Derivatives for Integrator: '<S2>/Integrator' */
  _rtXdot->Integrator_CSTATE_f = Navigation_loop_Animation_B.Divide3;

  /* Derivatives for Integrator: '<S2>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_p = Navigation_loop_Animation_B.Divide4;

  /* Derivatives for Integrator: '<S2>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = Navigation_loop_Animation_B.Divide5;

  /* Derivatives for Integrator: '<S2>/Integrator6' */
  _rtXdot->Integrator6_CSTATE = Navigation_loop_Animation_B.z_dot_dot;

  /* Derivatives for Integrator: '<S2>/Integrator8' */
  _rtXdot->Integrator8_CSTATE = Navigation_loop_Animation_B.x_dot_dot;

  /* Derivatives for Integrator: '<S2>/Integrator9' */
  _rtXdot->Integrator9_CSTATE = Navigation_loop_Animation_B.y_dot_dot;
}

/* Model initialize function */
void Navigation_loop_Animation_initialize(void)
{
  /* InitializeConditions for Integrator: '<S2>/Integrator4' */
  Navigation_loop_Animation_X.Integrator4_CSTATE =
    Navigation_loop_Animation_P.Integrator4_IC;

  /* InitializeConditions for Integrator: '<S2>/Integrator5' */
  Navigation_loop_Animation_X.Integrator5_CSTATE =
    Navigation_loop_Animation_P.Integrator5_IC;

  /* InitializeConditions for Integrator: '<S2>/Integrator3' */
  Navigation_loop_Animation_X.Integrator3_CSTATE =
    Navigation_loop_Animation_P.Integrator3_IC;

  /* InitializeConditions for Integrator: '<Root>/Integrator' */
  Navigation_loop_Animation_X.Integrator_CSTATE =
    Navigation_loop_Animation_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S2>/Integrator7' */
  Navigation_loop_Animation_X.Integrator7_CSTATE =
    Navigation_loop_Animation_P.Integrator7_IC;

  /* InitializeConditions for Integrator: '<Root>/Integrator1' */
  Navigation_loop_Animation_X.Integrator1_CSTATE =
    Navigation_loop_Animation_P.Integrator1_IC;

  /* InitializeConditions for Derivative: '<S5>/Derivative' */
  Navigation_loop_Animation_DW.TimeStampA = (rtInf);
  Navigation_loop_Animation_DW.TimeStampB = (rtInf);

  /* InitializeConditions for Derivative: '<S5>/Derivative2' */
  Navigation_loop_Animation_DW.TimeStampA_a = (rtInf);
  Navigation_loop_Animation_DW.TimeStampB_n = (rtInf);

  /* InitializeConditions for Derivative: '<S5>/Derivative5' */
  Navigation_loop_Animation_DW.TimeStampA_j = (rtInf);
  Navigation_loop_Animation_DW.TimeStampB_a = (rtInf);

  /* InitializeConditions for Integrator: '<S5>/Integrator' */
  Navigation_loop_Animation_X.Integrator_CSTATE_b =
    Navigation_loop_Animation_P.Integrator_IC_l;

  /* InitializeConditions for Derivative: '<S5>/Derivative1' */
  Navigation_loop_Animation_DW.TimeStampA_c = (rtInf);
  Navigation_loop_Animation_DW.TimeStampB_m = (rtInf);

  /* InitializeConditions for Derivative: '<S5>/Derivative3' */
  Navigation_loop_Animation_DW.TimeStampA_e = (rtInf);
  Navigation_loop_Animation_DW.TimeStampB_ap = (rtInf);

  /* InitializeConditions for Derivative: '<S5>/Derivative4' */
  Navigation_loop_Animation_DW.TimeStampA_ak = (rtInf);
  Navigation_loop_Animation_DW.TimeStampB_nx = (rtInf);

  /* InitializeConditions for Integrator: '<S5>/Integrator1' */
  Navigation_loop_Animation_X.Integrator1_CSTATE_n =
    Navigation_loop_Animation_P.Integrator1_IC_g;

  /* InitializeConditions for Integrator: '<S2>/Integrator' */
  Navigation_loop_Animation_X.Integrator_CSTATE_f =
    Navigation_loop_Animation_P.Integrator_IC_c;

  /* InitializeConditions for Integrator: '<S2>/Integrator1' */
  Navigation_loop_Animation_X.Integrator1_CSTATE_p =
    Navigation_loop_Animation_P.Integrator1_IC_a;

  /* InitializeConditions for Integrator: '<S2>/Integrator2' */
  Navigation_loop_Animation_X.Integrator2_CSTATE =
    Navigation_loop_Animation_P.Integrator2_IC;

  /* InitializeConditions for Integrator: '<S2>/Integrator6' */
  Navigation_loop_Animation_X.Integrator6_CSTATE =
    Navigation_loop_Animation_P.Integrator6_IC;

  /* InitializeConditions for Integrator: '<S2>/Integrator8' */
  Navigation_loop_Animation_X.Integrator8_CSTATE =
    Navigation_loop_Animation_P.Integrator8_IC;

  /* InitializeConditions for Integrator: '<S2>/Integrator9' */
  Navigation_loop_Animation_X.Integrator9_CSTATE =
    Navigation_loop_Animation_P.Integrator9_IC;
}

/* Model terminate function */
void Navigation_loop_Animation_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  Navigation_loop_Animation_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Navigation_loop_Animation_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  Navigation_loop_Animation_initialize();
}

void MdlTerminate(void)
{
  Navigation_loop_Animation_terminate();
}

/* Registration function */
RT_MODEL_Navigation_loop_Anim_T *Navigation_loop_Animation(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Navigation_loop_Animation_M, 0,
                sizeof(RT_MODEL_Navigation_loop_Anim_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Navigation_loop_Animation_M->solverInfo,
                          &Navigation_loop_Animation_M->Timing.simTimeStep);
    rtsiSetTPtr(&Navigation_loop_Animation_M->solverInfo, &rtmGetTPtr
                (Navigation_loop_Animation_M));
    rtsiSetStepSizePtr(&Navigation_loop_Animation_M->solverInfo,
                       &Navigation_loop_Animation_M->Timing.stepSize0);
    rtsiSetdXPtr(&Navigation_loop_Animation_M->solverInfo,
                 &Navigation_loop_Animation_M->ModelData.derivs);
    rtsiSetContStatesPtr(&Navigation_loop_Animation_M->solverInfo, (real_T **)
                         &Navigation_loop_Animation_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&Navigation_loop_Animation_M->solverInfo,
      &Navigation_loop_Animation_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&Navigation_loop_Animation_M->solverInfo,
                          (&rtmGetErrorStatus(Navigation_loop_Animation_M)));
    rtsiSetRTModelPtr(&Navigation_loop_Animation_M->solverInfo,
                      Navigation_loop_Animation_M);
  }

  rtsiSetSimTimeStep(&Navigation_loop_Animation_M->solverInfo, MAJOR_TIME_STEP);
  Navigation_loop_Animation_M->ModelData.intgData.y =
    Navigation_loop_Animation_M->ModelData.odeY;
  Navigation_loop_Animation_M->ModelData.intgData.f[0] =
    Navigation_loop_Animation_M->ModelData.odeF[0];
  Navigation_loop_Animation_M->ModelData.intgData.f[1] =
    Navigation_loop_Animation_M->ModelData.odeF[1];
  Navigation_loop_Animation_M->ModelData.intgData.f[2] =
    Navigation_loop_Animation_M->ModelData.odeF[2];
  Navigation_loop_Animation_M->ModelData.contStates = ((real_T *)
    &Navigation_loop_Animation_X);
  rtsiSetSolverData(&Navigation_loop_Animation_M->solverInfo, (void *)
                    &Navigation_loop_Animation_M->ModelData.intgData);
  rtsiSetSolverName(&Navigation_loop_Animation_M->solverInfo,"ode3");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Navigation_loop_Animation_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    Navigation_loop_Animation_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Navigation_loop_Animation_M->Timing.sampleTimes =
      (&Navigation_loop_Animation_M->Timing.sampleTimesArray[0]);
    Navigation_loop_Animation_M->Timing.offsetTimes =
      (&Navigation_loop_Animation_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Navigation_loop_Animation_M->Timing.sampleTimes[0] = (0.0);
    Navigation_loop_Animation_M->Timing.sampleTimes[1] = (0.1);

    /* task offsets */
    Navigation_loop_Animation_M->Timing.offsetTimes[0] = (0.0);
    Navigation_loop_Animation_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(Navigation_loop_Animation_M,
             &Navigation_loop_Animation_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Navigation_loop_Animation_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    Navigation_loop_Animation_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Navigation_loop_Animation_M, 20.0);
  Navigation_loop_Animation_M->Timing.stepSize0 = 0.1;
  Navigation_loop_Animation_M->Timing.stepSize1 = 0.1;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    Navigation_loop_Animation_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(Navigation_loop_Animation_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(Navigation_loop_Animation_M->rtwLogInfo, (NULL));
    rtliSetLogT(Navigation_loop_Animation_M->rtwLogInfo, "tout");
    rtliSetLogX(Navigation_loop_Animation_M->rtwLogInfo, "");
    rtliSetLogXFinal(Navigation_loop_Animation_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Navigation_loop_Animation_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Navigation_loop_Animation_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(Navigation_loop_Animation_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(Navigation_loop_Animation_M->rtwLogInfo, 1);
    rtliSetLogY(Navigation_loop_Animation_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(Navigation_loop_Animation_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(Navigation_loop_Animation_M->rtwLogInfo, (NULL));
  }

  Navigation_loop_Animation_M->solverInfoPtr =
    (&Navigation_loop_Animation_M->solverInfo);
  Navigation_loop_Animation_M->Timing.stepSize = (0.1);
  rtsiSetFixedStepSize(&Navigation_loop_Animation_M->solverInfo, 0.1);
  rtsiSetSolverMode(&Navigation_loop_Animation_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Navigation_loop_Animation_M->ModelData.blockIO = ((void *)
    &Navigation_loop_Animation_B);
  (void) memset(((void *) &Navigation_loop_Animation_B), 0,
                sizeof(B_Navigation_loop_Animation_T));

  /* parameters */
  Navigation_loop_Animation_M->ModelData.defaultParam = ((real_T *)
    &Navigation_loop_Animation_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &Navigation_loop_Animation_X;
    Navigation_loop_Animation_M->ModelData.contStates = (x);
    (void) memset((void *)&Navigation_loop_Animation_X, 0,
                  sizeof(X_Navigation_loop_Animation_T));
  }

  /* states (dwork) */
  Navigation_loop_Animation_M->ModelData.dwork = ((void *)
    &Navigation_loop_Animation_DW);
  (void) memset((void *)&Navigation_loop_Animation_DW, 0,
                sizeof(DW_Navigation_loop_Animation_T));

  /* Initialize Sizes */
  Navigation_loop_Animation_M->Sizes.numContStates = (14);/* Number of continuous states */
  Navigation_loop_Animation_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  Navigation_loop_Animation_M->Sizes.numY = (0);/* Number of model outputs */
  Navigation_loop_Animation_M->Sizes.numU = (0);/* Number of model inputs */
  Navigation_loop_Animation_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Navigation_loop_Animation_M->Sizes.numSampTimes = (2);/* Number of sample times */
  Navigation_loop_Animation_M->Sizes.numBlocks = (190);/* Number of blocks */
  Navigation_loop_Animation_M->Sizes.numBlockIO = (33);/* Number of block outputs */
  Navigation_loop_Animation_M->Sizes.numBlockPrms = (67);/* Sum of parameter "widths" */
  return Navigation_loop_Animation_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/

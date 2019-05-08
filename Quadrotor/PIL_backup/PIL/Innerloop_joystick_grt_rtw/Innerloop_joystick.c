/*
 * Innerloop_joystick.c
 *
 * Code generation for model "Innerloop_joystick".
 *
 * Model version              : 1.123
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Mon Nov 07 09:34:22 2016
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Innerloop_joystick.h"
#include "Innerloop_joystick_private.h"

/* Block signals (auto storage) */
B_Innerloop_joystick_T Innerloop_joystick_B;

/* Continuous states */
X_Innerloop_joystick_T Innerloop_joystick_X;

/* Block states (auto storage) */
DW_Innerloop_joystick_T Innerloop_joystick_DW;

/* External inputs (root inport signals with auto storage) */
ExtU_Innerloop_joystick_T Innerloop_joystick_U;

/* Real-time model */
RT_MODEL_Innerloop_joystick_T Innerloop_joystick_M_;
RT_MODEL_Innerloop_joystick_T *const Innerloop_joystick_M =
  &Innerloop_joystick_M_;

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
  Innerloop_joystick_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  Innerloop_joystick_step();
  Innerloop_joystick_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  Innerloop_joystick_step();
  Innerloop_joystick_derivatives();

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

/* Model step function */
void Innerloop_joystick_step(void)
{
  real_T rtb_Fcn;
  real_T rtb_Divide;
  real_T rtb_Saturation;
  real_T rtb_sinpitch;
  real_T rtb_cosyaw;
  real_T rtb_cosroll;
  real_T rtb_sinyaw;
  real_T rtb_sinroll;
  if (rtmIsMajorTimeStep(Innerloop_joystick_M)) {
    /* set solver stop time */
    if (!(Innerloop_joystick_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Innerloop_joystick_M->solverInfo,
                            ((Innerloop_joystick_M->Timing.clockTickH0 + 1) *
        Innerloop_joystick_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Innerloop_joystick_M->solverInfo,
                            ((Innerloop_joystick_M->Timing.clockTick0 + 1) *
        Innerloop_joystick_M->Timing.stepSize0 +
        Innerloop_joystick_M->Timing.clockTickH0 *
        Innerloop_joystick_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Innerloop_joystick_M)) {
    Innerloop_joystick_M->Timing.t[0] = rtsiGetT
      (&Innerloop_joystick_M->solverInfo);
  }

  /* Integrator: '<Root>/Integrator' */
  Innerloop_joystick_B.Integrator = Innerloop_joystick_X.Integrator_CSTATE;
  if (rtmIsMajorTimeStep(Innerloop_joystick_M)) {
  }

  /* Integrator: '<Root>/Integrator1' */
  Innerloop_joystick_B.Integrator1 = Innerloop_joystick_X.Integrator1_CSTATE;
  if (rtmIsMajorTimeStep(Innerloop_joystick_M)) {
  }

  /* Integrator: '<S1>/Integrator7' */
  Innerloop_joystick_B.Integrator7 = Innerloop_joystick_X.Integrator7_CSTATE;

  /* Saturate: '<Root>/Saturation1' incorporates:
   *  Integrator: '<Root>/Integrator3'
   */
  if (Innerloop_joystick_X.Integrator3_CSTATE >
      Innerloop_joystick_P.Saturation1_UpperSat) {
    Innerloop_joystick_B.Saturation1 = Innerloop_joystick_P.Saturation1_UpperSat;
  } else if (Innerloop_joystick_X.Integrator3_CSTATE <
             Innerloop_joystick_P.Saturation1_LowerSat) {
    Innerloop_joystick_B.Saturation1 = Innerloop_joystick_P.Saturation1_LowerSat;
  } else {
    Innerloop_joystick_B.Saturation1 = Innerloop_joystick_X.Integrator3_CSTATE;
  }

  /* End of Saturate: '<Root>/Saturation1' */
  if (rtmIsMajorTimeStep(Innerloop_joystick_M)) {
  }

  /* Gain: '<Root>/Gain2' incorporates:
   *  Integrator: '<S1>/Integrator4'
   */
  Innerloop_joystick_B.Gain2 = Innerloop_joystick_P.Gain2_Gain *
    Innerloop_joystick_X.Integrator4_CSTATE;

  /* Fcn: '<Root>/Fcn' incorporates:
   *  Inport: '<Root>/In1'
   */
  rtb_Fcn = ((Innerloop_joystick_U.In1 + 0.832) * 43.42 - 35.0) / 57.3;

  /* Gain: '<Root>/Gain3' */
  Innerloop_joystick_B.Gain3 = Innerloop_joystick_P.Gain3_Gain * rtb_Fcn;
  if (rtmIsMajorTimeStep(Innerloop_joystick_M)) {
  }

  /* Gain: '<Root>/Gain' incorporates:
   *  Integrator: '<S1>/Integrator3'
   */
  Innerloop_joystick_B.Gain = Innerloop_joystick_P.Gain_Gain *
    Innerloop_joystick_X.Integrator3_CSTATE_a;

  /* Fcn: '<Root>/Fcn1' incorporates:
   *  Inport: '<Root>/In5'
   */
  rtb_Divide = ((Innerloop_joystick_U.In5 + 0.965) * 38.48 - 35.0) / 57.3;

  /* Gain: '<Root>/Gain1' */
  Innerloop_joystick_B.Gain1 = Innerloop_joystick_P.Gain1_Gain * rtb_Divide;
  if (rtmIsMajorTimeStep(Innerloop_joystick_M)) {
  }

  /* Gain: '<Root>/Gain5' incorporates:
   *  Integrator: '<S1>/Integrator5'
   */
  Innerloop_joystick_B.Gain5 = Innerloop_joystick_P.Gain5_Gain *
    Innerloop_joystick_X.Integrator5_CSTATE;

  /* Saturate: '<Root>/Saturation' incorporates:
   *  Integrator: '<Root>/Integrator2'
   */
  if (Innerloop_joystick_X.Integrator2_CSTATE >
      Innerloop_joystick_P.Saturation_UpperSat) {
    rtb_Saturation = Innerloop_joystick_P.Saturation_UpperSat;
  } else if (Innerloop_joystick_X.Integrator2_CSTATE <
             Innerloop_joystick_P.Saturation_LowerSat) {
    rtb_Saturation = Innerloop_joystick_P.Saturation_LowerSat;
  } else {
    rtb_Saturation = Innerloop_joystick_X.Integrator2_CSTATE;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* Gain: '<Root>/Gain4' */
  Innerloop_joystick_B.Gain4 = Innerloop_joystick_P.Gain4_Gain * rtb_Saturation;
  if (rtmIsMajorTimeStep(Innerloop_joystick_M)) {
  }

  /* Integrator: '<S1>/Integrator' */
  Innerloop_joystick_B.roll_dot = Innerloop_joystick_X.Integrator_CSTATE_f;

  /* Integrator: '<S1>/Integrator1' */
  Innerloop_joystick_B.pitch_dot = Innerloop_joystick_X.Integrator1_CSTATE_p;

  /* Integrator: '<S1>/Integrator2' */
  Innerloop_joystick_B.yaw_dot = Innerloop_joystick_X.Integrator2_CSTATE_e;

  /* Integrator: '<S1>/Integrator6' */
  Innerloop_joystick_B.Integrator6 = Innerloop_joystick_X.Integrator6_CSTATE;

  /* Integrator: '<S1>/Integrator8' */
  Innerloop_joystick_B.Integrator8 = Innerloop_joystick_X.Integrator8_CSTATE;

  /* Integrator: '<S1>/Integrator9' */
  Innerloop_joystick_B.Integrator9 = Innerloop_joystick_X.Integrator9_CSTATE;

  /* MATLAB Function: '<S1>/MATLAB Function' incorporates:
   *  Integrator: '<S1>/Integrator3'
   *  Integrator: '<S1>/Integrator4'
   *  Integrator: '<S1>/Integrator5'
   */
  /* MATLAB Function 'Dynamic model/MATLAB Function': '<S4>:1' */
  /* '<S4>:1:2' */
  /* '<S4>:1:3' */
  /* '<S4>:1:4' */
  /* '<S4>:1:5' */
  /* '<S4>:1:6' */
  /* '<S4>:1:7' */
  rtb_sinpitch = sin(Innerloop_joystick_X.Integrator4_CSTATE);
  rtb_sinroll = sin(Innerloop_joystick_X.Integrator3_CSTATE_a);
  rtb_cosroll = cos(Innerloop_joystick_X.Integrator3_CSTATE_a);
  rtb_sinyaw = sin(Innerloop_joystick_X.Integrator5_CSTATE);
  rtb_cosyaw = cos(Innerloop_joystick_X.Integrator5_CSTATE);
  if (rtmIsMajorTimeStep(Innerloop_joystick_M)) {
    /* Sum: '<S5>/Add6' incorporates:
     *  Constant: '<S3>/ineretia_yy'
     *  Constant: '<S3>/inertia_zz'
     */
    Innerloop_joystick_B.Add6 = Innerloop_joystick_P.ineretia_yy_Value -
      Innerloop_joystick_P.inertia_zz_Value;
  }

  /* Product: '<S5>/Divide4' incorporates:
   *  Constant: '<S3>/Arm_length_'
   *  Constant: '<S3>/inertia_xx'
   *  Gain: '<S2>/kdt'
   *  Gain: '<S2>/kpt'
   *  Integrator: '<S1>/Integrator4'
   *  Product: '<S5>/Product12'
   *  Product: '<S5>/Product13'
   *  Product: '<S5>/Product9'
   *  Sum: '<S2>/Add6'
   *  Sum: '<S2>/eTheta'
   *  Sum: '<S5>/Add3'
   */
  Innerloop_joystick_B.Divide4 = (((rtb_Fcn -
    Innerloop_joystick_X.Integrator4_CSTATE) * Innerloop_joystick_P.kpt -
    Innerloop_joystick_P.kdt * Innerloop_joystick_B.pitch_dot) *
    Innerloop_joystick_P.Arm_length_Value + Innerloop_joystick_B.roll_dot *
    Innerloop_joystick_B.yaw_dot * Innerloop_joystick_B.Add6) /
    Innerloop_joystick_P.inertia_xx_Value;
  if (rtmIsMajorTimeStep(Innerloop_joystick_M)) {
    /* Sum: '<S6>/Add5' incorporates:
     *  Constant: '<S3>/inertia_xx'
     *  Constant: '<S3>/inertia_zz'
     */
    Innerloop_joystick_B.Add5 = Innerloop_joystick_P.inertia_zz_Value -
      Innerloop_joystick_P.inertia_xx_Value;
  }

  /* Product: '<S6>/Divide3' incorporates:
   *  Constant: '<S3>/Arm_length_'
   *  Constant: '<S3>/ineretia_yy'
   *  Gain: '<S2>/kdp'
   *  Gain: '<S2>/kpp'
   *  Integrator: '<S1>/Integrator3'
   *  Product: '<S6>/Product10'
   *  Product: '<S6>/Product11'
   *  Product: '<S6>/Product8'
   *  Sum: '<S2>/Add5'
   *  Sum: '<S2>/ePhi'
   *  Sum: '<S6>/Add2'
   */
  Innerloop_joystick_B.Divide3 = (((rtb_Divide -
    Innerloop_joystick_X.Integrator3_CSTATE_a) * Innerloop_joystick_P.kpp -
    Innerloop_joystick_P.kdp * Innerloop_joystick_B.roll_dot) *
    Innerloop_joystick_P.Arm_length_Value + Innerloop_joystick_B.pitch_dot *
    Innerloop_joystick_B.yaw_dot * Innerloop_joystick_B.Add5) /
    Innerloop_joystick_P.ineretia_yy_Value;

  /* Product: '<S2>/Divide' incorporates:
   *  Constant: '<S2>/Constant1'
   *  Gain: '<S2>/kdz'
   *  Gain: '<S2>/kpz'
   *  Gain: '<S2>/m'
   *  Integrator: '<S1>/Integrator3'
   *  Integrator: '<S1>/Integrator4'
   *  Product: '<S2>/Product'
   *  Sum: '<S2>/Add2'
   *  Sum: '<S2>/Add4'
   *  Sum: '<S2>/ez'
   *  Trigonometry: '<S2>/cos Phi'
   *  Trigonometry: '<S2>/cos Theta'
   */
  rtb_Divide = (((Innerloop_joystick_B.Saturation1 -
                  Innerloop_joystick_B.Integrator7) * Innerloop_joystick_P.kpz -
                 Innerloop_joystick_P.kdz * Innerloop_joystick_B.Integrator6) +
                Innerloop_joystick_P.Constant1_Value) *
    Innerloop_joystick_P.m_Gain / (cos(Innerloop_joystick_X.Integrator3_CSTATE_a)
    * cos(Innerloop_joystick_X.Integrator4_CSTATE));

  /* Product: '<S7>/Divide' incorporates:
   *  Constant: '<S3>/mass'
   *  Product: '<S7>/Product1'
   *  Product: '<S7>/Product2'
   *  Product: '<S7>/Product3'
   *  Sum: '<S7>/Add'
   */
  Innerloop_joystick_B.x_dot_dot = (rtb_sinpitch * rtb_cosyaw * rtb_cosroll +
    rtb_sinyaw * rtb_sinroll) * rtb_Divide / Innerloop_joystick_P.mass_Value;

  /* Product: '<S8>/Divide1' incorporates:
   *  Constant: '<S3>/mass'
   *  Product: '<S8>/Product5'
   *  Product: '<S8>/Product6'
   *  Product: '<S8>/Product7'
   *  Sum: '<S8>/Add1'
   */
  Innerloop_joystick_B.y_dot_dot = (rtb_sinyaw * rtb_sinpitch * rtb_cosroll -
    rtb_sinroll * rtb_cosyaw) * rtb_Divide / Innerloop_joystick_P.mass_Value;
  if (rtmIsMajorTimeStep(Innerloop_joystick_M)) {
    /* Sum: '<S9>/Add8' incorporates:
     *  Constant: '<S3>/ineretia_yy'
     *  Constant: '<S3>/inertia_xx'
     */
    Innerloop_joystick_B.Add8 = Innerloop_joystick_P.inertia_xx_Value -
      Innerloop_joystick_P.ineretia_yy_Value;
  }

  /* Product: '<S9>/Divide5' incorporates:
   *  Constant: '<S3>/inertia_zz'
   *  Gain: '<S2>/kdps'
   *  Gain: '<S2>/kpps'
   *  Integrator: '<S1>/Integrator5'
   *  Product: '<S9>/Product14'
   *  Product: '<S9>/Product15'
   *  Sum: '<S2>/Add7'
   *  Sum: '<S2>/ePsi'
   *  Sum: '<S9>/Add7'
   */
  Innerloop_joystick_B.Divide5 = (((rtb_Saturation -
    Innerloop_joystick_X.Integrator5_CSTATE) * Innerloop_joystick_P.kpps -
    Innerloop_joystick_P.kdps * Innerloop_joystick_B.yaw_dot) +
    Innerloop_joystick_B.pitch_dot * Innerloop_joystick_B.roll_dot *
    Innerloop_joystick_B.Add8) / Innerloop_joystick_P.inertia_zz_Value;

  /* Sum: '<S10>/Add4' incorporates:
   *  Constant: '<S10>/u5'
   *  Constant: '<S3>/mass'
   *  Integrator: '<S1>/Integrator4'
   *  MATLAB Function: '<S1>/MATLAB Function'
   *  Product: '<S10>/Divide2'
   *  Product: '<S10>/Product'
   *  Product: '<S10>/Product4'
   */
  Innerloop_joystick_B.z_dot_dot = cos(Innerloop_joystick_X.Integrator4_CSTATE) *
    rtb_cosroll * rtb_Divide / Innerloop_joystick_P.mass_Value -
    Innerloop_joystick_P.u5_Value;

  /* Fcn: '<Root>/Fcn2' incorporates:
   *  Inport: '<Root>/In2'
   */
  Innerloop_joystick_B.Fcn2 = ((Innerloop_joystick_U.In2 + 0.956) * 21.61 - 20.0)
    / 57.3;

  /* Fcn: '<Root>/Fcn3' incorporates:
   *  Inport: '<Root>/In4'
   */
  Innerloop_joystick_B.Fcn3 = 14.81 * Innerloop_joystick_U.In4 / 1.17;
  if (rtmIsMajorTimeStep(Innerloop_joystick_M)) {
  }

  if (rtmIsMajorTimeStep(Innerloop_joystick_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(Innerloop_joystick_M->rtwLogInfo,
                        (Innerloop_joystick_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(Innerloop_joystick_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(Innerloop_joystick_M)!=-1) &&
          !((rtmGetTFinal(Innerloop_joystick_M)-
             (((Innerloop_joystick_M->Timing.clockTick1+
                Innerloop_joystick_M->Timing.clockTickH1* 4294967296.0)) * 2.0))
            > (((Innerloop_joystick_M->Timing.clockTick1+
                 Innerloop_joystick_M->Timing.clockTickH1* 4294967296.0)) * 2.0)
            * (DBL_EPSILON))) {
        rtmSetErrorStatus(Innerloop_joystick_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&Innerloop_joystick_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Innerloop_joystick_M->Timing.clockTick0)) {
      ++Innerloop_joystick_M->Timing.clockTickH0;
    }

    Innerloop_joystick_M->Timing.t[0] = rtsiGetSolverStopTime
      (&Innerloop_joystick_M->solverInfo);

    {
      /* Update absolute timer for sample time: [2.0s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 2.0, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      Innerloop_joystick_M->Timing.clockTick1++;
      if (!Innerloop_joystick_M->Timing.clockTick1) {
        Innerloop_joystick_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void Innerloop_joystick_derivatives(void)
{
  XDot_Innerloop_joystick_T *_rtXdot;
  _rtXdot = ((XDot_Innerloop_joystick_T *)
             Innerloop_joystick_M->ModelData.derivs);

  /* Derivatives for Integrator: '<Root>/Integrator' */
  _rtXdot->Integrator_CSTATE = Innerloop_joystick_B.Integrator8;

  /* Derivatives for Integrator: '<Root>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = Innerloop_joystick_B.Integrator9;

  /* Derivatives for Integrator: '<S1>/Integrator7' */
  _rtXdot->Integrator7_CSTATE = Innerloop_joystick_B.Integrator6;

  /* Derivatives for Integrator: '<Root>/Integrator3' */
  _rtXdot->Integrator3_CSTATE = Innerloop_joystick_B.Fcn3;

  /* Derivatives for Integrator: '<S1>/Integrator4' */
  _rtXdot->Integrator4_CSTATE = Innerloop_joystick_B.pitch_dot;

  /* Derivatives for Integrator: '<S1>/Integrator3' */
  _rtXdot->Integrator3_CSTATE_a = Innerloop_joystick_B.roll_dot;

  /* Derivatives for Integrator: '<S1>/Integrator5' */
  _rtXdot->Integrator5_CSTATE = Innerloop_joystick_B.yaw_dot;

  /* Derivatives for Integrator: '<Root>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = Innerloop_joystick_B.Fcn2;

  /* Derivatives for Integrator: '<S1>/Integrator' */
  _rtXdot->Integrator_CSTATE_f = Innerloop_joystick_B.Divide3;

  /* Derivatives for Integrator: '<S1>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_p = Innerloop_joystick_B.Divide4;

  /* Derivatives for Integrator: '<S1>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_e = Innerloop_joystick_B.Divide5;

  /* Derivatives for Integrator: '<S1>/Integrator6' */
  _rtXdot->Integrator6_CSTATE = Innerloop_joystick_B.z_dot_dot;

  /* Derivatives for Integrator: '<S1>/Integrator8' */
  _rtXdot->Integrator8_CSTATE = Innerloop_joystick_B.x_dot_dot;

  /* Derivatives for Integrator: '<S1>/Integrator9' */
  _rtXdot->Integrator9_CSTATE = Innerloop_joystick_B.y_dot_dot;
}

/* Model initialize function */
void Innerloop_joystick_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Innerloop_joystick_M, 0,
                sizeof(RT_MODEL_Innerloop_joystick_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Innerloop_joystick_M->solverInfo,
                          &Innerloop_joystick_M->Timing.simTimeStep);
    rtsiSetTPtr(&Innerloop_joystick_M->solverInfo, &rtmGetTPtr
                (Innerloop_joystick_M));
    rtsiSetStepSizePtr(&Innerloop_joystick_M->solverInfo,
                       &Innerloop_joystick_M->Timing.stepSize0);
    rtsiSetdXPtr(&Innerloop_joystick_M->solverInfo,
                 &Innerloop_joystick_M->ModelData.derivs);
    rtsiSetContStatesPtr(&Innerloop_joystick_M->solverInfo, (real_T **)
                         &Innerloop_joystick_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&Innerloop_joystick_M->solverInfo,
      &Innerloop_joystick_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&Innerloop_joystick_M->solverInfo, (&rtmGetErrorStatus
      (Innerloop_joystick_M)));
    rtsiSetRTModelPtr(&Innerloop_joystick_M->solverInfo, Innerloop_joystick_M);
  }

  rtsiSetSimTimeStep(&Innerloop_joystick_M->solverInfo, MAJOR_TIME_STEP);
  Innerloop_joystick_M->ModelData.intgData.y =
    Innerloop_joystick_M->ModelData.odeY;
  Innerloop_joystick_M->ModelData.intgData.f[0] =
    Innerloop_joystick_M->ModelData.odeF[0];
  Innerloop_joystick_M->ModelData.intgData.f[1] =
    Innerloop_joystick_M->ModelData.odeF[1];
  Innerloop_joystick_M->ModelData.intgData.f[2] =
    Innerloop_joystick_M->ModelData.odeF[2];
  Innerloop_joystick_M->ModelData.contStates = ((X_Innerloop_joystick_T *)
    &Innerloop_joystick_X);
  rtsiSetSolverData(&Innerloop_joystick_M->solverInfo, (void *)
                    &Innerloop_joystick_M->ModelData.intgData);
  rtsiSetSolverName(&Innerloop_joystick_M->solverInfo,"ode3");
  rtmSetTPtr(Innerloop_joystick_M, &Innerloop_joystick_M->Timing.tArray[0]);
  rtmSetTFinal(Innerloop_joystick_M, 100.0);
  Innerloop_joystick_M->Timing.stepSize0 = 2.0;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    Innerloop_joystick_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(Innerloop_joystick_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(Innerloop_joystick_M->rtwLogInfo, (NULL));
    rtliSetLogT(Innerloop_joystick_M->rtwLogInfo, "tout");
    rtliSetLogX(Innerloop_joystick_M->rtwLogInfo, "");
    rtliSetLogXFinal(Innerloop_joystick_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Innerloop_joystick_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Innerloop_joystick_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(Innerloop_joystick_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(Innerloop_joystick_M->rtwLogInfo, 1);
    rtliSetLogY(Innerloop_joystick_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(Innerloop_joystick_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(Innerloop_joystick_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &Innerloop_joystick_B), 0,
                sizeof(B_Innerloop_joystick_T));

  /* states (continuous) */
  {
    (void) memset((void *)&Innerloop_joystick_X, 0,
                  sizeof(X_Innerloop_joystick_T));
  }

  /* states (dwork) */
  (void) memset((void *)&Innerloop_joystick_DW, 0,
                sizeof(DW_Innerloop_joystick_T));

  /* external inputs */
  (void) memset((void *)&Innerloop_joystick_U, 0,
                sizeof(ExtU_Innerloop_joystick_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(Innerloop_joystick_M->rtwLogInfo, 0.0,
    rtmGetTFinal(Innerloop_joystick_M), Innerloop_joystick_M->Timing.stepSize0,
    (&rtmGetErrorStatus(Innerloop_joystick_M)));

  /* InitializeConditions for Integrator: '<Root>/Integrator' */
  Innerloop_joystick_X.Integrator_CSTATE = Innerloop_joystick_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<Root>/Integrator1' */
  Innerloop_joystick_X.Integrator1_CSTATE = Innerloop_joystick_P.Integrator1_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator7' */
  Innerloop_joystick_X.Integrator7_CSTATE = Innerloop_joystick_P.Integrator7_IC;

  /* InitializeConditions for Integrator: '<Root>/Integrator3' */
  Innerloop_joystick_X.Integrator3_CSTATE = Innerloop_joystick_P.Integrator3_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator4' */
  Innerloop_joystick_X.Integrator4_CSTATE = Innerloop_joystick_P.Integrator4_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator3' */
  Innerloop_joystick_X.Integrator3_CSTATE_a =
    Innerloop_joystick_P.Integrator3_IC_o;

  /* InitializeConditions for Integrator: '<S1>/Integrator5' */
  Innerloop_joystick_X.Integrator5_CSTATE = Innerloop_joystick_P.Integrator5_IC;

  /* InitializeConditions for Integrator: '<Root>/Integrator2' */
  Innerloop_joystick_X.Integrator2_CSTATE = Innerloop_joystick_P.Integrator2_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator' */
  Innerloop_joystick_X.Integrator_CSTATE_f =
    Innerloop_joystick_P.Integrator_IC_c;

  /* InitializeConditions for Integrator: '<S1>/Integrator1' */
  Innerloop_joystick_X.Integrator1_CSTATE_p =
    Innerloop_joystick_P.Integrator1_IC_a;

  /* InitializeConditions for Integrator: '<S1>/Integrator2' */
  Innerloop_joystick_X.Integrator2_CSTATE_e =
    Innerloop_joystick_P.Integrator2_IC_p;

  /* InitializeConditions for Integrator: '<S1>/Integrator6' */
  Innerloop_joystick_X.Integrator6_CSTATE = Innerloop_joystick_P.Integrator6_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator8' */
  Innerloop_joystick_X.Integrator8_CSTATE = Innerloop_joystick_P.Integrator8_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator9' */
  Innerloop_joystick_X.Integrator9_CSTATE = Innerloop_joystick_P.Integrator9_IC;
}

/* Model terminate function */
void Innerloop_joystick_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * Innerloop_joystick_data.c
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

/* Block parameters (auto storage) */
P_Innerloop_joystick_T Innerloop_joystick_P = {
  0.4,                                 /* Variable: kdp
                                        * Referenced by: '<S2>/kdp'
                                        */
  0.4,                                 /* Variable: kdps
                                        * Referenced by: '<S2>/kdps'
                                        */
  0.4,                                 /* Variable: kdt
                                        * Referenced by: '<S2>/kdt'
                                        */
  20.0,                                /* Variable: kdz
                                        * Referenced by: '<S2>/kdz'
                                        */
  0.8,                                 /* Variable: kpp
                                        * Referenced by: '<S2>/kpp'
                                        */
  1.0,                                 /* Variable: kpps
                                        * Referenced by: '<S2>/kpps'
                                        */
  1.2,                                 /* Variable: kpt
                                        * Referenced by: '<S2>/kpt'
                                        */
  100.0,                               /* Variable: kpz
                                        * Referenced by: '<S2>/kpz'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Integrator1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Integrator7'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Integrator3'
                                        */
  100.0,                               /* Expression: 100
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Integrator4'
                                        */
  57.3,                                /* Expression: 57.3
                                        * Referenced by: '<Root>/Gain2'
                                        */
  57.3,                                /* Expression: 57.3
                                        * Referenced by: '<Root>/Gain3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Integrator3'
                                        */
  57.3,                                /* Expression: 57.3
                                        * Referenced by: '<Root>/Gain'
                                        */
  57.3,                                /* Expression: 57.3
                                        * Referenced by: '<Root>/Gain1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Integrator5'
                                        */
  57.3,                                /* Expression: 57.3
                                        * Referenced by: '<Root>/Gain5'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Integrator2'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<Root>/Saturation'
                                        */
  -3.1415926535897931,                 /* Expression: -pi
                                        * Referenced by: '<Root>/Saturation'
                                        */
  57.3,                                /* Expression: 57.3
                                        * Referenced by: '<Root>/Gain4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Integrator1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Integrator2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Integrator6'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Integrator8'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Integrator9'
                                        */
  0.228,                               /* Expression: 0.228
                                        * Referenced by: '<S3>/Arm_length_'
                                        */
  0.00025955,                          /* Expression: 2.5955e-4
                                        * Referenced by: '<S3>/ineretia_yy'
                                        */
  5.7824E-5,                           /* Expression: 5.7824e-5
                                        * Referenced by: '<S3>/inertia_zz'
                                        */
  0.0002754,                           /* Expression: 2.754e-4
                                        * Referenced by: '<S3>/inertia_xx'
                                        */
  9.8,                                 /* Expression: 9.8
                                        * Referenced by: '<S2>/Constant1'
                                        */
  1.17,                                /* Expression: 1.17
                                        * Referenced by: '<S2>/m'
                                        */
  1.17,                                /* Expression: 1.17
                                        * Referenced by: '<S3>/mass'
                                        */
  9.8                                  /* Expression: 9.8
                                        * Referenced by: '<S10>/u5'
                                        */
};

/*
 * Navigation_loop_Animation_data.c
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

/* Block parameters (auto storage) */
P_Navigation_loop_Animation_T Navigation_loop_Animation_P = {
  9.8,                                 /* Variable: g
                                        * Referenced by:
                                        *   '<S5>/Gain'
                                        *   '<S5>/Gain1'
                                        */
  0.4,                                 /* Variable: kdp
                                        * Referenced by: '<S4>/kdp'
                                        */
  0.4,                                 /* Variable: kdps
                                        * Referenced by: '<S4>/kdps'
                                        */
  0.4,                                 /* Variable: kdt
                                        * Referenced by: '<S4>/kdt'
                                        */
  1.3,                                 /* Variable: kdx
                                        * Referenced by: '<S5>/Gain3'
                                        */
  1.3,                                 /* Variable: kdy
                                        * Referenced by: '<S5>/Gain5'
                                        */
  2.0,                                 /* Variable: kdz
                                        * Referenced by: '<S4>/kdz'
                                        */
  0.0001,                              /* Variable: kix
                                        * Referenced by: '<S5>/Gain6'
                                        */
  0.0003,                              /* Variable: kiy
                                        * Referenced by: '<S5>/Gain7'
                                        */
  0.8,                                 /* Variable: kpp
                                        * Referenced by: '<S4>/kpp'
                                        */
  1.0,                                 /* Variable: kpps
                                        * Referenced by: '<S4>/kpps'
                                        */
  1.2,                                 /* Variable: kpt
                                        * Referenced by: '<S4>/kpt'
                                        */
  0.8,                                 /* Variable: kpx
                                        * Referenced by: '<S5>/Gain2'
                                        */
  0.8,                                 /* Variable: kpy
                                        * Referenced by: '<S5>/Gain4'
                                        */
  1.2,                                 /* Variable: kpz
                                        * Referenced by: '<S4>/kpz'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Integrator4'
                                        */
  0.5,                                 /* Expression: 1/2
                                        * Referenced by: '<S17>/1//2'
                                        */

  /*  Expression: [1 0 0]
   * Referenced by: '<S3>/Vr Roll Axes'
   */
  { 1.0, 0.0, 0.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Integrator5'
                                        */
  0.5,                                 /* Expression: 1/2
                                        * Referenced by: '<S19>/1//2'
                                        */

  /*  Expression: [0 -1 0]
   * Referenced by: '<S3>/Vr Yaw Axes'
   */
  { 0.0, -1.0, 0.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Integrator3'
                                        */
  0.5,                                 /* Expression: 1/2
                                        * Referenced by: '<S18>/1//2'
                                        */

  /*  Expression: [0 0 1]
   * Referenced by: '<S3>/Vr Pitch Axes'
   */
  { 0.0, 0.0, 1.0 },
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S14>/2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Integrator7'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<Root>/Gain6'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S1>/rad-->deg1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Integrator1'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S1>/rad-->deg'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<Root>/X_desired'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<Root>/Y_desired'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<Root>/Z_desired'
                                        */
  57.3,                                /* Expression: 57.3
                                        * Referenced by: '<Root>/Gain2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/yaw_desired'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/Integrator1'
                                        */
  0.61082024432809778,                 /* Expression: 35/57.3
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  -0.61082024432809778,                /* Expression: -35/57.3
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  57.3,                                /* Expression: 57.3
                                        * Referenced by: '<Root>/Gain3'
                                        */
  57.3,                                /* Expression: 57.3
                                        * Referenced by: '<Root>/Gain'
                                        */
  0.61082024432809778,                 /* Expression: 35/57.3
                                        * Referenced by: '<Root>/Saturation'
                                        */
  -0.61082024432809778,                /* Expression: -35/57.3
                                        * Referenced by: '<Root>/Saturation'
                                        */
  57.3,                                /* Expression: 57.3
                                        * Referenced by: '<Root>/Gain1'
                                        */
  57.3,                                /* Expression: 57.3
                                        * Referenced by: '<Root>/Gain5'
                                        */
  57.3,                                /* Expression: 57.3
                                        * Referenced by: '<Root>/Gain4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Integrator1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Integrator2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Integrator6'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Integrator8'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Integrator9'
                                        */
  0.228,                               /* Expression: 0.228
                                        * Referenced by: '<S6>/Arm_length_'
                                        */
  0.00025955,                          /* Expression: 2.5955e-4
                                        * Referenced by: '<S6>/ineretia_yy'
                                        */
  5.7824E-5,                           /* Expression: 5.7824e-5
                                        * Referenced by: '<S6>/inertia_zz'
                                        */
  0.0002754,                           /* Expression: 2.754e-4
                                        * Referenced by: '<S6>/inertia_xx'
                                        */
  9.8,                                 /* Expression: 9.8
                                        * Referenced by: '<S4>/Constant1'
                                        */
  1.17,                                /* Expression: 1.17
                                        * Referenced by: '<S4>/m'
                                        */
  1.17,                                /* Expression: 1.17
                                        * Referenced by: '<S6>/mass'
                                        */
  9.8                                  /* Expression: 9.8
                                        * Referenced by: '<S13>/u5'
                                        */
};

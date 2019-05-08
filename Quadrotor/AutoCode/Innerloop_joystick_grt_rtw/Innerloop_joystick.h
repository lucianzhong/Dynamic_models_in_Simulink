/*
 * Innerloop_joystick.h
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

#ifndef RTW_HEADER_Innerloop_joystick_h_
#define RTW_HEADER_Innerloop_joystick_h_
#include <math.h>
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef Innerloop_joystick_COMMON_INCLUDES_
# define Innerloop_joystick_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* Innerloop_joystick_COMMON_INCLUDES_ */

#include "Innerloop_joystick_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->ModelData.blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->ModelData.blkStateChange = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->ModelData.contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->ModelData.contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->ModelData.contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->ModelData.contStates = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->ModelData.intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->ModelData.intgData = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->ModelData.odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->ModelData.odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->ModelData.odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->ModelData.odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->ModelData.periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->ModelData.periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->ModelData.periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->ModelData.periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->ModelData.derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->ModelData.derivs = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T Integrator;                   /* '<Root>/Integrator' */
  real_T Integrator1;                  /* '<Root>/Integrator1' */
  real_T Integrator7;                  /* '<S1>/Integrator7' */
  real_T Saturation1;                  /* '<Root>/Saturation1' */
  real_T Gain2;                        /* '<Root>/Gain2' */
  real_T Gain3;                        /* '<Root>/Gain3' */
  real_T Gain;                         /* '<Root>/Gain' */
  real_T Gain1;                        /* '<Root>/Gain1' */
  real_T Gain5;                        /* '<Root>/Gain5' */
  real_T Gain4;                        /* '<Root>/Gain4' */
  real_T roll_dot;                     /* '<S1>/Integrator' */
  real_T pitch_dot;                    /* '<S1>/Integrator1' */
  real_T yaw_dot;                      /* '<S1>/Integrator2' */
  real_T Integrator6;                  /* '<S1>/Integrator6' */
  real_T Integrator8;                  /* '<S1>/Integrator8' */
  real_T Integrator9;                  /* '<S1>/Integrator9' */
  real_T Add6;                         /* '<S5>/Add6' */
  real_T Divide4;                      /* '<S5>/Divide4' */
  real_T Add5;                         /* '<S6>/Add5' */
  real_T Divide3;                      /* '<S6>/Divide3' */
  real_T x_dot_dot;                    /* '<S7>/Divide' */
  real_T y_dot_dot;                    /* '<S8>/Divide1' */
  real_T Add8;                         /* '<S9>/Add8' */
  real_T Divide5;                      /* '<S9>/Divide5' */
  real_T z_dot_dot;                    /* '<S10>/Add4' */
  real_T Fcn2;                         /* '<Root>/Fcn2' */
  real_T Fcn3;                         /* '<Root>/Fcn3' */
} B_Innerloop_joystick_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  struct {
    void *LoggedData;
  } X_PWORK;                           /* '<Root>/X' */

  struct {
    void *LoggedData;
  } Y_PWORK;                           /* '<Root>/Y' */

  struct {
    void *LoggedData;
  } Z_PWORK;                           /* '<Root>/Z' */

  struct {
    void *LoggedData;
  } Z1_PWORK;                          /* '<Root>/Z1' */

  struct {
    void *LoggedData;
  } pitch_angle_PWORK;                 /* '<Root>/pitch_angle' */

  struct {
    void *LoggedData;
  } roll_angle_PWORK;                  /* '<Root>/roll_angle' */

  struct {
    void *LoggedData;
  } yaw_angle_PWORK;                   /* '<Root>/yaw_angle' */

  struct {
    void *LoggedData;
  } _PWORK;                            /* '<Root>/3' */

  struct {
    void *LoggedData;
  } _PWORK_j;                          /* '<Root>/6' */
} DW_Innerloop_joystick_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<Root>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<Root>/Integrator1' */
  real_T Integrator7_CSTATE;           /* '<S1>/Integrator7' */
  real_T Integrator3_CSTATE;           /* '<Root>/Integrator3' */
  real_T Integrator4_CSTATE;           /* '<S1>/Integrator4' */
  real_T Integrator3_CSTATE_a;         /* '<S1>/Integrator3' */
  real_T Integrator5_CSTATE;           /* '<S1>/Integrator5' */
  real_T Integrator2_CSTATE;           /* '<Root>/Integrator2' */
  real_T Integrator_CSTATE_f;          /* '<S1>/Integrator' */
  real_T Integrator1_CSTATE_p;         /* '<S1>/Integrator1' */
  real_T Integrator2_CSTATE_e;         /* '<S1>/Integrator2' */
  real_T Integrator6_CSTATE;           /* '<S1>/Integrator6' */
  real_T Integrator8_CSTATE;           /* '<S1>/Integrator8' */
  real_T Integrator9_CSTATE;           /* '<S1>/Integrator9' */
} X_Innerloop_joystick_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<Root>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<Root>/Integrator1' */
  real_T Integrator7_CSTATE;           /* '<S1>/Integrator7' */
  real_T Integrator3_CSTATE;           /* '<Root>/Integrator3' */
  real_T Integrator4_CSTATE;           /* '<S1>/Integrator4' */
  real_T Integrator3_CSTATE_a;         /* '<S1>/Integrator3' */
  real_T Integrator5_CSTATE;           /* '<S1>/Integrator5' */
  real_T Integrator2_CSTATE;           /* '<Root>/Integrator2' */
  real_T Integrator_CSTATE_f;          /* '<S1>/Integrator' */
  real_T Integrator1_CSTATE_p;         /* '<S1>/Integrator1' */
  real_T Integrator2_CSTATE_e;         /* '<S1>/Integrator2' */
  real_T Integrator6_CSTATE;           /* '<S1>/Integrator6' */
  real_T Integrator8_CSTATE;           /* '<S1>/Integrator8' */
  real_T Integrator9_CSTATE;           /* '<S1>/Integrator9' */
} XDot_Innerloop_joystick_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<Root>/Integrator' */
  boolean_T Integrator1_CSTATE;        /* '<Root>/Integrator1' */
  boolean_T Integrator7_CSTATE;        /* '<S1>/Integrator7' */
  boolean_T Integrator3_CSTATE;        /* '<Root>/Integrator3' */
  boolean_T Integrator4_CSTATE;        /* '<S1>/Integrator4' */
  boolean_T Integrator3_CSTATE_a;      /* '<S1>/Integrator3' */
  boolean_T Integrator5_CSTATE;        /* '<S1>/Integrator5' */
  boolean_T Integrator2_CSTATE;        /* '<Root>/Integrator2' */
  boolean_T Integrator_CSTATE_f;       /* '<S1>/Integrator' */
  boolean_T Integrator1_CSTATE_p;      /* '<S1>/Integrator1' */
  boolean_T Integrator2_CSTATE_e;      /* '<S1>/Integrator2' */
  boolean_T Integrator6_CSTATE;        /* '<S1>/Integrator6' */
  boolean_T Integrator8_CSTATE;        /* '<S1>/Integrator8' */
  boolean_T Integrator9_CSTATE;        /* '<S1>/Integrator9' */
} XDis_Innerloop_joystick_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T In1;                          /* '<Root>/In1' */
  real_T In2;                          /* '<Root>/In2' */
  real_T In3;                          /* '<Root>/In3' */
  real_T In4;                          /* '<Root>/In4' */
  real_T In5;                          /* '<Root>/In5' */
  real_T In6;                          /* '<Root>/In6' */
} ExtU_Innerloop_joystick_T;

/* Parameters (auto storage) */
struct P_Innerloop_joystick_T_ {
  real_T kdp;                          /* Variable: kdp
                                        * Referenced by: '<S2>/kdp'
                                        */
  real_T kdps;                         /* Variable: kdps
                                        * Referenced by: '<S2>/kdps'
                                        */
  real_T kdt;                          /* Variable: kdt
                                        * Referenced by: '<S2>/kdt'
                                        */
  real_T kdz;                          /* Variable: kdz
                                        * Referenced by: '<S2>/kdz'
                                        */
  real_T kpp;                          /* Variable: kpp
                                        * Referenced by: '<S2>/kpp'
                                        */
  real_T kpps;                         /* Variable: kpps
                                        * Referenced by: '<S2>/kpps'
                                        */
  real_T kpt;                          /* Variable: kpt
                                        * Referenced by: '<S2>/kpt'
                                        */
  real_T kpz;                          /* Variable: kpz
                                        * Referenced by: '<S2>/kpz'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<Root>/Integrator'
                                        */
  real_T Integrator1_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator1'
                                        */
  real_T Integrator7_IC;               /* Expression: 0
                                        * Referenced by: '<S1>/Integrator7'
                                        */
  real_T Integrator3_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator3'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 100
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: 0
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  real_T Integrator4_IC;               /* Expression: 0
                                        * Referenced by: '<S1>/Integrator4'
                                        */
  real_T Gain2_Gain;                   /* Expression: 57.3
                                        * Referenced by: '<Root>/Gain2'
                                        */
  real_T Gain3_Gain;                   /* Expression: 57.3
                                        * Referenced by: '<Root>/Gain3'
                                        */
  real_T Integrator3_IC_o;             /* Expression: 0
                                        * Referenced by: '<S1>/Integrator3'
                                        */
  real_T Gain_Gain;                    /* Expression: 57.3
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: 57.3
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T Integrator5_IC;               /* Expression: 0
                                        * Referenced by: '<S1>/Integrator5'
                                        */
  real_T Gain5_Gain;                   /* Expression: 57.3
                                        * Referenced by: '<Root>/Gain5'
                                        */
  real_T Integrator2_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator2'
                                        */
  real_T Saturation_UpperSat;          /* Expression: pi
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -pi
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Gain4_Gain;                   /* Expression: 57.3
                                        * Referenced by: '<Root>/Gain4'
                                        */
  real_T Integrator_IC_c;              /* Expression: 0
                                        * Referenced by: '<S1>/Integrator'
                                        */
  real_T Integrator1_IC_a;             /* Expression: 0
                                        * Referenced by: '<S1>/Integrator1'
                                        */
  real_T Integrator2_IC_p;             /* Expression: 0
                                        * Referenced by: '<S1>/Integrator2'
                                        */
  real_T Integrator6_IC;               /* Expression: 0
                                        * Referenced by: '<S1>/Integrator6'
                                        */
  real_T Integrator8_IC;               /* Expression: 0
                                        * Referenced by: '<S1>/Integrator8'
                                        */
  real_T Integrator9_IC;               /* Expression: 0
                                        * Referenced by: '<S1>/Integrator9'
                                        */
  real_T Arm_length_Value;             /* Expression: 0.228
                                        * Referenced by: '<S3>/Arm_length_'
                                        */
  real_T ineretia_yy_Value;            /* Expression: 2.5955e-4
                                        * Referenced by: '<S3>/ineretia_yy'
                                        */
  real_T inertia_zz_Value;             /* Expression: 5.7824e-5
                                        * Referenced by: '<S3>/inertia_zz'
                                        */
  real_T inertia_xx_Value;             /* Expression: 2.754e-4
                                        * Referenced by: '<S3>/inertia_xx'
                                        */
  real_T Constant1_Value;              /* Expression: 9.8
                                        * Referenced by: '<S2>/Constant1'
                                        */
  real_T m_Gain;                       /* Expression: 1.17
                                        * Referenced by: '<S2>/m'
                                        */
  real_T mass_Value;                   /* Expression: 1.17
                                        * Referenced by: '<S3>/mass'
                                        */
  real_T u5_Value;                     /* Expression: 9.8
                                        * Referenced by: '<S10>/u5'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Innerloop_joystick_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    X_Innerloop_joystick_T *contStates;
    int_T *periodicContStateIndices;
    real_T *periodicContStateRanges;
    real_T *derivs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    real_T odeY[14];
    real_T odeF[3][14];
    ODE3_IntgData intgData;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_Innerloop_joystick_T Innerloop_joystick_P;

/* Block signals (auto storage) */
extern B_Innerloop_joystick_T Innerloop_joystick_B;

/* Continuous states (auto storage) */
extern X_Innerloop_joystick_T Innerloop_joystick_X;

/* Block states (auto storage) */
extern DW_Innerloop_joystick_T Innerloop_joystick_DW;

/* External inputs (root inport signals with auto storage) */
extern ExtU_Innerloop_joystick_T Innerloop_joystick_U;

/* Model entry point functions */
extern void Innerloop_joystick_initialize(void);
extern void Innerloop_joystick_step(void);
extern void Innerloop_joystick_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Innerloop_joystick_T *const Innerloop_joystick_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Innerloop_joystick'
 * '<S1>'   : 'Innerloop_joystick/Dynamic model'
 * '<S2>'   : 'Innerloop_joystick/PD controller'
 * '<S3>'   : 'Innerloop_joystick/property '
 * '<S4>'   : 'Innerloop_joystick/Dynamic model/MATLAB Function'
 * '<S5>'   : 'Innerloop_joystick/Dynamic model/pitch_dot_dot'
 * '<S6>'   : 'Innerloop_joystick/Dynamic model/roll_dot_dot'
 * '<S7>'   : 'Innerloop_joystick/Dynamic model/x_dot_dot'
 * '<S8>'   : 'Innerloop_joystick/Dynamic model/y_dot_dot'
 * '<S9>'   : 'Innerloop_joystick/Dynamic model/yaw_dot_dot'
 * '<S10>'  : 'Innerloop_joystick/Dynamic model/z_dot_dot'
 */
#endif                                 /* RTW_HEADER_Innerloop_joystick_h_ */

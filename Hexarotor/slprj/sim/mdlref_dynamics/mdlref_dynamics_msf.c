#include "__cf_mdlref_dynamics.h"
#if !defined(S_FUNCTION_NAME)
#define S_FUNCTION_NAME mdlref_dynamics_msf
#endif
#define S_FUNCTION_LEVEL 2
#if !defined(RTW_GENERATED_S_FUNCTION)
#define RTW_GENERATED_S_FUNCTION
#endif
#include <stdio.h>
#include <math.h>
#include "simstruc.h"
#include "fixedpoint.h"
#define rt_logging_h
#include "mdlref_dynamics_types.h"
#include "mdlref_dynamics.h"
#include "mdlref_dynamics_private.h"
MdlRefChildMdlRec childModels [ 1 ] = { "mdlref_dynamics" , "mdlref_dynamics"
, 0 } ; const char * rt_GetMatSignalLoggingFileName ( void ) { return NULL ;
} const char * rt_GetMatSigLogSelectorFileName ( void ) { return NULL ; }
boolean_T slIsRapidAcceleratorSimulating ( void ) { return false ; } void
rt_RAccelReplaceFromFilename ( const char * blockpath , char * fileName ) { (
void ) blockpath ; ( void ) fileName ; } void rt_RAccelReplaceToFilename (
const char * blockpath , char * fileName ) { ( void ) blockpath ; ( void )
fileName ; } static void mdlInitializeSizes ( SimStruct * S ) {
ssSetNumSFcnParams ( S , 0 ) ; ssFxpSetU32BitRegionCompliant ( S , 1 ) ;
rt_InitInfAndNaN ( sizeof ( real_T ) ) ; if ( S -> mdlInfo -> genericFcn != (
NULL ) ) { _GenericFcn fcn = S -> mdlInfo -> genericFcn ; real_T lifeSpan =
rtInf ; real_T startTime = 0.0 ; real_T stopTime = 10.0 ; int_T hwSettings [
15 ] ; int_T opSettings [ 2 ] ; boolean_T concurrTaskSupport = 0 ; boolean_T
hasDiscTs = 0 ; ModelRefChildSolverInfo solverInfo = { 0 , - 1 , 0.001 , 0.2
, 0.0 , 0.0 } ; ( fcn ) ( S , GEN_FCN_CHK_MODELREF_SOLVER_TYPE_EARLY , 1 , (
NULL ) ) ; ( fcn ) ( S , GEN_FCN_MODELREF_RATE_GROUPED , 0 , ( NULL ) ) ; if
( ! ( fcn ) ( S , GEN_FCN_CHK_MODELREF_LIFE_SPAN , - 1 , & lifeSpan ) )
return ; if ( ! ( fcn ) ( S , GEN_FCN_CHK_MODELREF_START_TIME , - 1 , &
startTime ) ) return ; if ( ! ( fcn ) ( S , GEN_FCN_CHK_MODELREF_STOP_TIME ,
- 1 , & stopTime ) ) return ; hwSettings [ 0 ] = 8 ; hwSettings [ 1 ] = 16 ;
hwSettings [ 2 ] = 32 ; hwSettings [ 3 ] = 32 ; hwSettings [ 4 ] = 32 ;
hwSettings [ 5 ] = 64 ; hwSettings [ 6 ] = 32 ; hwSettings [ 7 ] = 2 ;
hwSettings [ 8 ] = 0 ; hwSettings [ 9 ] = 32 ; hwSettings [ 10 ] = 1 ;
hwSettings [ 11 ] = 0 ; hwSettings [ 12 ] = 2 ; hwSettings [ 13 ] = 64 ;
hwSettings [ 14 ] = 0 ; if ( ! ( fcn ) ( S ,
GEN_FCN_CHK_MODELREF_HARDWARE_SETTINGS , 15 , hwSettings ) ) return ; if ( !
( fcn ) ( S , GEN_FCN_CHK_MODELREF_DATA_DICTIONARY , 0 , ( void * ) "" ) )
return ; slmrSetDataDictionarySet ( S , "" ) ; opSettings [ 0 ] = 0 ;
opSettings [ 1 ] = 0 ; if ( ! ( fcn ) ( S ,
GEN_FCN_CHK_MODELREF_OPTIM_SETTINGS , 2 , opSettings ) ) return ;
slmrSetIsInlineParamsOn ( S , true ) ; if ( ! ( fcn ) ( S ,
GEN_FCN_CHK_MODELREF_CONCURRETNT_TASK_SUPPORT , ( int_T ) concurrTaskSupport
, ( NULL ) ) ) return ; if ( ! ( fcn ) ( S , GEN_FCN_CHK_MODELREF_SOLVER_TYPE
, 0 , & hasDiscTs ) ) return ; if ( ! ( fcn ) ( S ,
GEN_FCN_CHK_MODELREF_SOLVER_NAME , 0 , ( void * ) "ode45" ) ) return ; if ( !
( fcn ) ( S , GEN_FCN_CHK_MODELREF_SOLVER_MODE , SOLVER_MODE_SINGLETASKING ,
( NULL ) ) ) return ; if ( ! ( fcn ) ( S , GEN_FCN_CHK_MODELREF_VSOLVER_OPTS
, - 1 , & solverInfo ) ) return ; ( fcn ) ( S ,
GEN_FCN_CHK_MODELREF_FRAME_UPGRADE_DIAGNOSTICS , 2 , ( NULL ) ) ; } { static
const char * globalVarList [ ] = { "Md" , "Mq" , "Mw" , "Uo" , "Zd" , "Zw" }
; ssRegModelRefGlobalVarUsage ( S , 6 , ( void * ) globalVarList ) ; }
ssSetRTWGeneratedSFcn ( S , 2 ) ; ssSetNumContStates ( S , 2 ) ;
ssSetNumDiscStates ( S , 0 ) ; { const char * modelNames [ ] = { "" } ; const
size_t numModelNames = 0 ; slmrSetHasNonBuiltinLoggedState ( S ,
numModelNames , modelNames ) ; } if ( ! ssSetNumInputPorts ( S , 3 ) ) return
; if ( ! ssSetInputPortVectorDimension ( S , 0 , 1 ) ) return ;
ssSetInputPortDimensionsMode ( S , 0 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 0 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 0 , SS_DOUBLE ) ;
} ssSetInputPortDirectFeedThrough ( S , 0 , 1 ) ;
ssSetInputPortRequiredContiguous ( S , 0 , 1 ) ; ssSetInputPortOptimOpts ( S
, 0 , SS_NOT_REUSABLE_AND_GLOBAL ) ; ssSetInputPortOverWritable ( S , 0 ,
false ) ; ssSetInputPortSampleTime ( S , 0 , 0.0 ) ; ssSetInputPortOffsetTime
( S , 0 , 0.0 ) ; if ( ! ssSetInputPortVectorDimension ( S , 1 , 1 ) ) return
; ssSetInputPortDimensionsMode ( S , 1 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 1 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 1 , SS_DOUBLE ) ;
} ssSetInputPortDirectFeedThrough ( S , 1 , 1 ) ;
ssSetInputPortRequiredContiguous ( S , 1 , 1 ) ; ssSetInputPortOptimOpts ( S
, 1 , SS_NOT_REUSABLE_AND_GLOBAL ) ; ssSetInputPortOverWritable ( S , 1 ,
false ) ; ssSetInputPortSampleTime ( S , 1 , 0.0 ) ; ssSetInputPortOffsetTime
( S , 1 , 0.0 ) ; if ( ! ssSetInputPortVectorDimension ( S , 2 , 1 ) ) return
; ssSetInputPortDimensionsMode ( S , 2 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 2 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 2 , SS_DOUBLE ) ;
} ssSetInputPortDirectFeedThrough ( S , 2 , 1 ) ;
ssSetInputPortRequiredContiguous ( S , 2 , 1 ) ; ssSetInputPortOptimOpts ( S
, 2 , SS_NOT_REUSABLE_AND_GLOBAL ) ; ssSetInputPortOverWritable ( S , 2 ,
false ) ; ssSetInputPortSampleTime ( S , 2 , 0.0 ) ; ssSetInputPortOffsetTime
( S , 2 , 0.0 ) ; if ( ! ssSetNumOutputPorts ( S , 2 ) ) return ; if ( !
ssSetOutputPortVectorDimension ( S , 0 , 1 ) ) return ;
ssSetOutputPortDimensionsMode ( S , 0 , FIXED_DIMS_MODE ) ;
ssSetOutputPortFrameData ( S , 0 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetOutputPortDataType ( S , 0 , SS_DOUBLE )
; } ssSetOutputPortSampleTime ( S , 0 , 0.0 ) ; ssSetOutputPortOffsetTime ( S
, 0 , 0.0 ) ; ssSetOutputPortDiscreteValuedOutput ( S , 0 , 0 ) ;
ssSetOutputPortOkToMerge ( S , 0 , SS_NOT_OK_TO_MERGE ) ;
slmrModelRefSetOutputPortDrivenByResetITVS ( S , 0 , false ) ;
ssSetOutputPortOptimOpts ( S , 0 , SS_NOT_REUSABLE_AND_GLOBAL ) ; if ( !
ssSetOutputPortVectorDimension ( S , 1 , 1 ) ) return ;
ssSetOutputPortDimensionsMode ( S , 1 , FIXED_DIMS_MODE ) ;
ssSetOutputPortFrameData ( S , 1 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetOutputPortDataType ( S , 1 , SS_DOUBLE )
; } ssSetOutputPortSampleTime ( S , 1 , 0.0 ) ; ssSetOutputPortOffsetTime ( S
, 1 , 0.0 ) ; ssSetOutputPortDiscreteValuedOutput ( S , 1 , 0 ) ;
ssSetOutputPortOkToMerge ( S , 1 , SS_NOT_OK_TO_MERGE ) ;
slmrModelRefSetOutputPortDrivenByResetITVS ( S , 1 , false ) ;
ssSetOutputPortOptimOpts ( S , 1 , SS_NOT_REUSABLE_AND_GLOBAL ) ;
slmrModelRefSetHasDescExpFcnMdl ( S , false ) ; { real_T minValue =
rtMinusInf ; real_T maxValue = rtInf ; ssSetModelRefInputSignalDesignMin ( S
, 0 , & minValue ) ; ssSetModelRefInputSignalDesignMax ( S , 0 , & maxValue )
; } { real_T minValue = rtMinusInf ; real_T maxValue = rtInf ;
ssSetModelRefInputSignalDesignMin ( S , 1 , & minValue ) ;
ssSetModelRefInputSignalDesignMax ( S , 1 , & maxValue ) ; } { real_T
minValue = rtMinusInf ; real_T maxValue = rtInf ;
ssSetModelRefInputSignalDesignMin ( S , 2 , & minValue ) ;
ssSetModelRefInputSignalDesignMax ( S , 2 , & maxValue ) ; } { real_T
minValue = rtMinusInf ; real_T maxValue = rtInf ;
ssSetModelRefOutputSignalDesignMin ( S , 0 , & minValue ) ;
ssSetModelRefOutputSignalDesignMax ( S , 0 , & maxValue ) ; } { real_T
minValue = rtMinusInf ; real_T maxValue = rtInf ;
ssSetModelRefOutputSignalDesignMin ( S , 1 , & minValue ) ;
ssSetModelRefOutputSignalDesignMax ( S , 1 , & maxValue ) ; }
ssSetSimStateCompliance ( S , USE_CUSTOM_SIM_STATE ) ;
mr_mdlref_dynamics_RegisterSimStateChecksum ( S ) ; { static ssRTWStorageType
storageClass [ 5 ] = { SS_RTW_STORAGE_AUTO , SS_RTW_STORAGE_AUTO ,
SS_RTW_STORAGE_AUTO , SS_RTW_STORAGE_AUTO , SS_RTW_STORAGE_AUTO } ;
ssSetModelRefPortRTWStorageClasses ( S , storageClass ) ; }
ssSetModelRefSignalLoggingSaveFormat ( S , SS_MODEL_DATA_LOGS ) ;
slmrSetModelRefLoggingSaveFormat ( S , SS_ARRAY_FORMAT ) ;
ssSetNumSampleTimes ( S , PORT_BASED_SAMPLE_TIMES ) ; ssSetNumRWork ( S , 0 )
; ssSetNumIWork ( S , 0 ) ; ssSetNumPWork ( S , 0 ) ; ssSetNumModes ( S , 0 )
; { int_T zcsIdx = 0 ; } ssSetOutputPortIsNonContinuous ( S , 0 , 0 ) ;
ssSetOutputPortIsFedByBlockWithModesNoZCs ( S , 0 , 0 ) ;
ssSetOutputPortIsNonContinuous ( S , 1 , 0 ) ;
ssSetOutputPortIsFedByBlockWithModesNoZCs ( S , 1 , 0 ) ;
ssSetInputPortIsNotDerivPort ( S , 0 , 0 ) ; ssSetInputPortIsNotDerivPort ( S
, 1 , 0 ) ; ssSetInputPortIsNotDerivPort ( S , 2 , 0 ) ;
ssSetModelReferenceSampleTimeInheritanceRule ( S ,
DISALLOW_SAMPLE_TIME_INHERITANCE ) ; ssSetOptimizeModelRefInitCode ( S , 0 )
; ssSetAcceptsFcnCallInputs ( S ) ; { static const char * inlinedVars [ ] = {
"Md" , "Mq" , "Mw" , "Uo" , "Zd" , "Zw" } ; ssSetModelRefInlinedVars ( S , 6
, ( void * ) inlinedVars ) ; } ssSetModelReferenceNormalModeSupport ( S ,
MDL_START_AND_MDL_PROCESS_PARAMS_OK ) ; ssSupportsMultipleExecInstances ( S ,
true ) ; ssHasStateInsideForEachSS ( S , false ) ;
ssSetModelRefHasParforForEachSS ( S , false ) ;
ssSetModelRefHasVariantModelOrSubsystem ( S , false ) ; ssSetNumAsyncTs ( S ,
0 ) ; ssSetOptions ( S , SS_OPTION_SUPPORTS_ALIAS_DATA_TYPES |
SS_OPTION_DISALLOW_CONSTANT_SAMPLE_TIME | SS_OPTION_EXCEPTION_FREE_CODE |
SS_OPTION_WORKS_WITH_CODE_REUSE ) ; if ( S -> mdlInfo -> genericFcn != ( NULL
) ) { if ( ! ssRegModelRefChildModel ( S , 1 , childModels ) ) { return ; } }
#if SS_SFCN_FOR_SIM
if ( S -> mdlInfo -> genericFcn != ( NULL ) && ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { int_T retVal = 1 ;
mr_mdlref_dynamics_MdlInfoRegFcn ( S , "mdlref_dynamics" , & retVal ) ; if (
! retVal ) return ; }
#endif
if ( ! ssSetNumDWork ( S , 1 ) ) { return ; }
#if SS_SFCN_FOR_SIM
{ int mdlrefDWTypeId ; ssRegMdlRefDWorkType ( S , & mdlrefDWTypeId ) ; if (
mdlrefDWTypeId == INVALID_DTYPE_ID ) return ; if ( ! ssSetDataTypeSize ( S ,
mdlrefDWTypeId , sizeof ( jzhyltz23av ) ) ) return ; ssSetDWorkDataType ( S ,
0 , mdlrefDWTypeId ) ; ssSetDWorkWidth ( S , 0 , 1 ) ; }
#endif
slmrSetDataTypeOverrideSettings ( S , 0 , 0 ) ;
ssSetSimulinkVersionGeneratedIn ( S , "8.5" ) ; ssSetNeedAbsoluteTime ( S , 1
) ; ssSetModelRefHasEnablePort ( S , 0 ) ; } static void
mdlInitializeSampleTimes ( SimStruct * S ) { return ; }
#define  MDL_INITIALIZE_CONDITIONS
static void mdlInitializeConditions ( SimStruct * S ) { jzhyltz23av * dw = (
jzhyltz23av * ) ssGetDWork ( S , 0 ) ; bcn0znuh2k * localX = ( bcn0znuh2k * )
ssGetContStates ( S ) ; dshzp10j35 ( localX ) ; }
#define MDL_SET_WORK_WIDTHS
static void mdlSetWorkWidths ( SimStruct * S ) { if ( S -> mdlInfo ->
genericFcn != ( NULL ) ) { _GenericFcn fcn = S -> mdlInfo -> genericFcn ;
ssSetSignalSizesComputeType ( S , SS_VARIABLE_SIZE_FROM_INPUT_VALUE_AND_SIZE
) ; } { static const char * toFileNames [ ] = { "" } ; static const char *
fromFileNames [ ] = { "" } ; if ( ! ssSetModelRefFromFiles ( S , 0 ,
fromFileNames ) ) return ; if ( ! ssSetModelRefToFiles ( S , 0 , toFileNames
) ) return ; } }
#define MDL_START
static void mdlStart ( SimStruct * S ) { jzhyltz23av * dw = ( jzhyltz23av * )
ssGetDWork ( S , 0 ) ; bcn0znuh2k * localX = ( bcn0znuh2k * ) ssGetContStates
( S ) ; void * sysRanPtr = ( NULL ) ; int sysTid = 0 ;
ssGetContextSysRanBCPtr ( S , & sysRanPtr ) ; ssGetContextSysTid ( S , &
sysTid ) ; if ( sysTid == CONSTANT_TID ) { sysTid = 0 ; } b1zsspq0wq ( S ,
ssGetSampleTimeTaskID ( S , 0 ) , & ( dw -> rtm ) , & ( dw -> rtb ) , localX
, sysRanPtr , sysTid , ( NULL ) , ( NULL ) , 0 , - 1 ) ;
ssSetModelMappingInfoPtr ( S , & ( dw -> rtm . DataMapInfo . mmi ) ) ; if ( S
-> mdlInfo -> genericFcn != ( NULL ) ) { _GenericFcn fcn = S -> mdlInfo ->
genericFcn ; } } static void mdlOutputs ( SimStruct * S , int_T tid ) {
jzhyltz23av * dw = ( jzhyltz23av * ) ssGetDWork ( S , 0 ) ; const real_T *
i_l00by1fstm = ( real_T * ) ssGetInputPortSignal ( S , 0 ) ; const real_T *
i_e0pvanrki5 = ( real_T * ) ssGetInputPortSignal ( S , 1 ) ; const real_T *
i_nj10fja12m = ( real_T * ) ssGetInputPortSignal ( S , 2 ) ; real_T * o_B_1_1
= ( real_T * ) ssGetOutputPortSignal ( S , 0 ) ; real_T * o_B_1_2 = ( real_T
* ) ssGetOutputPortSignal ( S , 1 ) ; bcn0znuh2k * localX = ( bcn0znuh2k * )
ssGetContStates ( S ) ; if ( tid != CONSTANT_TID ) { mdlref_dynamics (
i_l00by1fstm , i_e0pvanrki5 , i_nj10fja12m , o_B_1_1 , o_B_1_2 , & ( dw ->
rtb ) , localX ) ; } }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { jzhyltz23av * dw = (
jzhyltz23av * ) ssGetDWork ( S , 0 ) ; g1noppauqu ( ) ; return ; }
#define MDL_DERIVATIVES
static void mdlDerivatives ( SimStruct * S ) { jzhyltz23av * dw = (
jzhyltz23av * ) ssGetDWork ( S , 0 ) ; bcn0znuh2k * localX = ( bcn0znuh2k * )
ssGetContStates ( S ) ; jgt53fueyv * localXdot = ( jgt53fueyv * ) ssGetdX ( S
) ; mwlzs2fwpd ( & ( dw -> rtb ) , localX , localXdot ) ; } static void
mdlTerminate ( SimStruct * S ) { return ; }
#if !defined(MDL_SIM_STATE)
#define MDL_SIM_STATE
#endif
static mxArray * mdlGetSimState ( SimStruct * S ) { static const char *
dwFieldNames [ 5 ] = { "localX" , "mdlrefDW" , "numPWorks" , "tNext" ,
"tNextTid" , } ; mxArray * ss = mxCreateStructMatrix ( 1 , 1 , 5 ,
dwFieldNames ) ; { const bcn0znuh2k * localX = ( const bcn0znuh2k * )
ssGetContStates ( S ) ; const size_t numBytes = sizeof ( bcn0znuh2k ) ;
mxArray * storedX = mxCreateNumericMatrix ( 1 , numBytes , mxUINT8_CLASS ,
mxREAL ) ; UINT8_T * rawData = ( UINT8_T * ) mxGetData ( storedX ) ; memcpy (
& rawData [ 0 ] , localX , numBytes ) ; mxSetFieldByNumber ( ss , 0 , 0 ,
storedX ) ; } { mxArray * mdlrefDW = mr_mdlref_dynamics_GetDWork ( ssGetDWork
( S , 0 ) ) ; if ( NULL != mdlrefDW ) { mxSetFieldByNumber ( ss , 0 , 2 ,
mxDuplicateArray ( mxGetFieldByNumber ( mdlrefDW , 0 , 3 ) ) ) ; } else {
mxSetFieldByNumber ( ss , 0 , 2 , mxCreateDoubleScalar ( 0.0 ) ) ; }
mxSetFieldByNumber ( ss , 0 , 1 , mdlrefDW ) ; } mxSetFieldByNumber ( ss , 0
, 3 , mxCreateDoubleScalar ( ( double ) ssGetTNext ( S ) ) ) ;
mxSetFieldByNumber ( ss , 0 , 4 , mxCreateDoubleScalar ( ( double )
ssGetTNextTid ( S ) ) ) ; return ss ; }
#if !defined(MDL_SIM_STATE)
#define MDL_SIM_STATE
#endif
static void mdlSetSimState ( SimStruct * S , const mxArray * ss ) { {
bcn0znuh2k * localX = ( bcn0znuh2k * ) ssGetContStates ( S ) ; const size_t
numBytes = sizeof ( bcn0znuh2k ) ; const mxArray * storedX =
mxGetFieldByNumber ( ss , 0 , 0 ) ; const UINT8_T * rawData = ( const UINT8_T
* ) mxGetData ( storedX ) ; memcpy ( localX , & rawData [ 0 ] , numBytes ) ;
} mr_mdlref_dynamics_SetDWork ( ssGetDWork ( S , 0 ) , mxGetFieldByNumber (
ss , 0 , 1 ) ) ; ssSetTNext ( S , ( time_T ) mxGetScalar ( mxGetFieldByNumber
( ss , 0 , 3 ) ) ) ; ssSetTNextTid ( S , ( int_T ) mxGetScalar (
mxGetFieldByNumber ( ss , 0 , 4 ) ) ) ; }
#ifdef MATLAB_MEX_FILE 
#include "simulink.c"
#include "fixedpoint.c"
#else
#error Assertion failed: file must be compiled as a MEX-file
#endif

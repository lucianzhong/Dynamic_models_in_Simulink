#include "__cf_Innerloop_joystick.h"
#include "rt_logging_mmi.h"
#include "Innerloop_joystick_capi.h"
#include <math.h>
#include "Innerloop_joystick.h"
#include "Innerloop_joystick_private.h"
#include "Innerloop_joystick_dt.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 2 ; const char_T
* gbl_raccel_Version = "8.8 (R2015a) 09-Feb-2015" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const char * gblSlvrJacPatternFileName =
"slprj\\raccel\\Innerloop_joystick\\Innerloop_joystick_Jpattern.mat" ; const
int_T gblNumRootInportBlks = 6 ; const int_T gblNumModelInputs = 6 ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
const int_T gblInportDataTypeIdx [ ] = { 0 , 0 , 0 , 0 , 0 , 0 } ; const
int_T gblInportDims [ ] = { 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 } ;
const int_T gblInportComplex [ ] = { 0 , 0 , 0 , 0 , 0 , 0 } ; const int_T
gblInportInterpoFlag [ ] = { 1 , 1 , 1 , 1 , 1 , 1 } ; const int_T
gblInportContinuous [ ] = { 1 , 1 , 1 , 1 , 1 , 1 } ;
#include "simstruc.h"
#include "fixedpoint.h"
void MdlOutputsParameterSampleTime ( int_T tid ) { UNUSED_PARAMETER ( tid ) ;
} B rtB ; X rtX ; DW rtDW ; ExtU rtU ; static SimStruct model_S ; SimStruct *
const rtS = & model_S ; void MdlInitialize ( void ) { rtX . ntgyq4g0p5 = rtP
. Integrator_IC ; rtX . azqf4obajp = rtP . Integrator1_IC ; rtX . kibywkbko4
= rtP . Integrator7_IC ; rtX . d3bftye4ie = rtP . Integrator3_IC ; rtX .
opjkxrmhm3 = rtP . Integrator4_IC ; rtX . bwmqhcsduy = rtP .
Integrator3_IC_oj4bssacfz ; rtX . poycw33cyc = rtP . Integrator5_IC ; rtX .
asir0wexi1 = rtP . Integrator2_IC ; rtX . j2swejbzkh = rtP .
Integrator_IC_cv5aw0xgvv ; rtX . itoxuokcqb = rtP . Integrator1_IC_aul1jddy20
; rtX . awf1utodht = rtP . Integrator2_IC_p13irtit1l ; rtX . halffsymco = rtP
. Integrator6_IC ; rtX . j44tdkv0pi = rtP . Integrator8_IC ; rtX . cy1aw34iqa
= rtP . Integrator9_IC ; } void MdlStart ( void ) { MdlInitialize ( ) ; }
void MdlOutputs ( int_T tid ) { real_T ic5indijw0 ; real_T ct2zizj5rl ;
real_T fnfizpm4ke ; real_T hbdkiq1ssm ; real_T h4oig4g3ai ; real_T hulx4b0xac
; real_T lqpihehx1y ; real_T mobcqbssig ; real_T h3m1x4cpg4 ; real_T
ebxqlugq1f ; real_T h1hrwz3sl3 ; if ( gblInportFileName != ( NULL ) ) { int_T
currTimeIdx ; int_T i ; if ( gblInportTUtables [ 0 ] . nTimePoints > 0 ) { if
( 1 ) { real_T time = ssGetTaskTime ( rtS , 0 ) ; int k = 1 ; if (
gblInportTUtables [ 0 ] . nTimePoints == 1 ) { k = 0 ; } currTimeIdx =
rt_getTimeIdx ( gblInportTUtables [ 0 ] . time , time , gblInportTUtables [ 0
] . nTimePoints , gblInportTUtables [ 0 ] . currTimeIdx , 1 , 0 ) ;
gblInportTUtables [ 0 ] . currTimeIdx = currTimeIdx ; for ( i = 0 ; i < 1 ; i
++ ) { real_T * realPtr1 = ( real_T * ) gblInportTUtables [ 0 ] . ur + i *
gblInportTUtables [ 0 ] . nTimePoints + currTimeIdx ; real_T * realPtr2 =
realPtr1 + 1 * k ; ( void ) rt_Interpolate_Datatype ( realPtr1 , realPtr2 , &
rtU . morfifqs3m , time , gblInportTUtables [ 0 ] . time [ currTimeIdx ] ,
gblInportTUtables [ 0 ] . time [ currTimeIdx + k ] , gblInportTUtables [ 0 ]
. uDataType ) ; } } } if ( gblInportTUtables [ 1 ] . nTimePoints > 0 ) { if (
1 ) { real_T time = ssGetTaskTime ( rtS , 0 ) ; int k = 1 ; if (
gblInportTUtables [ 1 ] . nTimePoints == 1 ) { k = 0 ; } currTimeIdx =
rt_getTimeIdx ( gblInportTUtables [ 1 ] . time , time , gblInportTUtables [ 1
] . nTimePoints , gblInportTUtables [ 1 ] . currTimeIdx , 1 , 0 ) ;
gblInportTUtables [ 1 ] . currTimeIdx = currTimeIdx ; for ( i = 0 ; i < 1 ; i
++ ) { real_T * realPtr1 = ( real_T * ) gblInportTUtables [ 1 ] . ur + i *
gblInportTUtables [ 1 ] . nTimePoints + currTimeIdx ; real_T * realPtr2 =
realPtr1 + 1 * k ; ( void ) rt_Interpolate_Datatype ( realPtr1 , realPtr2 , &
rtU . lpqa3ddvpp , time , gblInportTUtables [ 1 ] . time [ currTimeIdx ] ,
gblInportTUtables [ 1 ] . time [ currTimeIdx + k ] , gblInportTUtables [ 1 ]
. uDataType ) ; } } } if ( gblInportTUtables [ 2 ] . nTimePoints > 0 ) { if (
1 ) { real_T time = ssGetTaskTime ( rtS , 0 ) ; int k = 1 ; if (
gblInportTUtables [ 2 ] . nTimePoints == 1 ) { k = 0 ; } currTimeIdx =
rt_getTimeIdx ( gblInportTUtables [ 2 ] . time , time , gblInportTUtables [ 2
] . nTimePoints , gblInportTUtables [ 2 ] . currTimeIdx , 1 , 0 ) ;
gblInportTUtables [ 2 ] . currTimeIdx = currTimeIdx ; for ( i = 0 ; i < 1 ; i
++ ) { real_T * realPtr1 = ( real_T * ) gblInportTUtables [ 2 ] . ur + i *
gblInportTUtables [ 2 ] . nTimePoints + currTimeIdx ; real_T * realPtr2 =
realPtr1 + 1 * k ; ( void ) rt_Interpolate_Datatype ( realPtr1 , realPtr2 , &
rtU . ahpzfcqoif , time , gblInportTUtables [ 2 ] . time [ currTimeIdx ] ,
gblInportTUtables [ 2 ] . time [ currTimeIdx + k ] , gblInportTUtables [ 2 ]
. uDataType ) ; } } } if ( gblInportTUtables [ 3 ] . nTimePoints > 0 ) { if (
1 ) { real_T time = ssGetTaskTime ( rtS , 0 ) ; int k = 1 ; if (
gblInportTUtables [ 3 ] . nTimePoints == 1 ) { k = 0 ; } currTimeIdx =
rt_getTimeIdx ( gblInportTUtables [ 3 ] . time , time , gblInportTUtables [ 3
] . nTimePoints , gblInportTUtables [ 3 ] . currTimeIdx , 1 , 0 ) ;
gblInportTUtables [ 3 ] . currTimeIdx = currTimeIdx ; for ( i = 0 ; i < 1 ; i
++ ) { real_T * realPtr1 = ( real_T * ) gblInportTUtables [ 3 ] . ur + i *
gblInportTUtables [ 3 ] . nTimePoints + currTimeIdx ; real_T * realPtr2 =
realPtr1 + 1 * k ; ( void ) rt_Interpolate_Datatype ( realPtr1 , realPtr2 , &
rtU . kdtagg3114 , time , gblInportTUtables [ 3 ] . time [ currTimeIdx ] ,
gblInportTUtables [ 3 ] . time [ currTimeIdx + k ] , gblInportTUtables [ 3 ]
. uDataType ) ; } } } if ( gblInportTUtables [ 4 ] . nTimePoints > 0 ) { if (
1 ) { real_T time = ssGetTaskTime ( rtS , 0 ) ; int k = 1 ; if (
gblInportTUtables [ 4 ] . nTimePoints == 1 ) { k = 0 ; } currTimeIdx =
rt_getTimeIdx ( gblInportTUtables [ 4 ] . time , time , gblInportTUtables [ 4
] . nTimePoints , gblInportTUtables [ 4 ] . currTimeIdx , 1 , 0 ) ;
gblInportTUtables [ 4 ] . currTimeIdx = currTimeIdx ; for ( i = 0 ; i < 1 ; i
++ ) { real_T * realPtr1 = ( real_T * ) gblInportTUtables [ 4 ] . ur + i *
gblInportTUtables [ 4 ] . nTimePoints + currTimeIdx ; real_T * realPtr2 =
realPtr1 + 1 * k ; ( void ) rt_Interpolate_Datatype ( realPtr1 , realPtr2 , &
rtU . llz4kpubln , time , gblInportTUtables [ 4 ] . time [ currTimeIdx ] ,
gblInportTUtables [ 4 ] . time [ currTimeIdx + k ] , gblInportTUtables [ 4 ]
. uDataType ) ; } } } if ( gblInportTUtables [ 5 ] . nTimePoints > 0 ) { if (
1 ) { real_T time = ssGetTaskTime ( rtS , 0 ) ; int k = 1 ; if (
gblInportTUtables [ 5 ] . nTimePoints == 1 ) { k = 0 ; } currTimeIdx =
rt_getTimeIdx ( gblInportTUtables [ 5 ] . time , time , gblInportTUtables [ 5
] . nTimePoints , gblInportTUtables [ 5 ] . currTimeIdx , 1 , 0 ) ;
gblInportTUtables [ 5 ] . currTimeIdx = currTimeIdx ; for ( i = 0 ; i < 1 ; i
++ ) { real_T * realPtr1 = ( real_T * ) gblInportTUtables [ 5 ] . ur + i *
gblInportTUtables [ 5 ] . nTimePoints + currTimeIdx ; real_T * realPtr2 =
realPtr1 + 1 * k ; ( void ) rt_Interpolate_Datatype ( realPtr1 , realPtr2 , &
rtU . niiurjsjc4 , time , gblInportTUtables [ 5 ] . time [ currTimeIdx ] ,
gblInportTUtables [ 5 ] . time [ currTimeIdx + k ] , gblInportTUtables [ 5 ]
. uDataType ) ; } } } } rtB . odxbyhfnjy = rtX . ntgyq4g0p5 ; rtB .
foxxyx2prs = rtX . azqf4obajp ; rtB . gu2acazgtg = rtX . kibywkbko4 ; rtB .
cgoxntm3cy = rtX . d3bftye4ie ; if ( ssIsMajorTimeStep ( rtS ) ) { rtDW .
mnimyxb55z = rtB . cgoxntm3cy >= rtP . Saturation1_UpperSat ? 1 : rtB .
cgoxntm3cy > rtP . Saturation1_LowerSat ? 0 : - 1 ; } rtB . er35ifrkzu = rtDW
. mnimyxb55z == 1 ? rtP . Saturation1_UpperSat : rtDW . mnimyxb55z == - 1 ?
rtP . Saturation1_LowerSat : rtB . cgoxntm3cy ; ic5indijw0 = rtX . opjkxrmhm3
; rtB . ajay0ec0a5 = rtP . Gain2_Gain * ic5indijw0 ; hbdkiq1ssm = ( ( rtU .
niiurjsjc4 + 0.832 ) * 43.42 - 35.0 ) / 57.3 ; rtB . drjhwz0swq = rtP .
Gain3_Gain * hbdkiq1ssm ; ct2zizj5rl = rtX . bwmqhcsduy ; rtB . p1o5o0huo5 =
rtP . Gain_Gain * ct2zizj5rl ; h4oig4g3ai = ( ( rtU . kdtagg3114 + 0.965 ) *
38.48 - 35.0 ) / 57.3 ; rtB . kt1hgvmhli = rtP . Gain1_Gain * h4oig4g3ai ;
fnfizpm4ke = rtX . poycw33cyc ; rtB . gmrr3mvav2 = rtP . Gain5_Gain *
fnfizpm4ke ; rtB . nlhuxkkeaz = rtX . asir0wexi1 ; if ( ssIsMajorTimeStep (
rtS ) ) { rtDW . ohx50ui1o4 = rtB . nlhuxkkeaz >= rtP . Saturation_UpperSat ?
1 : rtB . nlhuxkkeaz > rtP . Saturation_LowerSat ? 0 : - 1 ; } hulx4b0xac =
rtDW . ohx50ui1o4 == 1 ? rtP . Saturation_UpperSat : rtDW . ohx50ui1o4 == - 1
? rtP . Saturation_LowerSat : rtB . nlhuxkkeaz ; rtB . ijrotbd5mr = rtP .
Gain4_Gain * hulx4b0xac ; rtB . buww11xrcy = rtX . j2swejbzkh ; rtB .
j3qtsodunc = rtX . itoxuokcqb ; rtB . potxx0uoyq = rtX . awf1utodht ; rtB .
i02owl5e5u = rtX . halffsymco ; rtB . abinfjhkvm = rtX . j44tdkv0pi ; rtB .
mz3wi0objr = rtX . cy1aw34iqa ; lqpihehx1y = muDoubleScalarSin ( ic5indijw0 )
; h1hrwz3sl3 = muDoubleScalarSin ( ct2zizj5rl ) ; h3m1x4cpg4 =
muDoubleScalarCos ( ct2zizj5rl ) ; ebxqlugq1f = muDoubleScalarSin (
fnfizpm4ke ) ; mobcqbssig = muDoubleScalarCos ( fnfizpm4ke ) ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . jpcc0h3u4c = rtP . ineretia_yy_Value
- rtP . inertia_zz_Value ; } rtB . gki0p45sip = ( ( ( hbdkiq1ssm - ic5indijw0
) * rtP . kpt_Gain - rtP . kdt_Gain * rtB . j3qtsodunc ) * rtP .
Arm_length_Value + rtB . buww11xrcy * rtB . potxx0uoyq * rtB . jpcc0h3u4c ) /
rtP . inertia_xx_Value ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB .
o0cigleavc = rtP . inertia_zz_Value - rtP . inertia_xx_Value ; } rtB .
pr3cdevtxw = ( ( ( h4oig4g3ai - ct2zizj5rl ) * rtP . kpp_Gain - rtP .
kdp_Gain * rtB . buww11xrcy ) * rtP . Arm_length_Value + rtB . j3qtsodunc *
rtB . potxx0uoyq * rtB . o0cigleavc ) / rtP . ineretia_yy_Value ; h4oig4g3ai
= ( ( ( rtB . er35ifrkzu - rtB . gu2acazgtg ) * rtP . kpz_Gain - rtP .
kdz_Gain * rtB . i02owl5e5u ) + rtP . Constant1_Value ) * rtP . m_Gain / (
muDoubleScalarCos ( ct2zizj5rl ) * muDoubleScalarCos ( ic5indijw0 ) ) ; rtB .
lywxjaghek = ( lqpihehx1y * mobcqbssig * h3m1x4cpg4 + ebxqlugq1f * h1hrwz3sl3
) * h4oig4g3ai / rtP . mass_Value ; rtB . lnzeezoyal = ( ebxqlugq1f *
lqpihehx1y * h3m1x4cpg4 - h1hrwz3sl3 * mobcqbssig ) * h4oig4g3ai / rtP .
mass_Value ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . mw40puxvb2 = rtP .
inertia_xx_Value - rtP . ineretia_yy_Value ; } rtB . fcn0xbpc3t = ( ( (
hulx4b0xac - fnfizpm4ke ) * rtP . kpps_Gain - rtP . kdps_Gain * rtB .
potxx0uoyq ) + rtB . j3qtsodunc * rtB . buww11xrcy * rtB . mw40puxvb2 ) / rtP
. inertia_zz_Value ; rtB . mtv0qk2lm0 = muDoubleScalarCos ( ic5indijw0 ) *
h3m1x4cpg4 * h4oig4g3ai / rtP . mass_Value - rtP . u5_Value ; rtB .
lqnelcz1fn = ( ( rtU . ahpzfcqoif + 0.956 ) * 21.61 - 20.0 ) / 57.3 ; rtB .
fteev5olqz = 14.81 * rtU . morfifqs3m / 1.17 ; UNUSED_PARAMETER ( tid ) ; }
void MdlUpdate ( int_T tid ) { UNUSED_PARAMETER ( tid ) ; } void
MdlDerivatives ( void ) { { ( ( XDot * ) ssGetdX ( rtS ) ) -> ntgyq4g0p5 =
rtB . abinfjhkvm ; } { ( ( XDot * ) ssGetdX ( rtS ) ) -> azqf4obajp = rtB .
mz3wi0objr ; } { ( ( XDot * ) ssGetdX ( rtS ) ) -> kibywkbko4 = rtB .
i02owl5e5u ; } { ( ( XDot * ) ssGetdX ( rtS ) ) -> d3bftye4ie = rtB .
fteev5olqz ; } { ( ( XDot * ) ssGetdX ( rtS ) ) -> opjkxrmhm3 = rtB .
j3qtsodunc ; } { ( ( XDot * ) ssGetdX ( rtS ) ) -> bwmqhcsduy = rtB .
buww11xrcy ; } { ( ( XDot * ) ssGetdX ( rtS ) ) -> poycw33cyc = rtB .
potxx0uoyq ; } { ( ( XDot * ) ssGetdX ( rtS ) ) -> asir0wexi1 = rtB .
lqnelcz1fn ; } { ( ( XDot * ) ssGetdX ( rtS ) ) -> j2swejbzkh = rtB .
pr3cdevtxw ; } { ( ( XDot * ) ssGetdX ( rtS ) ) -> itoxuokcqb = rtB .
gki0p45sip ; } { ( ( XDot * ) ssGetdX ( rtS ) ) -> awf1utodht = rtB .
fcn0xbpc3t ; } { ( ( XDot * ) ssGetdX ( rtS ) ) -> halffsymco = rtB .
mtv0qk2lm0 ; } { ( ( XDot * ) ssGetdX ( rtS ) ) -> j44tdkv0pi = rtB .
lywxjaghek ; } { ( ( XDot * ) ssGetdX ( rtS ) ) -> cy1aw34iqa = rtB .
lnzeezoyal ; } } void MdlProjection ( void ) { } void MdlZeroCrossings ( void
) { ZCV * _rtZCSV ; _rtZCSV = ( ( ZCV * ) ssGetSolverZcSignalVector ( rtS ) )
; _rtZCSV -> n4l3vok4dz = rtB . cgoxntm3cy - rtP . Saturation1_UpperSat ;
_rtZCSV -> frznyubji0 = rtB . cgoxntm3cy - rtP . Saturation1_LowerSat ;
_rtZCSV -> c1f2nbygep = rtB . nlhuxkkeaz - rtP . Saturation_UpperSat ;
_rtZCSV -> e2bownnie3 = rtB . nlhuxkkeaz - rtP . Saturation_LowerSat ; } void
MdlTerminate ( void ) { } void MdlInitializeSizes ( void ) {
ssSetNumContStates ( rtS , 14 ) ; ssSetNumPeriodicContStates ( rtS , 0 ) ;
ssSetNumY ( rtS , 0 ) ; ssSetNumU ( rtS , 6 ) ; ssSetDirectFeedThrough ( rtS
, 1 ) ; ssSetNumSampleTimes ( rtS , 2 ) ; ssSetNumBlocks ( rtS , 97 ) ;
ssSetNumBlockIO ( rtS , 29 ) ; ssSetNumBlockParams ( rtS , 40 ) ; } void
MdlInitializeSampleTimes ( void ) { ssSetSampleTime ( rtS , 0 , 0.0 ) ;
ssSetSampleTime ( rtS , 1 , 0.0 ) ; ssSetOffsetTime ( rtS , 0 , 0.0 ) ;
ssSetOffsetTime ( rtS , 1 , 1.0 ) ; } void raccel_set_checksum ( SimStruct *
rtS ) { ssSetChecksumVal ( rtS , 0 , 2804670492U ) ; ssSetChecksumVal ( rtS ,
1 , 392437038U ) ; ssSetChecksumVal ( rtS , 2 , 2387502295U ) ;
ssSetChecksumVal ( rtS , 3 , 1566906608U ) ; } SimStruct *
raccel_register_model ( void ) { static struct _ssMdlInfo mdlInfo ; ( void )
memset ( ( char * ) rtS , 0 , sizeof ( SimStruct ) ) ; ( void ) memset ( (
char * ) & mdlInfo , 0 , sizeof ( struct _ssMdlInfo ) ) ; ssSetMdlInfoPtr (
rtS , & mdlInfo ) ; { static time_T mdlPeriod [ NSAMPLE_TIMES ] ; static
time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T mdlTaskTimes [
NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ; static int_T
mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T mdlTNextWasAdjustedPtr [
NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits [ NSAMPLE_TIMES *
NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [ NSAMPLE_TIMES ] ; {
int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) { mdlPeriod [ i ] = 0.0 ;
mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ; mdlTsMap [ i ] = i ;
mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS , & mdlPeriod [ 0 ] )
; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ; ssSetSampleTimeTaskIDPtr (
rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , & mdlTaskTimes [ 0 ] ) ;
ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ; ssSetTNextWasAdjustedPtr
( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ; ssSetPerTaskSampleHitsPtr ( rtS ,
& mdlPerTaskSampleHits [ 0 ] ) ; ssSetTimeOfNextSampleHitPtr ( rtS , &
mdlTimeOfNextSampleHit [ 0 ] ) ; } ssSetSolverMode ( rtS ,
SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS , ( ( void * ) & rtB ) ) ;
( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof ( B ) ) ; } { ssSetU (
rtS , ( ( void * ) & rtU ) ) ; ( void ) memset ( ( void * ) & rtU , 0 ,
sizeof ( ExtU ) ) ; } ssSetDefaultParam ( rtS , ( real_T * ) & rtP ) ; {
real_T * x = ( real_T * ) & rtX ; ssSetContStates ( rtS , x ) ; ( void )
memset ( ( void * ) x , 0 , sizeof ( X ) ) ; } { void * dwork = ( void * ) &
rtDW ; ssSetRootDWork ( rtS , dwork ) ; ( void ) memset ( dwork , 0 , sizeof
( DW ) ) ; } { static DataTypeTransInfo dtInfo ; ( void ) memset ( ( char_T *
) & dtInfo , 0 , sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS , & dtInfo
) ; dtInfo . numDataTypes = 14 ; dtInfo . dataTypeSizes = & rtDataTypeSizes [
0 ] ; dtInfo . dataTypeNames = & rtDataTypeNames [ 0 ] ; dtInfo . B = &
rtBTransTable ; dtInfo . P = & rtPTransTable ; }
Innerloop_joystick_InitializeDataMapInfo ( rtS ) ;
ssSetIsRapidAcceleratorActive ( rtS , true ) ; ssSetRootSS ( rtS , rtS ) ;
ssSetVersion ( rtS , SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS ,
"Innerloop_joystick" ) ; ssSetPath ( rtS , "Innerloop_joystick" ) ;
ssSetTStart ( rtS , 0.0 ) ; ssSetTFinal ( rtS , 100.0 ) ; { static RTWLogInfo
rt_DataLoggingInfo ; ssSetRTWLogInfo ( rtS , & rt_DataLoggingInfo ) ; } { {
static int_T rt_LoggedStateWidths [ ] = { 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,
1 , 1 , 1 , 1 , 1 } ; static int_T rt_LoggedStateNumDimensions [ ] = { 1 , 1
, 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 } ; static int_T
rt_LoggedStateDimensions [ ] = { 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,
1 , 1 , 1 } ; static boolean_T rt_LoggedStateIsVarDims [ ] = { 0 , 0 , 0 , 0
, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ; static BuiltInDTypeId
rt_LoggedStateDataTypeIds [ ] = { SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE } ; static int_T
rt_LoggedStateComplexSignals [ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 } ; static const char_T * rt_LoggedStateLabels [ ] = { "CSTATE"
, "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE"
, "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" } ; static
const char_T * rt_LoggedStateBlockNames [ ] = {
"Innerloop_joystick/Integrator" , "Innerloop_joystick/Integrator1" ,
"Innerloop_joystick/Dynamic model/Integrator7" ,
"Innerloop_joystick/Integrator3" ,
"Innerloop_joystick/Dynamic model/Integrator4" ,
"Innerloop_joystick/Dynamic model/Integrator3" ,
"Innerloop_joystick/Dynamic model/Integrator5" ,
"Innerloop_joystick/Integrator2" ,
"Innerloop_joystick/Dynamic model/Integrator" ,
"Innerloop_joystick/Dynamic model/Integrator1" ,
"Innerloop_joystick/Dynamic model/Integrator2" ,
"Innerloop_joystick/Dynamic model/Integrator6" ,
"Innerloop_joystick/Dynamic model/Integrator8" ,
"Innerloop_joystick/Dynamic model/Integrator9" } ; static const char_T *
rt_LoggedStateNames [ ] = { "" , "" , "" , "" , "" , "" , "" , "" , "" , "" ,
"" , "" , "" , "" } ; static boolean_T rt_LoggedStateCrossMdlRef [ ] = { 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ; static
RTWLogDataTypeConvert rt_RTWLogDataTypeConvert [ ] = { { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } } ; static
RTWLogSignalInfo rt_LoggedStateSignalInfo = { 14 , rt_LoggedStateWidths ,
rt_LoggedStateNumDimensions , rt_LoggedStateDimensions ,
rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , { rt_LoggedStateLabels } , ( NULL )
, ( NULL ) , ( NULL ) , { rt_LoggedStateBlockNames } , { rt_LoggedStateNames
} , rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert } ; static void *
rt_LoggedStateSignalPtrs [ 14 ] ; rtliSetLogXSignalPtrs ( ssGetRTWLogInfo (
rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . ntgyq4g0p5 ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtX . azqf4obajp ;
rt_LoggedStateSignalPtrs [ 2 ] = ( void * ) & rtX . kibywkbko4 ;
rt_LoggedStateSignalPtrs [ 3 ] = ( void * ) & rtX . d3bftye4ie ;
rt_LoggedStateSignalPtrs [ 4 ] = ( void * ) & rtX . opjkxrmhm3 ;
rt_LoggedStateSignalPtrs [ 5 ] = ( void * ) & rtX . bwmqhcsduy ;
rt_LoggedStateSignalPtrs [ 6 ] = ( void * ) & rtX . poycw33cyc ;
rt_LoggedStateSignalPtrs [ 7 ] = ( void * ) & rtX . asir0wexi1 ;
rt_LoggedStateSignalPtrs [ 8 ] = ( void * ) & rtX . j2swejbzkh ;
rt_LoggedStateSignalPtrs [ 9 ] = ( void * ) & rtX . itoxuokcqb ;
rt_LoggedStateSignalPtrs [ 10 ] = ( void * ) & rtX . awf1utodht ;
rt_LoggedStateSignalPtrs [ 11 ] = ( void * ) & rtX . halffsymco ;
rt_LoggedStateSignalPtrs [ 12 ] = ( void * ) & rtX . j44tdkv0pi ;
rt_LoggedStateSignalPtrs [ 13 ] = ( void * ) & rtX . cy1aw34iqa ; }
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "tmp_raccel_xout" ) ; rtliSetLogXFinal (
ssGetRTWLogInfo ( rtS ) , "xFinal" ) ; rtliSetLogVarNameModifier (
ssGetRTWLogInfo ( rtS ) , "none" ) ; rtliSetLogFormat ( ssGetRTWLogInfo ( rtS
) , 2 ) ; rtliSetLogMaxRows ( ssGetRTWLogInfo ( rtS ) , 1000 ) ;
rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS ) , 1 ) ; rtliSetLogY (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogYSignalInfo ( ssGetRTWLogInfo (
rtS ) , ( NULL ) ) ; rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL
) ) ; } { static struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS ,
& statesInfo2 ) ; } { static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetPeriodicStatesInfo ( rtS , & periodicStatesInfo ) ; } { static
ssSolverInfo slvrInfo ; static boolean_T contStatesDisabled [ 14 ] ; static
real_T absTol [ 14 ] = { 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6
, 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 } ;
static uint8_T absTolControl [ 14 ] = { 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U
, 0U , 0U , 0U , 0U , 0U , 0U } ; static uint8_T zcAttributes [ 4 ] = { (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) } ;
static ssNonContDerivSigInfo nonContDerivSigInfo [ 3 ] = { { 1 * sizeof (
real_T ) , ( char * ) ( & rtB . mw40puxvb2 ) , ( NULL ) } , { 1 * sizeof (
real_T ) , ( char * ) ( & rtB . o0cigleavc ) , ( NULL ) } , { 1 * sizeof (
real_T ) , ( char * ) ( & rtB . jpcc0h3u4c ) , ( NULL ) } } ;
ssSetSolverRelTol ( rtS , 0.001 ) ; ssSetStepSize ( rtS , 0.0 ) ;
ssSetMinStepSize ( rtS , 0.0 ) ; ssSetMaxNumMinSteps ( rtS , - 1 ) ;
ssSetMinStepViolatedError ( rtS , 0 ) ; ssSetMaxStepSize ( rtS , 2.0 ) ;
ssSetSolverMaxOrder ( rtS , - 1 ) ; ssSetSolverRefineFactor ( rtS , 1 ) ;
ssSetOutputTimes ( rtS , ( NULL ) ) ; ssSetNumOutputTimes ( rtS , 0 ) ;
ssSetOutputTimesOnly ( rtS , 0 ) ; ssSetOutputTimesIndex ( rtS , 0 ) ;
ssSetZCCacheNeedsReset ( rtS , 0 ) ; ssSetDerivCacheNeedsReset ( rtS , 0 ) ;
ssSetNumNonContDerivSigInfos ( rtS , 3 ) ; ssSetNonContDerivSigInfos ( rtS ,
nonContDerivSigInfo ) ; ssSetSolverInfo ( rtS , & slvrInfo ) ;
ssSetSolverName ( rtS , "ode45" ) ; ssSetVariableStepSolver ( rtS , 1 ) ;
ssSetSolverConsistencyChecking ( rtS , 0 ) ; ssSetSolverAdaptiveZcDetection (
rtS , 0 ) ; ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetAbsTolVector (
rtS , absTol ) ; ssSetAbsTolControlVector ( rtS , absTolControl ) ;
ssSetSolverAbsTol_Obsolete ( rtS , absTol ) ;
ssSetSolverAbsTolControl_Obsolete ( rtS , absTolControl ) ;
ssSetSolverStateProjection ( rtS , 0 ) ; ssSetSolverMassMatrixType ( rtS , (
ssMatrixType ) 0 ) ; ssSetSolverMassMatrixNzMax ( rtS , 0 ) ;
ssSetModelOutputs ( rtS , MdlOutputs ) ; ssSetModelLogData ( rtS ,
rt_UpdateTXYLogVars ) ; ssSetModelUpdate ( rtS , MdlUpdate ) ;
ssSetModelDerivatives ( rtS , MdlDerivatives ) ; ssSetSolverZcSignalAttrib (
rtS , zcAttributes ) ; ssSetSolverNumZcSignals ( rtS , 4 ) ;
ssSetModelZeroCrossings ( rtS , MdlZeroCrossings ) ;
ssSetSolverConsecutiveZCsStepRelTol ( rtS , 2.8421709430404007E-13 ) ;
ssSetSolverMaxConsecutiveZCs ( rtS , 1000 ) ; ssSetSolverConsecutiveZCsError
( rtS , 2 ) ; ssSetSolverMaskedZcDiagnostic ( rtS , 1 ) ;
ssSetSolverIgnoredZcDiagnostic ( rtS , 1 ) ; ssSetSolverMaxConsecutiveMinStep
( rtS , 1 ) ; ssSetSolverShapePreserveControl ( rtS , 2 ) ; ssSetTNextTid (
rtS , INT_MIN ) ; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset (
rtS ) ; ssSetNumNonsampledZCs ( rtS , 4 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ; }
ssSetChecksumVal ( rtS , 0 , 2804670492U ) ; ssSetChecksumVal ( rtS , 1 ,
392437038U ) ; ssSetChecksumVal ( rtS , 2 , 2387502295U ) ; ssSetChecksumVal
( rtS , 3 , 1566906608U ) ; { static const sysRanDType rtAlwaysEnabled =
SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo ; static const
sysRanDType * systemRan [ 2 ] ; ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo
) ; rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = & rtAlwaysEnabled ;
rteiSetModelMappingInfoPtr ( ssGetRTWExtModeInfo ( rtS ) , &
ssGetModelMappingInfo ( rtS ) ) ; rteiSetChecksumsPtr ( ssGetRTWExtModeInfo (
rtS ) , ssGetChecksums ( rtS ) ) ; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS )
, ssGetTPtr ( rtS ) ) ; } return rtS ; }

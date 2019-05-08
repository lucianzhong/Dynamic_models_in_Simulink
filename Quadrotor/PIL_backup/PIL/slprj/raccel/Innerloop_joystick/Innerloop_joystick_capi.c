#include "__cf_Innerloop_joystick.h"
#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "Innerloop_joystick_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#else
#include "builtin_typeid_types.h"
#include "Innerloop_joystick.h"
#include "Innerloop_joystick_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"Innerloop_joystick/Fcn2" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , {
1 , 0 , TARGET_STRING ( "Innerloop_joystick/Fcn3" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 0 } , { 2 , 0 , TARGET_STRING ( "Innerloop_joystick/Gain" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 3 , 0 , TARGET_STRING (
"Innerloop_joystick/Gain1" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , {
4 , 0 , TARGET_STRING ( "Innerloop_joystick/Gain2" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 0 } , { 5 , 0 , TARGET_STRING ( "Innerloop_joystick/Gain3" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 6 , 0 , TARGET_STRING (
"Innerloop_joystick/Gain4" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , {
7 , 0 , TARGET_STRING ( "Innerloop_joystick/Gain5" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 0 } , { 8 , 0 , TARGET_STRING (
"Innerloop_joystick/Integrator" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0
} , { 9 , 0 , TARGET_STRING ( "Innerloop_joystick/Integrator1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 10 , 0 , TARGET_STRING (
"Innerloop_joystick/Integrator2" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0
} , { 11 , 0 , TARGET_STRING ( "Innerloop_joystick/Integrator3" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 12 , 0 , TARGET_STRING (
"Innerloop_joystick/Saturation1" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0
} , { 13 , 0 , TARGET_STRING ( "Innerloop_joystick/Dynamic model/Integrator"
) , TARGET_STRING ( "roll_dot" ) , 0 , 0 , 0 , 0 , 0 } , { 14 , 0 ,
TARGET_STRING ( "Innerloop_joystick/Dynamic model/Integrator1" ) ,
TARGET_STRING ( "pitch_dot" ) , 0 , 0 , 0 , 0 , 0 } , { 15 , 0 ,
TARGET_STRING ( "Innerloop_joystick/Dynamic model/Integrator2" ) ,
TARGET_STRING ( "yaw_dot" ) , 0 , 0 , 0 , 0 , 0 } , { 16 , 0 , TARGET_STRING
( "Innerloop_joystick/Dynamic model/Integrator6" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 0 } , { 17 , 0 , TARGET_STRING (
"Innerloop_joystick/Dynamic model/Integrator7" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 0 } , { 18 , 0 , TARGET_STRING (
"Innerloop_joystick/Dynamic model/Integrator8" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 0 } , { 19 , 0 , TARGET_STRING (
"Innerloop_joystick/Dynamic model/Integrator9" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 0 } , { 20 , 0 , TARGET_STRING (
"Innerloop_joystick/Dynamic model/pitch_dot_dot/Divide4" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 21 , 0 , TARGET_STRING (
"Innerloop_joystick/Dynamic model/pitch_dot_dot/Add6" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 1 } , { 22 , 0 , TARGET_STRING (
"Innerloop_joystick/Dynamic model/roll_dot_dot/Divide3" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 23 , 0 , TARGET_STRING (
"Innerloop_joystick/Dynamic model/roll_dot_dot/Add5" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 1 } , { 24 , 0 , TARGET_STRING (
"Innerloop_joystick/Dynamic model/x_dot_dot/Divide" ) , TARGET_STRING (
"x_dot_dot" ) , 0 , 0 , 0 , 0 , 0 } , { 25 , 0 , TARGET_STRING (
"Innerloop_joystick/Dynamic model/y_dot_dot/Divide1" ) , TARGET_STRING (
"y_dot_dot" ) , 0 , 0 , 0 , 0 , 0 } , { 26 , 0 , TARGET_STRING (
"Innerloop_joystick/Dynamic model/yaw_dot_dot/Divide5" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 0 } , { 27 , 0 , TARGET_STRING (
"Innerloop_joystick/Dynamic model/yaw_dot_dot/Add8" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 1 } , { 28 , 0 , TARGET_STRING (
"Innerloop_joystick/Dynamic model/z_dot_dot/Add4" ) , TARGET_STRING (
"z_dot_dot" ) , 0 , 0 , 0 , 0 , 0 } , { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 ,
0 , 0 , 0 } } ; static const rtwCAPI_BlockParameters rtBlockParameters [ ] =
{ { 29 , TARGET_STRING ( "Innerloop_joystick/Gain" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 30 , TARGET_STRING ( "Innerloop_joystick/Gain1" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 31 , TARGET_STRING (
"Innerloop_joystick/Gain2" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 32
, TARGET_STRING ( "Innerloop_joystick/Gain3" ) , TARGET_STRING ( "Gain" ) , 0
, 0 , 0 } , { 33 , TARGET_STRING ( "Innerloop_joystick/Gain4" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 34 , TARGET_STRING (
"Innerloop_joystick/Gain5" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 35
, TARGET_STRING ( "Innerloop_joystick/Integrator" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 36 , TARGET_STRING (
"Innerloop_joystick/Integrator1" ) , TARGET_STRING ( "InitialCondition" ) , 0
, 0 , 0 } , { 37 , TARGET_STRING ( "Innerloop_joystick/Integrator2" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 38 , TARGET_STRING (
"Innerloop_joystick/Integrator3" ) , TARGET_STRING ( "InitialCondition" ) , 0
, 0 , 0 } , { 39 , TARGET_STRING ( "Innerloop_joystick/Saturation" ) ,
TARGET_STRING ( "UpperLimit" ) , 0 , 0 , 0 } , { 40 , TARGET_STRING (
"Innerloop_joystick/Saturation" ) , TARGET_STRING ( "LowerLimit" ) , 0 , 0 ,
0 } , { 41 , TARGET_STRING ( "Innerloop_joystick/Saturation1" ) ,
TARGET_STRING ( "UpperLimit" ) , 0 , 0 , 0 } , { 42 , TARGET_STRING (
"Innerloop_joystick/Saturation1" ) , TARGET_STRING ( "LowerLimit" ) , 0 , 0 ,
0 } , { 43 , TARGET_STRING ( "Innerloop_joystick/Dynamic model/Integrator" )
, TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 44 , TARGET_STRING (
"Innerloop_joystick/Dynamic model/Integrator1" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 45 , TARGET_STRING (
"Innerloop_joystick/Dynamic model/Integrator2" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 46 , TARGET_STRING (
"Innerloop_joystick/Dynamic model/Integrator3" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 47 , TARGET_STRING (
"Innerloop_joystick/Dynamic model/Integrator4" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 48 , TARGET_STRING (
"Innerloop_joystick/Dynamic model/Integrator5" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 49 , TARGET_STRING (
"Innerloop_joystick/Dynamic model/Integrator6" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 50 , TARGET_STRING (
"Innerloop_joystick/Dynamic model/Integrator7" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 51 , TARGET_STRING (
"Innerloop_joystick/Dynamic model/Integrator8" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 52 , TARGET_STRING (
"Innerloop_joystick/Dynamic model/Integrator9" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 53 , TARGET_STRING (
"Innerloop_joystick/PD controller/Constant1" ) , TARGET_STRING ( "Value" ) ,
0 , 0 , 0 } , { 54 , TARGET_STRING ( "Innerloop_joystick/PD controller/kdp" )
, TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 55 , TARGET_STRING (
"Innerloop_joystick/PD controller/kdps" ) , TARGET_STRING ( "Gain" ) , 0 , 0
, 0 } , { 56 , TARGET_STRING ( "Innerloop_joystick/PD controller/kdt" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 57 , TARGET_STRING (
"Innerloop_joystick/PD controller/kdz" ) , TARGET_STRING ( "Gain" ) , 0 , 0 ,
0 } , { 58 , TARGET_STRING ( "Innerloop_joystick/PD controller/kpp" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 59 , TARGET_STRING (
"Innerloop_joystick/PD controller/kpps" ) , TARGET_STRING ( "Gain" ) , 0 , 0
, 0 } , { 60 , TARGET_STRING ( "Innerloop_joystick/PD controller/kpt" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 61 , TARGET_STRING (
"Innerloop_joystick/PD controller/kpz" ) , TARGET_STRING ( "Gain" ) , 0 , 0 ,
0 } , { 62 , TARGET_STRING ( "Innerloop_joystick/PD controller/m" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 63 , TARGET_STRING (
"Innerloop_joystick/property /Arm_length_" ) , TARGET_STRING ( "Value" ) , 0
, 0 , 0 } , { 64 , TARGET_STRING ( "Innerloop_joystick/property /ineretia_yy"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 65 , TARGET_STRING (
"Innerloop_joystick/property /inertia_xx" ) , TARGET_STRING ( "Value" ) , 0 ,
0 , 0 } , { 66 , TARGET_STRING ( "Innerloop_joystick/property /inertia_zz" )
, TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 67 , TARGET_STRING (
"Innerloop_joystick/property /mass" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0
} , { 68 , TARGET_STRING ( "Innerloop_joystick/Dynamic model/z_dot_dot/u5" )
, TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 , 0
, 0 } } ; static const rtwCAPI_ModelParameters rtModelParameters [ ] = { { 0
, ( NULL ) , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . lqnelcz1fn , & rtB . fteev5olqz ,
& rtB . p1o5o0huo5 , & rtB . kt1hgvmhli , & rtB . ajay0ec0a5 , & rtB .
drjhwz0swq , & rtB . ijrotbd5mr , & rtB . gmrr3mvav2 , & rtB . odxbyhfnjy , &
rtB . foxxyx2prs , & rtB . nlhuxkkeaz , & rtB . cgoxntm3cy , & rtB .
er35ifrkzu , & rtB . buww11xrcy , & rtB . j3qtsodunc , & rtB . potxx0uoyq , &
rtB . i02owl5e5u , & rtB . gu2acazgtg , & rtB . abinfjhkvm , & rtB .
mz3wi0objr , & rtB . gki0p45sip , & rtB . jpcc0h3u4c , & rtB . pr3cdevtxw , &
rtB . o0cigleavc , & rtB . lywxjaghek , & rtB . lnzeezoyal , & rtB .
fcn0xbpc3t , & rtB . mw40puxvb2 , & rtB . mtv0qk2lm0 , & rtP . Gain_Gain , &
rtP . Gain1_Gain , & rtP . Gain2_Gain , & rtP . Gain3_Gain , & rtP .
Gain4_Gain , & rtP . Gain5_Gain , & rtP . Integrator_IC , & rtP .
Integrator1_IC , & rtP . Integrator2_IC , & rtP . Integrator3_IC , & rtP .
Saturation_UpperSat , & rtP . Saturation_LowerSat , & rtP .
Saturation1_UpperSat , & rtP . Saturation1_LowerSat , & rtP .
Integrator_IC_cv5aw0xgvv , & rtP . Integrator1_IC_aul1jddy20 , & rtP .
Integrator2_IC_p13irtit1l , & rtP . Integrator3_IC_oj4bssacfz , & rtP .
Integrator4_IC , & rtP . Integrator5_IC , & rtP . Integrator6_IC , & rtP .
Integrator7_IC , & rtP . Integrator8_IC , & rtP . Integrator9_IC , & rtP .
Constant1_Value , & rtP . kdp_Gain , & rtP . kdps_Gain , & rtP . kdt_Gain , &
rtP . kdz_Gain , & rtP . kpp_Gain , & rtP . kpps_Gain , & rtP . kpt_Gain , &
rtP . kpz_Gain , & rtP . m_Gain , & rtP . Arm_length_Value , & rtP .
ineretia_yy_Value , & rtP . inertia_xx_Value , & rtP . inertia_zz_Value , &
rtP . mass_Value , & rtP . u5_Value , } ; static int32_T * rtVarDimsAddrMap [
] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , SS_DOUBLE , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } } ; static const uint_T rtDimensionArray [ ] = {
1 , 1 } ; static const real_T rtcapiStoredFloats [ ] = { 0.0 , 1.0 } ; static
const rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , 0 } , } ; static const rtwCAPI_SampleTimeMap
rtSampleTimeMap [ ] = { { ( const void * ) & rtcapiStoredFloats [ 0 ] , (
const void * ) & rtcapiStoredFloats [ 0 ] , 0 , 0 } , { ( const void * ) &
rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [ 1 ] , 1 ,
0 } } ; static rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals
, 29 , ( NULL ) , 0 , ( NULL ) , 0 } , { rtBlockParameters , 40 ,
rtModelParameters , 0 } , { ( NULL ) , 0 } , { rtDataTypeMap , rtDimensionMap
, rtFixPtMap , rtElementMap , rtSampleTimeMap , rtDimensionArray } , "float"
, { 2804670492U , 392437038U , 2387502295U , 1566906608U } , ( NULL ) , 0 , 0
} ; const rtwCAPI_ModelMappingStaticInfo *
Innerloop_joystick_GetCAPIStaticMap ( ) { return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void Innerloop_joystick_InitializeDataMapInfo ( SimStruct * const rtS ) {
rtwCAPI_SetVersion ( ( * rt_dataMapInfoPtr ) . mmi , 1 ) ;
rtwCAPI_SetStaticMap ( ( * rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ;
rtwCAPI_SetLoggingStaticMap ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetDataAddressMap ( ( * rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ;
rtwCAPI_SetVarDimsAddressMap ( ( * rt_dataMapInfoPtr ) . mmi ,
rtVarDimsAddrMap ) ; rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr )
. mmi , ( NULL ) ) ; rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi
, ( NULL ) ) ; rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi ,
0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void Innerloop_joystick_host_InitializeDataMapInfo (
Innerloop_joystick_host_DataMapInfo_T * dataMap , const char * path ) {
rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ; rtwCAPI_SetStaticMap ( dataMap ->
mmi , & mmiStatic ) ; rtwCAPI_SetDataAddressMap ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , NULL ) ; rtwCAPI_SetPath (
dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif

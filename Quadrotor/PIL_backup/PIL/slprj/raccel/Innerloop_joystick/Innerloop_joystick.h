#include "__cf_Innerloop_joystick.h"
#ifndef RTW_HEADER_Innerloop_joystick_h_
#define RTW_HEADER_Innerloop_joystick_h_
#include <stddef.h>
#include <string.h>
#include "rtw_modelmap.h"
#ifndef Innerloop_joystick_COMMON_INCLUDES_
#define Innerloop_joystick_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "Innerloop_joystick_types.h"
#include "multiword_types.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#define MODEL_NAME Innerloop_joystick
#define NSAMPLE_TIMES (2) 
#define NINPUTS (6)       
#define NOUTPUTS (0)     
#define NBLOCKIO (29) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (14)   
#elif NCSTATES != 14
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T odxbyhfnjy ; real_T foxxyx2prs ; real_T gu2acazgtg ;
real_T cgoxntm3cy ; real_T er35ifrkzu ; real_T ajay0ec0a5 ; real_T drjhwz0swq
; real_T p1o5o0huo5 ; real_T kt1hgvmhli ; real_T gmrr3mvav2 ; real_T
nlhuxkkeaz ; real_T ijrotbd5mr ; real_T buww11xrcy ; real_T j3qtsodunc ;
real_T potxx0uoyq ; real_T i02owl5e5u ; real_T abinfjhkvm ; real_T mz3wi0objr
; real_T jpcc0h3u4c ; real_T gki0p45sip ; real_T o0cigleavc ; real_T
pr3cdevtxw ; real_T lywxjaghek ; real_T lnzeezoyal ; real_T mw40puxvb2 ;
real_T fcn0xbpc3t ; real_T mtv0qk2lm0 ; real_T lqnelcz1fn ; real_T fteev5olqz
; } B ; typedef struct { struct { void * LoggedData ; } p1y0lpolue ; struct {
void * LoggedData ; } nhx1rfznmk ; struct { void * LoggedData ; } efv5lclxva
; struct { void * LoggedData ; } c0d0ab2vsm ; struct { void * LoggedData ; }
jqn1t2kbif ; struct { void * LoggedData ; } bosnyh10wo ; struct { void *
LoggedData ; } d0gsv44bin ; struct { void * LoggedData ; } kqkb2krtj4 ;
struct { void * LoggedData ; } abfshihfjc ; int_T mnimyxb55z ; int_T
ohx50ui1o4 ; } DW ; typedef struct { real_T ntgyq4g0p5 ; real_T azqf4obajp ;
real_T kibywkbko4 ; real_T d3bftye4ie ; real_T opjkxrmhm3 ; real_T bwmqhcsduy
; real_T poycw33cyc ; real_T asir0wexi1 ; real_T j2swejbzkh ; real_T
itoxuokcqb ; real_T awf1utodht ; real_T halffsymco ; real_T j44tdkv0pi ;
real_T cy1aw34iqa ; } X ; typedef struct { real_T ntgyq4g0p5 ; real_T
azqf4obajp ; real_T kibywkbko4 ; real_T d3bftye4ie ; real_T opjkxrmhm3 ;
real_T bwmqhcsduy ; real_T poycw33cyc ; real_T asir0wexi1 ; real_T j2swejbzkh
; real_T itoxuokcqb ; real_T awf1utodht ; real_T halffsymco ; real_T
j44tdkv0pi ; real_T cy1aw34iqa ; } XDot ; typedef struct { boolean_T
ntgyq4g0p5 ; boolean_T azqf4obajp ; boolean_T kibywkbko4 ; boolean_T
d3bftye4ie ; boolean_T opjkxrmhm3 ; boolean_T bwmqhcsduy ; boolean_T
poycw33cyc ; boolean_T asir0wexi1 ; boolean_T j2swejbzkh ; boolean_T
itoxuokcqb ; boolean_T awf1utodht ; boolean_T halffsymco ; boolean_T
j44tdkv0pi ; boolean_T cy1aw34iqa ; } XDis ; typedef struct { real_T
ntgyq4g0p5 ; real_T azqf4obajp ; real_T kibywkbko4 ; real_T d3bftye4ie ;
real_T opjkxrmhm3 ; real_T bwmqhcsduy ; real_T poycw33cyc ; real_T asir0wexi1
; real_T j2swejbzkh ; real_T itoxuokcqb ; real_T awf1utodht ; real_T
halffsymco ; real_T j44tdkv0pi ; real_T cy1aw34iqa ; } CStateAbsTol ; typedef
struct { real_T n4l3vok4dz ; real_T frznyubji0 ; real_T c1f2nbygep ; real_T
e2bownnie3 ; } ZCV ; typedef struct { real_T morfifqs3m ; real_T lpqa3ddvpp ;
real_T ahpzfcqoif ; real_T kdtagg3114 ; real_T llz4kpubln ; real_T niiurjsjc4
; } ExtU ; typedef struct { rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ;
struct P_ { real_T Integrator_IC ; real_T Integrator1_IC ; real_T
Integrator7_IC ; real_T Integrator3_IC ; real_T Saturation1_UpperSat ; real_T
Saturation1_LowerSat ; real_T Integrator4_IC ; real_T Gain2_Gain ; real_T
Gain3_Gain ; real_T Integrator3_IC_oj4bssacfz ; real_T Gain_Gain ; real_T
Gain1_Gain ; real_T Integrator5_IC ; real_T Gain5_Gain ; real_T
Integrator2_IC ; real_T Saturation_UpperSat ; real_T Saturation_LowerSat ;
real_T Gain4_Gain ; real_T Integrator_IC_cv5aw0xgvv ; real_T
Integrator1_IC_aul1jddy20 ; real_T Integrator2_IC_p13irtit1l ; real_T
Integrator6_IC ; real_T Integrator8_IC ; real_T Integrator9_IC ; real_T
kpt_Gain ; real_T kdt_Gain ; real_T Arm_length_Value ; real_T
ineretia_yy_Value ; real_T inertia_zz_Value ; real_T inertia_xx_Value ;
real_T kpp_Gain ; real_T kdp_Gain ; real_T kpz_Gain ; real_T kdz_Gain ;
real_T Constant1_Value ; real_T m_Gain ; real_T mass_Value ; real_T kpps_Gain
; real_T kdps_Gain ; real_T u5_Value ; } ; extern P rtP ; extern const char *
RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X rtX ; extern DW rtDW ;
extern ExtU rtU ; extern const rtwCAPI_ModelMappingStaticInfo *
Innerloop_joystick_GetCAPIStaticMap ( void ) ; extern SimStruct * const rtS ;
extern const int_T gblNumToFiles ; extern const int_T gblNumFrFiles ; extern
const int_T gblNumFrWksBlocks ; extern rtInportTUtable * gblInportTUtables ;
extern const char * gblInportFileName ; extern const int_T
gblNumRootInportBlks ; extern const int_T gblNumModelInputs ; extern const
int_T gblInportDataTypeIdx [ ] ; extern const int_T gblInportDims [ ] ;
extern const int_T gblInportComplex [ ] ; extern const int_T
gblInportInterpoFlag [ ] ; extern const int_T gblInportContinuous [ ] ;
extern DataMapInfo * rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo *
rt_modelMapInfoPtr ; void MdlOutputs ( int_T tid ) ; void
MdlOutputsParameterSampleTime ( int_T tid ) ; void MdlUpdate ( int_T tid ) ;
void MdlTerminate ( void ) ; void MdlInitializeSizes ( void ) ; void
MdlInitializeSampleTimes ( void ) ; SimStruct * raccel_register_model ( void
) ;
#endif

#include "__cf_mdlref_dynamics.h"
#ifndef RTW_HEADER_mdlref_dynamics_h_
#define RTW_HEADER_mdlref_dynamics_h_
#include <string.h>
#include <stddef.h>
#include "rtw_modelmap.h"
#ifndef mdlref_dynamics_COMMON_INCLUDES_
#define mdlref_dynamics_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#endif
#include "mdlref_dynamics_types.h"
#include "multiword_types.h"
#include "model_reference_types.h"
#include "rt_nonfinite.h"
typedef struct { real_T dzmgpohyiu ; real_T p344drfp0z ; real_T ksh4va5vei ;
real_T fvsvj2r5aa ; real_T p4hyg0dqbc ; real_T odn1wsebah ; } b2yern2xnu ;
typedef struct { real_T kyhnitqr2q ; real_T ajfiljalrb ; } bcn0znuh2k ;
typedef struct { real_T kyhnitqr2q ; real_T ajfiljalrb ; } jgt53fueyv ;
typedef struct { boolean_T kyhnitqr2q ; boolean_T ajfiljalrb ; } mqtc13tztz ;
typedef struct { real_T kyhnitqr2q ; real_T ajfiljalrb ; } efvixdhvfy ;
struct gtpwgcczci { struct SimStruct_tag * _mdlRefSfcnS ; struct {
rtwCAPI_ModelMappingInfo mmi ; rtwCAPI_ModelMapLoggingInstanceInfo
mmiLogInstanceInfo ; void * dataAddress [ 2 ] ; int32_T * vardimsAddress [ 2
] ; sysRanDType * systemRan [ 2 ] ; int_T systemTid [ 2 ] ; } DataMapInfo ; }
; typedef struct { b2yern2xnu rtb ; pkzqiadb0s rtm ; } jzhyltz23av ; extern
void b1zsspq0wq ( SimStruct * _mdlRefSfcnS , int_T mdlref_TID0 , pkzqiadb0s *
const jordystvml , b2yern2xnu * localB , bcn0znuh2k * localX , void *
sysRanPtr , int contextTid , rtwCAPI_ModelMappingInfo * rt_ParentMMI , const
char_T * rt_ChildPath , int_T rt_ChildMMIIdx , int_T rt_CSTATEIdx ) ; extern
void mr_mdlref_dynamics_MdlInfoRegFcn ( SimStruct * mdlRefSfcnS , char_T *
modelName , int_T * retVal ) ; extern mxArray * mr_mdlref_dynamics_GetDWork (
const jzhyltz23av * mdlrefDW ) ; extern void mr_mdlref_dynamics_SetDWork (
jzhyltz23av * mdlrefDW , const mxArray * ssDW ) ; extern void
mr_mdlref_dynamics_RegisterSimStateChecksum ( SimStruct * S ) ; extern const
rtwCAPI_ModelMappingStaticInfo * mdlref_dynamics_GetCAPIStaticMap ( void ) ;
extern void dshzp10j35 ( bcn0znuh2k * localX ) ; extern void mwlzs2fwpd (
b2yern2xnu * localB , bcn0znuh2k * localX , jgt53fueyv * localXdot ) ; extern
void g1noppauqu ( void ) ; extern void mdlref_dynamics ( const real_T *
ky3zpb4uzb , const real_T * kfmtoprvxm , const real_T * px5tkomgil , real_T *
cdgp0htrwl , real_T * np0knnkpq4 , b2yern2xnu * localB , bcn0znuh2k * localX
) ;
#endif

#include "__cf_mdlref_dynamics.h"
#ifndef _RTW_HEADER_mdlref_dynamics_cap_host_h__
#define _RTW_HEADER_mdlref_dynamics_cap_host_h__
#ifdef HOST_CAPI_BUILD
#include "rtw_capi.h"
#include "rtw_modelmap.h"
typedef struct { rtwCAPI_ModelMappingInfo mmi ; }
mdlref_dynamics_host_DataMapInfo_T ;
#ifdef __cplusplus
extern "C" {
#endif
void mdlref_dynamics_host_InitializeDataMapInfo (
mdlref_dynamics_host_DataMapInfo_T * dataMap , const char * path ) ;
#ifdef __cplusplus
}
#endif
#endif
#endif

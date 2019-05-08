#include "__cf_Innerloop_joystick.h"
#ifndef _RTW_HEADER_Innerloop_joystick_cap_host_h__
#define _RTW_HEADER_Innerloop_joystick_cap_host_h__
#ifdef HOST_CAPI_BUILD
#include "rtw_capi.h"
#include "rtw_modelmap.h"
typedef struct { rtwCAPI_ModelMappingInfo mmi ; }
Innerloop_joystick_host_DataMapInfo_T ;
#ifdef __cplusplus
extern "C" {
#endif
void Innerloop_joystick_host_InitializeDataMapInfo (
Innerloop_joystick_host_DataMapInfo_T * dataMap , const char * path ) ;
#ifdef __cplusplus
}
#endif
#endif
#endif

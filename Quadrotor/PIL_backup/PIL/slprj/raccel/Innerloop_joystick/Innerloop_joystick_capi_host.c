#include "Innerloop_joystick_capi_host.h"
static Innerloop_joystick_host_DataMapInfo_T root;
static int initialized = 0;
__declspec( dllexport ) rtwCAPI_ModelMappingInfo *getRootMappingInfo()
{
    if (initialized == 0) {
        initialized = 1;
        Innerloop_joystick_host_InitializeDataMapInfo(&(root), "Innerloop_joystick");
    }
    return &root.mmi;
}

rtwCAPI_ModelMappingInfo *mexFunction() {return(getRootMappingInfo());}

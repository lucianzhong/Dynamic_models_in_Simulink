/*
 * Navigation_loop_Animation.h
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

#ifndef RTW_HEADER_Navigation_loop_Animation_h_
#define RTW_HEADER_Navigation_loop_Animation_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef Navigation_loop_Animation_COMMON_INCLUDES_
# define Navigation_loop_Animation_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_logging.h"
#endif                                 /* Navigation_loop_Animation_COMMON_INCLUDES_ */

#include "Navigation_loop_Animation_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->ModelData.blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->ModelData.blkStateChange = (val))
#endif

#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->ModelData.blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->ModelData.blockIO = (val))
#endif

#ifndef rtmGetChecksums
# define rtmGetChecksums(rtm)          ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
# define rtmSetChecksums(rtm, val)     ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
# define rtmGetConstBlockIO(rtm)       ((rtm)->ModelData.constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
# define rtmSetConstBlockIO(rtm, val)  ((rtm)->ModelData.constBlockIO = (val))
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

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ()
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ()
#endif

#ifndef rtmGetDefaultParam
# define rtmGetDefaultParam(rtm)       ((rtm)->ModelData.defaultParam)
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ((rtm)->ModelData.defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
# define rtmGetDirectFeedThrough(rtm)  ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
# define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
# define rtmGetErrorStatusFlag(rtm)    ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
# define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
# define rtmSetFinalTime(rtm, val)     ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
# define rtmGetFirstInitCondFlag(rtm)  ()
#endif

#ifndef rtmSetFirstInitCondFlag
# define rtmSetFirstInitCondFlag(rtm, val) ()
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->ModelData.intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->ModelData.intgData = (val))
#endif

#ifndef rtmGetMdlRefGlobalTID
# define rtmGetMdlRefGlobalTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefGlobalTID
# define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
# define rtmGetMdlRefTriggerTID(rtm)   ()
#endif

#ifndef rtmSetMdlRefTriggerTID
# define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
# define rtmGetModelMappingInfo(rtm)   ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
# define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
# define rtmGetModelName(rtm)          ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
# define rtmSetModelName(rtm, val)     ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
# define rtmGetNonInlinedSFcns(rtm)    ()
#endif

#ifndef rtmSetNonInlinedSFcns
# define rtmSetNonInlinedSFcns(rtm, val) ()
#endif

#ifndef rtmGetNumBlockIO
# define rtmGetNumBlockIO(rtm)         ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
# define rtmSetNumBlockIO(rtm, val)    ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
# define rtmGetNumBlockParams(rtm)     ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
# define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
# define rtmGetNumBlocks(rtm)          ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
# define rtmSetNumBlocks(rtm, val)     ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
# define rtmGetNumContStates(rtm)      ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
# define rtmSetNumContStates(rtm, val) ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
# define rtmGetNumDWork(rtm)           ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
# define rtmSetNumDWork(rtm, val)      ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
# define rtmGetNumInputPorts(rtm)      ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
# define rtmSetNumInputPorts(rtm, val) ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
# define rtmGetNumNonSampledZCs(rtm)   ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
# define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
# define rtmGetNumOutputPorts(rtm)     ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
# define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumPeriodicContStates
# define rtmGetNumPeriodicContStates(rtm) ((rtm)->Sizes.numPeriodicContStates)
#endif

#ifndef rtmSetNumPeriodicContStates
# define rtmSetNumPeriodicContStates(rtm, val) ((rtm)->Sizes.numPeriodicContStates = (val))
#endif

#ifndef rtmGetNumSFcnParams
# define rtmGetNumSFcnParams(rtm)      ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
# define rtmSetNumSFcnParams(rtm, val) ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
# define rtmGetNumSFunctions(rtm)      ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
# define rtmSetNumSFunctions(rtm, val) ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
# define rtmGetNumSampleTimes(rtm)     ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
# define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
# define rtmGetNumU(rtm)               ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
# define rtmSetNumU(rtm, val)          ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
# define rtmGetNumY(rtm)               ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
# define rtmSetNumY(rtm, val)          ((rtm)->Sizes.numY = (val))
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

#ifndef rtmGetOffsetTimeArray
# define rtmGetOffsetTimeArray(rtm)    ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
# define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
# define rtmGetOffsetTimePtr(rtm)      ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
# define rtmSetOffsetTimePtr(rtm, val) ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
# define rtmGetOptions(rtm)            ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
# define rtmSetOptions(rtm, val)       ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
# define rtmGetParamIsMalloced(rtm)    ()
#endif

#ifndef rtmSetParamIsMalloced
# define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
# define rtmGetPath(rtm)               ((rtm)->path)
#endif

#ifndef rtmSetPath
# define rtmSetPath(rtm, val)          ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
# define rtmGetPerTaskSampleHits(rtm)  ()
#endif

#ifndef rtmSetPerTaskSampleHits
# define rtmSetPerTaskSampleHits(rtm, val) ()
#endif

#ifndef rtmGetPerTaskSampleHitsArray
# define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
# define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
# define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
# define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
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

#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->ModelData.prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->ModelData.prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
# define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
# define rtmGetRTWGeneratedSFcn(rtm)   ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
# define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmSetRTWLogInfo
# define rtmSetRTWLogInfo(rtm, val)    ((rtm)->rtwLogInfo = (val))
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
# define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
# define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
# define rtmGetRTWSfcnInfo(rtm)        ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
# define rtmSetRTWSfcnInfo(rtm, val)   ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
# define rtmGetRTWSolverInfo(rtm)      ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
# define rtmSetRTWSolverInfo(rtm, val) ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
# define rtmGetRTWSolverInfoPtr(rtm)   ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
# define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
# define rtmGetReservedForXPC(rtm)     ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
# define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->ModelData.dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->ModelData.dwork = (val))
#endif

#ifndef rtmGetSFunctions
# define rtmGetSFunctions(rtm)         ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
# define rtmSetSFunctions(rtm, val)    ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
# define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
# define rtmGetSampleHitPtr(rtm)       ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
# define rtmSetSampleHitPtr(rtm, val)  ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
# define rtmGetSampleTimeArray(rtm)    ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
# define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
# define rtmGetSampleTimePtr(rtm)      ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
# define rtmSetSampleTimePtr(rtm, val) ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
# define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
# define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
# define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
# define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSimMode
# define rtmGetSimMode(rtm)            ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
# define rtmSetSimMode(rtm, val)       ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
# define rtmGetSimTimeStep(rtm)        ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
# define rtmSetSimTimeStep(rtm, val)   ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
# define rtmGetStartTime(rtm)          ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
# define rtmSetStartTime(rtm, val)     ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
# define rtmSetStepSize(rtm, val)      ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
# define rtmGetStopRequestedFlag(rtm)  ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
# define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
# define rtmGetTaskCounters(rtm)       ()
#endif

#ifndef rtmSetTaskCounters
# define rtmSetTaskCounters(rtm, val)  ()
#endif

#ifndef rtmGetTaskTimeArray
# define rtmGetTaskTimeArray(rtm)      ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
# define rtmSetTaskTimeArray(rtm, val) ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
# define rtmGetTimePtr(rtm)            ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
# define rtmSetTimePtr(rtm, val)       ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
# define rtmGetTimingData(rtm)         ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
# define rtmSetTimingData(rtm, val)    ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
# define rtmGetU(rtm)                  ((rtm)->ModelData.inputs)
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ((rtm)->ModelData.inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
# define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
# define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->ModelData.outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->ModelData.outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
# define rtmGetZCSignalValues(rtm)     ((rtm)->ModelData.zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
# define rtmSetZCSignalValues(rtm, val) ((rtm)->ModelData.zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
# define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->ModelData.derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->ModelData.derivs = (val))
#endif

#ifndef rtmGetChecksumVal
# define rtmGetChecksumVal(rtm, idx)   ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
# define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
# define rtmGetDWork(rtm, idx)         ((rtm)->ModelData.dwork[idx])
#endif

#ifndef rtmSetDWork
# define rtmSetDWork(rtm, idx, val)    ((rtm)->ModelData.dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
# define rtmGetOffsetTime(rtm, idx)    ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
# define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
# define rtmGetSFunction(rtm, idx)     ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
# define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
# define rtmGetSampleTime(rtm, idx)    ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
# define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
# define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
# define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTimeList
# define rtmGetVarNextHitTimeList(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTimeList
# define rtmSetVarNextHitTimeList(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
# define rtmIsContinuousTask(rtm, tid) ((tid) == 0)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
# define rtmIsSampleHit(rtm, sti, tid) ((rtmIsMajorTimeStep((rtm)) && (rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]]))
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

#ifndef rtmSetT
# define rtmSetT(rtm, val)                                       /* Do Nothing */
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
# define rtmSetTStart(rtm, val)        ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetTaskTime
# define rtmGetTaskTime(rtm, sti)      (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
# define rtmSetTaskTime(rtm, sti, val) (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define Navigation_loop_Animation_rtModel RT_MODEL_Navigation_loop_Anim_T

/* Block signals (auto storage) */
typedef struct {
  real_T Concatenate[4];               /* '<S14>/Concatenate' */
  real_T Integrator;                   /* '<Root>/Integrator' */
  real_T Integrator7;                  /* '<S2>/Integrator7' */
  real_T raddeg1;                      /* '<S1>/rad-->deg1' */
  real_T Integrator1;                  /* '<Root>/Integrator1' */
  real_T raddeg;                       /* '<S1>/rad-->deg' */
  real_T TmpSignalConversionAtVRSinkInpo[3];/* '<Root>/Axes to VR Axes' */
  real_T Gain2;                        /* '<Root>/Gain2' */
  real_T Derivative;                   /* '<S5>/Derivative' */
  real_T Subtract5;                    /* '<S5>/Subtract5' */
  real_T Fcn1;                         /* '<S5>/Fcn1' */
  real_T Derivative1;                  /* '<S5>/Derivative1' */
  real_T Subtract4;                    /* '<S5>/Subtract4' */
  real_T Fcn;                          /* '<S5>/Fcn' */
  real_T Gain3;                        /* '<Root>/Gain3' */
  real_T Gain;                         /* '<Root>/Gain' */
  real_T Gain1;                        /* '<Root>/Gain1' */
  real_T Gain5;                        /* '<Root>/Gain5' */
  real_T roll_dot;                     /* '<S2>/Integrator' */
  real_T pitch_dot;                    /* '<S2>/Integrator1' */
  real_T yaw_dot;                      /* '<S2>/Integrator2' */
  real_T Integrator6;                  /* '<S2>/Integrator6' */
  real_T Integrator8;                  /* '<S2>/Integrator8' */
  real_T Integrator9;                  /* '<S2>/Integrator9' */
  real_T Add6;                         /* '<S8>/Add6' */
  real_T Divide4;                      /* '<S8>/Divide4' */
  real_T Add5;                         /* '<S9>/Add5' */
  real_T Divide3;                      /* '<S9>/Divide3' */
  real_T x_dot_dot;                    /* '<S10>/Divide' */
  real_T y_dot_dot;                    /* '<S11>/Divide1' */
  real_T Add8;                         /* '<S12>/Add8' */
  real_T Divide5;                      /* '<S12>/Divide5' */
  real_T z_dot_dot;                    /* '<S13>/Add4' */
} B_Navigation_loop_Animation_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T TimeStampA;                   /* '<S5>/Derivative' */
  real_T LastUAtTimeA;                 /* '<S5>/Derivative' */
  real_T TimeStampB;                   /* '<S5>/Derivative' */
  real_T LastUAtTimeB;                 /* '<S5>/Derivative' */
  real_T TimeStampA_a;                 /* '<S5>/Derivative2' */
  real_T LastUAtTimeA_p;               /* '<S5>/Derivative2' */
  real_T TimeStampB_n;                 /* '<S5>/Derivative2' */
  real_T LastUAtTimeB_l;               /* '<S5>/Derivative2' */
  real_T TimeStampA_j;                 /* '<S5>/Derivative5' */
  real_T LastUAtTimeA_g;               /* '<S5>/Derivative5' */
  real_T TimeStampB_a;                 /* '<S5>/Derivative5' */
  real_T LastUAtTimeB_n;               /* '<S5>/Derivative5' */
  real_T TimeStampA_c;                 /* '<S5>/Derivative1' */
  real_T LastUAtTimeA_gt;              /* '<S5>/Derivative1' */
  real_T TimeStampB_m;                 /* '<S5>/Derivative1' */
  real_T LastUAtTimeB_h;               /* '<S5>/Derivative1' */
  real_T TimeStampA_e;                 /* '<S5>/Derivative3' */
  real_T LastUAtTimeA_d;               /* '<S5>/Derivative3' */
  real_T TimeStampB_ap;                /* '<S5>/Derivative3' */
  real_T LastUAtTimeB_f;               /* '<S5>/Derivative3' */
  real_T TimeStampA_ak;                /* '<S5>/Derivative4' */
  real_T LastUAtTimeA_l;               /* '<S5>/Derivative4' */
  real_T TimeStampB_nx;                /* '<S5>/Derivative4' */
  real_T LastUAtTimeB_n5;              /* '<S5>/Derivative4' */
  void *VRSink_PWORK[7];               /* '<Root>/VR Sink' */
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
  } pitch_angle_PWORK;                 /* '<Root>/pitch_angle' */

  struct {
    void *LoggedData;
  } roll_angle_PWORK;                  /* '<Root>/roll_angle' */

  struct {
    void *LoggedData;
  } yaw_angle_PWORK;                   /* '<Root>/yaw_angle' */
} DW_Navigation_loop_Animation_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T Integrator4_CSTATE;           /* '<S2>/Integrator4' */
  real_T Integrator5_CSTATE;           /* '<S2>/Integrator5' */
  real_T Integrator3_CSTATE;           /* '<S2>/Integrator3' */
  real_T Integrator_CSTATE;            /* '<Root>/Integrator' */
  real_T Integrator7_CSTATE;           /* '<S2>/Integrator7' */
  real_T Integrator1_CSTATE;           /* '<Root>/Integrator1' */
  real_T Integrator_CSTATE_b;          /* '<S5>/Integrator' */
  real_T Integrator1_CSTATE_n;         /* '<S5>/Integrator1' */
  real_T Integrator_CSTATE_f;          /* '<S2>/Integrator' */
  real_T Integrator1_CSTATE_p;         /* '<S2>/Integrator1' */
  real_T Integrator2_CSTATE;           /* '<S2>/Integrator2' */
  real_T Integrator6_CSTATE;           /* '<S2>/Integrator6' */
  real_T Integrator8_CSTATE;           /* '<S2>/Integrator8' */
  real_T Integrator9_CSTATE;           /* '<S2>/Integrator9' */
} X_Navigation_loop_Animation_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T Integrator4_CSTATE;           /* '<S2>/Integrator4' */
  real_T Integrator5_CSTATE;           /* '<S2>/Integrator5' */
  real_T Integrator3_CSTATE;           /* '<S2>/Integrator3' */
  real_T Integrator_CSTATE;            /* '<Root>/Integrator' */
  real_T Integrator7_CSTATE;           /* '<S2>/Integrator7' */
  real_T Integrator1_CSTATE;           /* '<Root>/Integrator1' */
  real_T Integrator_CSTATE_b;          /* '<S5>/Integrator' */
  real_T Integrator1_CSTATE_n;         /* '<S5>/Integrator1' */
  real_T Integrator_CSTATE_f;          /* '<S2>/Integrator' */
  real_T Integrator1_CSTATE_p;         /* '<S2>/Integrator1' */
  real_T Integrator2_CSTATE;           /* '<S2>/Integrator2' */
  real_T Integrator6_CSTATE;           /* '<S2>/Integrator6' */
  real_T Integrator8_CSTATE;           /* '<S2>/Integrator8' */
  real_T Integrator9_CSTATE;           /* '<S2>/Integrator9' */
} XDot_Navigation_loop_Animatio_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator4_CSTATE;        /* '<S2>/Integrator4' */
  boolean_T Integrator5_CSTATE;        /* '<S2>/Integrator5' */
  boolean_T Integrator3_CSTATE;        /* '<S2>/Integrator3' */
  boolean_T Integrator_CSTATE;         /* '<Root>/Integrator' */
  boolean_T Integrator7_CSTATE;        /* '<S2>/Integrator7' */
  boolean_T Integrator1_CSTATE;        /* '<Root>/Integrator1' */
  boolean_T Integrator_CSTATE_b;       /* '<S5>/Integrator' */
  boolean_T Integrator1_CSTATE_n;      /* '<S5>/Integrator1' */
  boolean_T Integrator_CSTATE_f;       /* '<S2>/Integrator' */
  boolean_T Integrator1_CSTATE_p;      /* '<S2>/Integrator1' */
  boolean_T Integrator2_CSTATE;        /* '<S2>/Integrator2' */
  boolean_T Integrator6_CSTATE;        /* '<S2>/Integrator6' */
  boolean_T Integrator8_CSTATE;        /* '<S2>/Integrator8' */
  boolean_T Integrator9_CSTATE;        /* '<S2>/Integrator9' */
} XDis_Navigation_loop_Animatio_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Backward compatible GRT Identifiers */
#define rtB                            Navigation_loop_Animation_B
#define BlockIO                        B_Navigation_loop_Animation_T
#define rtX                            Navigation_loop_Animation_X
#define ContinuousStates               X_Navigation_loop_Animation_T
#define rtXdot                         Navigation_loop_Animation_XDot
#define StateDerivatives               XDot_Navigation_loop_Animatio_T
#define tXdis                          Navigation_loop_Animation_XDis
#define StateDisabled                  XDis_Navigation_loop_Animatio_T
#define rtP                            Navigation_loop_Animation_P
#define Parameters                     P_Navigation_loop_Animation_T
#define rtDWork                        Navigation_loop_Animation_DW
#define D_Work                         DW_Navigation_loop_Animation_T

/* Parameters (auto storage) */
struct P_Navigation_loop_Animation_T_ {
  real_T g;                            /* Variable: g
                                        * Referenced by:
                                        *   '<S5>/Gain'
                                        *   '<S5>/Gain1'
                                        */
  real_T kdp;                          /* Variable: kdp
                                        * Referenced by: '<S4>/kdp'
                                        */
  real_T kdps;                         /* Variable: kdps
                                        * Referenced by: '<S4>/kdps'
                                        */
  real_T kdt;                          /* Variable: kdt
                                        * Referenced by: '<S4>/kdt'
                                        */
  real_T kdx;                          /* Variable: kdx
                                        * Referenced by: '<S5>/Gain3'
                                        */
  real_T kdy;                          /* Variable: kdy
                                        * Referenced by: '<S5>/Gain5'
                                        */
  real_T kdz;                          /* Variable: kdz
                                        * Referenced by: '<S4>/kdz'
                                        */
  real_T kix;                          /* Variable: kix
                                        * Referenced by: '<S5>/Gain6'
                                        */
  real_T kiy;                          /* Variable: kiy
                                        * Referenced by: '<S5>/Gain7'
                                        */
  real_T kpp;                          /* Variable: kpp
                                        * Referenced by: '<S4>/kpp'
                                        */
  real_T kpps;                         /* Variable: kpps
                                        * Referenced by: '<S4>/kpps'
                                        */
  real_T kpt;                          /* Variable: kpt
                                        * Referenced by: '<S4>/kpt'
                                        */
  real_T kpx;                          /* Variable: kpx
                                        * Referenced by: '<S5>/Gain2'
                                        */
  real_T kpy;                          /* Variable: kpy
                                        * Referenced by: '<S5>/Gain4'
                                        */
  real_T kpz;                          /* Variable: kpz
                                        * Referenced by: '<S4>/kpz'
                                        */
  real_T Integrator4_IC;               /* Expression: 0
                                        * Referenced by: '<S2>/Integrator4'
                                        */
  real_T u_Gain;                       /* Expression: 1/2
                                        * Referenced by: '<S17>/1//2'
                                        */
  real_T VrRollAxes_Value[3];          /* Expression: [1 0 0]
                                        * Referenced by: '<S3>/Vr Roll Axes'
                                        */
  real_T Integrator5_IC;               /* Expression: 0
                                        * Referenced by: '<S2>/Integrator5'
                                        */
  real_T u_Gain_f;                     /* Expression: 1/2
                                        * Referenced by: '<S19>/1//2'
                                        */
  real_T VrYawAxes_Value[3];           /* Expression: [0 -1 0]
                                        * Referenced by: '<S3>/Vr Yaw Axes'
                                        */
  real_T Integrator3_IC;               /* Expression: 0
                                        * Referenced by: '<S2>/Integrator3'
                                        */
  real_T u_Gain_o;                     /* Expression: 1/2
                                        * Referenced by: '<S18>/1//2'
                                        */
  real_T VrPitchAxes_Value[3];         /* Expression: [0 0 1]
                                        * Referenced by: '<S3>/Vr Pitch Axes'
                                        */
  real_T _Gain;                        /* Expression: 2
                                        * Referenced by: '<S14>/2'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<Root>/Integrator'
                                        */
  real_T Integrator7_IC;               /* Expression: 0
                                        * Referenced by: '<S2>/Integrator7'
                                        */
  real_T Gain6_Gain;                   /* Expression: -1
                                        * Referenced by: '<Root>/Gain6'
                                        */
  real_T raddeg1_Gain;                 /* Expression: -1
                                        * Referenced by: '<S1>/rad-->deg1'
                                        */
  real_T Integrator1_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator1'
                                        */
  real_T raddeg_Gain;                  /* Expression: -1
                                        * Referenced by: '<S1>/rad-->deg'
                                        */
  real_T X_desired_Value;              /* Expression: 10
                                        * Referenced by: '<Root>/X_desired'
                                        */
  real_T Y_desired_Value;              /* Expression: 10
                                        * Referenced by: '<Root>/Y_desired'
                                        */
  real_T Z_desired_Value;              /* Expression: 10
                                        * Referenced by: '<Root>/Z_desired'
                                        */
  real_T Gain2_Gain;                   /* Expression: 57.3
                                        * Referenced by: '<Root>/Gain2'
                                        */
  real_T Integrator_IC_l;              /* Expression: 0
                                        * Referenced by: '<S5>/Integrator'
                                        */
  real_T yaw_desired_Value;            /* Expression: 0
                                        * Referenced by: '<Root>/yaw_desired'
                                        */
  real_T Integrator1_IC_g;             /* Expression: 0
                                        * Referenced by: '<S5>/Integrator1'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 35/57.3
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -35/57.3
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  real_T Gain3_Gain;                   /* Expression: 57.3
                                        * Referenced by: '<Root>/Gain3'
                                        */
  real_T Gain_Gain;                    /* Expression: 57.3
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 35/57.3
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -35/57.3
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Gain1_Gain;                   /* Expression: 57.3
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T Gain5_Gain;                   /* Expression: 57.3
                                        * Referenced by: '<Root>/Gain5'
                                        */
  real_T Gain4_Gain;                   /* Expression: 57.3
                                        * Referenced by: '<Root>/Gain4'
                                        */
  real_T Integrator_IC_c;              /* Expression: 0
                                        * Referenced by: '<S2>/Integrator'
                                        */
  real_T Integrator1_IC_a;             /* Expression: 0
                                        * Referenced by: '<S2>/Integrator1'
                                        */
  real_T Integrator2_IC;               /* Expression: 0
                                        * Referenced by: '<S2>/Integrator2'
                                        */
  real_T Integrator6_IC;               /* Expression: 0
                                        * Referenced by: '<S2>/Integrator6'
                                        */
  real_T Integrator8_IC;               /* Expression: 0
                                        * Referenced by: '<S2>/Integrator8'
                                        */
  real_T Integrator9_IC;               /* Expression: 0
                                        * Referenced by: '<S2>/Integrator9'
                                        */
  real_T Arm_length_Value;             /* Expression: 0.228
                                        * Referenced by: '<S6>/Arm_length_'
                                        */
  real_T ineretia_yy_Value;            /* Expression: 2.5955e-4
                                        * Referenced by: '<S6>/ineretia_yy'
                                        */
  real_T inertia_zz_Value;             /* Expression: 5.7824e-5
                                        * Referenced by: '<S6>/inertia_zz'
                                        */
  real_T inertia_xx_Value;             /* Expression: 2.754e-4
                                        * Referenced by: '<S6>/inertia_xx'
                                        */
  real_T Constant1_Value;              /* Expression: 9.8
                                        * Referenced by: '<S4>/Constant1'
                                        */
  real_T m_Gain;                       /* Expression: 1.17
                                        * Referenced by: '<S4>/m'
                                        */
  real_T mass_Value;                   /* Expression: 1.17
                                        * Referenced by: '<S6>/mass'
                                        */
  real_T u5_Value;                     /* Expression: 9.8
                                        * Referenced by: '<S13>/u5'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Navigation_loop_Anima_T {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWLogInfo *rtwLogInfo;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    void *blockIO;
    const void *constBlockIO;
    void *defaultParam;
    ZCSigState *prevZCSigState;
    real_T *contStates;
    int_T *periodicContStateIndices;
    real_T *periodicContStateRanges;
    real_T *derivs;
    void *zcSignalValues;
    void *inputs;
    void *outputs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    real_T odeY[14];
    real_T odeF[3][14];
    ODE3_IntgData intgData;
    void *dwork;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[2];
    time_T offsetTimesArray[2];
    int_T sampleTimeTaskIDArray[2];
    int_T sampleHitArray[2];
    int_T perTaskSampleHitsArray[4];
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_Navigation_loop_Animation_T Navigation_loop_Animation_P;

/* Block signals (auto storage) */
extern B_Navigation_loop_Animation_T Navigation_loop_Animation_B;

/* Continuous states (auto storage) */
extern X_Navigation_loop_Animation_T Navigation_loop_Animation_X;

/* Block states (auto storage) */
extern DW_Navigation_loop_Animation_T Navigation_loop_Animation_DW;

/* Model entry point functions */
extern void Navigation_loop_Animation_initialize(void);
extern void Navigation_loop_Animation_output(void);
extern void Navigation_loop_Animation_update(void);
extern void Navigation_loop_Animation_terminate(void);

/*====================*
 * External functions *
 *====================*/
extern Navigation_loop_Animation_rtModel *Navigation_loop_Animation(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_Navigation_loop_Anim_T *const Navigation_loop_Animation_M;

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
 * '<Root>' : 'Navigation_loop_Animation'
 * '<S1>'   : 'Navigation_loop_Animation/Axes to VR Axes'
 * '<S2>'   : 'Navigation_loop_Animation/Dynamic model'
 * '<S3>'   : 'Navigation_loop_Animation/Euler to VR'
 * '<S4>'   : 'Navigation_loop_Animation/PD controller'
 * '<S5>'   : 'Navigation_loop_Animation/Position controller'
 * '<S6>'   : 'Navigation_loop_Animation/property '
 * '<S7>'   : 'Navigation_loop_Animation/Dynamic model/MATLAB Function'
 * '<S8>'   : 'Navigation_loop_Animation/Dynamic model/pitch_dot_dot'
 * '<S9>'   : 'Navigation_loop_Animation/Dynamic model/roll_dot_dot'
 * '<S10>'  : 'Navigation_loop_Animation/Dynamic model/x_dot_dot'
 * '<S11>'  : 'Navigation_loop_Animation/Dynamic model/y_dot_dot'
 * '<S12>'  : 'Navigation_loop_Animation/Dynamic model/yaw_dot_dot'
 * '<S13>'  : 'Navigation_loop_Animation/Dynamic model/z_dot_dot'
 * '<S14>'  : 'Navigation_loop_Animation/Euler to VR/Axis Angle Vector'
 * '<S15>'  : 'Navigation_loop_Animation/Euler to VR/Quaternion Multiplication (Pitch & Yaw)'
 * '<S16>'  : 'Navigation_loop_Animation/Euler to VR/Quaternion Multiplication (Roll)'
 * '<S17>'  : 'Navigation_loop_Animation/Euler to VR/Quaternion Normalization'
 * '<S18>'  : 'Navigation_loop_Animation/Euler to VR/Quaternion Normalization1'
 * '<S19>'  : 'Navigation_loop_Animation/Euler to VR/Quaternion Normalization2'
 * '<S20>'  : 'Navigation_loop_Animation/Euler to VR/Quaternion Multiplication (Pitch & Yaw)/q0'
 * '<S21>'  : 'Navigation_loop_Animation/Euler to VR/Quaternion Multiplication (Pitch & Yaw)/q1'
 * '<S22>'  : 'Navigation_loop_Animation/Euler to VR/Quaternion Multiplication (Pitch & Yaw)/q2'
 * '<S23>'  : 'Navigation_loop_Animation/Euler to VR/Quaternion Multiplication (Pitch & Yaw)/q3'
 * '<S24>'  : 'Navigation_loop_Animation/Euler to VR/Quaternion Multiplication (Roll)/q0'
 * '<S25>'  : 'Navigation_loop_Animation/Euler to VR/Quaternion Multiplication (Roll)/q1'
 * '<S26>'  : 'Navigation_loop_Animation/Euler to VR/Quaternion Multiplication (Roll)/q2'
 * '<S27>'  : 'Navigation_loop_Animation/Euler to VR/Quaternion Multiplication (Roll)/q3'
 */
#endif                                 /* RTW_HEADER_Navigation_loop_Animation_h_ */

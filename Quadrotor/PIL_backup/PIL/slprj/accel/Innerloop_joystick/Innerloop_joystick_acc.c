#include "__cf_Innerloop_joystick.h"
#include <math.h>
#include "Innerloop_joystick_acc.h"
#include "Innerloop_joystick_acc_private.h"
#include <stdio.h>
#include "simstruc.h"
#include "fixedpoint.h"
#define CodeFormat S-Function
#define AccDefine1 Accelerator_S-Function
static void mdlOutputs ( SimStruct * S , int_T tid ) { real_T hbdkiq1ssm ;
real_T h4oig4g3ai ; real_T hulx4b0xac ; otvvbja0md * _rtB ; fqzemmpmqe * _rtP
; arz0oncsus * _rtDW ; _rtDW = ( ( arz0oncsus * ) ssGetRootDWork ( S ) ) ;
_rtP = ( ( fqzemmpmqe * ) ssGetDefaultParam ( S ) ) ; _rtB = ( ( otvvbja0md *
) _ssGetBlockIO ( S ) ) ; _rtB -> cl1hsjaiwz = ( ( p3sam5bvmx * )
ssGetContStates ( S ) ) -> ntgyq4g0p5 ; ssCallAccelRunBlock ( S , 1 , 1 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> cl1hsjaiwz = ( ( p3sam5bvmx * )
ssGetContStates ( S ) ) -> azqf4obajp ; ssCallAccelRunBlock ( S , 1 , 3 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> cl1hsjaiwz = ( ( p3sam5bvmx * )
ssGetContStates ( S ) ) -> kibywkbko4 ; _rtB -> oxkyeagfit = ( ( p3sam5bvmx *
) ssGetContStates ( S ) ) -> d3bftye4ie ; if ( ssIsMajorTimeStep ( S ) ) {
_rtDW -> mnimyxb55z = _rtB -> oxkyeagfit >= _rtP -> P_4 ? 1 : _rtB ->
oxkyeagfit > _rtP -> P_5 ? 0 : - 1 ; } _rtB -> d3ymkeatds = _rtDW ->
mnimyxb55z == 1 ? _rtP -> P_4 : _rtDW -> mnimyxb55z == - 1 ? _rtP -> P_5 :
_rtB -> oxkyeagfit ; ssCallAccelRunBlock ( S , 1 , 7 , SS_CALL_MDL_OUTPUTS )
; ssCallAccelRunBlock ( S , 1 , 8 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
pyqesev2qf = ( ( p3sam5bvmx * ) ssGetContStates ( S ) ) -> opjkxrmhm3 ; _rtB
-> og04vu2hw3 = _rtP -> P_7 * _rtB -> pyqesev2qf ; hbdkiq1ssm = ( ( ( (
jzch413t2h * ) ssGetU ( S ) ) -> niiurjsjc4 + 0.832 ) * 43.42 - 35.0 ) / 57.3
; _rtB -> nmqwukmtul = _rtP -> P_8 * hbdkiq1ssm ; ssCallAccelRunBlock ( S , 1
, 13 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> gylrmb10pd = ( ( p3sam5bvmx * )
ssGetContStates ( S ) ) -> bwmqhcsduy ; _rtB -> nmqwukmtul = _rtP -> P_10 *
_rtB -> gylrmb10pd ; h4oig4g3ai = ( ( ( ( jzch413t2h * ) ssGetU ( S ) ) ->
kdtagg3114 + 0.965 ) * 38.48 - 35.0 ) / 57.3 ; _rtB -> og04vu2hw3 = _rtP ->
P_11 * h4oig4g3ai ; ssCallAccelRunBlock ( S , 1 , 18 , SS_CALL_MDL_OUTPUTS )
; _rtB -> hynzi33kpl = ( ( p3sam5bvmx * ) ssGetContStates ( S ) ) ->
poycw33cyc ; _rtB -> nmqwukmtul = _rtP -> P_13 * _rtB -> hynzi33kpl ; _rtB ->
gfg3s5womd = ( ( p3sam5bvmx * ) ssGetContStates ( S ) ) -> asir0wexi1 ; if (
ssIsMajorTimeStep ( S ) ) { _rtDW -> ohx50ui1o4 = _rtB -> gfg3s5womd >= _rtP
-> P_15 ? 1 : _rtB -> gfg3s5womd > _rtP -> P_16 ? 0 : - 1 ; } hulx4b0xac =
_rtDW -> ohx50ui1o4 == 1 ? _rtP -> P_15 : _rtDW -> ohx50ui1o4 == - 1 ? _rtP
-> P_16 : _rtB -> gfg3s5womd ; _rtB -> og04vu2hw3 = _rtP -> P_17 * hulx4b0xac
; ssCallAccelRunBlock ( S , 1 , 24 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
mnnjwvfdef = ( ( p3sam5bvmx * ) ssGetContStates ( S ) ) -> j2swejbzkh ; _rtB
-> d1k1ic0t41 = ( ( p3sam5bvmx * ) ssGetContStates ( S ) ) -> itoxuokcqb ;
_rtB -> f0tptxhyty = ( ( p3sam5bvmx * ) ssGetContStates ( S ) ) -> awf1utodht
; _rtB -> ddwnthn111 = ( ( p3sam5bvmx * ) ssGetContStates ( S ) ) ->
halffsymco ; _rtB -> kwxm1hdzax = ( ( p3sam5bvmx * ) ssGetContStates ( S ) )
-> j44tdkv0pi ; _rtB -> akaygiw4od = ( ( p3sam5bvmx * ) ssGetContStates ( S )
) -> cy1aw34iqa ; ssCallAccelRunBlock ( S , 0 , 0 , SS_CALL_MDL_OUTPUTS ) ;
if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> ibqbkogtvb = _rtP -> P_26 ; _rtB
-> npb0ou2y4q = _rtP -> P_27 ; _rtB -> kt5pnt3ory = _rtP -> P_28 ; _rtB ->
d0kevszdav = _rtB -> npb0ou2y4q - _rtB -> kt5pnt3ory ; _rtB -> lsdxbwybrk =
_rtP -> P_29 ; } _rtB -> j41vg54w5e = ( ( ( hbdkiq1ssm - _rtB -> pyqesev2qf )
* _rtP -> P_24 - _rtP -> P_25 * _rtB -> d1k1ic0t41 ) * _rtB -> ibqbkogtvb +
_rtB -> mnnjwvfdef * _rtB -> f0tptxhyty * _rtB -> d0kevszdav ) / _rtB ->
lsdxbwybrk ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> gbckgvndz4 = _rtB
-> kt5pnt3ory - _rtB -> lsdxbwybrk ; } _rtB -> cdput2qvxy = ( ( ( h4oig4g3ai
- _rtB -> gylrmb10pd ) * _rtP -> P_30 - _rtP -> P_31 * _rtB -> mnnjwvfdef ) *
_rtB -> ibqbkogtvb + _rtB -> d1k1ic0t41 * _rtB -> f0tptxhyty * _rtB ->
gbckgvndz4 ) / _rtB -> npb0ou2y4q ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB
-> izkqo33mkz = _rtP -> P_34 ; } h4oig4g3ai = ( ( ( _rtB -> d3ymkeatds - _rtB
-> cl1hsjaiwz ) * _rtP -> P_32 - _rtP -> P_33 * _rtB -> ddwnthn111 ) + _rtB
-> izkqo33mkz ) * _rtP -> P_35 / ( muDoubleScalarCos ( _rtB -> gylrmb10pd ) *
muDoubleScalarCos ( _rtB -> pyqesev2qf ) ) ; if ( ssIsSampleHit ( S , 1 , 0 )
) { _rtB -> p2efskalkc = _rtP -> P_36 ; } _rtB -> l3gg0bfbyy = ( _rtB ->
k5ycbsadfq * _rtB -> gmted5rj3g * _rtB -> nwz5xvnyd2 + _rtB -> fhctxsh3nx *
_rtB -> a0wmxx4gow ) * h4oig4g3ai / _rtB -> p2efskalkc ; _rtB -> b3e0e5p2dz =
( _rtB -> fhctxsh3nx * _rtB -> k5ycbsadfq * _rtB -> nwz5xvnyd2 - _rtB ->
a0wmxx4gow * _rtB -> gmted5rj3g ) * h4oig4g3ai / _rtB -> p2efskalkc ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> abjuomau4w = _rtB -> lsdxbwybrk -
_rtB -> npb0ou2y4q ; } _rtB -> hv3i2hjra2 = ( ( ( hulx4b0xac - _rtB ->
hynzi33kpl ) * _rtP -> P_37 - _rtP -> P_38 * _rtB -> f0tptxhyty ) + _rtB ->
d1k1ic0t41 * _rtB -> mnnjwvfdef * _rtB -> abjuomau4w ) / _rtB -> kt5pnt3ory ;
if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> iqxl3iwkiy = _rtP -> P_39 ; }
_rtB -> osbrofj4zp = _rtB -> blvraasy3r * _rtB -> nwz5xvnyd2 * h4oig4g3ai /
_rtB -> p2efskalkc - _rtB -> iqxl3iwkiy ; _rtB -> bj4w0ohmbt = ( ( ( (
jzch413t2h * ) ssGetU ( S ) ) -> ahpzfcqoif + 0.956 ) * 21.61 - 20.0 ) / 57.3
; _rtB -> oxb53yx3rn = 14.81 * ( ( jzch413t2h * ) ssGetU ( S ) ) ->
morfifqs3m / 1.17 ; ssCallAccelRunBlock ( S , 1 , 94 , SS_CALL_MDL_OUTPUTS )
; ssCallAccelRunBlock ( S , 1 , 95 , SS_CALL_MDL_OUTPUTS ) ; UNUSED_PARAMETER
( tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { otvvbja0md * _rtB ;
fqzemmpmqe * _rtP ; _rtP = ( ( fqzemmpmqe * ) ssGetDefaultParam ( S ) ) ;
_rtB = ( ( otvvbja0md * ) _ssGetBlockIO ( S ) ) ; UNUSED_PARAMETER ( tid ) ;
}
#define MDL_DERIVATIVES
static void mdlDerivatives ( SimStruct * S ) { otvvbja0md * _rtB ; fqzemmpmqe
* _rtP ; _rtP = ( ( fqzemmpmqe * ) ssGetDefaultParam ( S ) ) ; _rtB = ( (
otvvbja0md * ) _ssGetBlockIO ( S ) ) ; { ( ( bg2hluikgp * ) ssGetdX ( S ) )
-> ntgyq4g0p5 = _rtB -> kwxm1hdzax ; } { ( ( bg2hluikgp * ) ssGetdX ( S ) )
-> azqf4obajp = _rtB -> akaygiw4od ; } { ( ( bg2hluikgp * ) ssGetdX ( S ) )
-> kibywkbko4 = _rtB -> ddwnthn111 ; } { ( ( bg2hluikgp * ) ssGetdX ( S ) )
-> d3bftye4ie = _rtB -> oxb53yx3rn ; } { ( ( bg2hluikgp * ) ssGetdX ( S ) )
-> opjkxrmhm3 = _rtB -> d1k1ic0t41 ; } { ( ( bg2hluikgp * ) ssGetdX ( S ) )
-> bwmqhcsduy = _rtB -> mnnjwvfdef ; } { ( ( bg2hluikgp * ) ssGetdX ( S ) )
-> poycw33cyc = _rtB -> f0tptxhyty ; } { ( ( bg2hluikgp * ) ssGetdX ( S ) )
-> asir0wexi1 = _rtB -> bj4w0ohmbt ; } { ( ( bg2hluikgp * ) ssGetdX ( S ) )
-> j2swejbzkh = _rtB -> cdput2qvxy ; } { ( ( bg2hluikgp * ) ssGetdX ( S ) )
-> itoxuokcqb = _rtB -> j41vg54w5e ; } { ( ( bg2hluikgp * ) ssGetdX ( S ) )
-> awf1utodht = _rtB -> hv3i2hjra2 ; } { ( ( bg2hluikgp * ) ssGetdX ( S ) )
-> halffsymco = _rtB -> osbrofj4zp ; } { ( ( bg2hluikgp * ) ssGetdX ( S ) )
-> j44tdkv0pi = _rtB -> l3gg0bfbyy ; } { ( ( bg2hluikgp * ) ssGetdX ( S ) )
-> cy1aw34iqa = _rtB -> b3e0e5p2dz ; } }
#define MDL_ZERO_CROSSINGS
static void mdlZeroCrossings ( SimStruct * S ) { otvvbja0md * _rtB ;
fqzemmpmqe * _rtP ; eeyo5cfck5 * _rtZCSV ; _rtZCSV = ( ( eeyo5cfck5 * )
ssGetSolverZcSignalVector ( S ) ) ; _rtP = ( ( fqzemmpmqe * )
ssGetDefaultParam ( S ) ) ; _rtB = ( ( otvvbja0md * ) _ssGetBlockIO ( S ) ) ;
_rtZCSV -> n4l3vok4dz = _rtB -> oxkyeagfit - _rtP -> P_4 ; _rtZCSV ->
frznyubji0 = _rtB -> oxkyeagfit - _rtP -> P_5 ; _rtZCSV -> c1f2nbygep = _rtB
-> gfg3s5womd - _rtP -> P_15 ; _rtZCSV -> e2bownnie3 = _rtB -> gfg3s5womd -
_rtP -> P_16 ; } static void mdlInitializeSizes ( SimStruct * S ) {
ssSetChecksumVal ( S , 0 , 3363650752U ) ; ssSetChecksumVal ( S , 1 ,
2160717222U ) ; ssSetChecksumVal ( S , 2 , 1268767410U ) ; ssSetChecksumVal (
S , 3 , 266846896U ) ; { mxArray * slVerStructMat = NULL ; mxArray * slStrMat
= mxCreateString ( "simulink" ) ; char slVerChar [ 10 ] ; int status =
mexCallMATLAB ( 1 , & slVerStructMat , 1 , & slStrMat , "ver" ) ; if ( status
== 0 ) { mxArray * slVerMat = mxGetField ( slVerStructMat , 0 , "Version" ) ;
if ( slVerMat == NULL ) { status = 1 ; } else { status = mxGetString (
slVerMat , slVerChar , 10 ) ; } } mxDestroyArray ( slStrMat ) ;
mxDestroyArray ( slVerStructMat ) ; if ( ( status == 1 ) || ( strcmp (
slVerChar , "8.5" ) != 0 ) ) { return ; } } ssSetOptions ( S ,
SS_OPTION_EXCEPTION_FREE_CODE ) ; if ( ssGetSizeofDWork ( S ) != sizeof (
arz0oncsus ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal DWork sizes do "
"not match for accelerator mex file." ) ; } if ( ssGetSizeofGlobalBlockIO ( S
) != sizeof ( otvvbja0md ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal BlockIO sizes do "
"not match for accelerator mex file." ) ; } if ( ssGetSizeofU ( S ) != sizeof
( jzch413t2h ) ) { static char msg [ 256 ] ; sprintf ( msg ,
"Unexpected error: Internal ExternalInputs sizes do "
"not match for accelerator mex file." ) ; ssSetErrorStatus ( S , msg ) ; } {
int ssSizeofParams ; ssGetSizeofParams ( S , & ssSizeofParams ) ; if (
ssSizeofParams != sizeof ( fqzemmpmqe ) ) { static char msg [ 256 ] ; sprintf
( msg , "Unexpected error: Internal Parameters sizes do "
"not match for accelerator mex file." ) ; } } _ssSetDefaultParam ( S , (
real_T * ) & lodb1zfbsd ) ; rt_InitInfAndNaN ( sizeof ( real_T ) ) ; } static
void mdlInitializeSampleTimes ( SimStruct * S ) { { SimStruct * childS ;
SysOutputFcn * callSysFcns ; childS = ssGetSFunction ( S , 0 ) ; callSysFcns
= ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; } } static void mdlTerminate ( SimStruct * S ) { }
#include "simulink.c"

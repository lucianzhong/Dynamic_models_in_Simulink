@echo off
call "C:\Program Files (x86)\Microsoft Visual Studio 10.0\VC\VCVARSALL.BAT" amd64

cd .
nmake -f Innerloop_joystick.mk  RSIM_SOLVER_SELECTION=2 ISPROTECTINGMODEL=NOTPROTECTING OPTS="-DTGTCONN -DON_TARGET_WAIT_FOR_START=0"
@if errorlevel 1 goto error_exit
exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
An_error_occurred_during_the_call_to_make

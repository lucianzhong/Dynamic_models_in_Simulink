set MATLAB=E:\Matlab 2015a

cd .

if "%1"=="" (E:\MATLAB~1\bin\win64\gmake -f Innerloop_joystick.mk all) else (E:\MATLAB~1\bin\win64\gmake -f Innerloop_joystick.mk %1)
@if errorlevel 1 goto error_exit

exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
An_error_occurred_during_the_call_to_make

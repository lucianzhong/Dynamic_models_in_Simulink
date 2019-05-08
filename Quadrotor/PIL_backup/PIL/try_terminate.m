function experience(block)
% Level-2 MATLAB file S-Function for times two demo.
%   Copyright 1990-2009 The MathWorks, Inc.

  setup(block);
  
%endfunction

function setup(block)
  
  %% Register number of input and output ports
  block.NumInputPorts  = 11;
  block.NumOutputPorts = 1;

  %% Setup functional port properties to dynamically
  %% inherited.
  block.SetPreCompInpPortInfoToDynamic;
  block.SetPreCompOutPortInfoToDynamic;
 
  block.InputPort(1).DirectFeedthrough = true;
  
  %% Set block sample time to inherited
  block.SampleTimes = [-1 0];
  
  %% Set the block simStateCompliance to default (i.e., same as a built-in block)
  block.SimStateCompliance = 'DefaultSimState';

  %% Run accelerator on TLC
  block.SetAccelRunOnTLC(true);
  
  %% Register methods

  block.RegBlockMethod('Outputs',                 @Output);  

%endfunction






function Output(block)

block.OutputPort(1).Data = block.InputPort(1).Data;

s=serial('COM9','BaudRate',115200);
fopen(s);


Pitch=block.InputPort(1).Data;%1
Roll=block.InputPort(2).Data;%2
Yaw=block.InputPort(3).Data;%3
dpitch=block.InputPort(4).Data;%4
droll=block.InputPort(5).Data;%5
dyaw=block.InputPort(6).Data;%6
vd=block.InputPort(7).Data;%7
h=block.InputPort(8).Data;%8
an=block.InputPort(9).Data;%9
ae=block.InputPort(10).Data;%10
ad=block.InputPort(11).Data;%11

fprintf(s,'$');
fwrite(s,Pitch,'int16');%1
fprintf(s,',');

fwrite(s,Roll,'int16');%2
fprintf(s,',');

fwrite(s,Yaw,'int16');%3
fprintf(s,',');

fwrite(s,dpitch,'int16');%4
fprintf(s,',');

fwrite(s,droll,'int16');%5
fprintf(s,',');

fwrite(s,dyaw,'int16');%6
fprintf(s,',');

fwrite(s,vd,'int16');%7
fprintf(s,',');

fwrite(s,h,'int16');%8
fprintf(s,',');

fwrite(s,an,'int16');%9
fprintf(s,',');

fwrite(s,ae,'int16');%10
fprintf(s,',');

fwrite(s,ad,'int16');%11
fprintf(s,',');


fclose(s);
delete(s);
clear 










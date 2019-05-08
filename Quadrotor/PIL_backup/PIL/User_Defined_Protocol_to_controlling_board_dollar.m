function User_Defined_Protocol_to_controlling_board(block)
% Level-2 MATLAB file S-Function for times two demo.
%   Copyright 1990-2009 The MathWorks, Inc.

  setup(block);
  
%endfunction

function setup(block)
  
  %% Register number of input and output ports
  block.NumInputPorts  = 11;
  block.NumOutputPorts = 0;

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
 block.RegBlockMethod('Start', @Start);
  block.RegBlockMethod('Outputs',                 @Output);  
  block.RegBlockMethod('Terminate', @Terminate);
  
%endfunction
function Start(block)
global s;
s=serial('COM9','BaudRate',256000);
fopen(s);


function Output(block)





global s
fprintf(s,',');







function Terminate(block)
global s;
fclose(s);
delete(s);
clear s  
%endfunction


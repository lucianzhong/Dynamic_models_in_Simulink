function experience(block)
% Level-2 MATLAB file S-Function for times two demo.
%   Copyright 1990-2009 The MathWorks, Inc.

  setup(block);
  
%endfunction

function setup(block)
  
  %% Register number of input and output ports
  block.NumInputPorts  = 13;
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





IMU_data_pack=zeros(1,41);

IMU_data_pack(1,1)=165;%帧头
IMU_data_pack(1,2)=90;%帧头
IMU_data_pack(1,3)=83;%帧长度
IMU_data_pack(1,4)=0;%保留
IMU_data_pack(1,5)=97;%帧标志

%数据段
IMU_data_pack(1,6)=127;%Flag0
IMU_data_pack(1,7)=11;%Flag1
IMU_data_pack(1,8)=128;%NavStatus
IMU_data_1_8=[IMU_data_pack(1,1),IMU_data_pack(1,2),IMU_data_pack(1,3),    IMU_data_pack(1,4),IMU_data_pack(1,5),IMU_data_pack(1,6),    IMU_data_pack(1,7),IMU_data_pack(1,8)];
fwrite(s,IMU_data_1_8,'uint8');
% Pitch,Roll,Yaw
IMU_data_pack(1,9)=1;
IMU_data_pack(1,10)=1;
IMU_data_pack(1,11)=1;
IMU_data_9_10_11=[IMU_data_pack(1,9),IMU_data_pack(1,10),IMU_data_pack(1,11)];
fwrite(s,IMU_data_9_10_11,'int16');
%q0,q1,q2,q3
IMU_data_pack(1,12)=0;
IMU_data_pack(1,13)=0;
IMU_data_pack(1,14)=0;
IMU_data_pack(1,15)=0;
IMU_data_12_13_14_15=[IMU_data_pack(1,12),IMU_data_pack(1,13),IMU_data_pack(1,14),IMU_data_pack(1,15)];
fwrite(s,IMU_data_12_13_14_15,'float32');
%dpitch,droll,dyaw
IMU_data_pack(1,16)= 100;
IMU_data_pack(1,17)= 200;
IMU_data_pack(1,18)= 300;
IMU_data_9_10_11=[IMU_data_pack(1,16),IMU_data_pack(1,17),IMU_data_pack(1,18)];
fwrite(s,IMU_data_9_10_11,'int16');
%AngRateN,AngRateE,AngRateD
IMU_data_pack(1,19)=0;
IMU_data_pack(1,20)=0;
IMU_data_pack(1,21)=0;
IMU_data_19_20_21=[IMU_data_pack(1,19),IMU_data_pack(1,20),IMU_data_pack(1,21)];
fwrite(s,IMU_data_19_20_21,'int16');
%AngRateX,AngRateY,AngRateZ
IMU_data_pack(1,22)=0;
IMU_data_pack(1,23)=0;
IMU_data_pack(1,24)=0;
IMU_data_22_23_24=[IMU_data_pack(1,22),IMU_data_pack(1,23),IMU_data_pack(1,24)];
fwrite(s,IMU_data_22_23_24,'int16');
%Position
IMU_data_pack(1,25)=0;
IMU_data_pack(1,26)=0;
IMU_data_pack(1,27)=block.InputPort(8).Data;
IMU_data_25_26_27=[IMU_data_pack(1,25),IMU_data_pack(1,26),IMU_data_pack(1,27)];
fwrite(s,IMU_data_25_26_27,'int32');
%Velocity NED
IMU_data_pack(1,28)=block.InputPort(12).Data;
IMU_data_pack(1,29)=0;
IMU_data_pack(1,30)=0;
IMU_data_pack(1,31)=block.InputPort(7).Data;
IMU_data_29_30_31=[IMU_data_pack(1,28),IMU_data_pack(1,29),IMU_data_pack(1,30),IMU_data_pack(1,31)];
fwrite(s,IMU_data_pack(1,28),'uint8');
fwrite(s,IMU_data_29_30_31,'uint16');
%Acceleration NED
IMU_data_pack(1,32)=block.InputPort(9).Data;
IMU_data_pack(1,33)=block.InputPort(10).Data;
IMU_data_pack(1,34)=block.InputPort(11).Data;
IMU_data_32_33_34=[IMU_data_pack(1,32),IMU_data_pack(1,33),IMU_data_pack(1,34)];
fwrite(s,IMU_data_32_33_34,'int16');
%Acceleration XYZ
IMU_data_pack(1,35)=0;
IMU_data_pack(1,36)=0;
IMU_data_pack(1,37)=0;
IMU_data_35_36_37=[IMU_data_pack(1,35),IMU_data_pack(1,36),IMU_data_pack(1,37)];
fwrite(s,IMU_data_35_36_37,'int16');
%AirHeight
IMU_data_pack(1,38)=block.InputPort(8).Data;
fwrite(s,IMU_data_pack(1,38),'int32');

%cnt
IMU_data_pack(1,39)=block.InputPort(13).Data;
fwrite(s,IMU_data_pack(1,39),'int32');


%CRC
crc_gen=uint16(40961);
crc=uint16(65535);
buf_len=32;

if (buf_len~=0)
    for i=1:1:buf_len
        
        crc=uint16(bitxor(crc,uint16(IMU_data_pack(1,i))));
       if (crc&&1==1)
           crc=uint16(bitshift(crc,-1));
           crc=uint16(bitxor(crc,crc_gen));
       else
           crc=uint16(bitshift(crc,-1));
       end
    end
end

fwrite(s,crc,'uint16');
IMU_data_pack(1,40)=crc;


  
%endfunction


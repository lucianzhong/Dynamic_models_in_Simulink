

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
   block.RegBlockMethod('Start', @Start);
  block.RegBlockMethod('Outputs',                 @Output);  
  block.RegBlockMethod('Terminate', @Terminate);
  
%endfunction


function Start(block)
global s;
s=serial('COM5','BaudRate',256000);
fopen(s);


function Output(block)
global s

block.OutputPort(1).Data = block.InputPort(1).Data;

IMU_data_pack=zeros(1,41);

IMU_data_pack(1,1)=165;%֡ͷ
IMU_data_pack(1,2)=90;%֡ͷ
IMU_data_pack(1,3)=83;%֡����
IMU_data_pack(1,4)=0;%����
IMU_data_pack(1,5)=97;%֡��־

%���ݶ�
IMU_data_pack(1,6)=127;%Flag0
IMU_data_pack(1,7)=11;%Flag1
IMU_data_pack(1,8)=128;%NavStatus
IMU_data_1_8=[IMU_data_pack(1,1),IMU_data_pack(1,2),IMU_data_pack(1,3),IMU_data_pack(1,4),IMU_data_pack(1,5),IMU_data_pack(1,6),    IMU_data_pack(1,7),IMU_data_pack(1,8)];
fwrite(s,IMU_data_1_8,'uchar');
% Pitch,Roll,Yaw
IMU_data_pack(1,9)=-1;%block.InputPort(1).Data; %0,1
IMU_data_pack(1,10)=-1;%block.InputPort(2).Data;%2,3
IMU_data_pack(1,11)=-1;%block.InputPort(3).Data;%4,5
IMU_data_9_10_11=[IMU_data_pack(1,9),IMU_data_pack(1,10),IMU_data_pack(1,11)];
fwrite(s,IMU_data_9_10_11,'int16');
%q0,q1,q2,q3

IMU_data_pack(1,12)=-1;%6,7,8,9
IMU_data_pack(1,13)=-1;%10,11,12,13
IMU_data_pack(1,14)=-1;%14,15,16,17
IMU_data_pack(1,15)=-1;%18,19,20,21
IMU_data_12_13_14_15=[IMU_data_pack(1,12),IMU_data_pack(1,13),IMU_data_pack(1,14),IMU_data_pack(1,15)];
fwrite(s,IMU_data_12_13_14_15,'float32');


%dpitch,droll,dyaw 22~27
IMU_data_pack(1,16)= -1;%block.InputPort(4).Data;
IMU_data_pack(1,17)= -1;%block.InputPort(5).Data;
IMU_data_pack(1,18)=-1;% block.InputPort(6).Data;
IMU_data_9_10_11=[IMU_data_pack(1,16),IMU_data_pack(1,17),IMU_data_pack(1,18)];
fwrite(s,IMU_data_9_10_11,'int16');
%AngRateN,AngRateE,AngRateD 28~33
IMU_data_pack(1,19)=257;
IMU_data_pack(1,20)=257;
IMU_data_pack(1,21)=257;
IMU_data_19_20_21=[IMU_data_pack(1,19),IMU_data_pack(1,20),IMU_data_pack(1,21)];
fwrite(s,IMU_data_19_20_21,'int16');
%AngRateX,AngRateY,AngRateZ 34~39
IMU_data_pack(1,22)=258;
IMU_data_pack(1,23)=258;
IMU_data_pack(1,24)=258;
IMU_data_22_23_24=[IMU_data_pack(1,22),IMU_data_pack(1,23),IMU_data_pack(1,24)];
fwrite(s,IMU_data_22_23_24,'int16');
%Position 40~51
IMU_data_pack(1,25)=-1;
IMU_data_pack(1,26)=-1;
IMU_data_pack(1,27)=-1;%block.InputPort(8).Data;
IMU_data_25_26_27=[IMU_data_pack(1,25),IMU_data_pack(1,26),IMU_data_pack(1,27)];
fwrite(s,IMU_data_25_26_27,'int32');
%Velocity NED
IMU_data_pack(1,28)=1;%block.InputPort(12).Data; 52
fwrite(s,IMU_data_pack(1,28),'uchar');
%53~58
IMU_data_pack(1,29)=259;
IMU_data_pack(1,30)=259;
IMU_data_pack(1,31)=259;%block.InputPort(7).Data;
IMU_data_29_30_31=[IMU_data_pack(1,29),IMU_data_pack(1,30),IMU_data_pack(1,31)];
fwrite(s,IMU_data_29_30_31,'uint16');
%Acceleration NED 59~64
IMU_data_pack(1,32)=-1;%block.InputPort(9).Data;
IMU_data_pack(1,33)=-1;%block.InputPort(10).Data;
IMU_data_pack(1,34)=-1;%block.InputPort(11).Data;
IMU_data_32_33_34=[IMU_data_pack(1,32),IMU_data_pack(1,33),IMU_data_pack(1,34)];
fwrite(s,IMU_data_32_33_34,'int16');
%Acceleration XYZ 65~70
IMU_data_pack(1,35)=257;
IMU_data_pack(1,36)=257;
IMU_data_pack(1,37)=258;
IMU_data_35_36_37=[IMU_data_pack(1,35),IMU_data_pack(1,36),IMU_data_pack(1,37)];
fwrite(s,IMU_data_35_36_37,'int16');
%AirHeight 71~74
IMU_data_pack(1,38)=-1;%block.InputPort(8).Data;
fwrite(s,IMU_data_pack(1,38),'int32');

%cnt
cnt=1;%block.InputPort(13).Data;
IMU_data_pack(1,39)=cnt;%block.InputPort(13).Data;
fwrite(s,IMU_data_pack(1,39),'uchar');


%%%%%%%%%%%%%Split Data for CRC 1~84
IMU_split_crc=zeros(1,84);
%1~8
j=1;
for i=1:1:8
IMU_split_crc(1,i)=IMU_data_pack(1,i);
j=j+1;
end
%9~14
for i=9:1:11
    a=dec_to_bia(IMU_data_pack(1,i),16);
    
   IMU_split_crc(1,j)=bin2dec(a(9:16));
   j=j+1;
   IMU_split_crc(1,j)=bin2dec(a(1:8));
   j=j+1;
end
%15~30
for i=12:1:15
    a=dec_to_bia(IMU_data_pack(1,i),32);
    IMU_split_crc(1,j)=uint8(bin2dec(a(25:32)));
    j=j+1;
    IMU_split_crc(1,j)=bin2dec(a(17:24));
    j=j+1;
    IMU_split_crc(1,j)=bin2dec(a(9:16));
    j=j+1;
    IMU_split_crc(1,j)=bin2dec(a(1:8));
    j=j+1;
end
%31~36
for i=16:1:18
a=dec_to_bia(IMU_data_pack(1,i),16);
IMU_split_crc(1,j)=bin2dec(a(9:16));
j=j+1;
IMU_split_crc(1,j)=bin2dec(a(1:8));
j=j+1;
end
%37~42
for i=19:1:21
a=dec_to_bia(IMU_data_pack(1,i),16);
IMU_split_crc(1,j)=bin2dec(a(9:16));
j=j+1;
IMU_split_crc(1,j)=bin2dec(a(1:8));
j=j+1;
end
%43~48
for i=22:1:24
a=dec_to_bia(IMU_data_pack(1,i),16);
IMU_split_crc(1,j)=bin2dec(a(9:16));
j=j+1;
IMU_split_crc(1,j)=bin2dec(a(1:8));
j=j+1;
end
%49~60
for i=25:1:27
a=dec_to_bia(IMU_data_pack(1,i),32);
IMU_split_crc(1,j)=bin2dec(a(25:32));
j=j+1;
IMU_split_crc(1,j)=bin2dec(a(17:24));
j=j+1;
IMU_split_crc(1,j)=bin2dec(a(9:16));
j=j+1;
IMU_split_crc(1,j)=bin2dec(a(1:8));
j=j+1;
end
%61
i=28;
a=dec_to_bia(IMU_data_pack(1,i),8);
IMU_split_crc(1,j)=bin2dec(a(1:8));
j=j+1;
%62~67
for i=29:1:31
a=dec_to_bia(IMU_data_pack(1,i),16);  
IMU_split_crc(1,j)=bin2dec(a(9:16));
j=j+1;
IMU_split_crc(1,j)=bin2dec(a(1:8));
j=j+1;
end
%68~73
for i=32:1:34
a=dec_to_bia(IMU_data_pack(1,i),16);  
IMU_split_crc(1,j)=bin2dec(a(9:16));
j=j+1;
IMU_split_crc(1,j)=bin2dec(a(1:8));
j=j+1;
end
%74~79
for i=35:1:37
a=dec_to_bia(IMU_data_pack(1,i),16);  
IMU_split_crc(1,j)=bin2dec(a(9:16));
j=j+1;
IMU_split_crc(1,j)=bin2dec(a(1:8));
j=j+1;
end

%80~83
i=38;
a=dec_to_bia(IMU_data_pack(1,i),32);
IMU_split_crc(1,j)=bin2dec(a(25:32));
j=j+1;
IMU_split_crc(1,j)=bin2dec(a(17:24));
j=j+1;
IMU_split_crc(1,j)=bin2dec(a(9:16));
j=j+1;
IMU_split_crc(1,j)=bin2dec(a(1:8));
j=j+1;
%84
i=39;
a=dec_to_bia(IMU_data_pack(1,i),8);
IMU_split_crc(1,j)=bin2dec(a(1:8));
%%%%%%%%%%%%%%%%%%%%%

%CRC
crc_gen=uint16(40961);
crc=uint16(65535);
%buf_len=84;

buf_len=84;



 if (buf_len~=0)
    for i=1:1:buf_len
        crc=uint16(bitxor(crc,uint16(IMU_split_crc(1,i))));
        
        
        
       if (crc&&1==1)
           crc=uint16(bitshift(crc,-1));
           crc=uint16(bitxor(crc,crc_gen));
       else
           crc=uint16(bitshift(crc,-1));
       end
    end
end
crc
fwrite(s,crc,'uint16');
IMU_data_pack(1,40)=crc;

%checksum
checksum=0;

for j=1:1:40
    checksum_data=dec_to_bia(IMU_data_pack(1,j),16);
    checksum_data=bin2dec(checksum_data(9:16));    
    
   checksum=checksum_data+checksum;
   
   checksum=dec2bin(checksum,16);
   checksum=bin2dec(checksum(9:16));   
end


 fwrite(s,checksum,'uchar');
 
function Terminate(block)
global s;
fclose(s);
delete(s);
clear s  
  
%endfunction


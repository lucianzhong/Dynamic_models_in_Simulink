clear all

%Navigationloop initilization
m = 1.17;
g = 9.8;
Ixx =2.754e-4;
Iyy =2.5955e-4;
Izz =5.7874e-4;

L = 0.225;
%PID parameters for x axis
kpx = 0.8;
kix =0;
kdx =0.5;
%PID parameters for y axis
kpy = 0.8;
kiy =0;
kdy =0.5;



%Innerloop initiliztion
global Kpz Kdz Kpp Kdp Kpt Kdt Kpps Kdps cnt
global IMU_data_pack
IMU_data_pack=zeros(1,87);

kpp = 0.8;
kdp = 0.4;

kpt = 1.2;
kdt = 0.4;

kpps = 1;
kdps = 0.4;

kpz = 100;
kdz = 20;

cnt=0;
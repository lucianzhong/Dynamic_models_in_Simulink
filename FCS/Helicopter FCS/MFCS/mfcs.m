
clear all

A=[
   -0.0258,-0.0272,-0.007,-0.1709,0,-0.0097,0.0102,-0.0049,0.0023;
   0.0071,-0.0733,0.0455,0,0.1709,0,-0.0048,-0.0101,-0.3811;
   0.1402,-0.0054,-0.5581,0,0.0097,0,0.3844,-0.008,-0.001;
   0,0,0,0,0,0,1,0,0;
   0,0,0,0,0,0,0,1,0;
   0,0,0,0,0,0,0,0,1;
   1.2403,0.6055,-1.0832,0,0.0016,0,-0.9457,0.3126,0.005;
   1.0993,-3.5087,11.6361,0,0.0002,0,-1.2981,-2.9709,-0.0158;
   -0.5667,1.4329,0.2185,0,0,0,0.3139,-0.1260,-0.0918
 ];


B=[
   0.074,0,0,-0.0052;
   -0.0083,0.0632,-0.0614,0.0164;
   0.0887,0.006,0,-0.6181;
   0,0,0,0;
   0,0,0,0;
   0,0,0,0;
   -5.5627,0.3726,-0.1911,-0.2058;
   -2.4301,18.4029,1.6642,1.7999;
   -0.0184,1.7084,8.4545,4.4001
];


C=eye(9);
D=zeros(9,4);







T=0.1;
I=eye(9);
Bd=(I-A*T)^(-1)*B*T;
Baa=zeros(4,4);
Baa(1,:)=Bd(7,:);
Baa(2,:)=Bd(8,:);
Baa(3,:)=Bd(9,:);
Baa(4,:)=Bd(3,:);

G3=Baa^(-1);

G1=[
    0,0,0,1,0,0,0,0,0;
    0,0,0,0,1,0,0,0,0;
0,0,0,0,0,0,0,0,0;
0,0,0,0,0,0,0,0,0;
];


G2=[0,0,0,0,0,0,1,0,0;
    0,0,0,0,0,0,0,1,0;
    0,0,0,0,0,0,0,0,1;
    0,0,1,0,0,0,0,0,0;    
];


G4=[
    4,0,0,0;
    0,5,0,0;
    0,0,4.5,0;
    0,0,0,4;

];


G5=[7,0,0,0;
    0,7,0,0;
    0,0,1,0;
    0,0,0,1;];

R=[
    1.2,0,0,0;
    0,1.2,0,0;
    0,0,2.4,0;
    0,0,0,1.2;
];



run MFCS
sim MFCS
u=y(:,1);
v=y(:,2);
w=y(:,3);
pitch_angle=y(:,4);
roll_angle=y(:,5);
yaw_angle=y(:,6);
p=y(:,7);
q=y(:,8);
r=y(:,9);


figure
subplot(9,1,1) 
plot(t,u)
legend('u')

subplot(9,1,2)
plot(t,v)
legend('v')

subplot(9,1,3)
plot(t,w)
legend('w')

subplot(9,1,4)
plot(t,pitch_angle)
legend('pitch angle')

subplot(9,1,5)
plot(t,roll_angle)
legend('roll angle')

subplot(9,1,6)
plot(t,yaw_angle)
legend('yaw angle')

subplot(9,1,7)
plot(t,p)
legend('p')

subplot(9,1,8)
plot(t,q)
legend('q')

subplot(9,1,9)
plot(t,r)
legend('r')


pitch_angle_control_input=control_input(:,1);
roll_angle_control_input=control_input(:,2);
yaw_rate_control_input=control_input(:,3);
vertical_velocity_control_input=control_input(:,4);


figure
subplot(4,1,1) 
plot(t,pitch_angle_control_input)
legend('pitch angle control input')

subplot(4,1,2) 
plot(t,roll_angle_control_input)
legend('roll angle control input')

subplot(4,1,3) 
plot(t,yaw_rate_control_input)
legend('yaw rate control input')

subplot(4,1,4) 
plot(t,vertical_velocity_control_input)
legend('vertical velocity control input')






[A,B,C,D]=linmod('hexarotor_dynamic_model');
G=ss(A,B,C,D);
[G1,K,d,Gam]=decouple(G);


% Q=diag([100,1,1,1,1,1,1,1,1,1,1,1,1]);
% R=eye(4,4);
% [k,p,r]=lqr(A,B,Q,R);
% t=0:0.1:10;
% figure(1)
% step(A-B*k,B,C,D,1,t)
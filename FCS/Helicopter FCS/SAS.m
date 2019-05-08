clear all

s=tf('s');


sys1=1.01*(s+0.629)*(s+0.0145)/((s^2-0.042*s+0.152)*(s^2+1.36*s+0.864));%decoupled longtudinal transfer function
rlocus(sys1)
sgrid



a=1;%pitch rate feedback gain
b=0.8;%pitch angle feedback gain

sys2=a*(b/a+s);%negative feedback loop

H=feedback(sys1,sys2,-1);
damp(H)
figure
impulse(sys1,40)
figure
impulse(H,40)

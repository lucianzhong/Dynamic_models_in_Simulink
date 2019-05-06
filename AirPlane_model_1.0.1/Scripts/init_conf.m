function init_conf

global Conf Flight;
global Geom Atm;

% Interpolation to find Flap and Slat initial values form FlapSlat Lever
flapslat=[0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0];
slat=[0, 0, 0.0, 0.0, 0.0, 0.0, 0.0];
flap=[0, 0, 10.0, 20.0, 35.0, 35.0, 35.0];
Conf.slat = interp1(flapslat,slat,Flight.flapslat);
Conf.flap = interp1(flapslat,flap,Flight.flapslat);

% Green Band Stab

%Clmax
flap=[0, 10.0, 20.0, 35.0];
clmax=[1.2, 1.4, 1.8, 2.2];
Conf.clmax=interp1(flap,clmax,Conf.flap);

% Call to Atmosphere
[sqsig,sound,p_p0]=atmosphere(Flight.alt,Flight.delta_isa);
tas=sqrt(2.0*Flight.weight*Atm.grav/Atm.rho0/Geom.Wing.sw/Conf.clmax)/sqsig;
mach=tas/sound;
ias=Atm.vs0*sqrt(5.0*((p_p0*((mach*mach/5.0+1.0)^3.5-1.0)+1.0)^(1.0/3.5)-1.0));
kias=ias/Atm.kt_to_vel;

Conf.kvstall = kias;
Conf.kv2     = 1.13*kias;
Conf.kvref   = 1.23*kias;

switch Flight.Speed.type
    case  {'kias','vref','v2','vsfact'}
        switch Flight.Speed.type
          case   'vref'
              kias = Conf.vref + Flight.Speed.value;
          case  'v2'
              kias = Conf.v2 + Flight.Speed.value;
          case   'vsfact'
               kias = Conf.kvstall * Flight.Speed.value;
          otherwise
               kias=Flight.Speed.value;
        end
        cas    = kias*Atm.kt_to_vel;
        mach = sqrt(5*((((((((cas/Atm.vs0)^2)/5)+1)^3.5-1)/p_p0)+1)^(1/3.5)-1));
        tas      = mach*sound;
        keas  = tas/Atm.kt_to_vel*sqsig;
   case   'keas' 
        keas = Flight.Speed.value;
        tas = keas/sqsig*Atm.kt_to_vel;
        mach = tas/sound;
        cas = Atm.vs0*sqrt(5*(((p_p0*((((mach^2)/5)+1)^3.5-1))+1)^(1/3.5)-1));
        kias = cas/Atm.kt_to_vel;
   case  'mach' 
        mach = Flight.Speed.value;
        tas = mach*sound;
        keas = tas/Atm.kt_to_vel*sqsig;
        cas = Atm.vs0*sqrt(5*(((p_p0*((((mach^2)/5)+1)^3.5-1))+1)^(1/3.5)-1));
        kias = cas/Atm.kt_to_vel;
    otherwise
        kias=Flight.Speed.value;
        cas    = kias*Atm.kt_to_vel;
        mach = sqrt(5*((((((((cas/Atm.vs0)^2)/5)+1)^3.5-1)/p_p0)+1)^(1/3.5)-1));
        tas      = mach*sound;
        keas  = tas/Atm.kt_to_vel*sqsig;       
end

Conf.kias=kias;
Conf.mach=mach;
Conf.tas=tas;
Conf.cas=cas;
Conf.keas=keas;
Conf.dynp=Atm.rho0*(keas*Atm.kt_to_vel)^2/2.0;
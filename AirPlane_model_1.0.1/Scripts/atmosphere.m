function [Sqrt_Sigma,Vsound,P_P0,Rho,mu,DhpDh,T_T0]=atmosphere(Hp,isa)

%   Inputs:   Hp   (Pressure Altitude)    [m]

THp=11000;             %   THp  (Tropopause Hp  )     [m]
  e=4.2558797;         % Gas Constant Ratio
Rho0=1.225;             %   Rho0 (S.L. Density   ) slug/ft3  [Kg/m3]
Vs0=340.294;           %   Vs0  (S.L. Sound Vel.)      [m/s]
mu0=1.7894E-005; %  

if  nargin<2
  disp('---------------------------------------------')
  disp('     No isa given, using isa=0')
  disp('---------------------------------------------')
  isa=0;
end

H=Hp/THp;
if H<1
  T_std=288.15-71.5*H;
  P_P0=(1.0-0.248135*H)^(e+1);
  Rho_Rho0=(1.0-0.248135*H)^e;
else
  T_std=216.65;
  Nhp=exp(-1.73457*H);
  P_P0=Nhp*1.26567;
  Rho_Rho0=Nhp*1.68338;
end
Tisa=isa;
T_kelvin = T_std+Tisa;
T_T0=T_kelvin/288.15;
DhpDh=T_std/(T_std+Tisa);
Vsound=sqrt(T_T0)*Vs0;
Rho_Std=Rho_Rho0*Rho0;
Rho=Rho_Std/(1+Tisa/T_std);
Sqrt_Sigma=sqrt(Rho/Rho0);

% Absolute air viscosity
mu=mu0*(T_kelvin^1.5/(T_kelvin+120)/11.984);

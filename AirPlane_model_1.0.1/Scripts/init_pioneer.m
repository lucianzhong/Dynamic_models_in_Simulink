global Geom
global Controls
global Aero
global Mass
global Eng
global Lgear
global Atm
global Ap
global Sensors
global Flight_latitude Flight_longitude Flight_TargetPoints Flight_MaxTargetPoints
global Flight_Trimming Flight_AutoPilotON Flight_WindGustON Flight_TimeStep Flight_SensorsON Flight_DamperON
global Flight_LoiterRadius Flight_LoiterMode Flight_LoiterLenght Flight_DeltaSpiral

% Atmospheric Constants
Atm.grav      = 9.806;        % Acceleration of Gravity (m/s2)
Atm.tropopause= 11000;        % THp  (Tropopause Hp  )     [m]
Atm.gas_ratio = 4.2558797;    % Gas Constant Ratio
Atm.rho0      = 1.225;        % Rho0 (S.L. Density   ) slug/ft3  [Kg/m3]
Atm.vs0       = 340.294;      % Vs0  (S.L. Sound Vel.)      [m/s]
Atm.mu0       = 1.7894E-005;  % Kinematic Viscosity (S.L. ISA)
Atm.kt_to_vel = 0.5144444;    % Conversion kt to m/s  (=0.5148 used by Sergio)

% Wind and turbulence variables initialization
% Tower Wind Model
Flight_TowerWindON = 0;    % Choose a Tower Wind (with a computed Height Profile)
Flight_TowerWind_X = 0;    % Wind X (inertial)
Flight_TowerWind_Y = 0;    % Wind Y (inertial)
Flight_TowerWind_Z = 0;    % Wind Z (inertial)

% WindShear
Flight_WindShearON = 0;    % Choose a WindShear Profile
Atm.WindShear.WindHeight=[0 1500]; % Wind Height profile
Atm.WindShear.Wind_X    =[0 0];    % Wind X (inertial)
Atm.WindShear.Wind_Y    =[0 0];    % Wind Y (inertial)
Atm.WindShear.Wind_Z    =[0 0];    % Wind Z (inertial)

% Turbulence Model
% No Turbulence
Flight_TurbON=0;

% Light Turbulence
%Flight_TurbON=0.2;

% Mild turbulence
%Fligh_TurbON=0.5

% Full Turbulence Model
%Flight_TurbON=1;

% Variable required to tell RT-LAB to compile for use with DINAMO
OpalDinamo = 1;
% Variables used for DINAMO Demo
OpOutFileIndex = 1;
Flight_Trimming = 0;
Flight_AutoPilotON = 0;
Flight_SensorsON = 0;
Flight_WindGustON = 0;
Flight_TimeStep = 0.01;
Flight_DamperON = 1;
%---------------------
% Model parameters
%---------------------
init_geom_pioneer;
init_controls_pioneer;
init_aero_pioneer;
init_mass_pioneer;
init_eng_pioneer;
init_lgear_pioneer;
init_ap_pioneer;
init_sensors;

% Initial coordinates
Flight_latitude=30; 
Flight_longitude=150;
% Target Points
Flight_MaxTargetPoints=2; 
Flight_TargetPoints=zeros(4,Flight_MaxTargetPoints);
% Loiter Mode Parameters
Flight_LoiterMode = 1;
Flight_LoiterRadius = 3000; 
Flight_LoiterLenght=50000; 
Flight_DeltaSpiral=500;

trim_cruise_pioneer

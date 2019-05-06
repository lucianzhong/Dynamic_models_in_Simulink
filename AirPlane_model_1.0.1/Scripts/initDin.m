global Geom
global Controls
global Aero
global Mass
global Eng
global Lgear
global Atm
global Ap
global Sensors
global Flight_latitude Flight_longitude
global Flight_Trimming Flight_AutoPilotON Flight_WindGustON Flight_TimeStep Flight_SensorsON
global Flight_LoiterRadius Flight_LoiterLenght Flight_DeltaSpiral
global Flight_MaxTargetPoints
global PEG_CLwbnp PEG_CLht PEG_CMwbnp PEG_CMht PEG_CDwbnp PEG_CYrud PEG_CYbeta PEG_CRail
global PEG_CRrud PEG_CRp PEG_CRbeta PEG_CNr PEG_CNrud PEG_CNbeta PEG_CLht_elev
global Target_Lat Target_Lon Target_Alt Target_Speed
global Flight_LoiterMode Flight_LoiterMode2 Flight_LoiterMode3 Flight_LoiterMode4 Flight_LoiterMode5

% Atmospheric Data Constants
Atm.grav      = 9.806;        % Acceleration of Gravity (m/s2)
Atm.tropopause= 11000;        % THp  (Tropopause Hp  )     [m]
Atm.gas_ratio = 4.2558797;    % Gas Constant Ratio
Atm.rho0      = 1.225;        % Rho0 (S.L. Density   ) slug/ft3  [Kg/m3]
Atm.vs0       = 340.294;      % Vs0  (S.L. Sound Vel.)      [m/s]
Atm.mu0       = 1.7894E-005;  % Kinematic Viscosity (S.L. ISA)
Atm.kt_to_vel = 0.514444;     % Conversion kt to m/s

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

%--------------------------------------------------------------------------------------

% Variable required to tell RT-LAB to compile for use with DINAMO
OpalDinamo = 0;

% Variables used for DINAMO Demo
OpOutFileIndex = 1;
Flight_Trimming = 0;
Flight_AutoPilotON = 0;
Flight_DamperON = 1;
Flight_SensorsON = 0;
Flight_WindGustON = 0;
Flight_TimeStep = 0.01;
DataAcqON = 0;

%---------------------
% Model parameters
%---------------------
init_geom;
init_controls;
init_aero;
init_mass;
init_eng;
init_lgear;
init_ap;
init_sensors;

Ap.Alt.pgain = 0.1;
Ap.Track.LimPhi=30;
% Model parameters

Flight_latitude=34; 
Flight_longitude=-117.5; 
Flight_LoiterRadius = 20000; 
Flight_LoiterMode = 1;
Flight_LoiterMode2 = 2;
Flight_LoiterMode3 = 3;
Flight_LoiterMode4 = 2;
Flight_LoiterMode5 = 3;
Flight_LoiterLenght=50000; 
Flight_DeltaSpiral=1000;


% TP_Dinamo_demo
TP_Dinamo_demo11
Flight_MaxTargetPoints = 6;

trim_cruise

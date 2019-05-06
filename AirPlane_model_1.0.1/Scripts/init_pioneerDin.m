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
global Flight_Trimming Flight_AutoPilotON Flight_WindGustON Flight_TimeStep Flight_SensorsON Flight_DamperON
global Flight_LoiterRadius Flight_LoiterMode Flight_LoiterLenght Flight_DeltaSpiral
global Flight_MaxTargetPoints
global PEG_CLwb PEG_CLht_elev PEG_CMelev PEG_CRail PEG_CRbeta PEG_CNbeta
global Flight_PEST Flight_N1Driver
global Target_Lat Target_Lon Target_Alt Target_Speed
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
Flight_SensorsON = 0;
Flight_WindGustON = 0;
Flight_DamperON = 1;
Flight_TimeStep = 0.01;
DataAcqON = 0;

% Parameter Estimation Gain
Flight_PEST = 0; Flight_N1Driver = 0;
PEG_CLwb=1; PEG_CLht_elev=1; PEG_CMelev=1; PEG_CRail=1; PEG_CRbeta=1; PEG_CNbeta=1;
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

% Model parameters

Flight_latitude=33.954; 
Flight_longitude=-117.45; 
Flight_LoiterRadius = 1000; 
Flight_LoiterMode = 1; 
Flight_LoiterLenght=50000; 
Flight_DeltaSpiral=500;

Target_Lat = [ 34.02   34.025   34.03   34.05   34.03    34.02   34.05   34.04   34.02   34.01  34.02   34.00];
              %   1       2      3        4         5       6       7      8       9       10     11     12
Target_Lon = [-117.50 -117.50 -117.51 -117.505 -117.5 -117.49 -117.49 -117.505 -117.505 -117.49 -117.495 -117.5];
Target_Alt = [ 3300   3180  3520   3520  3500  2500  3100  3400   3600  2300  2500  2550];
Target_Speed = [105    96    105    100   105   125   104   100   104   120   106   105];

Flight_MaxTargetPoints = 12;

trim_cruise_pioneer


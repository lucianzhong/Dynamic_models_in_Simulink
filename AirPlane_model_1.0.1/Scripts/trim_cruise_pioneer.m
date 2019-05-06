% Configuration Parameters
global Flight Conf

% Model name
Flight.model='UAV';

% Flight Phase (for CAP)
Flight.cat='b'; % Cruise

% Weight and Cg
Flight.weight= 450*0.45;   % Weight [kg]
Flight.grav  = 9.806; ; % Gravity acceleration (ft/s2)
Flight.cg    = 0.25;    % Cg (/mac)
Flight.ycg   = 0.0;     % Lateral cg [ft]
Flight.zcg   =-0.2*0.305;   % Vertical cg [ft]

% Inertias
Flight.InertiaSelect=0;
% For InertiaSelect:
% 1: Inertia values are provided
% 0: Inertia are computed in the model from weight and cg
Flight.ixx   = 34.832; % Ixx [Slug.m2]
Flight.iyy   = 67.08; % Iyy [Slug.m2]
Flight.izz   = 82.22; % Izz [Slug.m2]
Flight.ixz   = 4.902; % Ixz [Slug.m2]

% This parameters are not used

% Empenage Controls
Flight.lgdown=1;
Flight.flapslat=0;
Flight.stab      = -1;   % Stab  Angle [deg], if null trim will find it!
Flight.regime    = 1;   % Engine Regime for both engines [1-6]
Flight.regime_lh = 1;   % LH Engine Regime [1-6]
Flight.regime_rh = 1;   % RH Engine Regime [1-6]

% Environmental conditions
Flight.alt          = 100; % Pressure Altitude [m]
Flight.icing_on     = 0;   % Icing ON [0-4]
Flight.delta_isa    = 0;   % Delta temperature form isa [deg]
Flight.ground_height= 0;

%Speed, choose one!
%Flight.Speed.type   = 'keas';   % Equivalent AirSpeed (kt)
%Flight.Speed.value  = 150;
Flight.Speed.type   = 'kias';   % Indicated AirSpeed (kt)
Flight.Speed.value  = 80;
% Flight.Speed.type   = 'mach';    % Mach number
% Flight.Speed.value  = 0.1;
%Flight.Speed.type   = 'dv2';    % Delta from V2 [kt]
%Flight.Speed.value  = 0;
%Flight.Speed.type   = 'dvref';  % Delta from Vref [kt]
%Flight.Speed.value  = 0;
%Flight.Speed.type   = 'vsfact'; % Factor on Vstall
%Flight.Speed.value  = 1.3;
%Flight.Speed.type   = 'cl'; % Performance Cl
%Flight.Speed.value  = 0.5;

% Trim initial values, these are just initialization,
% to be replaced by the trim routine
Flight.FuelCut= [0,0]; % Fuel cut (lh,rh)
Flight.gamma  = 0;     % Flight path angle
Flight.hagl   = [];    % Height above ground, if null, trim will use Flight.alt
Flight.hagl_trim = 0.27;% Height above ground for ground trim

Flight.beta   = 0;     % Sideslip angle [deg]
Flight.track  = 0;     % Track angle [deg]
Flight.heading= 0;     % Heading angle [deg]
Flight.nz     = [];    % Null unless set for pull-up trims
Flight.phi    = [];    % Null unless set for bank angle other than zero
% Engine
Flight.throttle     =[];
% Throttle: if null, trim will find it, if given, both lh and rh will be equal
Flight.throttle_lh  =[];
Flight.throttle_rh  =[];
% Throttle lh, rh: if null, trim will find it, if given, and not throttle, trim will use it

% Selected output names
Flight_longout={'Gamma','ThetaDeg','Altitude','Mach','KIAS','Alpha','NetThrust','Elevator','StabDeg','ColForce'};

trim_map
init_conf
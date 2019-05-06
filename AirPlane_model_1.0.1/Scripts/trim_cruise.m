% Configuration Parameters
global Flight Conf

% Model name
Flight.model='GenericAircraft';

% Flight Phase (for CAP)
Flight.cat='b'; % Cruise

% Weight and Cg
Flight.weight= 30000;   % Weight [kg]
Flight.grav  = 9.806; ; % Gravity acceleration (ft/s2)
Flight.cg    = 0.25;    % Cg (/mac)
Flight.ycg   = 0.0;     % Lateral cg [ft]
Flight.zcg   = 0.0;    % Vertical cg [ft]

% Inertias
Flight.InertiaSelect=0;
% For InertiaSelect:
% 1: Inertia values are provided
% 0: Inertia are computed in the model from weight and cg
Flight.ixx   = 0; % Ixx [Slug.m2]
Flight.iyy   = 0; % Iyy [Slug.m2]
Flight.izz   = 0; % Izz [Slug.m2]
Flight.ixz   = 0; % Ixz [Slug.m2]

% Wing Controls
Flight.flapslat   = 1;     % FlapSlat Lever [1-6]
% FlapSlatLever: 1   2   3   4   5   6
% Slat Pos       0  15  15  15  25  25
% Flap Pos       0  10  20  32  32  50
Flight.lgdown    = 0;   % Gear Down Lever [0-1]

% Empenage Controls
Flight.stab      = -1;   % Stab  Angle [deg], if null trim will find it!
Flight.regime    = 1;   % Engine Regime for both engines [1-6]
Flight.regime_lh = 1;   % LH Engine Regime [1-6]
Flight.regime_rh = 1;   % RH Engine Regime [1-6]

% Environmental conditions
Flight.alt          = 8000; % Pressure Altitude [m]
Flight.icing_on     = 0;   % Icing ON [0-4]
Flight.delta_isa    = 0;   % Delta temperature form isa [deg]
Flight.ground_height= 0;
Flight.hagl_trim = 2.865;% Height above ground for ground trim
%Speed, choose one!
%Flight.Speed.type   = 'keas';   % Equivalent AirSpeed (kt)
%Flight.Speed.value  = 150;
%Flight.Speed.type   = 'kias';   % Indicated AirSpeed (kt)
%Flight.Speed.value  = 150;
Flight.Speed.type   = 'mach';    % Mach number
Flight.Speed.value  = 0.7;
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
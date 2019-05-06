% Configuration Parameters
global Flight_weight Flight_cg Flight_flapslat Flight_fslever Flight_regime_lh Flight_regime_rh
global Flight_alt Flight_delta_isa Flight_Speed_type Flight_Speed_value Flight_lgdown 
global Flight
global Flight_longitude Flight_latitude Flight_GeodHeight

% Weight and Cg
Flight_weight= Flight.weight;   % Weight [lbf]
Flight_grav  = Flight.grav;  % Gravity acceleration (ft/s2)
Flight_cg    = Flight.cg;    % Cg (/mac)
Flight_ycg   = Flight.ycg;     % Lateral cg [ft]
Flight_zcg   = Flight.zcg;    % Vertical cg [ft]

% Inertias
Flight_InertiaSelect=Flight.InertiaSelect;
% For InertiaSelect:
% 1: Inertia values are provided
% 0: Inertia are computed in the model from weight and cg
Flight_ixx   = Flight.ixx; % Ixx [Slug.m2]
Flight_iyy   = Flight.iyy; % Iyy [Slug.m2]
Flight_izz   = Flight.izz; % Izz [Slug.m2]
Flight_ixz   = Flight.ixz; % Ixz [Slug.m2]

% Wing Controls
Flight_flapslat   = Flight.flapslat;     % FlapSlat Lever [1-6]
% FlapSlatLever: 1   2   3   4   5   6
% Slat Pos       0  15  15  15  25  25
% Flap Pos       0  10  20  32  32  50
Flight_lgdown    = Flight.lgdown;   % Gear Down Lever [0-1]

% Engine Controls
Flight_regime_lh = Flight.regime_lh;   % LH Engine Regime [1-6]
Flight_regime_rh = Flight.regime_rh;   % RH Engine Regime [1-6]

% Environmental conditions
Flight_alt          = Flight.alt; % Pressure Altitude [m]
Flight_delta_isa    = Flight.delta_isa;   % Delta temperature form isa [deg]

%Speeds
Flight_Speed_type   = Flight.Speed.type;    % Mach number
switch Flight.Speed.type
   case   'keas' 
        Flight_Speed_type = 0;
   case   'kias' 
        Flight_Speed_type = 1;
   case   'mach' 
        Flight_Speed_type = 2;
   case   'vref' 
        Flight_Speed_type = 3;
   case   'v2' 
        Flight_Speed_type = 4;
   case   'vsfact' 
        Flight_Speed_type = 5;
   case   'cl' 
        Flight_Speed_type = 6;
   otherwise
        Flight_Speed_type = 1;          
end
Flight_Speed_value  = Flight.Speed.value;


function init_geom_pioneer
global Geom
Geom.Wing.xwac = 2.638;
Geom.Wing.sw   = 30.42*0.09290304;% [m^2]
Geom.Wing.bref = 16.90*0.3048;    % [m]
Geom.Wing.cref = 1.80*0.3048;     % [m] 
Geom.C_B = Geom.Wing.cref/Geom.Wing.bref;
Geom.B_C = Geom.Wing.bref/Geom.Wing.cref;

Geom.Eng.Ypos = 0;           % [m]
Geom.Eng.Zpos = -0.2*0.3048; % [m] 
Geom.Eng.Xpos = -0.5*0.3048; % [m]
Geom.Eng.pitch = 0;      % [deg]
Geom.Eng.toeout=0;       % [deg]

Geom.Eng.Booster.Xpos = 0.1;    % [m] 
Geom.Eng.Booster.Ypos = 0;      % [m] 
Geom.Eng.Booster.Zpos =-0.05;   % [m]
Geom.Eng.Booster.pitch = 30;    % [deg]

Geom.Htail.xacht = 2*0.3048;
Geom.Htail.yacht = 0;
Geom.Htail.zacht = 0;

Geom.Vtail.xacvt = 2*0.3048;
Geom.Vtail.yacvt = 0;
Geom.Vtail.zacvt = 0;

Geom.Nacelle.xacnp = 0;
Geom.Nacelle.yacnp = 0;
Geom.Nacelle.zacnp = 0;

% Length              4.0 ft
% Wing Span           16.9 ft
% Max. Gross Wgt.     450.0 lb
% Payload Capacity    100.0 lb
% Max. Speed          115.0 mph
% Cruise Speed        92.0 mph
% Max. Altitude       15,000.0 ft
% Endurance           5.5 hr
% Engine              26.0 hp
% Landing Means       Net/Arresting
% Fuel Capacity       11 gallons
% Takeoff Means       RATO/Runway
% Fuel Type           AVGAS 100 










 
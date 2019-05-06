function init_lgear

global Lgear
global Geom
NN=2;
% Main Gear Parameters

%--------------------------------------------------------------------
% Local Parameters:
%--------------------------------------------------------------------

xpos = Geom.Wing.xwac + (6.05*0.3048 - 0.25*2.865);           % X pos of Hinge
ypos =  2.052;           % Y pos of Hinge
zpos = -1.163;           % Z pos of Hinge
strut_length=  1.880;    % Srut Length          [m]
tire_radius =  0.508;    % Tire Radius          [m]
hub_offset  =  0.162;    % Wheel Hub Offset     [m]

% Tire Contact Position Vector relative to Hinge
tire_rel_pos=[hub_offset,0,-(strut_length+tire_radius)];

% Tire local parameters
TAreaF = 3;                            % Tire Area Factor
TWidth = 0.2286;                       % Tire Width         [m]
TPress =  26800;                       % Tire Pressure      [N/m2]
TPRate =  32200;                       % Tire Pressure Rating

%Strut data in English Units
tire_stiffness = 5600; % lbf/in
strut_area=12.17; % in^2
tire_diam = 28.0; % in
damping=NN*400;      % lbf/(ft/s)^2
cfriction=NN*3400;   % lbf/(ft/s)
max_defl=2.00;    % ft
defl_in =[0.0 .162 .210 .350 0.510 0.655 1.080 1.220 1.350];  % ft
pres_psi=[0,420,550,920,1390,1850,3690,4620,10000]; % psi

%--------------------------------------------------------------------
% Global Parameters, returned in Lgear
%--------------------------------------------------------------------

% Hinge Position Vector
Lgear(1).Hinge.RposLmg=[xpos,-ypos,zpos];                    % LMG
Lgear(1).Hinge.RposRmg=[xpos,ypos,zpos];                    % RMG

% Tire Position Vector
Lgear(1).Tire.RposLmg = Lgear(1).Hinge.RposLmg+tire_rel_pos; % LMG
Lgear(1).Tire.RposRmg = Lgear(1).Hinge.RposRmg+tire_rel_pos; % RMG

Lgear(1).Tire.MaxComp     = 0.500;    % Max Tire Compression [m]
Lgear(1).Tire.Stiffness   = 2*tire_stiffness*.4536/.0254*9.806; % Tire Stiffness [N/m]

Lgear(1).Strut.Limit      = max_defl*.3048;    % Max Strut Compression [m]
Lgear(1).Strut.Damping    = damping*.4536/(.3048)^2*9.806;  % Hydraulic Damping [N/(m/s)^2]
Lgear(1).Strut.CFriction  = cfriction*.4536/.3048*9.806;     % Coulomb Friction, [N/(m/s)]
Lgear(1).Strut.Deflection = defl_in*.254;
Lgear(1).Strut.Stiffness  = pres_psi*strut_area*.4536*9.806;
Lgear(1).Strut.AccFactor  =    16;    % See NOTE

Lgear(1).Mass = 180;                   % Landing Gear Mass   [kg]

% Lgear(1).Friction.MaxSpeed = 76.2;    % Max Speed  (before slipping)    [m/s]
% Lgear(1).Friction.MaxFactor= -0.4;    % Max MuSide Factor
% Lgear(1).Tire.MaxRadius   = tire_diam*.0254;    % Tire Radius [m]
% Lgear(1).Tire.Radius      = tire_diam*.0254;    % Tire Radius [m]
% Lgear(1).Tire.AreaFactor  = TAreaF*sqrt(2*TWidth*Lgear(1).Tire.MaxRadius);
% Lgear(1).Tire.PressArea   = (TPress+0.44*TPRate)*TWidth^2;
% Lgear(1).Strut.Area       = strut_area*(.0254^2);  % Strut Area (m2)
% Lgear(1).Strut.Length     = strut_length;    % Srut Length          [m]


% Nose Gear Parameters

%--------------------------------------------------------------------
% Local Parameters:
%--------------------------------------------------------------------

xpos        =  Geom.Wing.xwac - 41.4*0.3048-0.25*2.865;               % X pos of Hinge
zpos        = -1.163;               % Z pos of Hinge
strut_length=  2.055;               % Srut Length          [m]  2.17  2.03
tire_radius =  0.343;               % Tire Radius          [m]
hub_offset  =  0.076;               % Wheel Hub Offset     [m]

% Tire Contact Position Vector relative to Hinge
tire_rel_pos=[hub_offset,0,-(strut_length+tire_radius)];

% Tire local parameters
TAreaF = 3;                            % Tire Area Factor
TWidth =  0.216;                       % Tire Width           [m]
TPress =  23500;                       % Tire Pressure      [N/m2]
TPrate =  33100;                       % Tire Pressure

%Strut_data in English Units
tire_stiffness = 2400; % lbf/in
strut_area=3.68;   % in^2
tire_diam = 19.5;  % in
damping=NN*165;      % lbf/(ft/s)^2
cfriction=NN*1700;   % lbf/(ft/s)
max_defl=1.51;%1.31; % ft
defl_in =[0,0.21,0.63,0.87,1.04,1.16,1.20,1.29,1.31]; % ft
pres_psi=[0, 250, 610,1040,1570,2020,2460,4460,5950]; % psi

%--------------------------------------------------------------------
% Global Parameters, returned in Lgear
%--------------------------------------------------------------------

% Hinge Position Vector
Lgear(2).Hinge.RposNg=[xpos,0,zpos];

% Tire Position Vector
Lgear(2).Tire.RposNg = Lgear(2).Hinge.RposNg+tire_rel_pos;

Lgear(2).Tire.MaxComp    = 0.500;    % Max Tire Compression [m]
Lgear(2).Tire.Stiffness  = 2*tire_stiffness*.4536/.0254*9.806; % Tire Stiffness [N/m]
Lgear(2).Strut.CFriction = cfriction*.4536/.3048*9.806;     % Coulomb Friction  [N/(m/s)]
Lgear(2).Strut.Damping   = damping*.4536/(.3048)^2*9.806;  % Hydraulic Damping [N/(m/s)^2]
Lgear(2).Strut.AccFactor = 16;    % See NOTE
Lgear(2).Strut.Deflection= defl_in*.254;
Lgear(2).Strut.Stiffness = pres_psi*strut_area*.4536*9.806;
% Lgear(2).Friction.MaxSpeed = 76.0;    % Max Speed  (before slipping)    [m/s]
% Lgear(2).Friction.MaxFactor= -0.4;    % Max MuSide Factor
% Lgear(2).Strut.Area      = strut_area*(.0254^2);  % Strut Area (m2)
% Lgear(2).Strut.Length    = strut_length;    Srut Length          [m]
Lgear(2).Strut.Limit     = max_defl*.3048;    %Max Strut Compression [m]
% Lgear(2).Tire.AreaFactor = TAreaF*sqrt(2*TWidth*Lgear(1).Tire.MaxRadius);
% Lgear(2).Tire.PressArea  = (TPress+0.44*TPrate)*TWidth^2;
% Lgear(2).Tire.MaxRadius  = tire_diam*.0254;    % Tire Radius [m]
% Lgear(2).Tire.Radius     = tire_diam*.0254;    % Tire Radius [m]



Lgear(2).Mass = 90;                    % Landing Gear Mass   [kg]

% NOTE: Strut.acc_factor is used to avoid numerical instability.
% For correct simulation this factor should be 1 (if one wants to match a drop test, for example).
% However, for the purpose of simulating an aicraft landing a factor of 100 can be  acceptable.

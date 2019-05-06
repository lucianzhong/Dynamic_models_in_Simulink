function init_lgear

global Lgear
global Geom
NN=1;

%--------------------------------------------------------------------
% Main Gear Parameters
%--------------------------------------------------------------------

% Local Parameters:

xpos = Geom.Wing.xwac+0.95*0.3048;% X pos of Hinge [m]
ypos = 1.25*0.3048;              % Y pos of Hinge [m]
zpos = -0.50*0.3048;             % Z pos of Hinge [m]
strut_length =  2.5*0.3048*0.5;      % Srut Length [m]        !!!!!!!!!!!!!!!
tire_radius  =  0.05;            % Tire Radius [m]
hub_offset   =  0.000;           % Wheel Hub Offset [m]

% Tire Contact Position Vector relative to Hinge
tire_rel_pos=[hub_offset,0,-(strut_length+tire_radius)];

%Strut data in English Units
%tire_stiffness = 45.36;% lbf/in
tire_stiffness = 20;% lbf/in
strut_area  =  1.217;  % in^2
damping     =  NN*125; % lbf/(ft/s)^2
cfriction   =  NN*340; % lbf/(ft/s)
max_defl    =  1;      % ft
defl_in     = [0   0.2025  0.2625  0.4375  0.6375  0.8188  1.3500  1.525  1.6875];
pres_psi    = [0   10.50   13.75   23.00   34.75   46.25   92.25  115.50  250.00];

%--------------------------------------------------------------------
% Global Parameters, returned in Lgear
%--------------------------------------------------------------------

% Hinge Position Vector
Lgear(1).Hinge.RposLmg=[xpos,-ypos,zpos];                    % LMG
Lgear(1).Hinge.RposRmg=[xpos, ypos,zpos];                    % RMG

% Tire Position Vector
Lgear(1).Tire.RposLmg = Lgear(1).Hinge.RposLmg+tire_rel_pos; % LMG
Lgear(1).Tire.RposRmg = Lgear(1).Hinge.RposRmg+tire_rel_pos; % RMG
Lgear(1).Tire.MaxComp     = 0.200;                           % Max Tire Compression [m]
Lgear(1).Tire.Stiffness   = 2*tire_stiffness*.4536/.0254*9.806; % Tire Stiffness [N/m]

Lgear(1).Strut.Limit      = max_defl*.3048;                % Max Strut Compression [m]
Lgear(1).Strut.Damping    = damping*.4536/(.3048)^2*9.806; % Hydraulic Damping [N/(m/s)^2]
Lgear(1).Strut.CFriction  = cfriction*.4536/.3048*9.806;   % Coulomb Friction, [N/(m/s)]
Lgear(1).Strut.Deflection = defl_in*.254;
Lgear(1).Strut.Stiffness  = pres_psi*strut_area*.4536*9.806;
Lgear(1).Strut.Stiffness  = [0  1421    1861    3113    4703    6259    12484    15631    33833];

Lgear(1).Strut.AccFactor  =    16;    % See NOTE

Lgear(1).Mass = 6.0;                  % Landing Gear Mass   [kg]

%--------------------------------------------------------------------
% Nose Gear Parameters
%--------------------------------------------------------------------

% Local Parameters:

xpos        =  Geom.Wing.xwac-4.5*0.3048;          % X pos of Hinge
zpos        =  -0.5*0.3048;          % Z pos of Hinge
strut_length=  2.5*0.3048*0.5;          % Srut Length          [m]  
tire_radius =  0.05;               % Tire Radius          [m]
hub_offset  =  0.010;               % Wheel Hub Offset     [m]

% Tire Contact Position Vector relative to Hinge
tire_rel_pos=[hub_offset,0,-(strut_length+tire_radius)];

%Strut_data in English Units
%tire_stiffness = 19.44; % lbf/in
tire_stiffness = 15; % lbf/in
strut_area     = 0.368;   % in^2
damping        = NN*125;      % lbf/(ft/s)^2
cfriction      = NN*170;   % lbf/(ft/s)
max_defl       = 1;% ft2.63
defl_in = [0 0.2625  0.7875  1.0875  1.3000  1.4500  1.5000   1.6125   1.6375]; % ft
pres_psi= [0 6.2500 15.2500 26.0000 39.2500 50.5000 61.5000 111.5000 148.7500]; % psi

%--------------------------------------------------------------------
% Global Parameters, returned in Lgear
%--------------------------------------------------------------------

% Hinge Position Vector
Lgear(2).Hinge.RposNg=[xpos,0,zpos];

% Tire Position Vector
Lgear(2).Tire.RposNg = Lgear(2).Hinge.RposNg+tire_rel_pos;

Lgear(2).Tire.MaxComp    = 0.200;    % Max Tire Compression [m]
Lgear(2).Tire.Stiffness  = 2*tire_stiffness*.4536/.0254*9.806; % Tire Stiffness [N/m]
Lgear(2).Strut.Limit      = max_defl*.3048; % [m]
Lgear(2).Strut.CFriction = cfriction*.4536/.3048*9.806;    % Coulomb Friction  [N/(m/s)]
Lgear(2).Strut.Damping   = damping*.4536/(.3048)^2*9.806;  % Hydraulic Damping [N/(m/s)^2]
Lgear(2).Strut.AccFactor = 16;    % See NOTE
Lgear(2).Strut.Deflection= defl_in*.254;
Lgear(2).Strut.Stiffness = pres_psi*strut_area*.4536*9.806;
Lgear(2).Strut.Stiffness = [0    512    1248    2128    3212    4133    5033    9126    12174];

Lgear(2).Mass = 2.0;                    % Landing Gear Mass   [kg]

% NOTE: Strut.acc_factor is used to avoid numerical instability.
% For correct simulation this factor should be 1 (if one wants to match a drop test, for example).
% However, for the purpose of simulating an aicraft landing a factor of 100 can be  acceptable.

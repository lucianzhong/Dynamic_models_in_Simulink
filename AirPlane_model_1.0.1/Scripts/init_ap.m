global Ap
%   ------ Auto Pilot Parameters ---------
%Controller for PID_Beta
Ap.Ny.pgain = 0.3;
Ap.Ny.igain = 0;
Ap.Ny.dgain = 2.7;
Ap.Ny.gain = -60;
%Controller for PID_Throttle
Ap.Throttle.pgain = 0.18;
Ap.Throttle.igain = 0.0005;
Ap.Throttle.dgain = 1;
Ap.Throttle.igainLim = 25; %[ kt ] - Error limit for integration. If more error=0;
%Controller for PID_Alt
Ap.Alt.igain = 0.001;
Ap.Alt.pgain = 0.04;
Ap.Alt.damph = -0.6;
Ap.Alt.dgain =  0.25;
Ap.Alt.Vmin = 140;       % [knot]
Ap.Alt.MinAlpha = 12;   % [Deg]
Ap.Alt.igainLim = 250;  % Max Altitude error. Error limit for integration. If more error=0;
Ap.Alt.LimAlt = 100;     % [m]   Error limit for Elevatoer control signal

%Controller for PID_Track
Ap.Track.pgain = 0.4;
Ap.Track.damph = -0.21;
Ap.Track.dgain = -0.06;
Ap.Track.err = 5;
Ap.Track.LimPhi = 60; % [Deg]

%Controller for Booster
Ap.Booster.Vmin = 120; % [knot]
Ap.Booster.Altmin = 300; % [ft]

% Counter Points
Ap.Target.MinDist = 500; % [m]
Ap.Loiter.MinDist = 100; % [m]
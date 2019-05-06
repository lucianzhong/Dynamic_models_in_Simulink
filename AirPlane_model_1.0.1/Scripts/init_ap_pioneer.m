global Ap
%   ------ Auto Pilot Parameters ---------
%Controller for PID_Beta
Ap.Ny.pgain = 0.3;
Ap.Ny.igain = 0;
Ap.Ny.dgain = 2.7;
Ap.Ny.gain = -60;
%Controller for PID_Throttle
Ap.Throttle.pgain = 0.38;
Ap.Throttle.igain = 0.001;
Ap.Throttle.dgain = 0.46;
Ap.Throttle.igainLim = 10;
%Controller for PID_Alt
Ap.Alt.pgain = 0.32;
Ap.Alt.damph = -0.2;
Ap.Alt.igain = 0.001;
Ap.Alt.dgain = 0.9;
Ap.Alt.Vmin = 70;       % [knot]
Ap.Alt.MinAlpha = 8;   % [Deg]
Ap.Alt.igainLim = 25;  % Max Altitude error. Error limit for integration. If more error=0;
Ap.Alt.LimAlt = 25;     % [m]   Error limit for Elevatoer control signal
%Controller for PID_Track
Ap.Track.pgain = 0.4;
Ap.Track.damph = -0.21;
Ap.Track.dgain = -0.06;
Ap.Track.err = 5;
Ap.Track.LimPhi = 15; % [Deg]
%Controller for Booster
Ap.Booster.Vmin = 60; % [knot]
Ap.Booster.Altmin = 100; % [ft]

% Counter Points
Ap.Target.MinDist = 250; % [m]
Ap.Loiter.MinDist = 100; % [m]
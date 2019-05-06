global Sensors
%   ------ Sensors Parameters ---------
% GPS - the model includes a Gauss-Markov noise correlation block and a transport delay block.
% Simple sensor - the model includes random walk and time lag (time constant)

% .TimeDelay - the transport time delay [sec]
% .Var - the white noise variance
% .Seed - the white noise source starting seed
% .CorTime - the Gauss-Marcov time constant [sec]
% .TimeConst - the time constant for the sensor dynamics (time lag) [sec]

% Heading deviation [deg]
Sensors.IRU.PlatDev = 0;
Sensors.IRU.MagDev = 0;

% --------------Flight System Computer---------------------------
% Weight coefficients for Inertial and GPS system
Sensors.FSC.Kins = 0.2;
Sensors.FSC.Kgps = 1 - Sensors.FSC.Kins;

% GPS

% Vector parameters: [ Latitude Longitude Altitude Vnorth Veast Vdown Xdist Ydist Track]

Sensors.GPS.TimeDelay = [0.2 0.2 0.2 0.2 0.2 0.2 0.2 0.2 0.2];
Sensors.GPS.Var = [0.000001 0.000001 5 0.2 0.2 0.15 100 100 0.0001];
Sensors.GPS.Seed = [round(rand*100000) round(rand*100000) round(rand*100000) round(rand*100000)...
                    round(rand*100000) round(rand*100000) round(rand*100000) round(rand*100000) round(rand*100000)];
Sensors.GPS.CorTime = [100 100 100 100 100 100 100 100 100];

% ------------------Press Altitude sensor-----------------

Sensors.ADC.Var = 50;
Sensors.ADC.Seed = round(rand*100000);
Sensors.ADC.TimeConst = 10;

% --------------Inertial Navigation System----------------
% Radar and Barometric altitude

Sensors.IRU.Alt.Pres.Var = 25;
Sensors.IRU.Alt.Pres.Seed = round(rand*100000);
Sensors.IRU.Alt.Pres.TimeConst = 20;
Sensors.IRU.Alt.Radar.Var = 0.1;
Sensors.IRU.Alt.Radar.Seed = round(rand*100000);
Sensors.IRU.Alt.Radar.TimeConst = 20;

% Speed sensors

Sensors.IRU.Speed.Var = 0.25;
Sensors.IRU.Speed.Seed = round(rand*100000);
Sensors.IRU.Speed.TimeConst = 25;

% Accelerometer sensors

Sensors.IRU.Acc.XYdist.Var = 500;
Sensors.IRU.Acc.XYdist.Seed = round(rand*100000);
Sensors.IRU.Acc.XYdist.TimeConst = 20;
Sensors.IRU.Acc.LatLon.Var = 0.000002;
Sensors.IRU.Acc.LatLon.Seed = round(rand*100000);
Sensors.IRU.Acc.LatLon.TimeConst = 20;

% ----------------Angle of Attack and Sideslip angle sensors----------------

Sensors.IRU.AlphaBeta.Var = 0.01; 
Sensors.IRU.AlphaBeta.Seed = round(rand*100000);
Sensors.IRU.AlphaBeta.TimeConst = 25;
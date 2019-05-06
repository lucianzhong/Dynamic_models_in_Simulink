global Controls

Controls.flapslat=[0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0];
Controls.slat=[0, 0, 0.0, 0.0, 0.0, 0.0, 0.0];
Controls.flap.Defl=[0, 0, 10.0, 20.0, 35.0, 35.0, 35.0];
Controls.flap.Rate =  [1.12 1.58 1.58];    % FLAP RATE LIMIT FROM  0 TO 20, DEG/SEC
                                           % FLAP RATE LIMIT FROM 20 TO 32, DEG/SEC
                                           % FLAP RATE LIMIT FROM 32 TO 50, DEG/SEC
Controls.Stab.MaxPos =3;    Controls.Stab.MaxNeg=-12;      Controls.Stab.Gain = 0.50;
Controls.Wheel.MaxAngle=40; Controls.Ail.MaxAngle=40;      Controls.Ail.Gain = 10; Control.Wheel.Ratio = [0.625 0.375];
Controls.Pedal.MaxAngle=10; Controls.Rudder.MaxAngle = 25; Controls.Rudder.Gain = 10;
Controls.Elev.MaxPos = 15;  Controls.Elev.MaxNeg = -25;    Controls.Elev.Gain = 10;
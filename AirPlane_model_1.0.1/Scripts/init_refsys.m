% Earth centered WGS84 reference system

wgs84_a = 6378137; % semi-major axis (m)
wgs84_f = 1/298.257223563; % flattening

wgs84_e = sqrt(2*wgs84_f - wgs84_f^2); % eccentricity

% M_hat = (wgs84_a*(1-wgs84_e^2))/(1-wgs84_e^2*(sin(u(1))^2))^(3/2); % Radius of curvature in the meridian
% N_hat = wgs84_a/sqrt(1-wgs84_e^2*(sin(u(1))^2)); % Radius of curvature in the prime vertical
% Where u(1) is the previous latitude

% Transformation matrix from delta X,Y,Z to delta latitude,longitude,height
% d_lat = (-(sin(lat)*cos(lon)*dx)-(sin(lat)*sin(lon)*dy)+(cos(lat)*dz))/(m+h)
% d_lon = (-(sin(lon)*dx)+(cos(lon)*dy)+(0*dz))/((n+h)*cos(lat))
% d_h = (cos(lat)*cos(lon)*dx)-(cos(lat)*sin(lon)*dy)+(sin(lat)*dz)
% d_lat = (-(sin(u(3))*cos(u(4))*u(6))-(sin(u(3))*sin(u(4))*u(7))+(cos(u(3))*u(8)))/(u(1)+u(5))
% d_lon = (-(sin(u(4))*u(6))+(cos(u(4))*u(7))+(0*u(8)))/((u(2)+u(5))*cos(u(3)))
% d_h = (cos(u(3))*cos(u(4))*u(6))-(cos(u(3))*sin(u(4))*u(7))+(sin(u(3))*u(8))

% Transformation matrix from delta latitude,longitude,height to delta X,Y,Z
% dx = -(m+h)*sin(lat)*cos(lon)*d_lat-(n+h)*cos(lat)*sin(lon)*d_lon+cos(lat)*cos(lon)*d_h
% dy = -(m+h)*sin(lat)*sin(lon)*d_lat+(n+h)*cos(lat)*cos(lon)*d_lon+cos(lat)*sin(lon)*d_h
% dz = (m+h)*cos(lat)*d_lat+0*d_lon+sin(lat)*d_h
% dx = -(u(1)+u(5))*sin(u(3))*cos(u(4))*u(6)-(u(2)+u(5))*cos(u(3))*sin(u(4))*u(7)+cos(u(3))*cos(u(4))*u(8)
% dy = -(u(1)+u(5))*sin(u(3))*sin(u(4))*u(6)+(u(2)+u(5))*cos(u(3))*cos(u(4))*u(7)+cos(u(3))*sin(u(4))*u(8)
% dz = (u(1)+u(5))*cos(u(3))*u(6)+0*u(7)+sin(u(3))*u(8)


% Latitude and longitude limitation tables
lat_lim_input = [-360 -270 -180 -90 0 90 180 270 360];
lat_lim_output = [0 90 0 -90 0 90 0 -90 0]';

lon_lim_input = [-720 -540 -360 -180 0 180 360 540 720];
lon_lim_output = [0 180 0 -180 0 180 0 -180 0]';

% lat_lim_input = [-2*pi -3*pi/2 -pi -pi/2 0 pi/2 pi 3*pi/2 2*pi];
% lat_lim_output = [0 pi/2 0 -pi/2 0 pi/2 0 -pi/2 0]';
% 
% lon_lim_input = [-4*pi -3*pi -2*pi -pi 0 pi 2*pi 3*pi 4*pi];
% lon_lim_output = [0 pi 0 -pi 0 pi 0 -pi 0]';

XYZ_0 = [0 0 0];

% Flight_Height = Flight_alt+6378137-21385*sin(Flight_latitude);
Flight_Height = Flight_alt + (wgs84_a/sqrt(1-wgs84_e^2*(sin(Flight_latitude))^2));

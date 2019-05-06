function target_coordinate(Target_lat, Target_lon, Target_alt, Target_speed);
global Flight_latitude Flight_longitude
global Flight_TargetPoints

TPoint_lat   = Target_lat;
TPoint_lon   = Target_lon;
TPoint_Alt   = Target_alt;
TPoint_Speed = Target_speed;


max_lat=max(size(TPoint_lat)); max_lon=max(size(TPoint_lon));
Flight_MaxTargetPoints = max(max_lat,max_lon);
if Flight_MaxTargetPoints < 2 Flight_MaxTargetPoints=2; end

if max(size(TPoint_lat)) < Flight_MaxTargetPoints
    for i=max(size(TPoint_lat))+1:Flight_MaxTargetPoints
    TPoint_lat(i)=TPoint_lat(i-1);
    end
end

if max(size(TPoint_lon)) < Flight_MaxTargetPoints
    for i=max(size(TPoint_lon))+1:Flight_MaxTargetPoints
    TPoint_lon(i)=TPoint_lon(i-1);
    end
end

if max(size(TPoint_Alt)) < Flight_MaxTargetPoints
    for i=max(size(TPoint_Alt))+1:Flight_MaxTargetPoints
    TPoint_Alt(i)=TPoint_Alt(i-1);
    end
end
if max(size(TPoint_Speed)) < Flight_MaxTargetPoints
    for i=max(size(TPoint_Speed))+1:Flight_MaxTargetPoints
    TPoint_Speed(i)=TPoint_Speed(i-1);
    end
end

if max(size(TPoint_lon)) > Flight_MaxTargetPoints | max(size(TPoint_lat)) > Flight_MaxTargetPoints | max(size(TPoint_Alt)) > Flight_MaxTargetPoints | max(size(TPoint_Speed)) > Flight_MaxTargetPoints
    disp('Max number of Target Points must be less than Flight_MaxTargetPoints!');
    return
end

TPoint_lat = reshape(TPoint_lat,1,Flight_MaxTargetPoints);
TPoint_lon = reshape(TPoint_lon,1,Flight_MaxTargetPoints);

Flight_TargetPoints = [TPoint_lat;TPoint_lon;TPoint_Alt;TPoint_Speed];

disp('Target Points coordinats:')
name={'Latitude [Deg]' 'Longitude [Deg]' 'Altitude [ft]' 'Speed [knot]'};
disp([name',num2cell(Flight_TargetPoints)]);

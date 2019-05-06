function setAeroLibPath(varargin)
% SETAEROLIBPATH Add and remove AeroLib directory to search Matlab path
%
%   SETAEROLIBPATH add and remove AeroLib directory using AEROLIB_ROOT
%   environment variable as AeroLib root directory.
%
%   SETAEROLIBPATH(AEROLIB_ROOT) add and remove AeroLib directory using 
%   the specified AEROLIB_ROOT directory.

%-----------------------------------------------------------------------
% Copyright 1996-2002 AeroLib, Opal-RT Technologies Inc.
%
% Visual SourceSafe Information%
%   File name =         $Workfile: $
%   Path =              $Logfile: $
%   Revision =          $Revision: $
%   Last checked in =   $Date: $
%   Last updated =      $Modtime: $
%   Last modified by =  $Author: $
%   Author =            Vincent Lapointe
%-----------------------------------------------------------------------

% Get aerolib root
if nargin == 0
    % Get aerolib root from environment variable
    aeroLibRoot = getenv('AEROLIB_ROOT');
elseif nargin == 1
    % Get AeroLib root from first argument
    AeroLibRoot = varargin{1};
else
    error('Not enough input arguments.');
end

% Get Matlab Release
matlabRelease = version('-release');
pos = findstr(matlabRelease,'.');
if ~isempty(pos)
    matlabRelease = matlabRelease(1:pos(1)-1);
end

% Define directory to remove from search path
aeroLibRmPath{1} = ['/Simulink/Scripts'];
aeroLibRmPath{2} = ['/Simulink/Models'];
aeroLibRmPath{3} = ['/Simulink/Images'];
aeroLibRmPath{4} = ['/Simulink/Lib'];
rmPath(aeroLibRmPath);

% Define directory to add to search path
aeroLibAddPath = [aeroLibRoot,'/Simulink/Scripts',pathsep,...
                  aeroLibRoot,'/Simulink/Models', pathsep, ...
                  aeroLibRoot,'/Simulink/Images', pathsep, ...
                  aeroLibRoot,'/Simulink/Lib', pathsep];

% Add directory to search path
addpath(aeroLibAddPath);

%========================================================
function rmPath(findstring)
% Remove directory from search path

% Get Matlab path string
paths = [path pathsep];
paths = strrep(paths,'\','/');
% Get ';' caracteres position
pos = [0, findstr(paths, pathsep)];

% we create a string of path to remove (it's faster than removing one path at a time)
rmStr = 'rmpath(';
% For each path
for t = 1 : length(pos)-1
    aPath = paths(pos(t)+1:pos(t+1)-1);
    % For each string to remove
    for u = 1 : length(findstring)
        % If we find the string to remove
        if ~isempty(findstr(lower(aPath),lower(findstring{u})))
            %remove path from search path
            rmStr = [rmStr '''' aPath ''','];
            break
        end
    end
end
if length(rmStr) ~= 7
    rmStr = [rmStr(1:end-1) ');'];
    eval(rmStr);
end
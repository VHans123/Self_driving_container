function cmFormat = getFloatingPointCompuMethodFormat(dataTypeName,cmUnits)
%GETFLOATINGPOINTCOMPUMETHODFORMAT outputs the string "Format" for the
% COMPU_METHOD for floating point numbers. 
%
% ABSTRACT:
%
% Input Arguments:
% dataTypeName - Name of datatype associated with this computation method
% cmUnits - Units associated with this computation method (specified as
% DocUnits in Simulink.Parameter or Simulink.Signal object)
%
% Output Argument:
% cmFormat - Format for computation method
% 
% The Format has the following scheme:
%
% <Length>.<Layout> where
% 
% <Length> indicates the overall length and <Layout> indicates the number
% of decimal places.

%   Copyright 2009-2010 The MathWorks, Inc.

if strcmp(dataTypeName, 'SINGLE')
    cmFormat = '%8.6';
elseif strcmp(dataTypeName, 'DOUBLE')
    cmFormat = '%15.10';
end

% Example of using the Units to decide the COMPU METHOD format 
if strcmp(cmUnits,'rpm')
%     cmFormat='%4.0';
% elseif strcmp(cmUnits,'m/(s^2)')
%     cmFormat='%6.2';
end

end

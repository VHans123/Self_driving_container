function cmName = getCompuMethodName(dataTypeName, cmUnits)
%GETCOMPUMETHODNAME constructs a computation method name. 
%
% ABSTRACT:
%
% Input Arguments:
% dataTypeName - Name of datatype associated with this computation method
% cmUnits - Units associated with this computation method (specified as
% DocUnits in Simulink.Parameter or Simulink.Signal object)
%
% Output Argument:
% cmName - Constructed computation method name
%
% The input arguments can be used to construct the computation method name.
% In this implementation, the constructed name has the scheme:
%
% <localPrefix><datatype>_<cmUnits> where
%
% You can customize the name construction as per your requirements. Also
% please note that the computation method name must be a valid identifier,
% that is:
% (1) Does not begin with a digit
% (2) Contains only alphanumeric characters (a-z, A-Z, 0-9) and
%     underscores ("_")s
%    
% Also note that
% $MATLABROOT/toolbox/rtw/targets/asap2/asap2/user/asap2setup.tlc
% defines a <ASAP2CompuMethodName_Prefix> (a model prefix) that gets
% prefixed to the name constructed in this function.

%   Copyright 2010-2012 The MathWorks, Inc.
    
    localPrefix = 'CM_'; 
    
    % Convert units to valid identifier. For example, convert "m/s" to
    % "m_s". 
    if ~isempty(cmUnits)
        cmUnits = ['_', convertNameToIdentifier(cmUnits)];
    end
    
    % Construct CompuMethod name
    cmName = strcat(localPrefix, dataTypeName, cmUnits);
    
end
    
    
function newName = convertNameToIdentifier(oldName)
%CONVERTNAMETOIDENTIFIER converts non-alphanumeric characters of a string
% to an underscore ("_") and returns the updated string. Note that you can
% customize this function as per your requirements.
%
% For more information on REGEXP and REGEXPREP, please refer to the MATLAB
% Help Documentation.
    
    newName = regexprep(oldName, '[^a-zA-Z_0-9]','_');
    
end

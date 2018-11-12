function cmFormat = getCompuMethodFormat(fracSlope,fixExp,bias,numBits,cmUnits)
%GETCOMPUMETHODFORMAT outputs the string "Format" for the COMPU_METHOD for
% integers and fixed point numbers.
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

%set the maximum number of digits that can be in the decimal place
limit_digits_in_decimal_places = 16;
%calculate number of digits based on the number of bits
if 2^numBits == floor(2^numBits) 
    numBitslength = length(int2str(2^numBits));
else
    numBitslength = length(num2str(2^numBits));
end

if (fracSlope == 1) && (bias == 0)
    if fixExp >= 0
        layout = 0;
    elseif fixExp <= -(limit_digits_in_decimal_places)
        %setting a limit to the number of digits in the decimal place
        layout = limit_digits_in_decimal_places;
    else
        %different calculation for numBitslength is required for this case
        %example:
        if 2^(numBits+fixExp) == floor(2^(numBits+fixExp))
            numBitslength = length(int2str(2^(numBits+fixExp)));
        else
            numBitslength = length(num2str(2^(numBits+fixExp)));
        end            
        %e.g. 2^-4 require 4 decimal places
        layout = abs(fixExp);
    end
    
    total_length = numBitslength + layout;
    cmFormat = ['%' num2str(total_length) '.' num2str(layout)];
else
    %default layout when a bias is provided and fracSlope not equal to 1
    cmFormat = 'customformat';
    %the string 'customformat' is replaced by the default format specified
    %in asap2setup.tlc. If a different cmFormat string is returned then
    %that cmFormat will be used for the respective Compu Method
end

% Example of using the Units to decide the COMPU METHOD format
if strcmp(cmUnits,'rpm')
%     cmFormat='%4.0';
% elseif strcmp(cmUnits,'m/(s^2)')
%     cmFormat='%6.2';
end

end

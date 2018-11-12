function blkStruct = slblocks
%SLBLOCKS Defines the block library for a specific Toolbox or Blockset.

% Name of the subsystem which will show up in the SIMULINK Blocksets
% and Toolboxes subsystem.
% Example:  blkStruct.Name = 'DSP Blockset';
blkStruct.Name = sprintf('HANcoder STM32 Target');

% The function that will be called when the user double-clicks on
% this icon.
% Example:  blkStruct.OpenFcn = 'dsplib';
blkStruct.OpenFcn = 'HANcoder_STM32_Target';

% The argument to be set as the Mask Display for the subsystem.  You
% may comment this line out if no specific mask is desired.
% Example:  blkStruct.MaskDisplay = 'plot([0:2*pi],sin([0:2*pi]));';
% blkStruct.MaskDisplay = 'disp(''......'')';

% Define the library list for the Simulink Library browser.
% Return the name of the library model and the name for it
release = version ('-release');
if(strcmp(release, '2009a') || strcmp(release,'2009b')...
 || strcmp(release, '2010a') || strcmp(release, '2010b')...
 || strcmp(release, '2011a') || strcmp(release, '2011b')...
 || strcmp(release, '2012a') || strcmp(release, '2012b')...
 || strcmp(release, '2013a'))
Browser(1).Library = 'HANcoder_STM32_Target2009b';
else
Browser(1).Library = 'HANcoder_STM32_Target';
end
Browser(1).Name    = 'HANcoder STM32 Target';
Browser(1).IsFlat  = 0;

blkStruct.Browser = Browser;


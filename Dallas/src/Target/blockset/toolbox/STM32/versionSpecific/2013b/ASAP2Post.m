function ASAP2Post(ASAP2file, MAPfile)
% ASAP2POST Post-processing of ASAP2 file.

%   Copyright 1994-2010 The MathWorks, Inc.
% 	Adapted by Jason van Kolfschoten 05-2016

% Declare boolean which registers if a element is in ASAP2 but not in MAP
ElementOptimizedOut = false;

if nargin~=2
    DAStudio.error('RTW:asap2:invalidInputParam',mfilename);
end

% these placement holders are used untill MATLAB 2012a
%addrPrefix = '@MemoryAddress@';
%addrSuffix = '@';

% these placement holders are used from MATLAB 2012a on
addrPrefix = '0x0000 \/\* @ECU_Address@';
addrSuffix = '@ \*\/';

% Extract contents of ASAP2 file
if exist(ASAP2file,'file')
    ASAP2fileString = fileread(ASAP2file);
else
    DAStudio.error('RTW:asap2:UnableFindFile',ASAP2file);
end

% Extract contents of MAP file
if exist(MAPfile,'file')
    MAPfileString = fileread(MAPfile);
else
    DAStudio.error('RTW:asap2:UnableFindFile',MAPfile);
end

% Find the signal and parameter names with their corresponding memory addresses in the .map file
pairs = regexp(MAPfileString,'\n([0-9a-fA-F]{8})\s{1}[a-z]\s{5}[A-Z]\s{1}[.][A-Za-z]+\t{1}[0-9a-f]{8}\s{1}(\w+)','tokens');

% Store symbol names and corresponding symbol values into a hash table
MAPfileHash = containers.Map;
for i = 1:length(pairs)
    MAPfileHash(pairs{i}{2}) = pairs{i}{1}; % pairs{i}{2} is name, pairs{1} is memory address
end  
% Get all element names from the ASAP2 file
%ASAP2Elements = {};
ASAP2Elements = regexp(ASAP2fileString,[addrPrefix '(\w+)' addrSuffix],'match');
ASAP2Elements = regexprep(ASAP2Elements,[addrPrefix '(\w+)' addrSuffix],'$1');
for j = 1:length(ASAP2Elements)
	if isKey(MAPfileHash,ASAP2Elements{j})
	% Do nothing
	else
	% Add the Element name to the Hash so no error will come when substituting the addresses
	% in the ASAP2 file
	MAPfileHash(ASAP2Elements{j}) = '0x0000';
	ElementOptimizedOut = true;
	end
end
% Check whether they are in the hash table
% enter missing elements in hash table with address 0x0000
% Give warning when 1 or more is missing
try
% create the contents of the new asap2 file by overwriting the placeholders by the memory addresses.
newASAP2fileString = regexprep(ASAP2fileString,[addrPrefix '(\w+)' addrSuffix], '${MAPfileHash($1)}');
 %$1 =name of element as found by '(\w+)'   %'${MAPfileHash($1)}' is the address beloning to that name
	
% Overwrite the existing ASAP2file	 
fid = fopen(ASAP2file, 'w');
fprintf(fid,'%s',newASAP2fileString);
fclose(fid);

catch
	error('ASAP2 file generation failed')
end

if ElementOptimizedOut
	disp('Warning! One or more parameters or signals were optimized out and are not included in the A2L file') %could be warndlg
end
end % End of function ASAP2Post
%% Check to see if compiler is installed by checking the path
function checkGnuArmToolchain(command)
[status,cmdResponse] = system('arm-none-eabi-gcc');
if isempty(strfind(cmdResponse, 'compilation'))
    [status,EnvironmentVariable] = system('echo %PATH%');
    if isempty(strfind(EnvironmentVariable, 'GNU Tools ARM Embedded'))
        fprintf(['Could not find path to ''GNU Tools ARM Embedded'' ',...
            'in the windows\nenvironment variables, please check if the tools\n',...
            'are properly installed and the path is set correctly.\n',...
            'GNU ARM Embedded Toolchain can be downloaded here: <a href="https://launchpad.net/gcc-arm-embedded">GNU ARM Tools</a>.\n'])
    else
        disp('### Path to ARM Tools found in windows environment variables...')
        disp('  but the tools are inresponsive. Consider reinstalling the toolchain.')
        disp('  It can be downloaded here: <a href="https://launchpad.net/gcc-arm-embedded">GNU ARM Tools</a>.')
    end
else
	if ~strcmp(command,'suppressOutput')
		disp('### GNU ARM toolchain installed correctly')
	end
end
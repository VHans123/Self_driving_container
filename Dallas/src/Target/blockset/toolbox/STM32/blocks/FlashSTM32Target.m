%% Automatic flash script
function FlashSTM32Target(modelName)
% find settings block
HANcoderBlocks = find_system(modelName, 'RegExp', 'on', 'LookUnderMasks', 'All', 'Tag', 'HANcoder_TARGET_.');
for index=1:1:length(HANcoderBlocks) % Loop through the HANcoder blocks
    HANcoderStruct = get_param(HANcoderBlocks{index},'UserData');
    BlockType = HANcoderStruct.BlockType;
    if strcmp(BlockType,'Settings')
        MaskValues = get_param(HANcoderBlocks{index},'MaskValues');
        if ~strcmp(MaskValues{2},'off')
            % Check if the HANcoder_BOOTLOADER setting is correct
            MakeCommand = get_param(bdroot(modelName),'MakeCommand');
            if ~isempty(strfind(MakeCommand, 'HANcoder_BOOTLOADER=0'))
                warndlg(['The model was not built for flashing with the bootloader. Flash procedure will not be started.',...
				'Please set HANcoder_BOATLOADER=1 in Configuration Options->Code Generation->Make command, if you wish to',...
				' use the automatic flash function'],'HANcoder warning');
            else
                disp('### Starting automatic flash procedure');
                FlashViaMicroBoot(modelName,MaskValues{2});
            end
            break
        end
    end
end
end % end of function FlashSTM32Target()

function FlashViaMicroBoot(modelName,Interface)
ModelPath= strcat(' "',pwd, '\..\',bdroot(modelName),'.srec"');
MircoBootPath = strcat('"',pwd,'\..\..\Host\MicroBoot\MicroBoot.exe"');
switch Interface
    case 'USB'
        cmdCommand = strcat(MircoBootPath, ' -iopenblt_usb.dll ', ModelPath, ' &');
    case 'CAN'
        cmdCommand = strcat(MircoBootPath, ' -iopenblt_can_peak.dll ', ModelPath, ' &');
    case 'Ethernet'
        cmdCommand = strcat(MircoBootPath, ' -iopenblt_net.dll ', ModelPath, ' &');
end

system(cmdCommand);
% Old code below froze Matlab untill MicroBoot was finished.
%output = system(cmdCommand);
%if (output == -1)
%    disp('Warning: Unable to start MicroBoot')
%end

end % end of function FlashSTM32Target()
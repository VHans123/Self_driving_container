%% SMV sending package
clc
clear all
close all

serialConnection = serial('COM4');                % Here the S object is created and filled with the correct arguments
set(serialConnection, 'DataBits', 8);
set(serialConnection, 'StopBits', 1);
set(serialConnection, 'BaudRate', 57600);
fopen(serialConnection);                           % At this point the serial connection is opened.

% This defines drive direction and type, with the result being a number 1-6 sent via XBee
drive_dir = questdlg('Please select driving direction',...          %Create prompt for direction
    'Drive direction','Forward','Reverse','Forward');
drive_type = questdlg('Please select drive type','Driveline',...    Create prompt for type
    'Front wheel','Four wheel','Rear wheel','Front wheel');
switch drive_dir        %Set base value to be added to in second switch-case
    case 'Forward'
        drive = 0;
    case 'Reverse'
        drive = 3;
end
switch drive_type       %Combine values to get correct values to send
    case 'Front wheel'      %1 = Front wheel driven direction forward
        drive = drive + 1;  %4 = Front wheel driven direction backward
    case 'Four wheel'       %2 = 4 wheel driven direction forward
        drive = drive + 2;  %5 = 4 wheel driven direction backward
    case 'Rear wheel'       %3 = Rear wheel driven direction forward
        drive = drive + 3;  %6 = Rear wheel driven direction backward
end

% This defines steering type, with the result being 1 or 2, sent to the XBee
steer_type = questdlg('Please select steering type',...         %Create prompt for steering type
    'Steering type','Front wheel','Four wheel','Front wheel');
switch steer_type       %Set values
    case 'Front wheel'
        steering = 1;   %1 = Front wheel steering
    case 'Four wheel'
        steering = 2;   %2 = All wheel steering
end
clear drive_dir drive_type steer_type;

fwrite(serialConnection, 252, 'uint8');                  % Start byte
fwrite(serialConnection, drive, 'uint8');                % Sending the bytes for the prefered driveline
fwrite(serialConnection, steering, 'uint8');             % Sending the bytes for the prefered steering
fwrite(serialConnection, 253, 'uint8');                  % Stop byte

% In this part will take the conversion place for sending with the Xbee and
% create a predefined path.

Width = 0.14;
Length = 0.1415;
Radius = [0;-0.3;0.3;-0.3;0.3;0;-0.3;0;-0.5;0;0];
Length_T = [1.1;0.94;0.52;1.06;1.11;0.3;0.94;0.55;0.79;0.58;0];
Speed = [0.4; 0.4; 0.4; 0.4; 0.4; 0.4; 0.4; 0.4; 0.4; 0.4;0];

v = [];
for i = 1:1:length(Speed)
    v(i) = Speed(i) * 250;
end

steer = [];
steer_angle = [];
for i = 1:1:length(Radius)
    if Radius(i) == 0
        steer(i) = 0;
    else
    steer(i) = (atan((Length/2)/Radius(i))*57.2958).*4;
    end
    
    steer_angle(i) = 125 + steer(i);
end

p = [];
for i = 1:1:length(Speed)
    p(i) = Length_T(i) / Speed(i);
end

%% Loop part, only use when connection is opened
loop = true;

while (loop)
    
    
for i=1:1:length(v)
    fwrite(serialConnection, 250, 'uint8');                 % Start byte
    fwrite(serialConnection, v(i), 'uint8');                % Speed array predefined path
    fwrite(serialConnection, steer_angle(i), 'uint8');      % Steeringangel array predefined path
    fwrite(serialConnection, 253, 'uint8');                 % Stop byte
    pause(p(i));                                            % Pause array for the predefined path
    
    if i == length(v)
        s = input('continue (1) stop (2)');
        if s == 1
            clear i
        else
            loop = false;
        end
    end
        
end
end
    
    % This will happen after 1 round is completed
    if serialConnection.BytesAvailable > 3
       % implement check to see if first byte is start byte
       ReceivedData = fread(serialConnection,4,'uint8')
       % implement check to see if last byte is checksum/stopbyte
    end 

%% Close connection
fclose(serialConnection);

%% Delete connection
delete(serialConnection);
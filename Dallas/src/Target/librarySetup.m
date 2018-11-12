%%***************************************************************************************
%% file         librarySetup.m
%% brief        Initialization that is automatically executed when a Simulink model in 
%%              the same directory is opened.
%%
%%---------------------------------------------------------------------------------------
%%                          C O P Y R I G H T
%%---------------------------------------------------------------------------------------
%%  Copyright 2012 (c) by HAN Automotive     http://www.han.nl     All rights reserved
%%
%%---------------------------------------------------------------------------------------
%%                            L I C E N S E
%%---------------------------------------------------------------------------------------
%% This file is part of the HANcoder Matlab/Simulink Blockset environment. For the
%% licensing terms, please contact HAN Automotive.
%%
%% This software has been carefully tested, but is not guaranteed for any particular
%% purpose. HAN Automotive does not offer any warranties and does not guarantee the 
%% accuracy, adequacy, or completeness of the software and is not responsible for any 
%% errors or omissions or the results obtained from use of the software.
%%
%%***************************************************************************************


% add STM32 Target blockset related directories to the MATLAB path
addpath(sprintf('%s\\blockset\\rtw\\STM32', pwd));
addpath(sprintf('%s\\blockset\\toolbox\\STM32\\blocks', pwd));
addpath(sprintf('%s\\blockset\\toolbox\\STM32\\help', pwd));
addpath(sprintf('%s\\blockset\\toolbox\\STM32\\blocks\\tlc_c', pwd));

% include asap2 setup files according to the Matlab version
if(strcmp(version ('-release'), '2009a') ||strcmp(version ('-release'), '2009b'))
    %disp('MATLAB 2009');
    addpath(sprintf('%s\\blockset\\toolbox\\STM32\\versionSpecific\\2010a', pwd));
elseif(strcmp(version ('-release'), '2010a'))
    %disp('MATLAB 2010a');
    addpath(sprintf('%s\\blockset\\toolbox\\STM32\\versionSpecific\\2010a', pwd));
elseif(strcmp(version ('-release'), '2010b'))
    %disp('MATLAB 2010b');
    addpath(sprintf('%s\\blockset\\toolbox\\STM32\\versionSpecific\\2010a', pwd));
elseif(strcmp(version ('-release'), '2012a'))
    %disp('MATLAB 2012a');
    addpath(sprintf('%s\\blockset\\toolbox\\STM32\\versionSpecific\\2012a', pwd));
elseif(strcmp(version ('-release'), '2012b'))
    %disp('MATLAB 2012b');
    addpath(sprintf('%s\\blockset\\toolbox\\STM32\\versionSpecific\\2012a', pwd));
elseif(strcmp(version ('-release'), '2013a'))
    %disp('MATLAB 2013a');
    addpath(sprintf('%s\\blockset\\toolbox\\STM32\\versionSpecific\\2013a', pwd));
elseif(strcmp(version ('-release'), '2013b'))
    %disp('MATLAB 2013b');
    addpath(sprintf('%s\\blockset\\toolbox\\STM32\\versionSpecific\\2013b', pwd));    
elseif(strcmp(version ('-release'), '2014a'))
    %disp('MATLAB 2014a');
    addpath(sprintf('%s\\blockset\\toolbox\\STM32\\versionSpecific\\2014a', pwd));
elseif(strcmp(version ('-release'), '2014b'))
    %disp('MATLAB 2014b');
    addpath(sprintf('%s\\blockset\\toolbox\\STM32\\versionSpecific\\2014b', pwd));
    disableInitializationCodeInIR;
elseif(strcmp(version ('-release'), '2015a'))
    %disp('MATLAB 2015a');
    addpath(sprintf('%s\\blockset\\toolbox\\STM32\\versionSpecific\\2014b', pwd));
    disableInitializationCodeInIR;
elseif(strcmp(version ('-release'), '2015b'))
    %disp('MATLAB 2015b');
    addpath(sprintf('%s\\blockset\\toolbox\\STM32\\versionSpecific\\2014b', pwd));
elseif(strcmp(version ('-release'), '2016a'))
    %disp('MATLAB 2016a');
    addpath(sprintf('%s\\blockset\\toolbox\\STM32\\versionSpecific\\2014b', pwd));
elseif(strcmp(version ('-release'), '2016b'))
    %disp('MATLAB 2016b');
	addpath(sprintf('%s\\blockset\\toolbox\\STM32\\versionSpecific\\2014b', pwd));
else 
	disp('This MATLAB version is not (yet) supported');
    addpath(sprintf('%s\\blockset\\toolbox\\STM32\\versionSpecific\\2014b', pwd));
end

%% load .mat file for this model
%load(strcat(bdroot,'.mat'));

checkGnuArmToolchain('suppressOutput');

warning off Simulink:SL_LoadMdlParameterizedLink;
warning off Simulink:Commands:LoadMdlParameterizedLink;

%%******************************* end of librarySetup.m **************************************

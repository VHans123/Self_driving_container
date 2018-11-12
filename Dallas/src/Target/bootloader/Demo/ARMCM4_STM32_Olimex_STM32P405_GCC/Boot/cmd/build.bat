@echo off
cs-make --directory=../ TARGET_USB=1 clean
cs-make --directory=../ TARGET_USB=1 all
cs-make --directory=../ TARGET_CAN=1 clean
cs-make --directory=../ TARGET_CAN=1 all

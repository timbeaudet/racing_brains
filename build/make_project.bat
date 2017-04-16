@ECHO off

REM
REM Simple batch script to create a Visual Studio project using premake5 and the racing_brains.lua script.
REM
REM <!-- Copyright (c) 2016 Tim Beaudet - All Rights Reserved -->
REM -------------------------------------------------------------------------------------------------------------------

premake5 --file="racing_brains.lua" vs2015

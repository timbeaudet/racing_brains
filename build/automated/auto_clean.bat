@ECHO off

REM
REM Automated Build Script for RacingBrains to automate the cleaning of the project.
REM
REM This may be run by an automated process to clean and/or build each project with an /automated/auto_ script.
REM
REM <!-- Copyright (c) 2016 Tim Beaudet - All Rights Reserved -->
REM -------------------------------------------------------------------------------------------------------------------

PUSHD ..\

premake5 --file="racing_brains.lua" clean

POPD

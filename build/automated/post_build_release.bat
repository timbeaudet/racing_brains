@ECHO off

REM
REM Automated Build Script for RacingBrains to copy the executable during a release build.
REM
REM <!-- Copyright (c) 2016 Tim Beaudet - All Rights Reserved -->
REM -------------------------------------------------------------------------------------------------------------------

SET toSlnDir=""
SET toRunDir="..\..\run\"

IF NOT DEFINED buildType SET buildType="release\"
REM IF NOT DEFINED exePostfix SET exePostfix=""

IF DEFINED exePostfix ( 
  IF EXIST "%toRunDir%racing_brains%exePostfix%.exe" (DEL "%toRunDir%racing_brains%exePostfix%.exe")
  COPY "%toSlnDir%%buildType%racing_brains.exe" "%toRunDir%\racing_brains%exePostfix%.exe" 
) ELSE ( 
  IF EXIST "%toRunDir%racing_brains.exe" (DEL "%toRunDir%racing_brains.exe")
  COPY "%toSlnDir%%buildType%racing_brains.exe" "%toRunDir%\racing_brains.exe"
)

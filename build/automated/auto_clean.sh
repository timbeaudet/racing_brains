#!/bin/bash

#
# Automated Build Script for RacingBrains to automate the cleaning of the project.
#
# This may be run by an automated process to clean and/or build each project with an /automated/auto_ script.
#
# <!-- Copyright (c) 2015 Tim Beaudet - All Rights Reserved -->
#---------------------------------------------------------------------------------------------------------------------#

export CurrentDirectory=$(pwd)
cd ../

premake5 --file="racing_brains.lua" clean

kLinuxPlatform="Linux"
currentPlatform=`uname`
if [ $kLinuxPlatform = $currentPlatform ]; then
  #If any deployable gets created, delete it during cleaning.
else
  #If the Mac OS X delpoyable application package exists, delete it during project cleaning.
  if [ -d "${toRunDir}../RacingBrains.app" ]; then
	rm -r "${toRunDir}../RacingBrains.app"
  fi
fi

cd $CurrentDirectory

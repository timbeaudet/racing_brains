#!/bin/bash

#
# Automated Build Script for RacingBrains to automate the building of both debug and release configurations 
#   of the project, including the post_build scripts that will build a release package.
#
# This may be run by an automated process to clean and/or build each project with an /automated/auto_ script.
#
# <!-- Copyright (c) 2016 Tim Beaudet - All Rights Reserved -->
#---------------------------------------------------------------------------------------------------------------------#

pushd ../

#Should we clean before build? If so we should add call clean to windows auto_build.bat
#sh auto_clean.sh

kLinuxPlatform="Linux"
currentPlatform=`uname`
if [ $kLinuxPlatform = $currentPlatform ]; then
  #Building a Linux project
  premake5 --file="racing_brains.lua" codelite
else
  #Building a Mac OS X project
  premake5 --file="racing_brains.lua" xcode4

  cd macosx/
  echo Building debug...
  xcodebuild -target "racing_brains" -configuration debug build

  echo Building release...
  xcodebuild -target "racing_brains" -configuration release build
fi

popd

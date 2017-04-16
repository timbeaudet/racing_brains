#

#
# Simple batch script to create an XCode4 project using premake5 and the racing_brains.lua script.
#
# <!-- Copyright (c) 2017 Tim Beaudet - All Rights Reserved -->
#----------------------------------------------------------------------------------------------------------------------

kLinuxPlatform="Linux"
currentPlatform=`uname`

if [ $kLinuxPlatform = $currentPlatform ]; then
  premake5 --file="racing_brains.lua" codelite
else
  premake5 --file="racing_brains.lua" xcode4
fi

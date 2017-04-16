#

#
# Automated Build Script for RacingBrains to copy the Mac OS X or Linux executable during a debug build.
#
# <!-- Copyright (c) 2017 Tim Beaudet - All Rights Reserved -->
#---------------------------------------------------------------------------------------------------------------------#

kLinuxPlatform="Linux"
currentPlatform=`uname`

export toSlnDir=""
export toRunDir="../../run/"

if [ -z ${buildType} ]; then
	export buildType="debug"
	echo Build type was undefined, defining as: $buildType
fi

if [ -z ${exePostfix} ]; then
	export exePostfix="_debug"
	echo exePostfix was undefined, defining as: $exePostfix
fi

if [ $kLinuxPlatform = $currentPlatform ]; then
	cp "../linux/${buildType}/racing_brains" "${toRunDir}racing_brains_linux${exePostfix}"
else
	#Copy the debug executable into the run directory, which can then be run via commandline from the run directory.
	if [ -d "${toRunDir}racing_brains${exePostfix}" ]; then
		rm "${toRunDir}racing_brains${exePostfix}"
	fi

	cp "../macosx/${buildType}/racing_brains.app/Contents/MacOS/racing_brains" "${toRunDir}racing_brains${exePostfix}"
fi

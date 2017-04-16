#

#
# Automated Build Script for RacingBrains to package the Mac OS X application during a release build.
#
# <!-- Copyright (c) 2017 Tim Beaudet - All Rights Reserved -->
#---------------------------------------------------------------------------------------------------------------------#

kLinuxPlatform="Linux"
currentPlatform=`uname`

export toSlnDir=""
export toRunDir="../../run/"

if [ -z ${buildType} ]; then
	export buildType="release"
	echo Build type was undefined, defining as: $buildType
fi

if [ -z ${exePostfix} ]; then
	export exePostfix=""
	echo exePostfix was undefined, defining as: $exePostfix
fi

if [ $kLinuxPlatform = $currentPlatform ]; then
	cp "../linux/${buildType}/racing_brains" "${toRunDir}racing_brains_linux${exePostfix}"
else
	#If the Mac OS X application package already exists, first delete it before recreating.
	if [ -d "${toRunDir}../RacingBrains.app" ]; then
  		rm -r "${toRunDir}../RacingBrains.app"
	fi

	#Make the directory structure of the Mac OS X application package, then copy executable and data into package.
	mkdir -p "${toRunDir}../RacingBrains.app"
	mkdir -p "${toRunDir}../RacingBrains.app/Contents"
	mkdir -p "${toRunDir}../RacingBrains.app/Contents/MacOS"
	mkdir -p "${toRunDir}../RacingBrains.app/Contents/Resources"
	mkdir -p "${toRunDir}../RacingBrains.app/Contents/Resources/data"
	cp "../macosx/${buildType}/racing_brains.app/Contents/MacOS/racing_brains" "${toRunDir}../RacingBrains.app/Contents/MacOS/RacingBrains"
	cp -r "${toRunDir}data/" "${toRunDir}../RacingBrains.app/Contents/Resources/data/"

	#Copy the executable into the run directory, if using source-control this could be committed and shared with team.
	if [ -d "${toRunDir}racing_brains${exePostfix}" ]; then
		rm "${toRunDir}racing_brains${exePostfix}"
	fi

	cp "../macosx/${buildType}/racing_brains.app/Contents/MacOS/racing_brains" "${toRunDir}racing_brains${exePostfix}"
fi

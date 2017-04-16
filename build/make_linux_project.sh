#

#
# Simple batch script to create a gmake project using premake5 and then build it.
#
# <!-- Copyright (c) 2017 Tim Beaudet - All Rights Reserved -->
#----------------------------------------------------------------------------------------------------------------------

premake5 --file="racing_brains.lua" clean
premake5 --file="racing_brains.lua" gmake
cd linux
make config=release
cd ../

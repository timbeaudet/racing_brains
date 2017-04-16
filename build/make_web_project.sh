#!/bin/bash

#
# This script creates and builds the RacingBrains project for web using emscripten. Still wip/testing.
#
# <!-- Copyright (c) 2017 Tim Beaudet - All Rights Reserved -->
#----------------------------------------------------------------------------------------------------------------------

#May find some help from NeiloGD's wisdom:
#https://github.com/Psybrus/Psybrus/blob/develop/Scripts/Project.lua#L399

premake5 --file="racing_brains.lua" --web="true" clean
premake5 --file="racing_brains.lua" --web="true" gmake

#It seems premake5 is failing a bit here, so once the web directory is generated (from above) comment it out then
#open the generated web/racing_brains.make file and modify the lines regarding CFLAGS, CPPFLAGS and CXXFLAGS
#  ALL_CPPFLAGS += $(CPPFLAGS) -MMD -MP $(DEFINES) $(INCLUDES) -std=c++11
#  ALL_CFLAGS += $(CFLAGS) -MMD -MP $(DEFINES) $(INCLUDES) -g -Wall -Wextra
#  ALL_CXXFLAGS += $(CXXFLAGS) $(ALL_CFLAGS) -std=c++11

cd web
emmake make
emcc debug/objects/**.o -g3 -s LINKABLE=1 -s DEMANGLE_SUPPORT=1 -s ALLOW_MEMORY_GROWTH=1 -s ASSERTIONS=2 -o debug/racing_brains.html --preload-file ../../run/data@/data --shell-file ../web_shell.html

emmake make config=release
emcc release/objects/**.o -O3 -s LINKABLE=1 -s DEMANGLE_SUPPORT=1 -s ALLOW_MEMORY_GROWTH=1 -s ASSERTIONS=2 -o release/racing_brains.html --preload-file ../../run/data@/data --shell-file ../web_shell.html
cd ../

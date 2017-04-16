--
-- Premake5 script for creating a Visual Studio, XCode or CodeLite workspace for the RacingBrains project.
--   Requires Premake5 from: http://industriousone.com/
--
-- <!-- Copyright (c) 2017 Tim Beaudet - All Rights Reserved -->
-----------------------------------------------------------------------------------------------------------------------

--It is expected that a file is
local turtle_brains = require("turtle_brains_build")
if (nil == turtle_brains or nil == turtle_brains.path) then
  print("Unknown location for TurtleBrains framework which can be downloaded using svn from https://www.timbeaudet.com/turtle_brains/")
  print("Once downloaded, create a file named \"turtle_brains_build\" in the same directory this script is running from, make it return an object containing the path to TurtleBrains, like:")
  print("return { path = \"../../../undefined/turtle_brains/\" }")
else
  print("Turtle Brains Path: " .. turtle_brains.path)
end

newoption {
  trigger = "web",
  description = "Chosen build system to override for web.",
  value = "",
}

--Documented at: http://industriousone.com/osget
local WINDOWS_SYSTEM_NAME = "windows"
local LINUX_SYSTEM_NAME = "linux"
local MACOSX_SYSTEM_NAME = "macosx"
local WEB_SYSTEM_NAME = "web"
--local MACIOS_SYSTEM_NAME = "macios"
--local ANDROID_SYSTEM_NAME = "android"

local PROJECT_NAME = "racing_brains"
local SYSTEM_NAME = os.get()
if _OPTIONS["web"] then
  SYSTEM_NAME = WEB_SYSTEM_NAME
end

if _ACTION == "clean" then
  os.rmdir("../build/" .. WINDOWS_SYSTEM_NAME)
  os.rmdir("../build/" .. LINUX_SYSTEM_NAME)
  os.rmdir("../build/" .. MACOSX_SYSTEM_NAME)
  os.rmdir("../build/" .. WEB_SYSTEM_NAME)
end

local SCRIPT_EXTENSION = ".sh"
if (SYSTEM_NAME == WINDOWS_SYSTEM_NAME) then
  SCRIPT_EXTENSION = ".bat"
end

solution(PROJECT_NAME)
  location ("../build/" .. SYSTEM_NAME)
  
configurations { "debug", "release" }
project (PROJECT_NAME)
  location ("../build/" .. SYSTEM_NAME)
  language ("C++")
  kind     ("WindowedApp")
  flags { "ExtraWarnings" }
  
  files { "../source/**.h", "../source/**.cpp", "../source/**.mm", "../source/**.c",
          turtle_brains.path .. "source/**.h", turtle_brains.path .. "source/**.cpp",
          turtle_brains.path .. "source/**.mm", turtle_brains.path .. "source/**.c" }  
  excludes { "../**/doxygen/**" }
  includedirs {
    turtle_brains.path .. "source",
    turtle_brains.path .. "/external_libraries/includes/"
  }
  
----------------------------------------------------------------------- Windows Platform Specifics  
  if (WINDOWS_SYSTEM_NAME == SYSTEM_NAME) then
    libdirs {
      turtle_brains.path .. "external_libraries/libraries/msvc/x32",
      "C:/Program Files (x86)/Windows Kits/10/Lib/10.0.14393.0/um/x86/" --for dxguid
    }

    --TODO: TIM: Cleanup: tb_windows define should be removed and placed in tb_configuration.h
    defines { "_WINDOWS", "WIN32", "tb_windows" }
    links { "OpenGL32", "OpenAL32", "glew32" }
    flags { "StaticRuntime" }
    toolset "v140_xp"
  end
  
----------------------------------------------------------------------- Mac OS X Platform Specifics
  if (MACOSX_SYSTEM_NAME == SYSTEM_NAME) then
    libdirs {
      turtle_brains.path .. "external_libraries/libraries/macosx/"
    }

    buildoptions "-mmacosx-version-min=10.7"
    --linkoptions ""

--    buildoptions "-std=c++11 -stdlib=libc++ -mmacosx-version-min=10.7"
--    linkoptions "-stdlib=libc++"
    
    --TODO: TIM: Cleanup: tb_macosx define should be removed and placed in tb_configuration.h
    defines { "tb_macosx" }
    links { "AppKit.framework", "IOKit.framework", "OpenGL.framework", "OpenAL.framework", "glew" }
  end
  
----------------------------------------------------------------------- Linux Platform Specifics 
  if (LINUX_SYSTEM_NAME == SYSTEM_NAME) then
    libdirs {
      turtle_brains.path .. "external_libraries/libraries/linux/",
      "/opt/lib/"
    }
    includedirs {
      "/usr/includes/GL/"
    }
    buildoptions "-std=c++11"
    --TODO: TIM: Cleanup: tb_linux define should be removed and placed in tb_configuration.h
    defines { "tb_linux" } 
    links { "GL", "GLEW", "openal", "X11" }
    excludes { "../**/**.mm" }
  end

----------------------------------------------------------------------- Web (Emscripten) Platform Specifics 
  if (WEB_SYSTEM_NAME == SYSTEM_NAME) then
    buildoptions "-std=c++11"
    linkoptions "-stdlib=libc++"    
    defines { "tb_web" }
  end  

--------------------------------------------------------------------- Build Configuration Specifics/Overrides  
  configuration "debug*"
    targetdir ("../build/" .. SYSTEM_NAME .. "/debug")
    objdir ("../build/" .. SYSTEM_NAME .. "/debug/objects" )
    defines { "_DEBUG", "DEBUG" }
    flags   { "Symbols", }
	  debugdir "../run"	
	--debugargs { "--nosplash", "--other" }
	  postbuildcommands { "../automated/post_build_debug" .. SCRIPT_EXTENSION }

  configuration "release*"
    targetdir ("../build/" .. SYSTEM_NAME .. "/release")
    objdir ("../build/" .. SYSTEM_NAME .. "/release/objects" )
    defines { "NDEBUG" }
    flags   { "Optimize", }
	  debugdir "../run"
	--debugargs { "--nosplash", "--other" }
	  postbuildcommands { "../automated/post_build_release" .. SCRIPT_EXTENSION }

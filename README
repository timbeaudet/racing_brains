# Racing Brains
This is a spin-off project of Tim Beaudet's Artificial Intelligence in Racing Simulations project that includes many similar code portions that are relevant to racing. The project uses the 2D TurtleBrains framework.

## To Build
1. Download/Install premake5 on your system.
2. Download latest version of [TurtleBrains.](https://www.turtlebrains.com)
3. Download latest version of Racing Brains.
4. Add `build/turtle_brains_build.lua` with contents similar to: `return { path = "your/path/to/turtle_brains/" }`
5. Run the script `make_project.bat` or `make_project.sh` depending on your system which will _(by default)_ create a Visual Studio or XCode project in the `build/system` directory. Open and edit freely.

### Additional Build Notes
The XCode project needs to be modified slightly by hand after getting generated with Premake5. Once opened, open **project settings** and modify the following:

| Setting Name | Value |
| ------------- | ---- |
| Deploy Target | 10.7 |
| C++ Lang. Dialect | C++11 _(-std=c++11)_ |
| C++ Std Library | libc++ _(with C++11 support)_ |

Finally you to run from XCode you will need to modify the working directory by editing the scheme, `Product > Scheme > Edit Scheme` choose Run, then Options and set the working directory to `path/to/racing_brains/run/`

_Premake5 works a bit better on Windows so all of this is setup properly in the generated Visual Studio project._

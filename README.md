# computational-geometry-playground

A C++ playground for computational geometry algorithms &amp; plotting.

Tested on:

* MacOS Monterey 12.3.1 with M1 chip
* Ubuntu 20.04 LTS
* Windows 11

## How to Build

This is a plain CMake project with C++ 17. Run the normal CMake build steps. All necessary dependencies should be resolved in CMake configure time.

### On MacOS & Linux

```bash
mkdir build && cd build
cmake .. -DCMAKE_EXPORT_COMPILE_COMMANDS=1
make -j
```

### On Windows (Beta)

This project is also tested on Visual Studio 2022, Windows 11. However, it is not recommended to develop on Windows since checking the build of OpenCV is extremely slow on Windows!

```bash
mkdir build && cd build
cmake-gui ..
```

Add `CMAKE_BUILD_PARALLEL_LEVEL=8` as an extra entry in CMake build flags. Then hit "Configure" in CMake GUI with default generator as Visual Studio 2022. Wait for all external dependencies to download and build. Then hit "Generate" and "Open in Visual Studio 2022".

In Visual Studio 2022, set `cg_playground` as startup project, and then hit `CTRL-B` to build, `CTRL-F5` to run.

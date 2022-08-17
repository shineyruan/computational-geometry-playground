# computational-geometry-playground

A C++ playground for computational geometry algorithms &amp; plotting.

Tested on:

* MacOS Monterey 12.5 with M1 chip
* Ubuntu 20.04 LTS
* Windows 11

## How to Build

This is a C++ 17 project managed with CMake and [Conan package manager](https://conan.io/). Make sure Conan is installed correctly onto your system.

### Configure Dependencies

```bash
mkdir build && cd build
conan install ..
```

If package install failure, try with building from source locally:

```bash
conan install .. --build=$(PKG_NAME)
```

### On MacOS & Linux

```bash
cmake .. -DCMAKE_EXPORT_COMPILE_COMMANDS=1
make -j
```

### On Windows (Beta)

This project is also tested on Visual Studio 2022, Windows 11. However, it is not recommended to develop on Windows since checking the build of OpenCV is extremely slow on Windows!

```bash
cmake-gui ..
```

Hit "Configure" in CMake GUI with default generator as Visual Studio 2022. Wait for all external dependencies to download and build. Then hit "Generate" and "Open in Visual Studio 2022".

In Visual Studio 2022, set `cg_playground` as startup project, and then hit `CTRL-B` to build, `CTRL-F5` to run.

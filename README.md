[![CMake Build](https://github.com/shineyruan/computational-geometry-playground/actions/workflows/cmake.yml/badge.svg)](https://github.com/shineyruan/computational-geometry-playground/actions/workflows/cmake.yml)

# computational-geometry-playground

A C++ playground for computational geometry algorithms &amp; plotting.

Tested on:

* MacOS Monterey 12.5 with M1 chip
* Ubuntu 20.04 LTS
* Windows 11

## How to Build

This is a C++ 17 project managed with CMake and [Conan package manager](https://conan.io/). Make sure Conan is installed correctly onto your system.

### Configure Dependencies

One could use the following commands to configure Conan dependencies:

#### On MacOS & Windows 11

Just a normal build on MacOS:

```bash
mkdir build && cd build
conan install ../conanfile_macos.txt --build=opencv
```

and a normal build on Windows:

```bash
mkdir build && cd build
conan install ../conanfile_windows.txt --build=opencv
```

**Note. VSCode debugging on macOS requires the use of extension `CodeLLDB`. Users shall have it installed in the workspace and use "Debug Launch (CodeLLDB) to launch the program.**

#### On Linux (Ubuntu)

Linux's version of OpenCV depends on GTK 2.0+ to provide GUI facilities. Also there is a known issue that [Conan defaults to `libstdc++` in the generated profile which only supports GCC ABI with version <5.0.](https://docs.conan.io/en/latest/howtos/manage_gcc_abi.html#manage-gcc-abi) We need to manually specify the new GCC ABI with the following command:

```bash
mkdir build && cd build
sudo apt install libgtk2.0-dev
conan install ../conanfile_linux.txt --build=opencv -s compiler.libcxx=libstdc++11
```

### Building Source Code

#### On MacOS & Linux

```bash
cmake .. -DCMAKE_EXPORT_COMPILE_COMMANDS=1
make -j
```

#### On Windows 11

In Powershell, run

```bash
cmake ..
```

Open Visual Studio 2022 with the generated project `cg_playground.sln`. In Visual Studio 2022, set `cg_playground` as startup project, and then hit `CTRL-B` to build, `CTRL-F5` to run.

[![CMake Build](https://github.com/shineyruan/computational-geometry-playground/actions/workflows/cmake.yml/badge.svg)](https://github.com/shineyruan/computational-geometry-playground/actions/workflows/cmake.yml)

# computational-geometry-playground

A C++ playground for computational geometry algorithms &amp; plotting.

Tested on:

* MacOS Monterey 12.5 with M1 chip
* Ubuntu 20.04 LTS
* Windows 11

## How to Build

This is a C++ 17 project managed with CMake and both [Vcpkg](https://vcpkg.io/en/) and [Conan 2.x](https://conan.io/). Make sure Conan/Vcpkg is installed correctly onto your system.

### Configure Conan Dependencies

One could use the following commands to configure Conan dependencies:

#### On MacOS, Linux (Ubuntu), Windows 11

On MacOS:

```bash
mkdir build && cd build
conan install ../conanfile_macos.txt --build=missing
```

On Windows:

```bash
mkdir build && cd build
conan install ../conanfile_windows.txt --build=missing
```

On Linux:

```bash
mkdir build && cd build
conan install ../conanfile_linux.txt --build=missing
```

**Note. VSCode debugging on macOS requires the use of extension `CodeLLDB`. Users shall have it installed in the workspace and use "Debug Launch (CodeLLDB) to launch the program.**

### Configure Vcpkg Dependencies

Clone the vcpkg repo into `$HOME`.

```bash
git clone https://github.com/microsoft/vcpkg "$HOME/vcpkg"
```

### Building Source Code

#### On MacOS & Linux

For Conan,

```bash
cmake .. -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake
make -j
```

or Vcpkg

```bash
cmake .. -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -DCMAKE_TOOLCHAIN_FILE=$HOME/vcpkg/scripts/buildsystems/vcpkg.cmake
make -j
```

#### On Windows 11

In Powershell, run

```bash
cmake .. -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake
```

or

```bash
cmake .. -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -DCMAKE_TOOLCHAIN_FILE=$HOME/vcpkg/scripts/buildsystems/vcpkg.cmake
```

Open Visual Studio 2022 with the generated project `cg_playground.sln`. In Visual Studio 2022, set `cg_playground` as startup project, and then hit `CTRL-B` to build, `CTRL-F5` to run.

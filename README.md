[![Vcpkg Build](https://github.com/shineyruan/computational-geometry-playground/actions/workflows/vcpkg_build_release.yml/badge.svg)](https://github.com/shineyruan/computational-geometry-playground/actions/workflows/vcpkg_build_release.yml)

# computational-geometry-playground

A C++ playground for computational geometry algorithms &amp; plotting.

Tested on:

* MacOS Ventura 13.3 with M1 chip
* Ubuntu 22.04 LTS
* Windows 11

## How to Build

This is a C++ 17 project managed with CMake and [Vcpkg](https://vcpkg.io/en/) in manifest mode. Make sure Vcpkg is installed correctly onto your system:

```bash
git clone https://github.com/microsoft/vcpkg "$HOME/vcpkg"
$HOME/vcpkg/bootstrap-vcpkg.sh   # or $HOME/vcpkg/bootstrap-vcpkg.bat on Windows
```

To build the source code, run CMake with Vcpkg toolchain:

```bash
cmake .. -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -DCMAKE_TOOLCHAIN_FILE=$HOME/vcpkg/scripts/buildsystems/vcpkg.cmake
make -j
```

On Windows 11, open Visual Studio 2022 with the generated project `cgsolver.sln`. In Visual Studio 2022, set `cgsolver` as startup project, and then hit `CTRL-B` to build, `CTRL-F5` to run.

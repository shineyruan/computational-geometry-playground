# computational-geometry-playground

A C++ playground for computational geometry algorithms &amp; plotting.

Tested on:

* MacOS Monterey 12.3.1 with M1 chip
* Ubuntu 20.04 LTS

## How to Build

This is a plain CMake project. Run the normal CMake build steps.

### On MacOS

```bash
mkdir build && cd build
cmake .. -DCMAKE_EXPORT_COMPILE_COMMANDS=1
make -j
```

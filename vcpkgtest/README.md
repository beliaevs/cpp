# vcpkg thirdparty repository test

## how it was created?

In empty directory vcpkgtest run tyhe following commands:

vcpkg new --application

vcpkg add port fmt

Create CMakeLists.txt and CMakePresets.json. Change generator in CMakePresets.json correspondingly (Ninja or "Visual Studio 17 2022")

cmake --preset=default

cmake --build build


# Janus Engine
A cross-platform game engine built in C++ for creating 2D & 3D games. This is an educational project. 

## Compile from Source

Start by recursively cloning the repository
``` bash
git clone --recursive https://github.com/Kytha/Janus.git
```
Alternatively, if the repository was not cloned recursively use the following command
``` bash
git submodule update --init
```
Once your local repo is setup, you'll want to run the premake scripts to generate the properly configured Visual Studio solution. To do this, simply navigate to the `scripts` folder and run the appropriate platform specific script file (currently only Windows is supported!)

## Dependancies 

- [GLFW](https://github.com/glfw/glfw) - Open Source, multi-platform library for OpenGL, OpenGL ES and Vulkan development on the desktop
- [GLAD](https://glad.dav1d.de/) - Multi-Language GL/GLES/EGL/GLX/WGL Loader-Generator
- [glm](https://github.com/g-truc/glm) - Header only C++ mathematics library for graphics software based on the GLSL
- [imgui](https://github.com/ocornut/imgui) - Immediate-mode, bloat-free graphical user interface library for C++
- [spdlog](https://github.com/gabime/spdlog) - Very fast, header-only/compiled, C++ logging library

Shout out to the authors and communities of these open-source libraries, which make projects like Janus Engine possible.

## Platform Support

The Janus engine is intended to be a cross-platform engine to design cross-platform games. Applications built with the Janus Engine have only been officially tested on Windows, but in its current state should support the following platforms;

- Windows ✔️
- Mac ✔️
- Linux ✔️
- Andriod ❌
- IOS ❌

## Features

Janus is in quite early development. List of current features coming soon! Current focus is on finishing the renderer primitives and pipeline to create the 2D renderer.

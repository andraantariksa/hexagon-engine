# Hexagon Engine

## This repository has been moved to https://github.com/shaderboi/hexagon-engine

[![Build Status](https://dev.azure.com/andraantariksa/Hexagon%20Engine/_apis/build/status/andraantariksa.hexagon-engine?branchName=master)](https://dev.azure.com/andraantariksa/Hexagon%20Engine/_build/latest?definitionId=5&branchName=master)

[Documentation](http://andraaa.github.io/hexagon-engine/)

## Overview

Hexagon Engine is an experimental game engine

## Goals

Creating a convenience game engine and embracing fearless C++

- [ ] Renderer
- [ ] Window
- [ ] Math library
and so on...

## Getting Started

You need to install SDL2 library and CMake to build the project

### Windows

You need to copy the .dll file from `Dependencies\SDL2\lib\%YOUR MACHINE ARCHITECTURE%\SDL2.dll` to `C:\Windows\`

TODO

### Linux

- Install SDL2 library

#### Debian or Ubuntu

```
sudo apt-get install libsdl2-dev
```

#### Arch or Manjaro

```
sudo pacman -S sdl2
```

### OSX

```
brew install sdl2
```

## Dependencies

- [spdlog](https://github.com/gabime/spdlog/tree/v1.4.2)

## Contributing

### Coding Style

Make sure you're following our [coding style](Docs/CodingStyle.md)

## License

[MIT Licensed](LICENSE)

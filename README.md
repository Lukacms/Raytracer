# Raytracer
Your CPU goes brrrrr!

![](https://cdn.discordapp.com/attachments/1093990022929195139/1102907617178816563/image.png)

## Project
Ray tracing is a technique used to generate realistic digital images by simulating the inverse path of light. Our goal here is to create a program from a file describing a scene.

We had the following objectives:
* have multiple types of primitives (Spheres, Planes, Cylinders, ...)
* have multiple types of lights (Point, Directionnal, ...)
* have at least an output to a ppm file
* load the elements from a json configutation file, using [nlohmann-json3](https://github.com/nlohmann/json/) library

### Dependencies
The project is done in [C++](https://en.wikipedia.org/wiki/C%2B%2B), and build using [CMake](https://cmake.org/)

### Documentation

To have more information, look at the [docs](https://github.com/Lukacms/Raytracer/docs) folder.

## Build
To build the project, follow the steps below:
```bash
# Make sure you have the necessary system packages installed
# ⚠️ The following system packages installation commands may change depending on 
# your OS. Below example is for Ubuntu 20.04
sudo apt-get update -qq
sudo apt-get install -y ninja-build clang-tidy-12 ccache
sudo update-alternatives --install /usr/bin/clang-tidy clang-tidy /usr/bin/clang-tidy-12 100
sudo apt-get install -y --no-install-recommends nlohmann-json3-dev libsfml-dev

# clone the repository
git clone git@github.com:Lukacms/Raytracer.git
cd Raytracer

# compile the project with flags required to close properly shared libraries, only available with g++
./compile.sh --gcc
```

Once the project is build, the `ratracer` executable is built at the root, and the plugins in the `plugins` directories:
```bash
.
├── plugins
│   ├── Catch2.a
│   ├── Catch2Main.a
│   ├── raytracer_ambiant_light.so
│   ├── raytracer-core.so
│   ├── raytracer_directional_light.so
│   ├── raytracer_moebius.so
│   ├── raytracer_plane.so
│   ├── raytracer_point_light.so
│   └── raytracer_sphere.so
└── raytracer
```

## Authors
* [Luka Camus](https://github.com/Lukacms)
* [Louis Bassagal](https://github.com/LouisBassagal)
* [Samuel Florentin](https://github.com/SamuelFlorentin)
* [Édouard Pradie](https://github.com/EdouardPradie)

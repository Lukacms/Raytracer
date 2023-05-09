# Raytracer - Configuration Files

The configuration file are in `json`, and the library to load them is [nlohmann/json](https://github.com/nlohmann/json/tree/v3.11.2).

A configuration file needs to have at least:
* a [camera](#Camera)
* a [primitive](#Primitives) to draw
* a [light](#Lights)
And a example of a configuration is [this file](https://github.com/Lukacms/Raytracer/blob/main/assets/configs/test.json).

## Camera
Will be loaded in a [Camera](https://github.com/Lukacms/Raytracer/blob/main/Core/include/raytracer/Camera.hh) class.
It is recognized with the `camera` key, and must have an `origin` and a `canva` defined.
```json
    "camera": {
        "origin": {
            "x": 0,
            "y": 0,
            "z": 1
        },
        "canva": {
            "origin": {
                "x": -0.5,
                "y": -0.5,
                "z": 0
            },
            "bottom": {
                "x": 1,
                "y": 0,
                "z": 0
            },
            "left": {
                "x": 0,
                "y": 1,
                "z": 0
            }
        }
    },
```

## Primitives
The primitive are loaded with the [PrimitiveFactory](https://github.com/Lukacms/Raytracer/blob/main/Core/include/raytracer/factory/PrimitiveFactory.hpp).
Their type is indicated with the `type` key, and they may have various elements, depending on which one it is. But they must all have a `material`.

Example for a sphere, which needs a `radius` and an `origin`:
```json
{
    "type": "sphere",
    "origin": {
        "x": -0.5,
        "y": 0,
        "z": -2
    },
    "radius": 0.5,
    "material": {
        "color": {
            "r": 0,
            "g": 0,
            "b": 255
        },
        "reflection": 0.2,
        "spec": 500
    }
},
```

## Lights
The lights are loaded with the [LightFactory](https://github.com/Lukacms/Raytracer/blob/main/Core/include/raytracer/factory/LightFactory.hpp).
Their type is indicated with the `type` key, and they may have various elements, depending on which one it is.

Example for a point light, which needs an `origin` and an `intensity`:
```json
{
    "type": "point",
    "origin": {
        "x": 2,
        "y": 1,
        "z": 0
    },
    "intensity": 0.3
},
```

# Raytracer - Plugins

For this project, the plugins (objects or lights) are loaded dynamically, which mean they are compiled in [shared libraries](https://www.bogotobogo.com/cplusplus/libraries.php).

## Compilation
The plugins are loaded using `CMakeLists`, which are called using the `add_subdirectory([Your plugin directory])` at the root of either the `Lights` or `Primitives` directories.

The structure of the `CMakeLists` in itself is:
```CMake
add_library(
  raytracer_[plugin name] SHARED
  [SOURCE FILES]
)

set(EXECUTABLE_OUTPUT_PATH ../${PROJECT_SOURCE_DIR}/plugins/)

target_include_directories(raytracer_[plugin name] PRIVATE ./include)
target_compile_options(raytracer_[plugin name] PRIVATE ${WARNING_FLAGS})
target_link_libraries(raytracer_[plugin name] PRIVATE raytracer-interface)
set_property(TARGET raytracer_[plugin name] PROPERTY CXX_STANDARD 20)
set_property(TARGET raytracer_[plugin name] PROPERTY CXX_STANDARD_REQUIRED ON)
```

And the structure of the plugin may look like this (example using the `Sphere` primitive):
```
Primitives/Sphere/
├── CMakeLists.txt
├── include
│   └── Sphere.hh
└── src
    ├── EntryPoint.cpp
    └── Sphere.cpp
```

## What's in the plugin itself
You have to create a class inheriting from either the `APrimitive` or the `Alight` abstract class. You may have as much parameters as needed, as the factory is templated.

You must however, add either a `primitive_entrypoint` or a `light_entrypoint` returning a unique_ptr of your object. If it's a `primitive`, the methods `setMaterial` must be called.

### Factories
As said before, the factories are templated, so you can have all the arguments needed. You will have to add a lambda to load correctly the arguments from the configuration file.

Example for the [PrimitiveFactory](https://github.com/Lukacms/Raytracer/blob/main/Core/src/factory/PrimitiveFactory.cpp) file:
```cpp
    {"plane", PLANE_LIB.data(),
     [](const std::string &lib, njson &json) -> std::unique_ptr<math::IPrimitive> {
         math::Point3D origin = json["origin"];
         math::Axis axis = json["axis"];
         raytracer::Material material = json["material"]; // there must be a material element. The rest is what is needed

         std::unique_ptr<math::IPrimitive> prim =
             raytracer::PrimitiveFactory::create
                <std::unique_ptr<math::IPrimitive>(const math::Point3D &, const math::Axis &, const raytracer::Material &)> // signature of the template to call loading function
                (lib, origin, axis, material);
         return prim;
     }},
```

The templated function `create` is called:
```cpp
    template <typename TSignature, typename... TValues> // signature and variadic arguments
    static std::unique_ptr<math::IPrimitive> create(const std::string &path,
                                                    TValues... values)
    {
        std::unique_ptr<math::IPrimitive> new_primitive;
        void *handle = nullptr;

        if (!(handle = dlopen(path.c_str(), RTLD_LAZY)))
            throw raytracer::PrimitiveFactory::FactoryException(dlerror());
        auto *loader =
            reinterpret_cast<TSignature *>(dlsym(handle, LOAD_PRIMITIVE_METHOD.data())); // where the signature is used
        if (!loader)
            throw raytracer::PrimitiveFactory::FactoryException(
                ERROR_PRIMITIVE_CANNOT_LOAD.data());
        if (!(new_primitive = loader(std::forward<TValues>(values)...)))
            throw raytracer::PrimitiveFactory::FactoryException(ERROR_NOT_PRIMITIVE.data());
        return new_primitive;
    }
```

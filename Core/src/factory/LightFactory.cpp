/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** LightFactory
*/

#include <raytracer/factory/LightFactory.hh>
#include <dlfcn.h>

// Constructor & Destructor

// Methods

std::unique_ptr<light::ILight> raytracer::LightFactory::createAmbiant(math::Point3D &origin)
{
    std::unique_ptr<light::ILight> new_light;
    void *handle;

    if (!(handle = dlopen(AMBIANT_LIB.data(), RTLD_LAZY)))
        throw raytracer::LightFactory::FactoryException(dlerror());
    auto *loader = reinterpret_cast<std::unique_ptr<light::ILight> (*)(math::Point3D &origin)>(
        dlsym(handle, LOAD_LIGHT_METHOD.data()));
    if (!loader)
        throw raytracer::LightFactory::FactoryException(ERROR_LIGHT_CANNOT_LOAD.data());
    if (!(new_light = loader(origin)))
        throw raytracer::LightFactory::FactoryException(ERROR_NOT_LIGHT.data());
    return new_light;
}

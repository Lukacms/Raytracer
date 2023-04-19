/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** PrimitiveFactory
*/

#include "raytracer/math/APrimitive.hh"
#include <raytracer/math/IPrimitive.hh>
#include <raytracer/factory/AFactory.hh>
#include <raytracer/factory/PrimitiveFactory.hh>
#include <dlfcn.h>
#include <memory>

// Constructor & Destructor

// Methods

std::unique_ptr<Math::IPrimitive> RayTracer::PrimitiveFactory::createSphere(Math::Point3D &origin, double radius)
{
    std::unique_ptr<Math::IPrimitive> new_sphere;
    void *handle;

    if (!(handle = dlopen(SPHERE_LIB.data(), RTLD_LAZY)))
        throw RayTracer::PrimitiveFactory::FactoryException(dlerror());
    auto *loader = reinterpret_cast<std::unique_ptr<Math::IPrimitive> (*)(Math::Point3D &origin, double radius)>(
        dlsym(handle, LOAD_METHOD.data()));
    if (!loader)
        throw RayTracer::PrimitiveFactory::FactoryException(ERROR_CANNOT_LOAD.data());
    if (!(new_sphere = loader(origin, radius)))
        throw RayTracer::PrimitiveFactory::FactoryException(ERROR_NOT_PRIMITIVE.data());
    return new_sphere;
}

std::unique_ptr<Math::IPrimitive> RayTracer::PrimitiveFactory::createPlane(Math::Point3D &origin, Math::Axis axis)
{
    std::unique_ptr<Math::IPrimitive> new_plane;
    void *handle;

    if (!(handle = dlopen(PLANE_LIB.data(), RTLD_LAZY)))
        throw RayTracer::PrimitiveFactory::FactoryException(dlerror());
    auto *loader = reinterpret_cast<std::unique_ptr<Math::IPrimitive> (*)(Math::Point3D &origin, Math::Axis axis)>(
        dlsym(handle, LOAD_METHOD.data()));
    if (!loader)
        throw RayTracer::PrimitiveFactory::FactoryException(ERROR_CANNOT_LOAD.data());
    if (!(new_plane = loader(origin, axis)))
        throw RayTracer::PrimitiveFactory::FactoryException(ERROR_NOT_PRIMITIVE.data());
    return new_plane;
}

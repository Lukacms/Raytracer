/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** PrimitiveFactory
*/

#include "raytracer/math/APrimitive.hh"
#include <dlfcn.h>
#include <memory>
#include <raytracer/factory/AFactory.hh>
#include <raytracer/factory/PrimitiveFactory.hh>
#include <raytracer/math/IPrimitive.hh>

// Constructor & Destructor

// Methods

std::unique_ptr<math::IPrimitive> raytracer::PrimitiveFactory::createSphere(math::Point3D &origin,
                                                                            double radius)
{
    std::unique_ptr<math::IPrimitive> new_sphere;
    void *handle;

    if (!(handle = dlopen(SPHERE_LIB.data(), RTLD_LAZY)))
        throw raytracer::PrimitiveFactory::FactoryException(dlerror());
    auto *loader = reinterpret_cast<std::unique_ptr<math::IPrimitive> (*)(
        math::Point3D & origin, double radius)>(dlsym(handle, LOAD_METHOD.data()));
    if (!loader)
        throw raytracer::PrimitiveFactory::FactoryException(ERROR_CANNOT_LOAD.data());
    if (!(new_sphere = loader(origin, radius)))
        throw raytracer::PrimitiveFactory::FactoryException(ERROR_NOT_PRIMITIVE.data());
    return new_sphere;
}

std::unique_ptr<math::IPrimitive> raytracer::PrimitiveFactory::createPlane(math::Point3D &origin,
                                                                           math::Axis axis)
{
    std::unique_ptr<math::IPrimitive> new_plane;
    void *handle;

    if (!(handle = dlopen(PLANE_LIB.data(), RTLD_LAZY)))
        throw raytracer::PrimitiveFactory::FactoryException(dlerror());
    auto *loader = reinterpret_cast<std::unique_ptr<math::IPrimitive> (*)(
        math::Point3D & origin, math::Axis axis)>(dlsym(handle, LOAD_METHOD.data()));
    if (!loader)
        throw raytracer::PrimitiveFactory::FactoryException(ERROR_CANNOT_LOAD.data());
    if (!(new_plane = loader(origin, axis)))
        throw raytracer::PrimitiveFactory::FactoryException(ERROR_NOT_PRIMITIVE.data());
    return new_plane;
}

/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** EntryPoint
*/

#pragma GCC diagnostic ignored "-Wreturn-type-c-linkage"

#include <Sphere.hh>
#include <memory>
#include <raytracer/RayTracer.hh>
#include <raytracer/math/Point3D.hh>

extern "C" { // NOLINT

std::unique_ptr<math::Sphere> primitive_entrypoint(const math::Point3D &origin,
                                                   const double &radius,
                                                   const raytracer::Material &material) // NOLINT
{
    std::unique_ptr<math::Sphere> new_sphere =
        std::make_unique<math::Sphere>(origin, radius, material);

    new_sphere->setMaterial(material);
    return new_sphere;
}
}

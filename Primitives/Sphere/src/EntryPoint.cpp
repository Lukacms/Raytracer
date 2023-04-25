/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** EntryPoint
*/

#pragma GCC diagnostic ignored "-Wreturn-type-c-linkage"

#include <Sphere.hh>
#include <memory>
#include <raytracer/math/Point3D.hh>

extern "C" { // NOLINT

std::unique_ptr<math::Sphere> entry_point_primitive(math::Point3D &origin, double radius) // NOLINT
{
    std::unique_ptr<math::Sphere> new_sphere = std::make_unique<math::Sphere>(origin, radius);
    return new_sphere;
}
}

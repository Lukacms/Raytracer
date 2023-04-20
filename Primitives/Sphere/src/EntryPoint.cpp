/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** EntryPoint
*/

#include <Sphere.hh>
#include <memory>
#include <raytracer/math/Point3D.hh>

extern "C" { // NOLINT

// NOLINTNEXTLINE
std::unique_ptr<Math::Sphere> entry_point_primitive(Math::Point3D &origin, double radius)
{
    std::unique_ptr<Math::Sphere> new_sphere = std::make_unique<Math::Sphere>(origin, radius);
    return new_sphere;
}
}

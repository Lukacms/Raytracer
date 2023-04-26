/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** EntryPoint
*/

#pragma GCC diagnostic ignored "-Wreturn-type-c-linkage"

#include <Plane.hh>
#include <memory>
#include <raytracer/math/Point3D.hh>

extern "C" { // NOLINT

std::unique_ptr<math::Plane> entry_point_primitive(math::Point3D &origin, math::Axis axis) // NOLINT
{
    std::unique_ptr<math::Plane> new_plane = std::make_unique<math::Plane>(origin, axis);

    return new_plane;
}
}

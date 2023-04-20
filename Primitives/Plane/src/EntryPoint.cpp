/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** EntryPoint
*/

#include <Plane.hh>
#include <memory>
#include <raytracer/math/Point3D.hh>

extern "C" { // NOLINT

std::unique_ptr<Math::Plane> entry_point_primitive(Math::Point3D &origin, Math::Axis axis)
{ // NOLINT

    std::unique_ptr<Math::Plane> new_plane = std::make_unique<Math::Plane>(origin, axis);
    return new_plane;
}
}

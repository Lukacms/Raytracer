/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** EntryPoint
*/

#pragma GCC diagnostic ignored "-Wreturn-type-c-linkage"

#include <Cylinder.hh>
#include <memory>
#include <raytracer/math/Point3D.hh>

extern "C" { // NOLINT

std::unique_ptr<math::Cylinder> entry_point_primitive(math::Point3D origin, double radius, double height, math::Vector3D axe) // NOLINT
{
    std::unique_ptr<math::Cylinder> new_Cylinder = std::make_unique<math::Cylinder>(origin, radius, height, axe);
    return new_Cylinder;
}
}

/*
** EPITECH PROJECT, 2023
** src
** File description:
** EntryPoint
*/

#include "raytracer/RayTracer.hh"
#include <Moebius.hh>
#include <memory>
#include <raytracer/math/Point3D.hh>

#pragma GCC diagnostic ignored "-Wreturn-type-c-linkage"

extern "C" {
std::unique_ptr<math::Moebius> entry_point_primitive(math::Point3D &origin, double radius,
                                                     const raytracer::Color &color)
{
    std::unique_ptr<math::Moebius> new_prim = std::make_unique<math::Moebius>(origin, radius);

    new_prim->setColor(color.red, color.green, color.blue);
    return new_prim;
}
}

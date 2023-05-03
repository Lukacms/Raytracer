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
std::unique_ptr<math::Moebius> primitive_entrypoint(const math::Point3D &origin,
                                                    const double &radius,
                                                    const raytracer::Material &material)
{
    std::unique_ptr<math::Moebius> new_prim = std::make_unique<math::Moebius>(origin, radius);

    new_prim->setMaterial(std::move(material));
    return new_prim;
}
}

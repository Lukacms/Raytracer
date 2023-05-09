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
#include <utility>

extern "C" { // NOLINT

std::unique_ptr<math::Plane> primitive_entrypoint(const math::Point3D &origin,
                                                  const math::Axis &axis,
                                                  const raytracer::Material &material) // NOLINT
{
    std::unique_ptr<math::Plane> new_plane = std::make_unique<math::Plane>(origin, axis, material);

    new_plane->setMaterial(material);
    return new_plane;
}
}

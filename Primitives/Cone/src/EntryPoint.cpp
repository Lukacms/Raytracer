/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** EntryPoint
*/

#include "raytracer/RayTracer.hh"
#include "raytracer/math/IPrimitive.hh"
#pragma GCC diagnostic ignored "-Wreturn-type-c-linkage"

#include <Cone.hh>
#include <memory>
#include <raytracer/math/Point3D.hh>

extern "C" { // NOLINT

std::unique_ptr<math::Cone> primitive_entrypoint(const math::Point3D &origin, double radius, double height, const raytracer::Material &material) // NOLINT
{
    std::unique_ptr<math::Cone> new_cone = std::make_unique<math::Cone>(origin, radius,height);

    new_cone->setMaterial(material);
    return new_cone;
}
}

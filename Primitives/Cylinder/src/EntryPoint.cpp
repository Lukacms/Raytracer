/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** EntryPoint
*/

#include "raytracer/RayTracer.hh"
#include "raytracer/math/IPrimitive.hh"
#pragma GCC diagnostic ignored "-Wreturn-type-c-linkage"

#include <Cylinder.hh>
#include <memory>
#include <raytracer/math/Point3D.hh>

extern "C" { // NOLINT

std::unique_ptr<math::Cylinder> primitive_entrypoint(const math::Point3D &origin, double radius, const raytracer::Material &material) // NOLINT
{
    std::unique_ptr<math::Cylinder> new_cylinder = std::make_unique<math::Cylinder>(origin, radius);

    new_cylinder->setMaterial(material);
    return new_cylinder;
}
}

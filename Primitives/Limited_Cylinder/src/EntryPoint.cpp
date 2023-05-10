/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** EntryPoint
*/

#include "raytracer/RayTracer.hh"
#include "raytracer/math/IPrimitive.hh"
#pragma GCC diagnostic ignored "-Wreturn-type-c-linkage"

#include <Limited_Cylinder.hh>
#include <memory>
#include <raytracer/math/Point3D.hh>

extern "C" { // NOLINT

std::unique_ptr<math::Limited_Cylinder>
primitive_entrypoint(const math::Point3D &origin, double radius, double limite,
                     const raytracer::Material &material) // NOLINT
{
    std::unique_ptr<math::Limited_Cylinder> new_limited_cylinder =
        std::make_unique<math::Limited_Cylinder>(origin, radius,limite);

    new_limited_cylinder->setMaterial(material);
    return new_limited_cylinder;
}
}

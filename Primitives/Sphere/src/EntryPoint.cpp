/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** EntryPoint
*/

#include <iostream>
#pragma GCC diagnostic ignored "-Wreturn-type-c-linkage"

#include <Sphere.hh>
#include <memory>
#include <raytracer/math/Point3D.hh>

extern "C" { // NOLINT

std::unique_ptr<math::Sphere> entry_point_primitive(math::Point3D &origin, double radius) // NOLINT
{
    std::unique_ptr<math::Sphere> new_sphere = std::make_unique<math::Sphere>(origin, radius);

    std::cerr << "radius -> " << radius << "\n";
    std::cerr << "origin -> " << origin.getX() << "\n";
    return new_sphere;
}
}

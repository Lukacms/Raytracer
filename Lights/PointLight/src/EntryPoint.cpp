/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** EntryPoint
*/

#pragma GCC diagnostic ignored "-Wreturn-type-c-linkage"

#include <PointLight.hh>
#include <memory>
#include <raytracer/math/Point3D.hh>

extern "C" { // NOLINT

    std::unique_ptr<light::ILight> entry_point_light(math::Point3D &position, double intensity) // NOLINT
    {
        return std::make_unique<light::PointLight>(position, intensity);
    };
}

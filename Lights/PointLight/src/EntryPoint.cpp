/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** EntryPoint
*/

#include <raytracer/math/Point3D.hh>
#include <memory>
#include <PointLight.hh>

extern "C" { // NOLINT

    std::unique_ptr<light::ILight> entry_point_light(math::Point3D &position) // NOLINT
    {
        return std::make_unique<light::PointLight>(position);
    };
}

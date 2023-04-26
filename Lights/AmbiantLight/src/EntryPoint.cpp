/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** EntryPoint
*/

#include <raytracer/math/Point3D.hh>
#include <memory>
#include <AmbiantLight.hh>

extern "C" { // NOLINT

    std::unique_ptr<light::ILight> entry_point_light(math::Point3D &position, double coefficient) // NOLINT
    {
        if (coefficient > 1 && coefficient < 0)
            throw;
        return std::make_unique<light::AmbientLight>(position, coefficient);
    };
}

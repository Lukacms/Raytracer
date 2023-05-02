/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** EntryPoint
*/

#pragma GCC diagnostic ignored "-Wreturn-type-c-linkage"

#include <AmbiantLight.hh>
#include <memory>
#include <raytracer/math/Point3D.hh>

extern "C" { // NOLINT

std::unique_ptr<light::ILight> light_entrypoint(math::Point3D &position,
                                                double coefficient) // NOLINT
{
    if (coefficient > 1 && coefficient < 0)
        throw;
    return std::make_unique<light::AmbientLight>(position, coefficient);
};
}

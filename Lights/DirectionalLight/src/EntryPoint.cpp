/*
** EPITECH PROJECT, 2023 ** RayTracer
** File description:
** EntryPoint
*/

#pragma GCC diagnostic ignored "-Wreturn-type-c-linkage"

#include <DirectionalLight.hh>
#include <memory>
#include <raytracer/math/Point3D.hh>
#include <raytracer/math/Vector3D.hh>

extern "C" { // NOLINT

std::unique_ptr<light::ILight> light_entrypoint(math::Vector3D &direction,
                                                const double &intensity) // NOLINT
{
    return std::make_unique<light::DirectionalLight>(direction, intensity);
};
}

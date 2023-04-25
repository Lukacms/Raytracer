/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** EntryPoint
*/

#include <raytracer/math/Vector3D.hh>
#include <raytracer/math/Point3D.hh>
#include <memory>
#include <DirectionalLight.hh>

extern "C" { // NOLINT

    std::unique_ptr<light::ILight> entry_point_light(math::Vector3D &direction) // NOLINT
    {
        return std::make_unique<light::DirectionalLight>(direction);
    };
}

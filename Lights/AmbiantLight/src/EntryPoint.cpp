/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** EntryPoint
*/

#pragma GCC diagnostic ignored "-Wreturn-type-c-linkage"

#include <AmbiantLight.hh>
#include <memory>

extern "C" { // NOLINT

std::unique_ptr<light::ILight> entry_point_light(math::Point3D position) // NOLINT
{
    return nullptr;
};
}

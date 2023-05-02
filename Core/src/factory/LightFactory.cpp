/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** LightFactory
*/

#include <array>
#include <dlfcn.h>
#include <iostream>
#include <raytracer/factory/LightFactory.hpp>
#include <string>
#include <vector>

static const std::vector<raytracer::LightHandler> HANDLER{
    {"ambient", AMBIENT_LIB.data(),
     [](const std::string &lib, njson &json) -> std::unique_ptr<light::ILight> {
         math::Point3D origin = json["origin"];
         double coefficient = json["coefficient"];
         return raytracer::LightFactory::create<std::unique_ptr<light::ILight>(
             const math::Point3D &, double)>(lib, origin, coefficient);
     }},
    {"diffuse", "",
     [](const std::string &lib, njson &json) -> std::unique_ptr<light::ILight> {
         double coefficient = json["coefficient"];
         return raytracer::LightFactory::create<std::unique_ptr<light::ILight>(double)>(
             lib, coefficient);
     }},
    {"directional", DIRECTIONAL_LIB.data(),
     [](const std::string &lib, njson &json) -> std::unique_ptr<light::ILight> {
         math::Vector3D direction = json["direction"];
         return raytracer::LightFactory::create<std::unique_ptr<light::ILight>(
             const math::Vector3D &)>(lib, direction);
     }},
    {"point", POINT_LIB.data(),
     [](const std::string &lib, njson &json) -> std::unique_ptr<light::ILight> {
         math::Point3D origin = json["origin"];
         return raytracer::LightFactory::create<std::unique_ptr<light::ILight>(
             const math::Point3D &)>(lib, origin);
     }},
};

// Methods

std::unique_ptr<light::ILight> raytracer::LightFactory::createLight(njson &json)
{
    std::string type = json["type"];

    for (const auto &light : HANDLER) {
        if (light.type == type)
            return light.handler(light.libpath, json);
    }
    std::cout << "type:\t" << type << "\n";
    throw LightFactory::FactoryException(ERROR_NOT_LIGHT.data());
}

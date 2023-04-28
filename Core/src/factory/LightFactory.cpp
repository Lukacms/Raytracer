/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** LightFactory
*/

#include <array>
#include <dlfcn.h>
#include <raytracer/factory/LightFactory.hpp>
#include <string>
#include <vector>

static const std::vector<raytracer::LightHandler> HANDLER{
    {"ambient", AMBIENT_LIB.data(),
     [](const std::string &lib, njson &json) -> std::unique_ptr<light::ILight> {
         math::Point3D origin = json["origin"];
         double coefficient = json["coefficient"];
         return raytracer::LightFactory::create(lib, origin, coefficient);
     }},
    {"diffuse", "",
     [](const std::string &lib, njson &json) -> std::unique_ptr<light::ILight> {
         double coefficient = json["coefficient"];
         return raytracer::LightFactory::create(lib, coefficient);
     }},
    {"directionnal", DIRECTIONAL_LIB.data(),
     [](const std::string &lib, njson &json) -> std::unique_ptr<light::ILight> {
         math::Vector3D direction = json["direction"];
         return raytracer::LightFactory::create(lib, direction);
     }},
    {"point", POINT_LIB.data(),
     [](const std::string &lib, njson &json) -> std::unique_ptr<light::ILight> {
         math::Point3D origin = json["origin"];
         return raytracer::LightFactory::create(lib, origin);
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
    throw LightFactory::FactoryException(ERROR_NOT_LIGHT.data());
}

/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** PrimitiveFactory
*/

#include <dlfcn.h>
#include <memory>
#include <raytracer/factory/AFactory.hh>
#include <raytracer/factory/PrimitiveFactory.hpp>
#include <raytracer/math/APrimitive.hh>
#include <raytracer/math/IPrimitive.hh>
#include <string>
#include <vector>

static const std::vector<raytracer::PrimitiveHandler> HANDLER{
    {"sphere", SPHERE_LIB.data(),
     [](const std::string &lib, njson &json) -> std::unique_ptr<math::IPrimitive> {
         math::Point3D origin = json["origin"];
         double radius = json["radius"];
         return raytracer::PrimitiveFactory::create(lib, origin, radius);
     }},
    {"plane", PLANE_LIB.data(),
     [](const std::string &lib, njson &json) -> std::unique_ptr<math::IPrimitive> {
         math::Point3D origin = json["origin"];
         math::Axis axis = json["axis"];
         return raytracer::PrimitiveFactory::create(lib, origin, axis);
     }},
};

// Methods
std::unique_ptr<math::IPrimitive> raytracer::PrimitiveFactory::createPrimitive(const njson &json)
{
    std::string type = json["type"];
    throw PrimitiveFactory::FactoryException(ERROR_NOT_PRIMITIVE.data());
}

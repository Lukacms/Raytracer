/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** PrimitiveFactory
*/

#include <dlfcn.h>
#include <iostream>
#include <memory>
#include <raytracer/factory/AFactory.hh>
#include <raytracer/factory/PrimitiveFactory.hpp>
#include <raytracer/math/APrimitive.hh>
#include <raytracer/math/IPrimitive.hh>
#include <string>
#include <tuple>
#include <vector>

static const std::vector<raytracer::PrimitiveHandler> HANDLER{
    {"sphere", SPHERE_LIB.data(),
     [](const std::string &lib, njson &json) -> std::unique_ptr<math::IPrimitive> {
         math::Point3D origin = json["origin"];
         double radius = json["radius"];
         raytracer::Color color = json["color"];
         std::unique_ptr<math::IPrimitive> prim =
             raytracer::PrimitiveFactory::create<std::unique_ptr<math::IPrimitive>(
                 const math::Point3D &, double)>(lib, origin, radius);
         prim->setColor(color.red, color.green, color.blue);
         return prim;
     }},
    {"plane", PLANE_LIB.data(),
     [](const std::string &lib, njson &json) -> std::unique_ptr<math::IPrimitive> {
         math::Point3D origin = json["origin"];
         math::Axis axis = json["axis"];
         raytracer::Color color = json["color"];
         std::unique_ptr<math::IPrimitive> prim =
             raytracer::PrimitiveFactory::create<std::unique_ptr<math::IPrimitive>(
                 const math::Point3D &, const math::Axis &)>(lib, origin, axis);
         prim->setColor(color.red, color.green, color.blue);
         return prim;
     }},
    {"moebius", MOEBIUS_LIB.data(),
     [](const std::string &lib, njson &json) -> std::unique_ptr<math::IPrimitive> {
         math::Point3D origin = json["origin"];
         double radius = json["radius"];
         raytracer::Color color = json["color"];
         return raytracer::PrimitiveFactory::create<std::unique_ptr<math::IPrimitive>(
             const math::Point3D &, double, const raytracer::Color &)>(lib, origin, radius, color);
     }},
};

// Methods
std::unique_ptr<math::IPrimitive> raytracer::PrimitiveFactory::createPrimitive(njson &json)
{
    std::string type = json["type"];

    for (const auto &prim : HANDLER) {
        if (prim.type == type)
            return prim.handler(prim.libpath, json);
    }
    throw PrimitiveFactory::FactoryException(ERROR_NOT_PRIMITIVE.data());
}

/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** PrimitiveFactory
*/

#include <dlfcn.h>
#include <iostream>
#include <memory>
#include <raytracer/RayTracer.hh>
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
         raytracer::Material material = json["material"];
         std::array<double, 3> angles = json["rotation"];
         std::unique_ptr<math::IPrimitive> prim =
             raytracer::PrimitiveFactory::create<std::unique_ptr<math::IPrimitive>(
                 const math::Point3D &, const double &, const raytracer::Material &)>(
                 lib, origin, radius, material);
         prim->translate(origin.getX(), origin.getY(), origin.getZ());

         //         for (size_t i{0}; i < prim->getTransform().size(); i++) {
         //             for (size_t y{0}; y < prim->getTransform()[i].size(); y++) {
         //                 std::cout << prim->getTransform()[i][y] << ' ';
         //             }
         //             std::cout << '\n';
         //         }
         //  prim->rotate_x(angles[0]);
         // prim->rotate_y(angles[1]);
         // prim->rotate_z(angles[2]);
         return prim;
     }},
    {"plane", PLANE_LIB.data(),
     [](const std::string &lib, njson &json) -> std::unique_ptr<math::IPrimitive> {
         math::Point3D origin = json["origin"];
         math::Axis axis = json["axis"];
         raytracer::Material material = json["material"];

         std::unique_ptr<math::IPrimitive> prim =
             raytracer::PrimitiveFactory::create<std::unique_ptr<math::IPrimitive>(
                 const math::Point3D &, const math::Axis &, const raytracer::Material &)>(
                 lib, origin, axis, material);
         return prim;
     }},
    {"moebius", MOEBIUS_LIB.data(),
     [](const std::string &lib, njson &json) -> std::unique_ptr<math::IPrimitive> {
         math::Point3D origin = json["origin"];
         double radius = json["radius"];
         raytracer::Material material = json["material"];

         return raytracer::PrimitiveFactory::create<std::unique_ptr<math::IPrimitive>(
             const math::Point3D &, double, const raytracer::Material &)>(lib, origin, radius,
                                                                          material);
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

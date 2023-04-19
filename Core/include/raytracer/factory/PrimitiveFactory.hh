/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** PrimitiveFactory
*/

#pragma once

#include <raytracer/factory/IFactory.hh>
#include <raytracer/math/IPrimitive.hh>
#include <raytracer/math/Point3D.hh>
#include <raytracer/math/APrimitive.hh>
#include <raytracer/factory/AFactory.hh>
#include <memory>

const std::string_view SPHERE_LIB = "./plugins/raytracer_sphere.so";
const std::string_view PLANE_LIB = "./plugins/raytracer_plane.so";
const std::string_view LOAD_METHOD = "entry_point_primitive";
const std::string_view ERROR_CANNOT_LOAD = "RayTracer: Unable to load library.";
const std::string_view ERROR_NOT_PRIMITIVE = "RayTracer: Not a primitive library.";

namespace RayTracer {
    class PrimitiveFactory : public AFactory {
        public:
            PrimitiveFactory() = default;
            PrimitiveFactory(const PrimitiveFactory&) = default;
            PrimitiveFactory(PrimitiveFactory &&) = default;
            ~PrimitiveFactory() = default;
    
            PrimitiveFactory &operator=(const PrimitiveFactory&) = default;
            PrimitiveFactory &operator=(PrimitiveFactory &&);

            static std::unique_ptr<Math::IPrimitive> createSphere(Math::Point3D &origin, double radius);
            static std::unique_ptr<Math::IPrimitive> createPlane(Math::Point3D &origin, Math::Axis axis);
        private:
    };
}

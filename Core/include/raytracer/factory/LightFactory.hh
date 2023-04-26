/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** LightFactory
*/

#pragma once

#include <memory>
#include <raytracer/ALight.hh>
#include <raytracer/factory/AFactory.hh>
#include <raytracer/math/IPrimitive.hh>
#include <raytracer/math/Point3D.hh>

const std::string_view AMBIANT_LIB = "./plugins/raytracer_ambiant_light.so";
const std::string_view POINT_LIB = "./plugins/raytracer_point_light.so";
const std::string_view DIRECTIONAL_LIB = "./plugins/raytracer_directional_light.so";
const std::string_view LOAD_LIGHT_METHOD = "entry_point_light";
const std::string_view ERROR_LIGHT_CANNOT_LOAD = "RayTracer: Unable to load library.";
const std::string_view ERROR_NOT_LIGHT = "RayTracer: Not a light library.";

namespace raytracer
{
    class LightFactory : public AFactory
    {
        public:
            LightFactory() = default;
            LightFactory(const LightFactory &) = default;
            LightFactory(LightFactory &&) = default;
            ~LightFactory() = default;

            LightFactory &operator=(const LightFactory &) = default;
            LightFactory &operator=(LightFactory &&);

            static std::unique_ptr<light::ILight> createAmbiant(math::Point3D &origin,
                                                                double coefficient);
            static std::unique_ptr<light::ILight> createDirectional(math::Vector3D &direction);
            static std::unique_ptr<light::ILight> createPoint(math::Point3D &origin);

        private:
    };
} // namespace raytracer
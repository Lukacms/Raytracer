/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** LightFactory
*/

#pragma once

#include <dlfcn.h>
#include <functional>
#include <iostream>
#include <memory>
#include <nlohmann/json.hpp>
#include <raytracer/ALight.hh>
#include <raytracer/ILight.hh>
#include <raytracer/factory/AFactory.hh>
#include <raytracer/math/IPrimitive.hh>
#include <raytracer/math/Point3D.hh>
#include <string>
#include <utility>

using njson = nlohmann::json;

constexpr std::string_view AMBIENT_LIB{"./plugins/raytracer_ambiant_light.so"};
constexpr std::string_view POINT_LIB{"./plugins/raytracer_point_light.so"};
constexpr std::string_view DIRECTIONAL_LIB = "./plugins/raytracer_directional_light.so";
constexpr std::string_view LOAD_LIGHT_METHOD{"entry_point_light"};
constexpr std::string_view ERROR_LIGHT_CANNOT_LOAD{"RayTracer: Unable to load library."};
constexpr std::string_view ERROR_NOT_LIGHT{"RayTracer: Not a light library."};

namespace raytracer
{
    struct LightHandler {
            std::string type;
            std::string libpath;
            std::function<std::unique_ptr<light::ILight>(const std::string &, njson &)> handler;
    };

    class LightFactory : public AFactory
    {
        public:
            LightFactory() = default;
            LightFactory(const LightFactory &) = default;
            LightFactory(LightFactory &&) = default;
            ~LightFactory() = default;

            LightFactory &operator=(const LightFactory &) = default;
            LightFactory &operator=(LightFactory &&);

            static std::unique_ptr<light::ILight> createLight(njson &json);

            template <typename TSignature, typename... TValues>
            static std::unique_ptr<light::ILight> create(const std::string &path, TValues... values)
            {
                std::unique_ptr<light::ILight> new_light;
                void *handle = nullptr;

                if (!(handle = dlopen(path.c_str(), RTLD_LAZY)))
                    throw raytracer::LightFactory::FactoryException(dlerror());
                auto *loader =
                    reinterpret_cast<TSignature *>(dlsym(handle, LOAD_LIGHT_METHOD.data()));
                if (!loader)
                    throw raytracer::LightFactory::FactoryException(ERROR_LIGHT_CANNOT_LOAD.data());
                if (!(new_light = loader(std::forward<TValues>(values)...)))
                    throw raytracer::LightFactory::FactoryException(ERROR_NOT_LIGHT.data());
                return new_light;
            }

        private:
    };
} // namespace raytracer

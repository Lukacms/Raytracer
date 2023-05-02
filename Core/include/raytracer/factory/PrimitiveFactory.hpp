/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** PrimitiveFactory
*/

#pragma once

#include <dlfcn.h>
#include <iostream>
#include <memory>
#include <nlohmann/json_fwd.hpp>
#include <raytracer/factory/AFactory.hh>
#include <raytracer/factory/IFactory.hh>
#include <raytracer/math/APrimitive.hh>
#include <raytracer/math/IPrimitive.hh>
#include <raytracer/math/Point3D.hh>
#include <string_view>

constexpr std::string_view SPHERE_LIB = "./plugins/raytracer_sphere.so";
constexpr std::string_view PLANE_LIB = "./plugins/raytracer_plane.so";
constexpr std::string_view MOEBIUS_LIB = "./plugins/raytracer_moebius.so";
constexpr std::string_view LOAD_PRIMITIVE_METHOD = "entry_point_primitive";
constexpr std::string_view ERROR_PRIMITIVE_CANNOT_LOAD = "RayTracer: Unable to load library.";
constexpr std::string_view ERROR_NOT_PRIMITIVE = "RayTracer: Not a primitive library.";

using njson = nlohmann::json;

namespace raytracer
{
    struct PrimitiveHandler {
            std::string type;
            std::string libpath;
            std::function<std::unique_ptr<math::IPrimitive>(const std::string &, njson &)> handler;
    };

    class PrimitiveFactory : public AFactory
    {
        public:
            PrimitiveFactory() = default;
            PrimitiveFactory(const PrimitiveFactory &) = default;
            PrimitiveFactory(PrimitiveFactory &&) = default;
            ~PrimitiveFactory() = default;

            PrimitiveFactory &operator=(const PrimitiveFactory &) = default;
            PrimitiveFactory &operator=(PrimitiveFactory &&) = default;

            static std::unique_ptr<math::IPrimitive> createPrimitive(njson &json);

            template <typename... T_values> static std::unique_ptr<math::IPrimitive>
            create(const std::string &path, std::tuple<T_values...> values)
            {
                std::unique_ptr<math::IPrimitive> new_primitive;
                void *handle = nullptr;

                if (!(handle = dlopen(path.c_str(), RTLD_LAZY)))
                    throw raytracer::PrimitiveFactory::FactoryException(dlerror());
                auto *loader =
                    reinterpret_cast<std::unique_ptr<math::IPrimitive> (*)(T_values && ...)>(
                        dlsym(handle, LOAD_PRIMITIVE_METHOD.data()));
                if (!loader)
                    throw raytracer::PrimitiveFactory::FactoryException(
                        ERROR_PRIMITIVE_CANNOT_LOAD.data());
                if (!(new_primitive =
                          loader(std::forward<T_values>(std::get<T_values>(values))...)))
                    throw raytracer::PrimitiveFactory::FactoryException(ERROR_NOT_PRIMITIVE.data());
                return new_primitive;
            }

        private:
    };
} // namespace raytracer

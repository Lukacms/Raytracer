/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** PrimitiveFactory
*/

#pragma once

#include <dlfcn.h>
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
constexpr std::string_view LOAD_PRIMITIVE_METHOD = "primitive_entrypoint";
constexpr std::string_view ERROR_PRIMITIVE_CANNOT_LOAD =
    "RayTracer: Unable to load primitive library.";
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

            template <typename TSignature, typename... TValues>
            static std::unique_ptr<math::IPrimitive> create(const std::string &path,
                                                            TValues... values)
            {
                std::unique_ptr<math::IPrimitive> new_primitive;
                void *handle = nullptr;

                if (!(handle = dlopen(path.c_str(), RTLD_LAZY)))
                    throw raytracer::PrimitiveFactory::FactoryException(dlerror());
                auto *loader =
                    reinterpret_cast<TSignature *>(dlsym(handle, LOAD_PRIMITIVE_METHOD.data()));
                if (!loader)
                    throw raytracer::PrimitiveFactory::FactoryException(
                        ERROR_PRIMITIVE_CANNOT_LOAD.data());
                if (!(new_primitive = loader(std::forward<TValues>(values)...)))
                    throw raytracer::PrimitiveFactory::FactoryException(ERROR_NOT_PRIMITIVE.data());
                return new_primitive;
            }

        private:
    };
} // namespace raytracer

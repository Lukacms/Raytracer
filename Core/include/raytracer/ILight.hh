/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** ILight
*/

#pragma once

#include <memory>
#include <raytracer/Ray.hh>
#include <raytracer/RayTracer.hh>
#include <raytracer/math/IPrimitive.hh>
#include <raytracer/math/Point3D.hh>
#include <vector>

namespace light
{
    class ILight
    {
        public:
            ILight() = default;
            ILight(const ILight &) = default;
            ILight(ILight &&) = default;
            virtual ~ILight() = default;

            ILight &operator=(const ILight &) = default;
            ILight &operator=(ILight &&) = default;

            virtual void setLightPosition(math::Point3D position) = 0;
            [[nodiscard]] virtual math::Point3D &getLightPosition() = 0;
            virtual Color lighten(HitInfos &infos, raytracer::Ray &view, Color color) = 0;
            virtual bool isShadowed(std::vector<std::unique_ptr<math::IPrimitive>> &primitives,
                                    std::unique_ptr<math::IPrimitive> &current,
                                    HitInfos &infos) = 0;
            virtual void setIntensity(double intensity) = 0;
    };
} // namespace light

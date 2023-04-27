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
#include <raytracer/math/Point3D.hh>

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
            virtual raytracer::Color lighten(raytracer::HitInfos &infos,
                                             raytracer::Color color) = 0;
    };
} // namespace light

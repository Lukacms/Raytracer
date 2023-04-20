/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** ILight
*/

#pragma once

#include <raytracer/math/Point3D.hh>

namespace Light
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

            virtual void setLightPosition(Math::Point3D position) = 0;
            [[nodiscard]] virtual Math::Point3D &getLightPosition() = 0;
    };
} // namespace Light

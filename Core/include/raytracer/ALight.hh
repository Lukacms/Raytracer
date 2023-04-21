/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** ALight
*/

#pragma once

#include <raytracer/ILight.hh>
#include <raytracer/math/Point3D.hh>

namespace light
{

    class ALight : public ILight
    {
        public:
            ALight() = default;
            ALight(math::Point3D position);
            ALight(const ALight &) = default;
            ALight(ALight &&) = default;
            ~ALight() override = default;

            ALight &operator=(const ALight &) = default;
            ALight &operator=(ALight &&) = default;

            void setLightPosition(math::Point3D position) final;
            [[nodiscard]] math::Point3D &getLightPosition() final;

        private:
            math::Point3D m_position{};
    };
} // namespace light

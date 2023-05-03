/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** ALight
*/

#pragma once

#include <nlohmann/json.hpp>
#include <raytracer/ILight.hh>
#include <raytracer/math/Point3D.hh>

using njson = nlohmann::json;

namespace light
{

    class ALight : public ILight
    {
        public:
            /* ctor / dtor */
            ALight() = default;
            ALight(math::Point3D position);
            ALight(const ALight &) = default;
            ALight(ALight &&) = default;
            ~ALight() override = default;

            /* operator overload */
            ALight &operator=(const ALight &) = default;
            ALight &operator=(ALight &&) = default;

            /* needed to load config */
            ALight(const njson &json);
            ALight &operator=(const njson &json);

            void setLightPosition(math::Point3D position) final;
            [[nodiscard]] math::Point3D &getLightPosition() final;
            void setIntensity(double intensity) final;

        protected:
            math::Point3D m_position{};
            double m_intensity = 1.0;
    };
} // namespace light

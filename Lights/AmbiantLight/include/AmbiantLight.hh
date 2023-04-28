/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** AmbiantLight
*/

#pragma once

#include "raytracer/math/Point3D.hh"
#include <raytracer/ALight.hh>
#include <raytracer/Ray.hh>
#include <raytracer/RayTracer.hh>

namespace light
{
    class AmbientLight : public ALight
    {
        public:
            AmbientLight() = default;
            AmbientLight(math::Point3D &position, double coefficient);
            AmbientLight(const AmbientLight &) = default;
            AmbientLight(AmbientLight &&) = default;
            ~AmbientLight() override = default;

            AmbientLight &operator=(const AmbientLight &) = default;
            AmbientLight &operator=(AmbientLight &&);

            Color lighten(HitInfos &infos, raytracer::Ray &view, Color color) final;
            bool isShadowed(std::vector<std::unique_ptr<math::IPrimitive>> &primitives,
                            std::unique_ptr<math::IPrimitive> &current, HitInfos &infos) final;

        private:
            double m_coefficient;
    };
} // namespace light

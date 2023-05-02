/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** AmbiantLight
*/

#pragma once

#include <raytracer/ALight.hh>
#include <raytracer/Ray.hh>
#include <raytracer/RayTracer.hh>
#include <raytracer/math/Point3D.hh>

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

            raytracer::Color lighten(raytracer::HitInfos &infos, raytracer::Ray &view,
                                     raytracer::Color color) final;
            bool isShadowed(std::vector<std::unique_ptr<math::IPrimitive>> &primitives,
                            std::unique_ptr<math::IPrimitive> &current,
                            raytracer::HitInfos &infos) final;

        private:
            double m_coefficient;
    };
} // namespace light

/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** AmbiantLight
*/

#pragma once

#include "raytracer/math/Vector3D.hh"
#include <raytracer/ALight.hh>
#include <raytracer/Ray.hh>
#include <raytracer/RayTracer.hh>
#include <raytracer/math/Point3D.hh>

namespace light
{
    class PointLight : public ALight
    {
        public:
            PointLight() = default;
            PointLight(math::Point3D &position);
            PointLight(const PointLight &) = default;
            PointLight(PointLight &&) = default;
            ~PointLight() override = default;

            PointLight &operator=(const PointLight &) = default;
            PointLight &operator=(PointLight &&);

            Color lighten(HitInfos &infos, raytracer::Ray &view, Color color) final;
            bool isShadowed(std::vector<std::unique_ptr<math::IPrimitive>> &primitives,
                            std::unique_ptr<math::IPrimitive> &current, HitInfos &infos) final;

        private:
            math::Vector3D getPhongSpecular(math::Vector3D &normal, math::Vector3D &camera_vector,
                                            math::Vector3D &light_vector);
    };
} // namespace light

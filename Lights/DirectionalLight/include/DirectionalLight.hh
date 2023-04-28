/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** DirectionalLight
*/

#pragma once

#include <raytracer/ALight.hh>
#include <raytracer/Ray.hh>
#include <raytracer/RayTracer.hh>
#include <raytracer/math/Point3D.hh>
#include <raytracer/math/Vector3D.hh>

namespace light
{
    class DirectionalLight : public ALight
    {
        public:
            DirectionalLight() = default;
            DirectionalLight(math::Vector3D &direction);
            DirectionalLight(const DirectionalLight &) = default;
            DirectionalLight(DirectionalLight &&) = default;
            ~DirectionalLight() override = default;

            DirectionalLight &operator=(const DirectionalLight &) = default;
            DirectionalLight &operator=(DirectionalLight &&);

            Color lighten(HitInfos &infos, Color color, math::Vector3D &ray) final;

        private:
            math::Vector3D m_direction;
    };
} // namespace light

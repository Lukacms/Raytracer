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

            Color lighten(HitInfos &infos, Color color, math::Vector3D &ray) final;

        private:
    };
} // namespace light

/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** AmbiantLight
*/

#pragma once

#include "raytracer/math/Point3D.hh"
#include <raytracer/Ray.hh>
#include <raytracer/RayTracer.hh>
#include <raytracer/ALight.hh>

namespace light
{
    class AmbientLight : public ALight
    {
        public:
            AmbientLight() = default;
            AmbientLight(math::Point3D &position);
            AmbientLight(const AmbientLight&) = default;
            AmbientLight(AmbientLight &&) = default;
            ~AmbientLight() override = default;

            AmbientLight &operator=(const AmbientLight &) = default;
            AmbientLight &operator=(AmbientLight &&);

            Color lighten(HitInfos &infos, Color color) final;
        private:
    };
} // namespace light

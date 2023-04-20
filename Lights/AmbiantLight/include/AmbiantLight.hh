/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** AmbiantLight
*/

#pragma once

#include <raytracer/ALight.hh>

namespace Light
{
    class AmbientLight : public ALight
    {
        public:
            AmbientLight() = default;
            AmbientLight(const AmbientLight &) = default;
            AmbientLight(AmbientLight &&) = default;
            ~AmbientLight() override = default;

            AmbientLight &operator=(const AmbientLight &) = default;
            AmbientLight &operator=(AmbientLight &&);

        private:
    };
} // namespace Light
/*
** EPITECH PROJECT, 2023
** include
** File description:
** Moebius
*/

#pragma once

#include <raytracer/Ray.hh>
#include <raytracer/RayTracer.hh>
#include <raytracer/math/APrimitive.hh>

namespace math
{
    class Moebius : public APrimitive
    {
        public:
            Moebius() = default;
            Moebius(Moebius const &to_copy) = default;
            ~Moebius() override = default;
            Moebius &operator=(Moebius const &to_copy) = default;
            Moebius(Moebius &&to_move) = default;
            Moebius &operator=(Moebius &&to_move) = default;

            bool hits(raytracer::Ray &ray, raytracer::HitInfos &infos) const final;

        private:
    };

} // namespace math

/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Plane
*/

#pragma once

#include <raytracer/Ray.hh>
#include <raytracer/math/APrimitive.hh>
#include <raytracer/math/Vector3D.hh>

namespace math
{
    class Plane : public APrimitive
    {
        public:
            Plane() = default;
            Plane(math::Point3D corigin, math::Axis axis);
            Plane(const Plane &) = default;
            Plane(Plane &&) = default;
            ~Plane() override = default;

            Plane &operator=(const Plane &) = default;
            Plane &operator=(Plane &&);

            bool hits(raytracer::Ray &ray) const final;

        private:
            math::Vector3D m_normal;
    };
} // namespace math

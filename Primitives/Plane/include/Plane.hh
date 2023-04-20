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

namespace Math
{
    class Plane : public APrimitive
    {
        public:
            Plane() = default;
            Plane(Math::Point3D corigin, Math::Axis axis);
            Plane(const Plane &) = default;
            Plane(Plane &&) = default;
            ~Plane() override = default;

            Plane &operator=(const Plane &) = default;
            Plane &operator=(Plane &&);

            bool hits(RayTracer::Ray &ray) const final;

        private:
            Math::Vector3D m_normal;
    };
} // namespace Math

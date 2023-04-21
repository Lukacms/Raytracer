/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Sphere
*/

#pragma once

#include <raytracer/Ray.hh>
#include <raytracer/math/APrimitive.hh>
#include <raytracer/math/Point3D.hh>

namespace math
{
    class Sphere : public APrimitive
    {
        public:
            Sphere() = default;
            Sphere(math::Point3D corigin, double cradius);
            Sphere(const Sphere &) = default;
            Sphere(Sphere &&) = default;
            ~Sphere() override = default;

            Sphere &operator=(const Sphere &) = default;
            Sphere &operator=(Sphere &&);

            [[nodiscard]] double get_radius() const;
            double set_radius(double radius);
            bool hits(raytracer::Ray &ray) const final;

        private:
            double m_radius;
    };
} // namespace math

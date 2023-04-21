/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** IPrimitive
*/

#pragma once

#include <raytracer/Ray.hh>
#include <raytracer/RayTracer.hh>

namespace math
{
    class IPrimitive
    {
        public:
            IPrimitive() = default;
            IPrimitive(const IPrimitive &) = default;
            IPrimitive(IPrimitive &&) = default;
            virtual ~IPrimitive() = default;

            IPrimitive &operator=(const IPrimitive &) = default;
            IPrimitive &operator=(IPrimitive &&) = default;

            virtual void rotate_x(double angle) = 0;
            virtual void rotate_y(double angle) = 0;
            virtual void rotate_z(double angle) = 0;
            virtual void translate(double t_x, double t_y, double t_z) = 0;
            virtual bool hits(raytracer::Ray &ray) const = 0;
            // virtual void scale(double t_x, double t_y, double t_z);
            [[nodiscard]] virtual Color getColor() const = 0;
            virtual void setColor(int red, int green, int blue) = 0;
    };
} // namespace math

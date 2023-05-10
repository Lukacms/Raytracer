/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Limited_Cylinder
*/

#pragma once

#include <raytracer/Ray.hh>
#include <raytracer/math/APrimitive.hh>
#include <raytracer/math/Point3D.hh>
#include <raytracer/math/Vector3D.hh>

namespace math
{
    class Limited_Cylinder : public APrimitive
    {
        public:
            Limited_Cylinder() = default;
            Limited_Cylinder(const math::Point3D &corigin, double cradius, double climite);
            Limited_Cylinder(const Limited_Cylinder &) = default;
            Limited_Cylinder(Limited_Cylinder &&) = default;
            ~Limited_Cylinder() override = default;

            Limited_Cylinder &operator=(const Limited_Cylinder &) = default;
            Limited_Cylinder &operator=(Limited_Cylinder &&);

            [[nodiscard]] double get_radius() const;
            double set_radius(double radius);
            [[nodiscard]] double get_limite() const;
            double set_limite(double limite);
            bool hits(raytracer::Ray &ray, raytracer::HitInfos &infos) const final;

        private:
            double m_radius;
            double m_limite;
    };
} // namespace math

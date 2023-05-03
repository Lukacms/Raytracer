/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Cylinder
*/

#pragma once

#include <raytracer/Ray.hh>
#include <raytracer/math/APrimitive.hh>
#include <raytracer/math/Point3D.hh>
#include <raytracer/math/Vector3D.hh>

namespace math
{
    class Cylinder : public APrimitive
    {
        public:
            Cylinder() = default;
            Cylinder(math::Point3D corigin, double cradius, double cheight, math::Vector3D caxe);
            Cylinder(const Cylinder &) = default;
            Cylinder(Cylinder &&) = default;
            ~Cylinder() override = default;

            Cylinder &operator=(const Cylinder &) = default;
            Cylinder &operator=(Cylinder &&);

            [[nodiscard]] double get_radius() const;
            double set_radius(double radius);
            [[nodiscard]] double get_height() const;
            double set_height(double height);
            [[nodiscard]] math::Vector3D get_axe() const;
            math::Vector3D set_axe(math::Vector3D axe);
            bool hits(raytracer::Ray &ray, raytracer::HitInfos &infos) const final;

        private:
            double m_radius;
            double m_height;
            math::Vector3D m_axe;
    };
} // namespace math

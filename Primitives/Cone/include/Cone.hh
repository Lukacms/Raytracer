/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Cone
*/

#pragma once

#include <raytracer/Ray.hh>
#include <raytracer/math/APrimitive.hh>
#include <raytracer/math/Point3D.hh>
#include <raytracer/math/Vector3D.hh>

namespace math
{
    class Cone : public APrimitive
    {
        public:
            Cone() = default;
            Cone(const math::Point3D &corigin, double cradius, double cheight);
            Cone(const Cone &) = default;
            Cone(Cone &&) = default;
            ~Cone() override = default;

            Cone &operator=(const Cone &) = default;
            Cone &operator=(Cone &&);

            [[nodiscard]] double get_radius() const;
            double set_radius(double radius);
            bool hits(raytracer::Ray &ray, raytracer::HitInfos &infos) const final;

        private:
            double m_radius;
            double m_height;
    };
} // namespace math

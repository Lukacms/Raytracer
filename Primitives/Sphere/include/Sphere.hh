/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Sphere
*/

#pragma once

#include <raytracer/classes/Ray.hh>
#include <raytracer/classes/APrimitive.hh>
#include <raytracer/classes/Point3D.hh>

namespace Math {
    class Sphere : public APrimitive {
        public:
            Sphere() = default;
            Sphere(Math::Point3D corigin, double cradius);
            Sphere(const Sphere&) = default;
            Sphere(Sphere &&) = default;
            ~Sphere() override = default;
    
            Sphere &operator=(const Sphere&) = default;
            Sphere &operator=(Sphere &&);

            [[nodiscard]] double get_radius() const;
            double set_radius(double radius);
            bool hits(RayTracer::Ray &ray) const;

        private:
            double m_radius;
    };
}
/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Plane
*/

#pragma once

#include <raytracer/classes/Vector3D.hh>
#include <raytracer/classes/APrimitive.hh>
#include <raytracer/classes/Ray.hh>

namespace Math {

    enum class Axis {
        X,
        Y,
        Z,
    };

    class Plane : public APrimitive {
        public:
            Plane() = default;
            Plane(Math::Point3D corigin, Math::Axis axis);
            Plane(const Plane&) = default;
            Plane(Plane &&) = default;
            ~Plane() override = default;

            Plane &operator=(const Plane&) = default;
            Plane &operator=(Plane &&);

            bool hits(RayTracer::Ray &ray) const;

        private:
            Math::Vector3D m_normal;
    };
}

/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Point3D
*/

#pragma once

#include <raytracer/math/Vector3D.hh>

namespace Math {

    class Point3D {
        public:
            Point3D() = default;
            Point3D(double c_x, double c_y, double c_z);
            Point3D(const Point3D&) = default;
            Point3D(Point3D &&) = default;
            ~Point3D() = default;
    
            Point3D &operator=(const Point3D&) = default;
            Point3D &operator=(Point3D &&) = default;
            Point3D &operator+=(Math::Vector3D &);
            Point3D &operator-=(Math::Vector3D &);
            Point3D operator+(Math::Vector3D &) const;
            Point3D operator-(Math::Vector3D &) const;

            [[nodiscard]] double get_x() const;
            [[nodiscard]] double get_y() const;
            [[nodiscard]] double get_z() const;

        private:
            double m_x = 0;
            double m_y = 0;
            double m_z = 0;
    };
}

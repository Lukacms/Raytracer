/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Vector3D
*/

#pragma once

namespace Math
{
    class Vector3D
    {
        public:
            Vector3D() = default;
            Vector3D(double c_x, double c_y, double c_z);
            Vector3D(const Vector3D &) = default;
            Vector3D(Vector3D &&) = default;
            ~Vector3D() = default;

            Vector3D &operator=(const Vector3D &) = default;
            Vector3D &operator=(Vector3D &&) = default;
            Vector3D &operator+=(Vector3D &vector);
            Vector3D &operator-=(Vector3D &vector);
            Vector3D &operator*=(Vector3D &vector);
            Vector3D &operator/=(Vector3D &vector);
            Vector3D &operator*=(double coefficient);
            Vector3D &operator/=(double coefficient);
            Vector3D operator+(const Vector3D &vector) const;
            Vector3D operator-(const Vector3D &vector) const;
            Vector3D operator*(const Vector3D &vector) const;
            Vector3D operator/(const Vector3D &vector) const;
            Vector3D operator*(double coefficient) const;
            Vector3D operator/(double coefficient) const;

            [[nodiscard]] double length() const;
            [[nodiscard]] double dot(const Vector3D &vector) const;
            [[nodiscard]] double getX() const;
            [[nodiscard]] double getY() const;
            [[nodiscard]] double getZ() const;

        private:
            double m_x = 0;
            double m_y = 0;
            double m_z = 0;
    };
} // namespace Math

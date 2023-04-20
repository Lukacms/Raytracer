/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Canva
*/

#pragma once

#include <raytracer/math/Point3D.hh>
#include <raytracer/math/Vector3D.hh>

namespace RayTracer
{
    class Canva
    {
        public:
            Canva() = default;
            Canva(Math::Point3D &origin);
            Canva(const Canva &) = default;
            Canva(Canva &&) = default;
            ~Canva() = default;

            Canva &operator=(const Canva &) = default;
            Canva &operator=(Canva &&) = default;

            [[nodiscard]] Math::Vector3D &getBottomSide();
            [[nodiscard]] Math::Vector3D &getLeftSide();
            [[nodiscard]] Math::Point3D &getOrigin();
            void setOrigin(Math::Point3D &origin);
            Math::Point3D pointAt(double canva_x, double canva_y);

        private:
            Math::Point3D m_origin{0, 0, 0};
            Math::Vector3D m_bottom_side{1, 0, 0};
            Math::Vector3D m_left_side{0, 1, 0};
    };
} // namespace RayTracer

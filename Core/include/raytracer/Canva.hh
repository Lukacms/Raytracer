/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Canva
*/

#pragma once

#include <nlohmann/json.hpp>
#include <raytracer/math/Point3D.hh>
#include <raytracer/math/Vector3D.hh>

using njson = nlohmann::json;

namespace raytracer
{
    class Canva
    {
        public:
            /* ctor / dtor */
            Canva() = default;
            Canva(math::Point3D &origin);
            Canva(const Canva &) = default;
            Canva(Canva &&) = default;
            ~Canva() = default;

            /* operator overload */
            Canva &operator=(const Canva &) = default;
            Canva &operator=(Canva &&) = default;

            /* needed to load config */
            Canva(const njson &json);
            Canva &operator=(const njson &json);

            [[nodiscard]] math::Vector3D &getBottomSide();
            [[nodiscard]] math::Vector3D &getLeftSide();
            [[nodiscard]] math::Point3D &getOrigin();
            void setOrigin(math::Point3D &origin);
            math::Point3D pointAt(double canva_x, double canva_y);

        private:
            math::Point3D m_origin{0, 0, 0};
            math::Vector3D m_bottom_side{1, 0, 0};
            math::Vector3D m_left_side{0, 1, 0};
    };
} // namespace raytracer

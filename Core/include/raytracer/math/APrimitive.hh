/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** APrimitive
*/

#pragma once

#include <nlohmann/json.hpp>
#include <raytracer/math/IPrimitive.hh>
#include <raytracer/math/Point3D.hh>

using njson = nlohmann::json;

namespace math
{

    enum MatrixIndex {
        MATRIX_0_0,
        MATRIX_0_1,
        MATRIX_0_2,
        MATRIX_0_3,
        MATRIX_1_0,
        MATRIX_1_1,
        MATRIX_1_2,
        MATRIX_1_3,
        MATRIX_2_0,
        MATRIX_2_1,
        MATRIX_2_2,
        MATRIX_2_3,
        MATRIX_3_0,
        MATRIX_3_1,
        MATRIX_3_2,
        MATRIX_3_3,
    };

    enum class Axis {
        X,
        Y,
        Z,
    };

    class APrimitive : public IPrimitive
    {
        public:
            /* ctor / dtor */
            APrimitive() = default;
            APrimitive(const APrimitive &) = default;
            APrimitive(APrimitive &&) = default;
            ~APrimitive() override = default;

            /* operator overload */
            APrimitive &operator=(const APrimitive &) = default;
            APrimitive &operator=(APrimitive &&) = default;

            /* needed to load config */
            APrimitive(const njson &json);
            APrimitive &operator=(const njson &json);

            /* methods */
            void rotate_x(double angle) final;
            void rotate_y(double angle) final;
            void rotate_z(double angle) final;
            void translate(double t_x, double t_y, double t_z) final;
            // void scale(double t_x, double t_y, double t_z) final;
            [[nodiscard]] raytracer::Color getColor() const final;
            void setColor(int red, int green, int blue) final;

        protected:
            math::Point3D m_origin{};
            raytracer::Color m_color{0, 0, 0};
    };
} // namespace math

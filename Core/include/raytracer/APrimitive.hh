/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** APrimitive
*/

#pragma once

#include <raytracer/IPrimitive.hh>
#include <raytracer/Point3D.hh>

namespace Math {

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

    class APrimitive : public IPrimitive {
        public:
            APrimitive() = default;
            APrimitive(const APrimitive&) = default;
            APrimitive(APrimitive &&) = default;
            ~APrimitive() override = default;
    
            APrimitive &operator=(const APrimitive&) = default;
            APrimitive &operator=(APrimitive &&);

            void rotate_x(double angle) final;
            void rotate_y(double angle) final;
            void rotate_z(double angle) final;
            void translate(double t_x, double t_y, double t_z) final;
            // void scale(double t_x, double t_y, double t_z) final;

        protected:
            Math::Point3D m_origin{};
    };
}

/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** IPrimitive
*/

#pragma once

namespace Math {
    class IPrimitive {
        public:
            IPrimitive() = default;
            IPrimitive(const IPrimitive&) = default;
            IPrimitive(IPrimitive &&) = default;
            virtual ~IPrimitive() = default;
    
            IPrimitive &operator=(const IPrimitive&) = default;
            IPrimitive &operator=(IPrimitive &&) = default;

            virtual void rotate_x(double angle) = 0;
            virtual void rotate_y(double angle) = 0;
            virtual void rotate_z(double angle) = 0;
            virtual void translate(double t_x, double t_y, double t_z) = 0;
            // virtual void scale(double t_x, double t_y, double t_z);
    };
}

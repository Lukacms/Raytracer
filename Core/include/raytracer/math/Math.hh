/*
** EPITECH PROJECT, 2023
** NewRayTracer
** File description:
** Math
*/

#pragma once

#include <raytracer/math/Point3D.hh>
#include <vector>

namespace math {
    std::vector<std::vector<double>> multiply_matrices(std::vector<std::vector<double>> matrix1, std::vector<std::vector<double>> matrix2);
    math::Point3D multiply_point_by_matrix(math::Point3D point, std::vector<std::vector<double>> matrix);
}

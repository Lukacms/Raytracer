/*
** EPITECH PROJECT, 2023
** NewRayTracer
** File description:
** Math
*/

#pragma once

#include <raytracer/math/Point3D.hh>
#include <vector>

namespace math
{
    std::vector<std::vector<double>> multiply_matrices(std::vector<std::vector<double>> &matrix1,
                                                       std::vector<std::vector<double>> &matrix2);
    math::Point3D multiply_point_by_matrix(math::Point3D &point,
                                           const std::vector<std::vector<double>> &matrix);
    math::Vector3D multiply_vector_by_matrix(math::Vector3D &vector,
                                             const std::vector<std::vector<double>> &matrix);
} // namespace math

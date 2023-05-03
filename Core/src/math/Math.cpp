/*
** EPITECH PROJECT, 2023
** NewRayTracer
** File description:
** Math
*/

#include "raytracer/math/Point3D.hh"
#include <cstddef>
#include <raytracer/math/Math.hh>

std::vector<std::vector<double>> math::multiply_matrices(std::vector<std::vector<double>> &matrix1,
                                                         std::vector<std::vector<double>> &matrix2)
{
    std::vector<std::vector<double>> result(4, std::vector<double>(4, 0.0));

    for (std::size_t i = 0; i < 4; i += 1) {
        for (std::size_t j = 0; j < 4; j += 1) {
            for (std::size_t k = 0; k < 4; k += 1) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return result;
}

math::Point3D math::multiply_point_by_matrix(math::Point3D &point,
                                       const std::vector<std::vector<double>> &matrix)
{
    std::vector<double> point_vector = {point.getX(), point.getY(), point.getZ(), 1.0};
    std::vector<double> result(4, 0);

    for (std::size_t i = 0; i < 4; i++) {
        for (std::size_t j = 0; j < 4; j++) {
            result[i] += point_vector[j] * matrix[j][i];
        }
    }
    for (std::size_t i = 0; i < 3; i++)
        result[i] /= result[3];
    return math::Point3D{result[0], result[1], result[2]};
}

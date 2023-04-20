/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** APrimitive
*/

#include <cmath>
#include <raytracer/math/APrimitive.hh>
#include <raytracer/math/Vector3D.hh>
#include <vector>

// Constructor & Destructor

// Methods

void Math::APrimitive::rotate_x(double angle)
{
    std::vector<double> matrix{1, 0,          0,          0, 0, cos(angle), -sin(angle), 0,
                               0, sin(angle), cos(angle), 0, 0, 0,          0,           1};
    double n_x = 0;
    double n_y = 0;
    double n_z = 0;

    n_x += this->m_origin.getX() * matrix[MATRIX_0_0] + this->m_origin.getY() * matrix[MATRIX_1_0] +
        this->m_origin.getZ() * matrix[MATRIX_2_0];
    n_y += this->m_origin.getX() * matrix[MATRIX_0_1] + this->m_origin.getY() * matrix[MATRIX_1_1] +
        this->m_origin.getZ() * matrix[MATRIX_2_1];
    n_z += this->m_origin.getX() * matrix[MATRIX_0_2] + this->m_origin.getY() * matrix[MATRIX_1_2] +
        this->m_origin.getZ() * matrix[MATRIX_2_2];
    this->m_origin = Math::Point3D{n_x, n_y, n_z};
}

void Math::APrimitive::rotate_y(double angle)
{
    std::vector<double> matrix{cos(angle),  0, sin(angle), 0, 0, 1, 0, 0,
                               -sin(angle), 0, cos(angle), 0, 0, 0, 0, 1};
    double n_x = 0;
    double n_y = 0;
    double n_z = 0;

    n_x += this->m_origin.getX() * matrix[MATRIX_0_0] + this->m_origin.getY() * matrix[MATRIX_1_0] +
        this->m_origin.getZ() * matrix[MATRIX_2_0];
    n_y += this->m_origin.getX() * matrix[MATRIX_0_1] + this->m_origin.getY() * matrix[MATRIX_1_1] +
        this->m_origin.getZ() * matrix[MATRIX_2_1];
    n_z += this->m_origin.getX() * matrix[MATRIX_0_2] + this->m_origin.getY() * matrix[MATRIX_1_2] +
        this->m_origin.getZ() * matrix[MATRIX_2_2];
    this->m_origin = Math::Point3D{n_x, n_y, n_z};
}

void Math::APrimitive::rotate_z(double angle)
{
    std::vector<double> matrix{cos(angle), -sin(angle), 0, 0, sin(angle), cos(angle), 0, 0,
                               0,          0,           1, 0, 0,          0,          0, 1};
    double n_x = 0;
    double n_y = 0;
    double n_z = 0;

    n_x += this->m_origin.getX() * matrix[MATRIX_0_0] + this->m_origin.getY() * matrix[MATRIX_1_0] +
        this->m_origin.getZ() * matrix[MATRIX_2_0];
    n_y += this->m_origin.getX() * matrix[MATRIX_0_1] + this->m_origin.getY() * matrix[MATRIX_1_1] +
        this->m_origin.getZ() * matrix[MATRIX_2_1];
    n_z += this->m_origin.getX() * matrix[MATRIX_0_2] + this->m_origin.getY() * matrix[MATRIX_1_2] +
        this->m_origin.getZ() * matrix[MATRIX_2_2];
    this->m_origin = Math::Point3D{n_x, n_y, n_z};
}

void Math::APrimitive::translate(double t_x, double t_y, double t_z)
{
    std::vector<double> matrix{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, t_x, t_y, t_z, 1};
    double n_x = 0;
    double n_y = 0;
    double n_z = 0;

    n_x += this->m_origin.getX() * matrix[MATRIX_0_0] + this->m_origin.getY() * matrix[MATRIX_1_0] +
        this->m_origin.getZ() * matrix[MATRIX_2_0] + 1 * matrix[MATRIX_3_0];
    n_y += this->m_origin.getX() * matrix[MATRIX_0_1] + this->m_origin.getY() * matrix[MATRIX_1_1] +
        this->m_origin.getZ() * matrix[MATRIX_2_1] + 1 * matrix[MATRIX_3_1];
    n_z += this->m_origin.getX() * matrix[MATRIX_0_2] + this->m_origin.getY() * matrix[MATRIX_1_2] +
        this->m_origin.getZ() * matrix[MATRIX_2_2] + 1 * matrix[MATRIX_3_2];
    this->m_origin = Math::Point3D{n_x, n_y, n_z};
}

// void Math::APrimitive::scale(double t_x, double t_y, double t_z)
// {

// }

Color Math::APrimitive::getColor() const
{
    return this->m_color;
}

void Math::APrimitive::setColor(int red, int green, int blue)
{
    this->m_color.red = red;
    this->m_color.green = green;
    this->m_color.blue = blue;
}

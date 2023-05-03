/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** APrimitive
*/

#include "raytracer/math/Math.hh"
#include <cmath>
#include <raytracer/math/APrimitive.hh>
#include <raytracer/math/Vector3D.hh>
#include <vector>

// Constructor & Destructor

/* njson config */
math::APrimitive::APrimitive(const njson &json)
{
    this->m_origin = json.at("origin");
    this->m_material.material_color = json.at("color");
}

math::APrimitive &math::APrimitive::operator=(const njson &json)
{
    this->m_origin = json.at("origin");
    this->m_material.material_color = json.at("color");
    return *this;
}

// Methods

void math::APrimitive::rotate_x(double angle)
{
    std::vector<std::vector<double>> matrix{{1, 0, 0, 0, 0},
                                            {cos(angle), -sin(angle), 0, 0},
                                            {sin(angle), cos(angle), 0},
                                            {0, 0, 0, 1}};

    this->m_transform = math::multiply_matrices(this->m_transform, matrix);
}

void math::APrimitive::rotate_y(double angle)
{
    std::vector<std::vector<double>> matrix{{cos(angle), 0, sin(angle), 0},
                                            {0, 1, 0, 0},
                                            {-sin(angle), 0, cos(angle), 0},
                                            {0, 0, 0, 1}};
    this->m_transform = math::multiply_matrices(this->m_transform, matrix);
}

void math::APrimitive::rotate_z(double angle)
{
    std::vector<std::vector<double>> matrix{{cos(angle), -sin(angle), 0, 0},
                                            {sin(angle), cos(angle), 0, 0},
                                            {0, 0, 1, 0},
                                            {0, 0, 0, 1}};
    this->m_transform = math::multiply_matrices(this->m_transform, matrix);
}

void math::APrimitive::translate(double t_x, double t_y, double t_z)
{
    std::vector<std::vector<double>> matrix{{1, 0, 0, 0},
                                            {0, 1, 0, 0},
                                            {0, 0, 1, 0},
                                            {t_x, t_y, t_z, 1}};
    this->m_transform = math::multiply_matrices(this->m_transform, matrix);
}

raytracer::Color math::APrimitive::getColor() const
{
    return this->m_material.material_color;
}

void math::APrimitive::setColor(int red, int green, int blue)
{
    this->m_material.material_color.red = red;
    this->m_material.material_color.green = green;
    this->m_material.material_color.blue = blue;
}

void math::APrimitive::setMaterial(raytracer::Material material)
{
    this->m_material = std::move(material);
}

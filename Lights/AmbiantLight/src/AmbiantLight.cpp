/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** AmbiantLight
*/

#include "raytracer/math/Vector3D.hh"
#include <AmbiantLight.hh>
#include <iostream>
#include <raytracer/Ray.hh>
#include <raytracer/math/Point3D.hh>

// Constructor & Destructor

light::AmbientLight::AmbientLight(math::Point3D &position, double coefficient)
{
    this->m_position = position;
    this->m_coefficient = coefficient;
}

// Methods

Color light::AmbientLight::lighten(HitInfos & /* infos */, Color color, math::Vector3D & /* ray */)
{
    color.red = static_cast<int>(color.red * this->m_coefficient);
    color.green = static_cast<int>(color.green * this->m_coefficient);
    color.blue = static_cast<int>(color.blue * this->m_coefficient);
    return color;
}

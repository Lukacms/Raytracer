/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** AmbiantLight
*/

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

Color light::AmbientLight::lighten(HitInfos & /* infos */, Color color)
{
    color.red *= static_cast<int>(this->m_coefficient);
    color.green *= static_cast<int>(this->m_coefficient);
    color.blue *= static_cast<int>(this->m_coefficient);
    return color;
}

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

Color light::AmbientLight::lighten(HitInfos &infos, raytracer::Ray &view, Color color)
{
    color.red *= this->m_coefficient;
    color.green *= this->m_coefficient;
    color.blue *= this->m_coefficient;
    return color;
}

bool light::AmbientLight::isShadowed(std::vector<std::unique_ptr<math::IPrimitive>> &primitives,
                                     std::unique_ptr<math::IPrimitive> &current, HitInfos &infos)
{
    return false;
}
/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** ALight
*/

#include <raytracer/ALight.hh>

// Constructor & Destructor

Light::ALight::ALight(Math::Point3D position)
{
    this->m_position = position;
}

// Methods

Math::Point3D &Light::ALight::getLightPosition()
{
    return this->m_position;
}

void Light::ALight::setLightPosition(Math::Point3D position)
{
    this->m_position = position;
}

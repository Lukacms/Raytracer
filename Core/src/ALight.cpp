/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** ALight
*/

#include <raytracer/ALight.hh>

// Constructor & Destructor

light::ALight::ALight(math::Point3D position)
{
    this->m_position = position;
}

/* njson config */
light::ALight::ALight(const njson &json)
{
    this->m_position = json.at("position");
}

light::ALight &light::ALight::operator=(const njson &json)
{
    this->m_position = json.at("position");
    return *this;
}

// Methods

math::Point3D &light::ALight::getLightPosition()
{
    return this->m_position;
}

void light::ALight::setLightPosition(math::Point3D position)
{
    this->m_position = position;
}

void light::ALight::setIntensity(double intensity)
{
    this->m_intensity = intensity;
}

/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** PointLight
*/

#include <PointLight.hh>
#include <iostream>
#include <raytracer/Ray.hh>
#include <raytracer/math/Point3D.hh>

// Constructor & Destructor

light::PointLight::PointLight(math::Point3D &position)
{
    this->m_position = position;
}

// Methods

Color light::PointLight::lighten(HitInfos &infos, Color color, math::Vector3D & /*ray*/)
{
    math::Vector3D light{this->m_position.getX() - infos.point.getX(),
                         this->m_position.getY() - infos.point.getY(),
                         this->m_position.getZ() - infos.point.getZ()};
    light /= light.length();
    double rho = light.dot(infos.normal);

    if (rho <= 0)
        return Color{0, 0, 0};
    color.red = static_cast<int>(color.red * rho);
    color.green = static_cast<int>(color.green * rho);
    color.blue = static_cast<int>(color.blue * rho);
    return color;
}

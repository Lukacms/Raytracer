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

light::AmbientLight::AmbientLight(math::Point3D &position)
{
    this->m_position = position;
}

// Methods

Color light::AmbientLight::lighten(HitInfos &infos, Color color)
{
    math::Vector3D light{this->m_position.getX() - infos.point.getX(),
                         this->m_position.getY() - infos.point.getY(),
                         this->m_position.getZ() - infos.point.getZ()};
    light /= light.length();
    double rho = light.dot(infos.normal);

    if (rho > 1)
        return color;
    if (rho <= 0)
        return Color{0, 0, 0};
    // if (rho > 0 && rho <= 1) {
        color.red *= rho;
        color.green *= rho;
        color.blue *= rho;
    // }
    return color;
}

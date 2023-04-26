/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** DirectionalLight
*/

#include <DirectionalLight.hh>
#include <iostream>
#include <raytracer/Ray.hh>
#include <raytracer/math/Point3D.hh>
#include <raytracer/math/Vector3D.hh>

// Constructor & Destructor

light::DirectionalLight::DirectionalLight(math::Vector3D &direction)
{
    this->m_direction = direction;
}

// Methods

Color light::DirectionalLight::lighten(HitInfos &infos, Color color)
{
    math::Vector3D tmp_vector = this->m_direction * -1;
    tmp_vector /= tmp_vector.length();
    double rho = tmp_vector.dot(infos.normal);

    if (rho < 0)
        return Color{0, 0, 0};
    color.red = static_cast<int>(color.red * rho);
    color.green = static_cast<int>(color.green * rho);
    color.blue = static_cast<int>(color.blue * rho);
    return color;
}

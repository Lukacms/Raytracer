/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** AmbiantLight
*/

#include <raytracer/math/Point3D.hh>
#include <raytracer/Ray.hh>
#include <AmbiantLight.hh>
#include <iostream>

// Constructor & Destructor

light::AmbientLight::AmbientLight(math::Point3D &position)
{
    this->m_position = position;
}

// Methods

Color light::AmbientLight::lighten(HitInfos &infos, Color color)
{
    math::Vector3D light{infos.point_on_primitive.getX() - this->m_position.getX(), infos.point_on_primitive.getY() - this->m_position.getY(), infos.point_on_primitive.getZ() - this->m_position.getZ()};
    double rho = infos.normal.dot(light);

    color.red *= rho;
    color.green *= rho;
    color.blue *= rho;
    return color;
}

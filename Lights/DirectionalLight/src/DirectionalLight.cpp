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

raytracer::Color light::DirectionalLight::lighten(raytracer::HitInfos &infos,
                                                  raytracer::Color color)
{
    math::Vector3D tmp_vector = this->m_direction * -1;
    tmp_vector /= tmp_vector.length();
    double rho = tmp_vector.dot(infos.normal);

    if (rho < 0)
        return raytracer::Color{0, 0, 0};
    color.red *= static_cast<int>(rho);
    color.green *= static_cast<int>(rho);
    color.blue *= static_cast<int>(rho);
    return color;
}

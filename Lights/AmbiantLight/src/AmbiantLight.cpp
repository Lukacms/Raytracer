/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** AmbiantLight
*/

#include "raytracer/math/Vector3D.hh"
#include <AmbiantLight.hh>
#include <raytracer/Ray.hh>
#include <raytracer/math/Point3D.hh>

// Constructor & Destructor

light::AmbientLight::AmbientLight(math::Point3D &position, double coefficient)
    : m_coefficient{coefficient}
{
    this->m_position = position;
}

// Methods

raytracer::Color light::AmbientLight::lighten(raytracer::HitInfos & /* infos */,
                                              raytracer::Ray & /* view */, raytracer::Color color)
{
    color.red = static_cast<int>(color.red * this->m_coefficient);
    color.green = static_cast<int>(color.green * this->m_coefficient);
    color.blue = static_cast<int>(color.blue * this->m_coefficient);
    return color;
}

bool light::AmbientLight::isShadowed(
    std::vector<std::unique_ptr<math::IPrimitive>> & /* primitives */,
    std::unique_ptr<math::IPrimitive> & /* current */, raytracer::HitInfos & /* infos */)
{
    return false;
}

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

light::DirectionalLight::DirectionalLight(math::Vector3D &direction, double intensity)
    : m_direction{direction}
{
    this->m_intensity = intensity;
}

// Methods

raytracer::Color light::DirectionalLight::lighten(raytracer::HitInfos &infos,
                                                  raytracer::Ray & /* view */,
                                                  raytracer::Color color)
{
    math::Vector3D tmp_vector = this->m_direction * -1;
    tmp_vector /= tmp_vector.length();
    double rho = tmp_vector.dot(infos.normal);

    if (rho < 0)
        return raytracer::Color{0, 0, 0};
    color.red = static_cast<int>(color.red * rho);
    color.green = static_cast<int>(color.green * rho);
    color.blue = static_cast<int>(color.blue * rho);
    return color;
}

bool light::DirectionalLight::isShadowed(std::vector<std::unique_ptr<math::IPrimitive>> &primitives,
                                         std::unique_ptr<math::IPrimitive> &current,
                                         raytracer::HitInfos &infos)
{
    math::Vector3D vector = this->m_direction * -1;
    math::Vector3D tmp;
    double scalaire1 = vector.dot(vector);
    double scalaire2;
    bool is_hit = false;
    raytracer::HitInfos info{};

    raytracer::Ray shadow_ray{infos.point, vector};
    for (auto &primitive : primitives) {
        is_hit = primitive->hits(shadow_ray, info);
        tmp = math::Vector3D{info.point.getX() - infos.point.getX(),
                             info.point.getY() - infos.point.getY(),
                             info.point.getZ() - infos.point.getZ()};
        scalaire2 = vector.dot(tmp);
        if (is_hit && primitive != current && (0 < scalaire2 && scalaire2 < scalaire1))
            return true;
    }
    return false;
}

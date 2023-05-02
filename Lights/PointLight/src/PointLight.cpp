/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** PointLight
*/

#include <PointLight.hh>
#include <cmath>
#include <fmt/core.h>
#include <iostream>
#include <memory>
#include <raytracer/Ray.hh>
#include <raytracer/RayTracer.hh>
#include <raytracer/math/IPrimitive.hh>
#include <raytracer/math/Point3D.hh>
#include <raytracer/math/Vector3D.hh>
#include <vector>

// Constructor & Destructor

light::PointLight::PointLight(math::Point3D &position, double intensity)
{
    this->m_position = position;
    this->m_intensity = intensity;
}

// Methods

raytracer::Color light::PointLight::lighten(raytracer::HitInfos &infos, raytracer::Ray & view,
                                            raytracer::Color color)
{
    math::Vector3D light{this->m_position.getX() - infos.point.getX(),
                         this->m_position.getY() - infos.point.getY(),
                         this->m_position.getZ() - infos.point.getZ()};
    light /= light.length();
    math::Vector3D reflection =  infos.normal * 2 * infos.normal.dot(light) - light;
    math::Vector3D inversed_view = view.m_direction * -1;
    double rho = light.dot(infos.normal);
    double light_coefficient = 0.2;
    double specular = reflection.dot(inversed_view) / (reflection.length() * inversed_view.length());

    if (rho > 0)
        light_coefficient += this->m_intensity * rho;
    if (specular > 0 && specular < 1)
        light_coefficient += this->m_intensity * pow(specular, infos.specularity);
    color *= light_coefficient;
    if (color.red > 255)
        color.red = 255;
    if (color.green > 255)
        color.green = 255;
    if (color.blue > 255)
        color.blue = 255;
    return color;
}

bool light::PointLight::isShadowed(std::vector<std::unique_ptr<math::IPrimitive>> &primitives,
                                   std::unique_ptr<math::IPrimitive> &current,
                                   raytracer::HitInfos &infos)
{
    math::Vector3D vector = {this->m_position.getX() - infos.point.getX(),
                             this->m_position.getY() - infos.point.getY(),
                             this->m_position.getZ() - infos.point.getZ()};
    math::Vector3D tmp;
    raytracer::HitInfos info{};
    double scalaire1 = vector.dot(vector);
    double scalaire2;
    bool is_hit;

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

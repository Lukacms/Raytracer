/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** PointLight
*/

#include "raytracer/RayTracer.hh"
#include "raytracer/math/IPrimitive.hh"
#include "raytracer/math/Vector3D.hh"
#include <PointLight.hh>
#include <cmath>
#include <fmt/core.h>
#include <iostream>
#include <memory>
#include <raytracer/Ray.hh>
#include <raytracer/math/Point3D.hh>
#include <vector>

// Constructor & Destructor

light::PointLight::PointLight(math::Point3D &position)
{
    this->m_position = position;
}

// Methods

Color light::PointLight::lighten(HitInfos &infos, raytracer::Ray &view, Color color)
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
        light_coefficient += 0.6 * rho;
    if (specular > 0 && specular < 1)
        light_coefficient += 0.6 * pow(specular, 10);
    color.red *= light_coefficient;
    color.green *= light_coefficient;
    color.blue *= light_coefficient;
    if (color.red > 255)
        color.red = 255;
    if (color.green > 255)
        color.green = 255;
    if (color.blue > 255)
        color.blue = 255;
    return color;
}

bool light::PointLight::isShadowed(std::vector<std::unique_ptr<math::IPrimitive>> &primitives,
                                   std::unique_ptr<math::IPrimitive> &current, HitInfos &infos)
{
    math::Vector3D vector = {this->m_position.getX() - infos.point.getX(),
                             this->m_position.getY() - infos.point.getY(),
                             this->m_position.getZ() - infos.point.getZ()};
    math::Vector3D tmp;
    HitInfos info{};
    double scalaire1 = vector.dot(vector);
    double scalaire2;
    bool is_hit;

    raytracer::Ray shadow_ray{infos.point, vector};
    for (auto &primitive : primitives) {
        is_hit = primitive->hits(shadow_ray, info);
        tmp = {info.point.getX() - infos.point.getX(), info.point.getY() - infos.point.getY(),
               info.point.getZ() - infos.point.getZ()};
        scalaire2 = vector.dot(tmp);
        if (is_hit && primitive != current && (0 < scalaire2 && scalaire2 < scalaire1))
            return true;
    }
    return false;
}

math::Vector3D light::PointLight::getPhongSpecular(math::Vector3D &normal,
                                                   math::Vector3D &camera_vector,
                                                   math::Vector3D &light_vector)
{
    math::Vector3D cam_vector = (camera_vector / camera_vector.length()) * -1;
    math::Vector3D reflected_vector = (normal * (2 * light_vector.dot(normal))) - light_vector;

    if (reflected_vector.dot(cam_vector) > 0 && reflected_vector.dot(cam_vector) < 1) {
        fmt::print("Dot Product : {}\n", reflected_vector.dot(cam_vector));
        double specular = 255 * reflected_vector.dot(cam_vector) /
            (reflected_vector.length() * camera_vector.length());
        return math::Vector3D{specular, specular, specular};
    }
    return math::Vector3D{0, 0, 0};
}

/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** PointLight
*/

#include <PointLight.hh>
#include <cmath>
#include <iostream>
#include <memory>
#include <raytracer/Ray.hh>
#include <raytracer/RayTracer.hh>
#include <raytracer/math/IPrimitive.hh>
#include <raytracer/math/Point3D.hh>
#include <raytracer/math/Vector3D.hh>
#include <vector>

// Constructor & Destructor

light::PointLight::PointLight(math::Point3D &position)
{
    this->m_position = position;
}

// Methods

raytracer::Color light::PointLight::lighten(raytracer::HitInfos &infos, raytracer::Ray & /* view */,
                                            raytracer::Color color)
{
    math::Vector3D light{this->m_position.getX() - infos.point.getX(),
                         this->m_position.getY() - infos.point.getY(),
                         this->m_position.getZ() - infos.point.getZ()};
    light /= light.length();
    double rho = light.dot(infos.normal);
    // math::Vector3D specular = getPhongSpecular(infos.normal, view.m_direction, light);

    if (rho <= 0)
        return raytracer::Color{0, 0, 0};
    // fmt::print("Specular : {} {} {}\n", specular.getX(), specular.getY(), specular.getZ());
    // color.red = (color.red * rho) + specular.getX();
    // color.green = (color.green * rho) + specular.getY();
    // color.blue = (color.blue * rho) + specular.getZ();
    color.red = static_cast<int>(color.red * rho);
    color.green = static_cast<int>(color.green * rho);
    color.blue = static_cast<int>(color.blue * rho);
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

math::Vector3D light::PointLight::getPhongSpecular(math::Vector3D &normal,
                                                   math::Vector3D &camera_vector,
                                                   math::Vector3D &light_vector)
{
    math::Vector3D cam_vector = (camera_vector / camera_vector.length()) * -1;
    math::Vector3D reflected_vector = (normal * (2 * light_vector.dot(normal))) - light_vector;

    if (reflected_vector.dot(cam_vector) > 0 && reflected_vector.dot(cam_vector) < 1) {
        double specular = 255 * reflected_vector.dot(cam_vector) /
            (reflected_vector.length() * camera_vector.length());
        return math::Vector3D{specular, specular, specular};
    }
    return math::Vector3D{0, 0, 0};
}

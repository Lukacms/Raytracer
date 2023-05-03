/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Cylinder
*/

#include "raytracer/math/Point3D.hh"
#include <Cylinder.hh>
#include <cmath>
#include <raytracer/Ray.hh>
#include <raytracer/RayTracer.hh>
#include <raytracer/math/Vector3D.hh>

// Constructor & Destructor

math::Cylinder::Cylinder(math::Point3D corigin, double cradius, double cheight, math::Vector3D caxe) : m_radius{cradius}
{
    this->m_origin = corigin;
    this->m_height = cheight;
    this->m_axe = caxe;
}

// Methods

bool math::Cylinder::hits(raytracer::Ray &ray, raytracer::HitInfos &infos) const
{
    double value_a = pow(ray.m_direction.getX(), 2) +
    pow(ray.m_direction.getY(), 2) - pow(ray.m_direction.getZ(), 2);
    double value_b = 2 * ((ray.m_direction.getX() * (ray.m_origin.getX() - this->m_origin.getX())) +
    (ray.m_direction.getY() * (ray.m_origin.getY() - this->m_origin.getY())) -
    (ray.m_direction.getZ() * (ray.m_origin.getZ() - this->m_origin.getZ())));
    double value_c = pow(ray.m_origin.getX() - this->m_origin.getX(), 2) +
    pow(ray.m_origin.getY() - this->m_origin.getY(), 2) -
    pow(ray.m_origin.getZ() - this->m_origin.getZ(), 2) -
    pow(this->m_radius, 2);
    double delta = pow(value_b, 2) - 4 * value_a * value_c;

    if (delta > 0) {
        infos.is_solution = true;
        double x_1 = (-value_b - sqrt(delta)) / (2 * value_a);
        double x_2 = (-value_b + sqrt(delta)) / (2 * value_a);
        if (x_1 < x_2)
            infos.point = math::Point3D{ray.m_origin.getX() + x_1 * ray.m_direction.getX(),
                                        ray.m_origin.getY() + x_1 * ray.m_direction.getY(),
                                        ray.m_origin.getZ() + x_1 * ray.m_direction.getZ()};
        else
            infos.point = math::Point3D{ray.m_origin.getX() + x_2 * ray.m_direction.getX(),
                                        ray.m_origin.getY() + x_2 * ray.m_direction.getY(),
                                        ray.m_origin.getZ() + x_2 * ray.m_direction.getZ()};
        infos.normal = math::Vector3D{infos.point.getX() - this->m_origin.getX(),
                                      infos.point.getY() - this->m_origin.getY(),
                                      infos.point.getZ() - this->m_origin.getZ()};
    } else if (delta == 0.0) {
        infos.is_solution = true;
        double x_0 = (-value_b - sqrt(delta)) / (2 * value_a);
        infos.point = math::Point3D{ray.m_origin.getX() + x_0 * ray.m_direction.getX(),
                                    ray.m_origin.getY() + x_0 * ray.m_direction.getY(),
                                    ray.m_origin.getZ() + x_0 * ray.m_direction.getZ()};
        infos.normal = math::Vector3D{infos.point.getX() - this->m_origin.getX(),
                                      infos.point.getY() - this->m_origin.getY(),
                                      infos.point.getZ() - this->m_origin.getZ()};
    }
    return delta >= 0;
}

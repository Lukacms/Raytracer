/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Sphere
*/

#include <raytracer/Ray.hh>
#include <Sphere.hh>
#include <cmath>

// Constructor & Destructor

Math::Sphere::Sphere(Math::Point3D corigin, double cradius)
{
    this->m_origin = corigin;
    this->m_radius = cradius;
}

// Methods

bool Math::Sphere::hits(RayTracer::Ray &ray) const
{
    double value_a = pow(ray.m_direction.getX(), 2) + pow(ray.m_direction.getY(), 2) + pow(ray.m_direction.getZ(), 2);
    double value_b = 2 * (ray.m_origin.getX() * ray.m_direction.getX() + ray.m_origin.getY() * ray.m_direction.getY() + ray.m_origin.getZ() * ray.m_direction.getZ());
    // double b = 2 * (ray.m_origin.m_x * ray.m_direction.m_x + ray.m_origin.m_y * ray.m_direction.m_y + ray.m_origin.m_z * ray.m_direction.m_z) -
    //     (2 * (ray.m_direction.m_x * this->m_origin.m_x + ray.m_direction.m_y * this->m_origin.m_y + ray.m_direction.m_z * this->m_origin.m_z));
    double value_c = pow(ray.m_origin.getX(),2) + pow(ray.m_origin.getY(),2) + pow(ray.m_origin.getZ(),2) - pow(this->m_radius,2);
    // double c = (pow(ray.m_origin.m_x,2) + pow(ray.m_origin.m_y,2) + pow(ray.m_origin.m_z,2) - pow(this->m_radius,2) +
    //     ray.m_direction.m_x * this->m_origin.m_x + ray.m_direction.m_y * this->m_origin.m_y + ray.m_direction.m_z * this->m_origin.m_z);
    double value_d = pow(value_b, 2) - 4 * value_a * value_c;

    return value_d >= 0;
}

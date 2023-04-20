/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Sphere
*/

#include <Sphere.hh>
#include <cmath>
#include <raytracer/Ray.hh>

// Constructor & Destructor

Math::Sphere::Sphere(Math::Point3D corigin, double cradius)
{
    this->m_origin = corigin;
    this->m_radius = cradius;
}

// Methods

bool Math::Sphere::hits(RayTracer::Ray &ray) const
{
    double value_a = pow(ray.m_direction.getX(), 2) + pow(ray.m_direction.getY(), 2) +
        pow(ray.m_direction.getZ(), 2);
    double value_b = -2 * this->m_origin.getX() * ray.m_direction.getX() + 2 * ray.m_origin.getX() * ray.m_direction.getX()
                    - 2 * this->m_origin.getY() * ray.m_direction.getY() + 2 * ray.m_origin.getY() * ray.m_direction.getY()
                    - 2 * this->m_origin.getZ() * ray.m_direction.getZ() + 2 * ray.m_origin.getZ() * ray.m_direction.getZ();
    double value_c = pow(this->m_origin.getX(), 2) + pow(ray.m_origin.getX(), 2)
        + pow(this->m_origin.getY(), 2) + pow(ray.m_origin.getY(), 2)
        + pow(this->m_origin.getZ(), 2) + pow(ray.m_origin.getZ(), 2)
        -2 * this->m_origin.getX() * ray.m_origin.getX() - 2 * this->m_origin.getY() * ray.m_origin.getY() - 2 * this->m_origin.getZ() * ray.m_origin.getZ()
        - pow(this->m_radius, 2);
    double value_d = pow(value_b, 2) - 4 * value_a * value_c;

    return value_d >= 0;
}

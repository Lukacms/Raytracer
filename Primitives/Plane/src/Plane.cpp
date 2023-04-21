/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Plane
*/

#include <Plane.hh>
#include <raytracer/math/Vector3D.hh>

// Constructor & Destructor

math::Plane::Plane(math::Point3D corigin, math::Axis axis)
{
    this->m_origin = corigin;
    if (axis == math::Axis::X)
        this->m_normal = math::Vector3D{1, 0, 0};
    if (axis == math::Axis::Y)
        this->m_normal = math::Vector3D{0, 1, 0};
    if (axis == math::Axis::Z)
        this->m_normal = math::Vector3D{0, 0, 1};
}

// Methods

bool math::Plane::hits(raytracer::Ray &ray) const
{
    return (this->m_normal.dot(ray.m_direction) == 0);
}

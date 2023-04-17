/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Plane
*/

#include <raytracer/math/Vector3D.hh>
#include <Plane.hh>

// Constructor & Destructor

Math::Plane::Plane(Math::Point3D corigin, Math::Axis axis)
{
    this->m_origin = corigin;
    if (axis == Math::Axis::X)
        this->m_normal = Math::Vector3D{1, 0, 0};
    if (axis == Math::Axis::Y)
        this->m_normal = Math::Vector3D{0, 1, 0};
    if (axis == Math::Axis::Z)
        this->m_normal = Math::Vector3D{0, 0, 1};
}

// Methods

bool Math::Plane::hits(RayTracer::Ray &ray) const
{
    return (this->m_normal.dot(ray.m_direction) == 0);
}

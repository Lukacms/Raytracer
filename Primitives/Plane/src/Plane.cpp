/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Plane
*/

#include "raytracer/Ray.hh"
#include "raytracer/math/Point3D.hh"
#include <Plane.hh>
#include <fmt/core.h>
#include <memory>
#include <raytracer/RayTracer.hh>
#include <raytracer/math/Vector3D.hh>

// Constructor & Destructor

math::Plane::Plane(math::Point3D corigin, math::Axis axis)
{
    this->m_origin = corigin;
    if (axis == math::Axis::X)
        this->m_normal = math::Vector3D{1, 0, 0};
    if (axis == math::Axis::Y)
        this->m_normal = math::Vector3D{0, -1, 0};
    if (axis == math::Axis::Z)
        this->m_normal = math::Vector3D{0, 0, 1};
}

// Methods

bool math::Plane::hits(raytracer::Ray &ray, HitInfos &infos) const
{
    double value_d = -(this->m_normal.getX() * this->m_origin.getX() +
                       this->m_normal.getY() * this->m_origin.getY() + this->m_normal.getZ() +
                       this->m_origin.getZ());
    double value_a = (this->m_normal.getX() * ray.m_direction.getX() +
                      this->m_normal.getY() * ray.m_direction.getY() +
                      this->m_normal.getZ() * ray.m_direction.getZ());
    double value_b =
        (this->m_normal.getX() * ray.m_origin.getX() + this->m_normal.getY() * ray.m_origin.getY() +
         this->m_normal.getZ() * ray.m_origin.getZ()) - value_d;
    double solution = -value_b / value_a;

    if (this->m_normal.dot(ray.m_direction) == 0 || solution < 0)
        return false;
    infos.normal = this->m_normal;
    infos.point = Point3D{ray.m_origin.getX() + ray.m_direction.getX() * solution,
                          ray.m_origin.getY() + ray.m_direction.getY() * solution,
                          ray.m_origin.getZ() + ray.m_direction.getZ() * solution};
    return true;
}

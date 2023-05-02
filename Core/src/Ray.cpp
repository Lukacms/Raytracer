/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Ray
*/

#include <memory>
#include <raytracer/Ray.hh>

// Constructor & Destructor

raytracer::Ray::Ray(math::Point3D corigin, math::Vector3D cdirection)
{
    this->m_origin = corigin;
    this->m_direction = cdirection;
}

// Methods

[[nodiscard]] math::Point3D raytracer::Ray::get_origin() const
{
    return m_origin;
}

[[nodiscard]] math::Vector3D raytracer::Ray::get_direction() const
{
    return m_direction;
}

void raytracer::Ray::reflect_ray(const HitInfos &infos)
{
    math::Vector3D normalized_vector{infos.normal};

    normalized_vector /= normalized_vector.length();

    math::Vector3D new_direction{
        m_direction.getX() - m_direction.dot(normalized_vector) * normalized_vector.getX(),
        m_direction.getY() - m_direction.dot(normalized_vector) * normalized_vector.getY(),
        m_direction.getZ() - m_direction.dot(normalized_vector) * normalized_vector.getZ()};
    m_direction = new_direction;
    m_origin = infos.point;
}

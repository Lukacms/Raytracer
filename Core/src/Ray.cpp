/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Ray
*/

#include "raytracer/math/Math.hh"
#include <raytracer/Ray.hh>
#include <vector>

// Constructor & Destructor

raytracer::Ray::Ray(math::Point3D corigin, math::Vector3D cdirection)
{
    this->m_origin = corigin;
    this->m_direction = cdirection;
    m_direction_backup = cdirection;
    m_origin_backup = corigin;
}

// Methods

math::Point3D raytracer::Ray::get_origin() const
{
    return m_origin;
}

math::Vector3D raytracer::Ray::get_direction() const
{
    return m_direction;
}

void raytracer::Ray::transform(const std::vector<std::vector<double>> &matrix)
{
    //    m_origin = math::multiply_point_by_matrix(m_origin, matrix);
    //    m_direction = math::multiply_vector_by_matrix(m_direction, matrix);
}

void raytracer::Ray::reset()
{
    m_direction = m_direction_backup;
    m_origin = m_origin_backup;
}

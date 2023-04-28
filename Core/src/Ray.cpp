/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Ray
*/

#include <raytracer/Ray.hh>

// Constructor & Destructor

raytracer::Ray::Ray(math::Point3D corigin, math::Vector3D cdirection)
{
    this->m_origin = corigin;
    this->m_direction = cdirection;
}

// Methods

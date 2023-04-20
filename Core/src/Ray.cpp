/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Ray
*/

#include <raytracer/Ray.hh>

// Constructor & Destructor

RayTracer::Ray::Ray(Math::Point3D corigin, Math::Vector3D cdirection)
{
    this->m_origin = corigin;
    this->m_direction = cdirection;
}

// Methods

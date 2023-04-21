/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Camera
*/

#include <raytracer/Camera.hh>
#include <raytracer/Ray.hh>

// Constructor & Destructor

raytracer::Camera::Camera()
{
    math::Point3D point{-(1 / 2), -(1 / 2), 0};
    raytracer::Canva canva{};

    this->m_canva.setOrigin(point);
}

raytracer::Camera::Camera(math::Point3D &origin, raytracer::Canva &canva)
{
    this->m_origin = origin;
    this->m_canva = canva;
}

// Methods

raytracer::Ray raytracer::Camera::ray(double canva_x, double canva_y)
{
    math::Point3D new_point = this->m_canva.pointAt(canva_x, canva_y);
    double pos_x = new_point.getX() - this->m_origin.getX();
    double pos_y = new_point.getY() - this->m_origin.getY();
    double pos_z = new_point.getZ() - this->m_origin.getZ();

    return raytracer::Ray{new_point, math::Vector3D{pos_x, pos_y, pos_z}};
}

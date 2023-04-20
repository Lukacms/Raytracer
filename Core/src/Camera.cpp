/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Camera
*/

#include <raytracer/Camera.hh>
#include <raytracer/Ray.hh>

// Constructor & Destructor

RayTracer::Camera::Camera()
{
    Math::Point3D point{-(1 / 2), -(1 / 2), 0};
    RayTracer::Canva canva{};

    this->m_canva.setOrigin(point);
}

RayTracer::Camera::Camera(Math::Point3D &origin, RayTracer::Canva &canva)
{
    this->m_origin = origin;
    this->m_canva = canva;
}

// Methods

RayTracer::Ray RayTracer::Camera::ray(double canva_x, double canva_y)
{
    Math::Point3D new_point = this->m_canva.pointAt(canva_x, canva_y);
    double pos_x = new_point.getX() - this->m_origin.getX();
    double pos_y = new_point.getY() - this->m_origin.getY();
    double pos_z = new_point.getZ() - this->m_origin.getZ();

    return RayTracer::Ray{new_point, Math::Vector3D{pos_x, pos_y, pos_z}};
}

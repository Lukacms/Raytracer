/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Camera
*/

#include <nlohmann/json.hpp>
#include <raytracer/Camera.hh>
#include <raytracer/Ray.hh>
#include <raytracer/math/Point3D.hh>

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

/* constructor and operators with json */
raytracer::Camera::Camera(const njson &json)
{
    this->m_origin = json.at("origin");
    this->m_canva = json.at("canva");
}

raytracer::Camera &raytracer::Camera::operator=(const njson &json)
{
    this->m_origin = json.at("origin");
    this->m_canva = json.at("canva");
    return *this;
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

[[nodiscard]] math::Point3D raytracer::Camera::get_origin() const
{
    return m_origin;
}

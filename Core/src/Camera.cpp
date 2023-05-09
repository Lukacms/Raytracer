/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Camera
*/

#include "raytracer/math/Math.hh"
#include <iostream>
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
    this->m_backup = this->m_origin;
}

raytracer::Camera::Camera(math::Point3D &origin, raytracer::Canva &canva)
{
    this->m_origin = origin;
    this->m_backup = origin;
    this->m_canva = canva;
}

/* constructor and operators with json */
raytracer::Camera::Camera(const njson &json)
{
    this->m_origin = json.at("origin");
    this->m_backup = json.at("origin");
    this->m_canva = json.at("canva");
}

raytracer::Camera &raytracer::Camera::operator=(const njson &json)
{
    this->m_origin = json.at("origin");
    this->m_backup = json.at("origin");
    this->m_canva = json.at("canva");
    return *this;
}

// Methods

raytracer::Ray raytracer::Camera::ray(double canva_x, double canva_y)
{
    math::Point3D new_point = this->m_canva.pointAt(canva_x, canva_y);
    std::cout << "point at: ";
    std::cout << new_point.getX() << ' ';
    std::cout << new_point.getY() << ' ';
    std::cout << new_point.getZ() << '\n';
    double pos_x = new_point.getX() - this->m_origin.getX();
    double pos_y = new_point.getY() - this->m_origin.getY();
    double pos_z = new_point.getZ() - this->m_origin.getZ();
    std::cout << "direction: ";
    std::cout << pos_x << ' ';
    std::cout << pos_y << ' ';
    std::cout << pos_z << '\n';

    return raytracer::Ray{new_point, math::Vector3D{pos_x, pos_y, pos_z}};
}

[[nodiscard]] math::Point3D raytracer::Camera::get_origin() const
{
    return m_origin;
}

void raytracer::Camera::transform(const std::vector<std::vector<double>> &matrix)
{
    std::cout << "canva back trasnform :\n";
    std::cout << m_canva.getOrigin().getX() << ' ';
    std::cout << m_canva.getOrigin().getY() << ' ';
    std::cout << m_canva.getOrigin().getZ() << '\n';
    std::cout << "m_canva transform: \n";
    math::Point3D new_canva_point =
        math::multiply_point_by_matrix(this->m_canva.getOrigin(), matrix);

    std::cout << "m_origin transform: \n";
    math::Point3D test{math::multiply_point_by_matrix(this->m_origin, matrix)};
    this->m_origin = test;
    this->m_canva.setOrigin(new_canva_point);
    std::cout << "canva after trasnform :\n";
    std::cout << m_canva.getOrigin().getX() << ' ';
    std::cout << m_canva.getOrigin().getY() << ' ';
    std::cout << m_canva.getOrigin().getZ() << '\n';
}

void raytracer::Camera::reset()
{
    this->m_origin = this->m_backup;
    m_canva.reset();
}
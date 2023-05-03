/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Canva
*/

#include <iostream>
#include <raytracer/Canva.hh>
#include <raytracer/math/Point3D.hh>

// Contructor & Destructor

raytracer::Canva::Canva(math::Point3D &origin)
{
    this->m_origin = origin;
    this->m_backup = origin;
}

/* njson */
raytracer::Canva::Canva(const njson &json)
{
    this->m_origin = json.at("origin");
    this->m_backup = json.at("origin");
    this->m_bottom_side = json.at("bottom");
    this->m_left_side = json.at("left");
}

raytracer::Canva &raytracer::Canva::operator=(const njson &json)
{
    this->m_origin = json.at("origin");
    this->m_backup = json.at("origin");
    this->m_bottom_side = json.at("bottom");
    this->m_left_side = json.at("left");
    return *this;
}

// Methods

math::Vector3D &raytracer::Canva::getBottomSide()
{
    return this->m_bottom_side;
}

math::Vector3D &raytracer::Canva::getLeftSide()
{
    return this->m_left_side;
}

math::Point3D &raytracer::Canva::getOrigin()
{
    return this->m_origin;
}

void raytracer::Canva::setOrigin(math::Point3D &origin)
{
    this->m_origin = origin;
    this->m_backup = origin;
}

math::Point3D raytracer::Canva::pointAt(double canva_x, double canva_y)
{
    double x_pos = canva_x + (this->m_origin.getX() * this->m_bottom_side.getX());
    double y_pos = canva_y + (this->m_origin.getY() * this->m_left_side.getY());

    return math::Point3D{x_pos, y_pos, this->m_origin.getZ()};
}

void raytracer::Canva::reset()
{
    this->m_origin = this->m_backup;
}

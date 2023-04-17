/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Canva
*/

#include <raytracer/math/Point3D.hh>
#include <raytracer/Canva.hh>

// Contructor & Destructor

RayTracer::Canva::Canva(Math::Point3D &origin)
{
    this->m_origin = origin;
}

// Methods

Math::Vector3D &RayTracer::Canva::getBottomSide()
{
    return this->m_bottom_side;
}


Math::Vector3D &RayTracer::Canva::getLeftSide()
{
    return this->m_left_side;
}


Math::Point3D &RayTracer::Canva::getOrigin()
{
    return this->m_origin;
}

void RayTracer::Canva::setOrigin(Math::Point3D &origin)
{
    this->m_origin = origin;
}

Math::Point3D RayTracer::Canva::pointAt(double canva_x, double canva_y)
{
    double x_pos = this->m_origin.getX() + (canva_x * this->m_bottom_side.getX() * this->m_left_side.getX());
    double y_pos = this->m_origin.getY() + (canva_y * this->m_bottom_side.getY() * this->m_left_side.getY());

    return Math::Point3D{x_pos, y_pos, this->m_origin.getZ()};
}

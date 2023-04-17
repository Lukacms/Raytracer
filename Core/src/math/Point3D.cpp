/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Point3D
*/

#include <raytracer/math/Point3D.hh>
#include <raytracer/math/Vector3D.hh>

// Constructor & Destructor

Math::Point3D::Point3D(double c_x, double c_y, double c_z)
{
    this->m_x = c_x;
    this->m_y = c_y;
    this->m_z = c_z;
}

// Operators

Math::Point3D Math::Point3D::operator+(Math::Vector3D &vector) const
{
    return Math::Point3D{this->m_x + vector.get_x(), this->m_y + vector.get_y(), this->m_z + vector.get_z()};
}

Math::Point3D Math::Point3D::operator-(Math::Vector3D &vector) const
{
    return Math::Point3D{this->m_x + vector.get_x(), this->m_y + vector.get_y(), this->m_z + vector.get_z()};
}

Math::Point3D &Math::Point3D::operator+=(Math::Vector3D &vector)
{
    this->m_x += vector.get_x();
    this->m_y += vector.get_y();
    this->m_z += vector.get_z();
    return *this;
}

Math::Point3D &Math::Point3D::operator-=(Math::Vector3D &vector)
{
    this->m_x -= vector.get_x();
    this->m_y -= vector.get_y();
    this->m_z -= vector.get_z();
    return *this;
}

// Methods

double Math::Point3D::get_x() const
{
    return this->m_x;
}

double Math::Point3D::get_y() const
{
    return this->m_y;
}

double Math::Point3D::get_z() const
{
    return this->m_z;
}
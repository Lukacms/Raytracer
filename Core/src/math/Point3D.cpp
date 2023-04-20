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
    return Math::Point3D{this->m_x + vector.getX(), this->m_y + vector.getY(),
                         this->m_z + vector.getZ()};
}

Math::Point3D Math::Point3D::operator-(Math::Vector3D &vector) const
{
    return Math::Point3D{this->m_x + vector.getX(), this->m_y + vector.getY(),
                         this->m_z + vector.getZ()};
}

Math::Point3D &Math::Point3D::operator+=(Math::Vector3D &vector)
{
    this->m_x += vector.getX();
    this->m_y += vector.getY();
    this->m_z += vector.getZ();
    return *this;
}

Math::Point3D &Math::Point3D::operator-=(Math::Vector3D &vector)
{
    this->m_x -= vector.getX();
    this->m_y -= vector.getY();
    this->m_z -= vector.getZ();
    return *this;
}

// Methods

double Math::Point3D::getX() const
{
    return this->m_x;
}

double Math::Point3D::getY() const
{
    return this->m_y;
}

double Math::Point3D::getZ() const
{
    return this->m_z;
}
/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Vector3D
*/

#include <cmath>
#include <math.h>
#include <raytracer/math/Vector3D.hh>

// Constructor & Destructor

math::Vector3D::Vector3D(double c_x, double c_y, double c_z)
{
    this->m_x = c_x;
    this->m_y = c_y;
    this->m_z = c_z;
}

// Operators

math::Vector3D math::Vector3D::operator+(const math::Vector3D &vector) const
{
    return math::Vector3D{this->m_x + vector.getX(), this->m_y + vector.getY(),
                          this->m_z + vector.getZ()};
}

math::Vector3D &math::Vector3D::operator+=(math::Vector3D &vector)
{
    this->m_x += vector.getX();
    this->m_y += vector.getY();
    this->m_z += vector.getZ();
    return *this;
}

math::Vector3D math::Vector3D::operator-(const math::Vector3D &vector) const
{
    return math::Vector3D{this->m_x - vector.getX(), this->m_y - vector.getY(),
                          this->m_z - vector.getZ()};
}

math::Vector3D &math::Vector3D::operator-=(math::Vector3D &vector)
{
    this->m_x -= vector.getX();
    this->m_y -= vector.getY();
    this->m_z -= vector.getZ();
    return *this;
}

math::Vector3D math::Vector3D::operator*(const math::Vector3D &vector) const
{
    return math::Vector3D{this->m_x * vector.getX(), this->m_y * vector.getY(),
                          this->m_z * vector.getZ()};
}

math::Vector3D &math::Vector3D::operator*=(math::Vector3D &vector)
{
    this->m_x *= vector.getX();
    this->m_y *= vector.getY();
    this->m_z *= vector.getZ();
    return *this;
}

math::Vector3D math::Vector3D::operator/(const math::Vector3D &vector) const
{
    return math::Vector3D{this->m_x / vector.getX(), this->m_y / vector.getY(),
                          this->m_z / vector.getZ()};
}

math::Vector3D &math::Vector3D::operator/=(math::Vector3D &vector)
{
    this->m_x /= vector.getX();
    this->m_y /= vector.getY();
    this->m_z /= vector.getZ();
    return *this;
}

math::Vector3D math::Vector3D::operator*(double coefficient) const
{
    return math::Vector3D{this->m_x * coefficient, this->m_y * coefficient,
                          this->m_z * coefficient};
}

math::Vector3D &math::Vector3D::operator*=(double coefficient)
{
    this->m_x *= coefficient;
    this->m_y *= coefficient;
    this->m_z *= coefficient;
    return *this;
}

math::Vector3D math::Vector3D::operator/(double coefficient) const
{
    return math::Vector3D{this->m_x + coefficient, this->m_y + coefficient,
                          this->m_z + coefficient};
}

math::Vector3D &math::Vector3D::operator/=(double coefficient)
{
    this->m_x /= coefficient;
    this->m_y /= coefficient;
    this->m_z /= coefficient;
    return *this;
}

// Methods

double math::Vector3D::length() const
{
    return sqrt(this->dot(*this));
}

double math::Vector3D::dot(const math::Vector3D &vector) const
{
    return this->getX() * vector.getX() + this->getY() * vector.getY() +
        this->getZ() * vector.getZ();
}

double math::Vector3D::getX() const
{
    return this->m_x;
}

double math::Vector3D::getY() const
{
    return this->m_y;
}

double math::Vector3D::getZ() const
{
    return this->m_z;
}

/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Vector3D
*/

#include <raytracer/math/Vector3D.hh>
#include <cmath>


// Constructor & Destructor

Math::Vector3D::Vector3D(double c_x, double c_y, double c_z) {
    this->m_x = c_x;
    this->m_y = c_y;
    this->m_z = c_z;
}

// Operators

Math::Vector3D Math::Vector3D::operator+(const Math::Vector3D &vector) const
{
    return Math::Vector3D{this->m_x + vector.get_x(), this->m_y + vector.get_y(), this->m_z + vector.get_z()};
}

Math::Vector3D &Math::Vector3D::operator+=(Math::Vector3D &vector)
{
    this->m_x += vector.get_x();
    this->m_y += vector.get_y();
    this->m_z += vector.get_z();
    return *this;
}

Math::Vector3D Math::Vector3D::operator-(const Math::Vector3D &vector) const
{
    return Math::Vector3D{this->m_x - vector.get_x(), this->m_y - vector.get_y(), this->m_z - vector.get_z()};
}

Math::Vector3D &Math::Vector3D::operator-=(Math::Vector3D &vector)
{
    this->m_x -= vector.get_x();
    this->m_y -= vector.get_y();
    this->m_z -= vector.get_z();
    return *this;
}

Math::Vector3D Math::Vector3D::operator*(const Math::Vector3D &vector) const
{
    return Math::Vector3D{this->m_x * vector.get_x(), this->m_y * vector.get_y(), this->m_z * vector.get_z()};
}

Math::Vector3D &Math::Vector3D::operator*=(Math::Vector3D &vector)
{
    this->m_x *= vector.get_x();
    this->m_y *= vector.get_y();
    this->m_z *= vector.get_z();
    return *this;
}

Math::Vector3D Math::Vector3D::operator/(const Math::Vector3D &vector) const
{
    return Math::Vector3D{this->m_x / vector.get_x(), this->m_y / vector.get_y(), this->m_z / vector.get_z()};
}

Math::Vector3D &Math::Vector3D::operator/=(Math::Vector3D &vector)
{
    this->m_x /= vector.get_x();
    this->m_y /= vector.get_y();
    this->m_z /= vector.get_z();
    return *this;
}

Math::Vector3D Math::Vector3D::operator*(double coefficient) const
{
    return Math::Vector3D{this->m_x * coefficient, this->m_y + coefficient, this->m_z + coefficient};
}

Math::Vector3D &Math::Vector3D::operator*=(double coefficient)
{
    this->m_x *= coefficient;
    this->m_y *= coefficient;
    this->m_z *= coefficient;
    return *this;
}

Math::Vector3D Math::Vector3D::operator/(double coefficient) const 
{
    return Math::Vector3D{this->m_x + coefficient, this->m_y + coefficient, this->m_z + coefficient};
}

Math::Vector3D &Math::Vector3D::operator/=(double coefficient)
{
    this->m_x /= coefficient;
    this->m_y /= coefficient;
    this->m_z /= coefficient;
    return *this;
}

// Methods

double Math::Vector3D::length() const
{
    return sqrt(std::pow(m_x, 2) + std::pow(m_y, 2) + std::pow(m_z, 2));
}

double Math::Vector3D::dot(const Math::Vector3D &vector) const
{
    Math::Vector3D new_vector = *this + vector;
    return (1/2) * (std::pow(new_vector.length(), 2) - pow(this->length(), 2) - pow(vector.length(), 2));
}

double Math::Vector3D::get_x() const
{
    return this->m_x;
}

double Math::Vector3D::get_y() const
{
    return this->m_y;
}

double Math::Vector3D::get_z() const
{
    return this->m_z;
}

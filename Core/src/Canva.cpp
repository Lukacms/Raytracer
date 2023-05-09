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
    /*   std::cout << "canva init :\n";
       std::cout << m_backup.getX() << '\n';
       std::cout << m_backup.getY() << '\n';
       std::cout << m_backup.getZ() << '\n';*/
}

/* njson */
raytracer::Canva::Canva(const njson &json)
{
    this->m_origin = json.at("origin");
    this->m_backup = math::Point3D{m_origin.getX(), m_origin.getY(), m_origin.getZ()};
    this->m_bottom_side = json.at("bottom");
    this->m_left_side = json.at("left");
    /*
    std::cout << "canva init :\n";
    std::cout << m_backup.getX() << '\n';
    std::cout << m_backup.getY() << '\n';
    std::cout << m_backup.getZ() << '\n';*/
}

raytracer::Canva &raytracer::Canva::operator=(const njson &json)
{
    this->m_origin = json.at("origin");
    this->m_backup = math::Point3D{m_origin.getX(), m_origin.getY(), m_origin.getZ()};
    this->m_bottom_side = json.at("bottom");
    this->m_left_side = json.at("left");
    /*    std::cout << "canva init :\n";
        std::cout << m_backup.getX() << '\n';
        std::cout << m_backup.getY() << '\n';
        std::cout << m_backup.getZ() << '\n';*/
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
}

math::Point3D raytracer::Canva::pointAt(double canva_x, double canva_y)
{
    double x_pos = canva_x + (this->m_origin.getX() * this->m_bottom_side.getX());
    double y_pos = canva_y + (this->m_origin.getY() * this->m_left_side.getY());

    return math::Point3D{x_pos, y_pos, m_origin.getZ()};
}

void raytracer::Canva::reset()
{
    /*
    std::cout << "m_backup :\n";
    std::cout << m_backup.getX() << ' ';
    std::cout << m_backup.getY() << ' ';
    std::cout << m_backup.getZ() << '\n';*/
    this->m_origin = this->m_backup;
}

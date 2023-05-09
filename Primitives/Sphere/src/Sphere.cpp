/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Sphere
*/

#include <Sphere.hh>
#include <cmath>
#include <iostream>
#include <raytracer/Ray.hh>
#include <raytracer/RayTracer.hh>
#include <raytracer/math/Point3D.hh>
#include <raytracer/math/Vector3D.hh>

// Constructor & Destructor

math::Sphere::Sphere(math::Point3D corigin, double cradius, raytracer::Material material)
    : m_radius{cradius}
{
    this->m_origin = corigin;
    this->m_material = material;
}

// Methods

bool math::Sphere::hits(raytracer::Ray &ray, raytracer::HitInfos &infos) const
{
    /*    std::cout << "le points: ";
        std::cout << m_origin.getX() << ' ';
        std::cout << m_origin.getY() << ' ';
        std::cout << m_origin.getZ() << '\n';*/
    double value_a = ray.get_direction().getX() * ray.get_direction().getX() +
        ray.get_direction().getY() * ray.get_direction().getY() +
        ray.get_direction().getZ() * ray.get_direction().getZ();

    double value_b = 2 * ray.get_origin().getX() * ray.get_direction().getX() +
        2 * ray.get_origin().getY() * ray.get_direction().getY() +
        2 * ray.get_origin().getZ() * ray.get_direction().getZ();

    double value_c = std::pow(ray.get_origin().getX(), 2) + std::pow(ray.get_origin().getY(), 2) +
        std::pow(ray.get_origin().getZ(), 2) - std::pow(m_radius, 2);

    double delta = value_b * value_b - 4 * value_a * value_c;

    // std::cout << value_a << " " << value_b << " " << value_c << std::endl;

    std::cout << "delta: ";
    std::cout << delta << '\n';
    if (delta > 0) {
        // std::cout << "in\n";
        double x_1 = (-value_b - sqrt(delta)) / (2 * value_a);
        double x_2 = (-value_b + sqrt(delta)) / (2 * value_a);
        std::cout << "x_1: " << x_1 << '\n';
        std::cout << "x_2: " << x_2 << '\n';
        if (x_1 < 0 && x_2 < 0)
            return false;
        double min = std::min(std::max(x_1, -1.0), std::max(x_2, -1.0));
        std::cout << "min: ";
        std::cout << min << '\n';
        std::cout << "calcul: ";
        std::cout << ray.get_origin().getZ() << " + " << min << " * " << ray.get_direction().getZ()
                  << '\n';
        infos.point = math::Point3D{ray.get_origin().getX() + min * ray.get_direction().getX(),
                                    ray.get_origin().getY() + min * ray.get_direction().getY(),
                                    ray.get_origin().getZ() + min * ray.get_direction().getZ()};
        infos.normal = math::Vector3D{infos.point.getX() - this->m_origin.getX(),
                                      infos.point.getY() - this->m_origin.getY(),
                                      infos.point.getZ() - this->m_origin.getZ()};
        // std::cout << "Intersection at " << infos.point.getX() << " " << infos.point.getY() << " "
        //           << infos.point.getZ() << '\n';
    } else if (delta == 0.0) {
        double x_0 = (-value_b - sqrt(delta)) / (2 * value_a);
        infos.point = math::Point3D{ray.get_origin().getX() + x_0 * ray.get_direction().getX(),
                                    ray.get_origin().getY() + x_0 * ray.get_direction().getY(),
                                    ray.get_origin().getZ() + x_0 * ray.get_direction().getZ()};
        infos.normal = math::Vector3D{infos.point.getX() - this->m_origin.getX(),
                                      infos.point.getY() - this->m_origin.getY(),
                                      infos.point.getZ() - this->m_origin.getZ()};
    }
    math::Vector3D vector = {infos.point.getX() - ray.get_origin().getX(),
                             infos.point.getY() - ray.get_origin().getY(),
                             infos.point.getZ() - ray.get_origin().getZ()};
    infos.normal /= infos.normal.length();
    infos.specularity = this->m_material.specularity;
    // double scalaire1 = ray.get_direction().dot(ray.get_direction());
    // double scalaire2 = ray.get_direction().dot(vector);

    // if (0 > scalaire2 && scalaire2 < scalaire1)
    //     return false;
    return delta >= 0;
}

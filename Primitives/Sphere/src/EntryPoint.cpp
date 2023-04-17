/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** EntryPoint
*/

#include <raytracer/classes/Point3D.hh>
#include <Sphere.hh>
#include <memory>

extern "C" { // NOLINT

    std::unique_ptr<Math::Sphere> entry_point_primitive(Math::Point3D &origin, double radius) { // NOLINT

        std::unique_ptr<Math::Sphere> new_sphere = std::make_unique<Math::Sphere>(origin, radius);
        return new_sphere;
    }
}

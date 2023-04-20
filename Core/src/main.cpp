/*
** EPITECH PROJECT, 2023
** src
** File description:
** main
*/

#include <iostream>
#include <memory>
#include <raytracer/Camera.hh>
#include <raytracer/Canva.hh>
#include <raytracer/Ray.hh>
#include <raytracer/RayTracer.hh>
#include <raytracer/factory/PrimitiveFactory.hh>
#include <raytracer/math/IPrimitive.hh>
#include <raytracer/math/Point3D.hh>

// int main(int argc, const char *argv[])
// {
//     return SUCCESS;
// }

int main()
{
    Math::Point3D point1{0, 0, 0.1};
    Math::Point3D point2{0, 0, -1};
    Math::Point3D point3{-0.5, -0.5, 0};
    RayTracer::Canva canva{point3};
    // Set up camera
    RayTracer::Camera camera(point1, canva);

    // Set up sphere
    std::unique_ptr<Math::IPrimitive> sphere =
        RayTracer::PrimitiveFactory::createSphere(point2, 0.5);
    sphere->setColor(238, 130, 238);
    // Set up Cylinder
    // RayTracer::Cylinder cylinder(Math::Point3D(0, 0, 50), Math::Vector3D(0, 0, 1), 20, 10);
    // Set up image buffer
    // Ray trace
    std::cout << "P3\n1920 1080\n255\n";
    for (double y = 0.00092; y <= 1; y += 0.00092) {
        for (double x = 0.00052; x <= 1; x += 0.00052) {
            // Calculate ray for current pixel
            RayTracer::Ray ray = camera.ray(x, y);
            Color c = sphere->getColor();
            // Check for intersection with sphere
            // std::cout << "Ray number ? :" << ray.m_direction.getX() << " " <<
            // ray.m_direction.getY() << " " << ray.m_direction.getZ() << std::endl;
            if (sphere->hits(ray))
                std::cout << c.red << " " << c.green << " " << c.blue << std::endl;
            else
                std::cout << "173 216 230\n";
        }
    }
    return 0;
}

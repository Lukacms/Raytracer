/*
** EPITECH PROJECT, 2023
** src
** File description:
** main
*/

#include "raytracer/math/APrimitive.hh"
#include <fmt/core.h>
#include <iostream>
#include <memory>
#include <raytracer/Camera.hh>
#include <raytracer/Canva.hh>
#include <raytracer/ILight.hh>
#include <raytracer/Ray.hh>
#include <raytracer/RayTracer.hh>
#include <raytracer/factory/LightFactory.hh>
#include <raytracer/factory/PrimitiveFactory.hh>
#include <raytracer/math/IPrimitive.hh>
#include <raytracer/math/Point3D.hh>

// int main(int argc, const char *argv[])
// {
//     return SUCCESS;
// }

int main()
{
    math::Point3D point1{0, 0, 1};
    math::Point3D point2{0, 0, -1};
    math::Point3D point3{-0.5, -0.5, 0};
    math::Point3D point4{1, -1, 0};
    math::Vector3D vector{-1, 1, -1};
    raytracer::Canva canva{point3};
    // Set up camera
    raytracer::Camera camera(point1, canva);
    // Set up sphere
    std::unique_ptr<math::IPrimitive> sphere =
        raytracer::PrimitiveFactory::createSphere(point2, 0.5);
    // std::unique_ptr<light::ILight> light = raytracer::LightFactory::createPoint(point4);
    std::unique_ptr<light::ILight> light = raytracer::LightFactory::createDirectional(vector);
    sphere->setColor(220, 20, 60);
    HitInfos infos{};
    std::cout << "P3\n1600 1600\n255\n";
    for (double y = 0.000625; y <= 1; y += 0.000625) {
        for (double x = 0.000625; x <= 1; x += 0.000625) {
            // Calculate ray for current pixel
            raytracer::Ray ray = camera.ray(x, y);
            Color c1 = sphere->getColor();
            if (sphere->hits(ray, infos)) {
                c1 = light->lighten(infos, c1);
                fmt::print("{} {} {}\n", c1.red, c1.green, c1.blue);
            } else
                fmt::print("105 105 105\n");
        }
    }
    return 0;
}
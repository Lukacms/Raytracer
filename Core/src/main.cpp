/*
** EPITECH PROJECT, 2023
** src
** File description:
** main
*/

#include "raytracer/ILight.hh"
#include "raytracer/factory/LightFactory.hh"
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
    math::Point3D point1{0, 0, 1};
    math::Point3D point2{0, 0, -1};
    math::Point3D point3{-0.5, -0.5, 0};
    math::Point3D point4{2, 0, 1};
    raytracer::Canva canva{point3};
    // Set up camera
    raytracer::Camera camera(point1, canva);
    // Set up sphere
    std::unique_ptr<math::IPrimitive> sphere =
        raytracer::PrimitiveFactory::createSphere(point2, 0.5);
    std::unique_ptr<light::ILight> light = raytracer::LightFactory::createAmbiant(point4);
    sphere->setColor(238, 130, 238);
    HitInfos infos{};
    std::cout << "P3\n800 800\n255\n";
    for (double y = 0.00125; y <= 1; y += 0.00125) {
        for (double x = 0.00125; x <= 1; x += 0.00125) {
            // Calculate ray for current pixel
            raytracer::Ray ray = camera.ray(x, y);
            Color c = sphere->getColor();
            if (sphere->hits(ray, infos)) {
                c = light->lighten(infos, c);
                std::cout << c.red << " " << c.green << " " << c.blue << std::endl;
            } else
                std::cout << "173 216 230\n";
        }
    }
    return 0;
}

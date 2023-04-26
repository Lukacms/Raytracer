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
#include <raytracer/Core.hh>
#include <raytracer/Ray.hh>
#include <raytracer/RayTracer.hh>
#include <raytracer/factory/PrimitiveFactory.hh>
#include <raytracer/math/IPrimitive.hh>
#include <raytracer/math/Point3D.hh>

// int main(int argc, const char *argv[])
// {
//     return SUCCESS;
// }

/*
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
*/

int main()
{
    math::Point3D point1{0, 0, 1};
    math::Point3D point5{-2, 0, -3};
    math::Point3D point2{-0.5, 0, -2};
    math::Point3D point6{0, 0, -1};
    math::Point3D point3{-0.5, -0.5, 0};
    math::Point3D point4{2, 0, 1};
    raytracer::Canva canva{point3};
    // Set up camera
    raytracer::Camera camera(point1, canva);
    // Set up Core
    raytracer::Core core{camera};
    // Set up sphere
    std::unique_ptr<math::IPrimitive> sphere =
        raytracer::PrimitiveFactory::createSphere(point2, 0.5);
    sphere->setColor(0, 0, 255);
    std::unique_ptr<math::IPrimitive> sphere2 =
        raytracer::PrimitiveFactory::createSphere(point5, 0.5);
    sphere2->setColor(255, 0, 0);
    std::unique_ptr<math::IPrimitive> sphere3 =
        raytracer::PrimitiveFactory::createSphere(point6, 0.5);
    sphere3->setColor(0, 255, 0);
    std::unique_ptr<light::ILight> light = raytracer::LightFactory::createAmbiant(point4);
    core.add_object(std::move(sphere));
    core.add_object(std::move(sphere2));
    core.add_object(std::move(sphere3));
    core.add_lights(std::move(light));
    core.launch();
}

/*
** EPITECH PROJECT, 2023
** src
** File description:
** main
*/

#include <fmt/core.h>
#include <iostream>
#include <memory>
#include <raytracer/Core.hh>
#include <raytracer/RayTracer.hh>
#include <raytracer/config/ConfigFile.hh>
#include <raytracer/config/Scene.hh>
#include <raytracer/factory/LightFactory.hpp>
#include <raytracer/factory/PrimitiveFactory.hpp>

int main(int argc, const char *argv[])
{
    raytracer::Scene scene{};
    if (argc != 2) {
        std::cout << HELP_MSG;
        return FAILURE;
    }
    raytracer::ConfigFile config{argv[1]};
    try {
        scene = config.parse();
    } catch (raytracer::ConfigFile::ConfigException &e) {
        std::cout << HEADER_MSG << e.what() << "\n";
        return FAILURE;
    }
    raytracer::Raytracer core{scene.camera};
    core.add_object(std::move(scene.primitives[0]));
    core.add_object(std::move(scene.primitives[1]));
    core.add_object(std::move(scene.primitives[2]));
    core.add_lights(std::move(scene.lights[0]));
    core.launch();
    return SUCCESS;
}

/* int main()
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
} */

/*
int main()
{
    math::Point3D point1{0, 0, 1};
    math::Point3D point2{-0.5, 0, -1};
    math::Point3D point3{-0.5, -0.5, 0};
    math::Point3D point4{0, 0, 0};
    math::Point3D point5{0.5, 0, -1};
    math::Point3D point6{0.5, 0, -1};
    math::Point3D point7{0, -0.5, 0};
    math::Vector3D vector{-1, 0.5, -1};
    raytracer::Canva canva{point3};
    double const size = 0.5;
    // Set up camera
    raytracer::Camera camera(point1, canva);
    // Set up Core
    raytracer::Raytracer core{camera, raytracer::Resolution{4000, 4000}};
    /*    // Set up sphere
    //    std::unique_ptr<math::IPrimitive> plane =
    //        raytracer::PrimitiveFactory::createPlane(point7, math::Axis::Y);
    //    std::unique_ptr<math::IPrimitive> sphere =
    //        raytracer::PrimitiveFactory::createSphere(point2, 0.5);
    //   sphere->setColor(255, 0, 255);
        std::unique_ptr<math::IPrimitive> sphere2 =
            raytracer::PrimitiveFactory::createSphere(point5, 0.5);
        sphere2->setColor(255, 0, 0);
        //    std::unique_ptr<math::IPrimitive> sphere3 =
        //        raytracer::PrimitiveFactory::createSphere(point6, 0.5);
        //    sphere3->setColor(0, 255, 0);
        plane->setColor(255, 255, 0);
        // std::unique_ptr<light::ILight> light =
    raytracer::LightFactory::createDirectional(vector); std::unique_ptr<light::ILight> light =
    raytracer::LightFactory::createPoint(point4);
        // std::unique_ptr<light::ILight> light = raytracer::LightFactory::createAmbiant(point4, 1);
        core.add_object(std::move(sphere));
        core.add_object(std::move(sphere2));
        // core.add_object(std::move(sphere2));
        //   core.add_object(std::move(sphere3));
        core.add_object(std::move(plane));
        core.add_lights(std::move(light));
        core.launch();
    }
*/

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

/* int main(int argc, const char *argv[])
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
    core.add_lights(std::move(scene.lights[1]));
    core.launch();
    return SUCCESS;
} */

int main()
{
    math::Point3D point1{0, 0, 1};
    math::Point3D point2{0, 0, -1};
    math::Point3D point3{-0.5, -0.5, 0};
    math::Point3D point4{1, -1, 0};
    math::Vector3D vector{-1, 1, -1};
    raytracer::Canva canva{point3};
    double size = 6.0;
    // Set up camera
    raytracer::Camera camera(point1, canva);
    // Set up sphere
    std::unique_ptr<math::IPrimitive> sphere =
        raytracer::PrimitiveFactory::create(SPHERE_LIB.data(), std::forward_as_tuple(point2, size));
    // std::unique_ptr<light::ILight> light = raytracer::LightFactory::createPoint(point4);
    std::unique_ptr<light::ILight> light =
        raytracer::LightFactory::create(DIRECTIONAL_LIB.data(), vector);
    sphere->setColor(220, 20, 60);
    raytracer::HitInfos infos{};
    std::cout << "P3\n1600 1600\n255\n";
    std::cerr << "sphere:\n\tcolors:" << sphere->getColor().green << sphere->getColor().red
              << sphere->getColor().blue << "\n";
    for (double y = 0.000625; y <= 1; y += 0.000625) {
        for (double x = 0.000625; x <= 1; x += 0.000625) {
            // Calculate ray for current pixel
            raytracer::Ray ray = camera.ray(x, y);
            raytracer::Color c1 = sphere->getColor();
            if (sphere->hits(ray, infos)) {
                c1 = light->lighten(infos, ray, c1);
                fmt::print("{} {} {}\n", c1.red, c1.green, c1.blue);
            } else
                fmt::print("105 105 105\n");
        }
    }
    return 0;
}

/* int main()
{
    math::Point3D point1{0, 0, 1};
    math::Point3D point2{0, 0, -1};
    math::Point3D point3{-0.5, -0.5, 0};
    math::Point3D point4{10, -10, 10};
    math::Point3D point5{-2, 0, -3};
    math::Point3D point6{0.5, 0, -2};
    math::Point3D point7{0, -0.5, 0};
    math::Vector3D vector{-1, 0.5, -1};
    raytracer::Canva canva{point3};
    math::Axis axis = math::Axis::Y;
    double size = 0.5;
    // Set up camera
    raytracer::Camera camera(point1, canva);
    // Set up Core
    raytracer::Raytracer core{camera, raytracer::Resolution{800, 800}};
    // Set up sphere
    std::unique_ptr<math::IPrimitive> plane =
        raytracer::PrimitiveFactory::create(PLANE_LIB.data(), point7, axis);
    std::unique_ptr<math::IPrimitive> sphere =
        raytracer::PrimitiveFactory::create(SPHERE_LIB.data(), point2, size);
    sphere->setColor(255, 0, 255);
    // std::unique_ptr<math::IPrimitive> sphere2 =
    //     raytracer::PrimitiveFactory::createSphere(point5, 0.5);
    // sphere2->setColor(255, 0, 0);
    std::unique_ptr<math::IPrimitive> sphere3 =
        raytracer::PrimitiveFactory::create(SPHERE_LIB.data(), point6, size);
    sphere3->setColor(0, 255, 0);
    plane->setColor(255, 255, 0);
    // std::unique_ptr<light::ILight> light = raytracer::LightFactory::createDirectional(vector);
    std::unique_ptr<light::ILight> light =
        raytracer::LightFactory::create(POINT_LIB.data(), point4);
    // std::unique_ptr<light::ILight> light = raytracer::LightFactory::createAmbiant(point4, 1);
    core.add_object(std::move(sphere));
    // core.add_object(std::move(sphere2));
    core.add_object(std::move(sphere3));
    core.add_object(std::move(plane));
    core.add_lights(std::move(light));
    core.launch();
} */

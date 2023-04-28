/*
** EPITECH PROJECT, 2023
** src
** File description:
** Core
*/

#include "raytracer/PpmCreator.hh"
#include "raytracer/Ray.hh"
#include "raytracer/math/Point3D.hh"
#include <cmath>
#include <fmt/core.h>
#include <iostream>
#include <raytracer/Core.hh>
#include <utility>

raytracer::Core::Core(raytracer::Camera &camera, const raytracer::Resolution &res)
    : m_camera(camera), m_resolution(res)
{
    m_resolution.x = 1 / m_resolution.x;
    m_resolution.y = 1 / m_resolution.y;
}

void raytracer::Core::add_lights(std::unique_ptr<light::ILight> &&light)
{
    m_lights.push_back(std::move(light));
}

void raytracer::Core::add_object(std::unique_ptr<math::IPrimitive> &&object)
{
    m_objects.push_back(std::move(object));
}

static double get_length(math::Point3D first, math::Point3D second)
{
    return std::sqrt(std::pow(second.getX() - first.getX(), 2) +
                     std::pow(second.getY() - first.getY(), 2) +
                     std::pow(second.getZ() - first.getZ(), 2));
}

int raytracer::Core::get_closest(raytracer::Ray &ray)
{
    int index_closest{-1};
    int index{0};
    int incr{0};
    math::Point3D camera_origin = m_camera.get_origin();

    if (m_objects.empty())
        return 0;
    m_max_infos.point = math::Point3D{-1, -1, -1};
    for (auto &object : m_objects) {
        HitInfos infos{};
        if (object->hits(ray, infos)) {
            if (incr == 0) {
                m_max_infos = infos;
                incr++;
            }
            if (get_length(camera_origin, infos.point) <=
                get_length(camera_origin, m_max_infos.point)) {
                index_closest = index;
                m_max_infos = infos;
            }
        }
        index++;
    }
    return index_closest;
}

void raytracer::Core::launch()
{
    for (double y_axes = m_resolution.y; y_axes <= 1; y_axes += m_resolution.y) {
        for (double x_axes = m_resolution.x; x_axes <= 1; x_axes += m_resolution.x) {
            raytracer::Ray ray = m_camera.ray(x_axes, y_axes);
            int closest = get_closest(ray);
            m_result.emplace_back(Color{0, 0, 0});
            if (closest >= 0) {
                m_result[m_result.size() - 1] = m_objects[static_cast<size_t>(closest)]->getColor();
                m_result[m_result.size() - 1] =
                    m_lights[0]->lighten(m_max_infos, ray, m_result[m_result.size() - 1]);
                if (m_lights[0]->isShadowed(this->m_objects,
                                            m_objects[static_cast<size_t>(closest)], m_max_infos)) {
                    m_result[m_result.size() - 1].red *= 0.3;
                    m_result[m_result.size() - 1].blue *= 0.3;
                    m_result[m_result.size() - 1].green *= 0.3;
                }
            } else {
                m_result[m_result.size() - 1] = Color{52, 37, 47};
            }
        }
    }
    PpmCreator::create_ppm_file(m_result, m_resolution, "test.ppm");
}

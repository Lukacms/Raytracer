/*
** EPITECH PROJECT, 2023
** src
** File description:
** Core
*/

#include <cmath>
#include <iostream>
#include <raytracer/Core.hh>
#include <raytracer/PpmCreator.hh>
#include <raytracer/Ray.hh>
#include <raytracer/RayTracer.hh>
#include <raytracer/math/Point3D.hh>
#include <utility>

raytracer::Raytracer::Raytracer(raytracer::Camera &camera, const raytracer::Resolution &res)
    : m_camera(camera), m_resolution(res)
{
    m_resolution.x_value = 1.0 / res.x;
    m_resolution.y_value = 1.0 / res.y;
}

void raytracer::Raytracer::add_lights(std::unique_ptr<light::ILight> &&light)
{
    m_lights.push_back(std::move(light));
}

void raytracer::Raytracer::add_object(std::unique_ptr<math::IPrimitive> &&object)
{
    m_objects.push_back(std::move(object));
}

static double get_length(math::Point3D first, math::Point3D second)
{
    return std::sqrt(std::pow(second.getX() - first.getX(), 2) +
                     std::pow(second.getY() - first.getY(), 2) +
                     std::pow(second.getZ() - first.getZ(), 2));
}

int raytracer::Raytracer::get_closest(raytracer::Ray &ray)
{
    int index{0};
    int incr{0};
    math::Point3D camera_origin = m_camera.get_origin();
    int index_closest{-1};

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

void raytracer::Raytracer::shader_b_w()
{
    for (auto &result : m_result) {
        int median = (result.color.green + result.color.blue + result.color.red) / 3;
        result.color = Color{median, median, median};
    }
}

void raytracer::Raytracer::launch()
{

    for (int y_axes = 1; y_axes <= m_resolution.y; y_axes += 1) {
        for (int x_axes = 1; x_axes <= m_resolution.x; x_axes += 1) {
            raytracer::Ray ray = m_camera.ray(static_cast<double>(x_axes) * m_resolution.x_value,
                                              static_cast<double>(y_axes) * m_resolution.y_value);
            int closest = get_closest(ray);
            m_result.emplace_back();
            m_result[0].color = Color{0, 0, 0};
            m_result[0].infos = HitInfos{math::Point3D{}, math::Vector3D{}, 0};
            if (closest >= 0) {
                m_result[m_result.size() - 1].color =
                    m_objects[static_cast<size_t>(closest)]->getColor();
                m_result[m_result.size() - 1].color =
                    m_lights[0]->lighten(m_max_infos, ray, m_result[m_result.size() - 1].color);
                m_result[m_result.size() - 1].infos = m_max_infos;
                if (m_lights[0]->isShadowed(this->m_objects,
                                            m_objects[static_cast<size_t>(closest)], m_max_infos)) {
                    m_result[m_result.size() - 1].color.red =
                        static_cast<int>(m_result[m_result.size() - 1].color.red * 0.3);
                    m_result[m_result.size() - 1].color.green =
                        static_cast<int>(m_result[m_result.size() - 1].color.green * 0.3);
                    m_result[m_result.size() - 1].color.blue =
                        static_cast<int>(m_result[m_result.size() - 1].color.blue * 0.3);
                }
            } else {
                m_result[m_result.size() - 1].color = Color{0, 0, 0};
            }
        }
    }
    PpmCreator::create_ppm_file(m_result, m_resolution, "test.ppm");
}

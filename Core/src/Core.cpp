/*
** EPITECH PROJECT, 2023
** src
** File description:
** Core
*/

#include "raytracer/config/ArgsConfig.hh"
#include "raytracer/config/ConfigFile.hh"
#include "raytracer/display/Clock.hh"
#include "raytracer/display/Display.hh"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <raytracer/Core.hh>
#include <raytracer/PpmCreator.hh>
#include <raytracer/Ray.hh>
#include <raytracer/RayTracer.hh>
#include <raytracer/config/Scene.hh>
#include <raytracer/math/Point3D.hh>
#include <utility>

/* ctor / dtor */

raytracer::Raytracer::Raytracer(raytracer::Scene &pscene, const raytracer::Resolution &res)
    : m_resolution{res}
{
    for (auto &prim : pscene.primitives)
        scene.primitives.push_back(std::move(prim));
    for (auto &light : pscene.lights)
        scene.lights.push_back(std::move(light));
    scene.camera = std::move(pscene.camera);
    m_resolution.x_value = 1.0 / res.x;
    m_resolution.y_value = 1.0 / res.y;
}

raytracer::Raytracer::Raytracer(Infos pinfos, const raytracer::Resolution &res) : m_resolution{res}
{
    this->infos = std::move(pinfos);
    m_resolution.x_value = 1.0 / res.x;
    m_resolution.y_value = 1.0 / res.y;
}

/* overload operators */
raytracer::Raytracer &raytracer::Raytracer::operator=(raytracer::Scene &&update)
{
    for (auto &prim : update.primitives)
        scene.primitives.push_back(std::move(prim));
    for (auto &light : update.lights)
        scene.lights.push_back(std::move(light));
    scene.camera = std::move(update.camera);
    return *this;
}

/* methods */

void raytracer::Raytracer::add_lights(std::unique_ptr<light::ILight> &&light)
{
    scene.lights.push_back(std::move(light));
}

void raytracer::Raytracer::add_object(std::unique_ptr<math::IPrimitive> &&object)
{
    scene.primitives.push_back(std::move(object));
}

static double get_length(math::Point3D first, math::Point3D second)
{
    return std::sqrt(std::pow(second.getX() - first.getX(), 2) +
                     std::pow(second.getY() - first.getY(), 2) +
                     std::pow(second.getZ() - first.getZ(), 2));
}

int raytracer::Raytracer::get_closest(raytracer::Ray &ray)
{
    int index_closest{-1};
    int index{0};
    int incr{0};
    math::Point3D camera_origin = scene.camera.get_origin();

    if (scene.primitives.empty())
        return 0;
    m_max_infos.point = math::Point3D{-1, -1, -1};
    for (auto &object : scene.primitives) {
        HitInfos hinfos{};
        if (object->hits(ray, hinfos)) {
            if (incr == 0) {
                m_max_infos = hinfos;
                incr++;
            }
            if (get_length(camera_origin, hinfos.point) <=
                get_length(camera_origin, m_max_infos.point)) {
                index_closest = index;
                m_max_infos = hinfos;
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

void raytracer::Raytracer::render()
{
    for (int y_axes = 1; y_axes <= m_resolution.y; y_axes += 1) {
        for (int x_axes = 1; x_axes <= m_resolution.x; x_axes += 1) {
            raytracer::Ray ray =
                scene.camera.ray(static_cast<double>(x_axes) * m_resolution.x_value,
                                 static_cast<double>(y_axes) * m_resolution.y_value);
            int closest = get_closest(ray);
            m_result.emplace_back();
            m_result[0].color = Color{0, 0, 0};
            m_result[0].infos = HitInfos{math::Point3D{}, math::Vector3D{}, 0};
            if (closest >= 0) {
                m_result[m_result.size() - 1].color =
                    scene.primitives[static_cast<size_t>(closest)]->getColor();
                m_result[m_result.size() - 1].color =
                    scene.lights[0]->lighten(m_max_infos, ray, m_result[m_result.size() - 1].color);
                m_result[m_result.size() - 1].infos = m_max_infos;
                if (scene.lights[0]->isShadowed(scene.primitives,
                                                scene.primitives[static_cast<size_t>(closest)],
                                                m_max_infos)) {
                    m_result[m_result.size() - 1].color.red =
                        static_cast<int>(m_result[m_result.size() - 1].color.red * SHADOW_RENDER);
                    m_result[m_result.size() - 1].color.green =
                        static_cast<int>(m_result[m_result.size() - 1].color.green * SHADOW_RENDER);
                    m_result[m_result.size() - 1].color.blue =
                        static_cast<int>(m_result[m_result.size() - 1].color.blue * SHADOW_RENDER);
                }
            } else {
                m_result[m_result.size() - 1].color = Color{0, 0, 0};
            }
        }
    }
}

/* launch program from configuration */
void raytracer::Raytracer::launch()
{
    try {
        this->scene = raytracer::ConfigFile::parser(this->infos.input);
    } catch (ConfigFile::ConfigException &e) {
        throw e;
    }
    if (infos.type == DisplayType::PpmOutput)
        this->ppmOutput();
    else
        this->sfmlOutput();
}

/* display methods */
void raytracer::Raytracer::ppmOutput()
{
    this->render();
    PpmCreator::create_ppm_file(m_result, m_resolution, infos.output);
}

void raytracer::Raytracer::sfmlOutput()
{
    Display display{};
    Clock clock{};

    while (display.getEvents() != DisplayStatus::Stopped) {
        if (clock.getElapsedTimeInS() > CLOCK_UPDATE_TIME) {
            this->render();
            display.display(m_result);
            m_result.erase(m_result.begin(), m_result.end());
            clock.reset();
        }
    }
}

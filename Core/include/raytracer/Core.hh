/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Core
*/

#pragma once

#include "raytracer/RayTracer.hh"
#include "raytracer/config/Scene.hh"
#include <memory>
#include <raytracer/Camera.hh>
#include <raytracer/ILight.hh>
#include <raytracer/math/IPrimitive.hh>
#include <vector>

namespace raytracer
{
    constexpr raytracer::Resolution DEFAULT_RES{800, 800};

    class Raytracer
    {
        public:
            Raytracer() = delete;
            Raytracer(Raytracer const &to_copy) = delete;
            Raytracer(raytracer::Scene &scene, const raytracer::Resolution &res = DEFAULT_RES);
            Raytracer(Raytracer &&to_move) = default;
            Raytracer &operator=(Raytracer const &to_copy) = delete;
            Raytracer &operator=(Raytracer &&to_move) = default;
            ~Raytracer() = default;

            void launch();
            void add_lights(std::unique_ptr<light::ILight> &&light);
            void add_object(std::unique_ptr<math::IPrimitive> &&object);
            void shader_b_w();

        private:
            int get_closest(raytracer::Ray &ray);
            std::vector<std::unique_ptr<light::ILight>> m_lights{};
            std::vector<std::unique_ptr<math::IPrimitive>> m_objects{};
            raytracer::Camera m_camera{};
            Resolution m_resolution{};
            std::vector<Pixel> m_result{};
            HitInfos m_max_infos{};
    };
} // namespace raytracer

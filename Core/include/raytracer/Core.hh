/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Core
*/

#pragma once

#include <memory>
#include <raytracer/Camera.hh>
#include <raytracer/ILight.hh>
#include <raytracer/RayTracer.hh>
#include <raytracer/config/Scene.hh>
#include <raytracer/math/IPrimitive.hh>
#include <vector>

constexpr double SHADOW_RENDER{0.3};

namespace raytracer
{
    struct Resolution {
        public:
            int x{0};
            int y{0};
            double x_value{0.00};
            double y_value{0.00};
    };

    constexpr raytracer::Resolution DEFAULT_RES{800, 800};

    class Raytracer
    {
        public:
            Raytracer() = delete;
            Raytracer(Raytracer const &to_copy) = delete;
            Raytracer(raytracer::Scene &scene, const raytracer::Resolution &res = DEFAULT_RES);
            Raytracer(Raytracer &&to_move) = default;
            ~Raytracer() = default;

            // overload operator
            Raytracer &operator=(Raytracer const &to_copy) = delete;
            Raytracer &operator=(Raytracer &&to_move) = default;
            Raytracer &operator=(raytracer::Scene &&update);

            /* methods */
            void render();
            void launch();
            void displayLoop();
            void add_lights(std::unique_ptr<light::ILight> &&light);
            void add_object(std::unique_ptr<math::IPrimitive> &&object);
            void shader_b_w();

        private:
            /* attributes */
            std::vector<std::unique_ptr<light::ILight>> m_lights{};
            std::vector<std::unique_ptr<math::IPrimitive>> m_objects{};
            raytracer::Camera m_camera{};

            Resolution m_resolution{};
            std::vector<Pixel> m_result{};
            HitInfos m_max_infos{};

            // NOTE loading with options from argv
            std::string filepath{};

            /* methods */
            int get_closest(raytracer::Ray &ray);
    };
} // namespace raytracer

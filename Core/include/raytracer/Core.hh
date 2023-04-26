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
#include <raytracer/math/IPrimitive.hh>
#include <vector>

namespace raytracer
{
    struct Resolution {
            double x{0};
            double y{0};
    };

    constexpr raytracer::Resolution DEFAULT_RES{800, 800};

    class Core
    {
        public:
            Core(Core const &to_copy) = delete;
            Core() = delete;
            Core(raytracer::Camera &camera, const raytracer::Resolution &res = DEFAULT_RES);
            Core(Core &&to_move) = default;
            Core &operator=(Core const &to_copy) = delete;
            Core &operator=(Core &&to_move) = default;
            ~Core() = default;

            void launch();
            void add_lights(std::unique_ptr<light::ILight> &&light);
            void add_object(std::unique_ptr<math::IPrimitive> &&object);

        private:
            int get_closest(raytracer::Ray &ray);
            std::vector<std::unique_ptr<light::ILight>> m_lights{};
            std::vector<std::unique_ptr<math::IPrimitive>> m_objects{};
            raytracer::Camera m_camera{};
            Resolution m_resolution{};
            std::vector<Color> m_result{};
            HitInfos m_max_infos{};
    };
} // namespace raytracer

/*
** EPITECH PROJECT, 2023
** config
** File description:
** Scene
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
        public:
            int x{0};
            int y{0};
            double x_value{0.00};
            double y_value{0.00};

            Resolution &operator=(const njson &json);
    };

    /*
     * structure used in ConfigFile to return to Core after the file has been parsed
     * NOTE: may need to associate a few methods
     */
    struct Scene {
        public:
            raytracer::Camera camera{};
            std::vector<std::unique_ptr<light::ILight>> lights{};
            std::vector<std::unique_ptr<math::IPrimitive>> primitives{};
            Resolution res{};
    };
} // namespace raytracer

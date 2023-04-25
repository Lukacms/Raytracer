/*
** EPITECH PROJECT, 2023
** config
** File description:
** Scene
*/

#pragma once

#include <memory>
#include <raytracer/ILight.hh>
#include <raytracer/math/IPrimitive.hh>
#include <vector>

namespace raytracer
{
    /*
     * structure used in ConfigFile to return to Core after the file has been parsed
     * NOTE: may need to associate a few methods
     */
    struct Scene {
            std::vector<std::unique_ptr<light::ILight>> lights{};
            std::vector<std::unique_ptr<math::IPrimitive>> primitives{};
    };
} // namespace raytracer

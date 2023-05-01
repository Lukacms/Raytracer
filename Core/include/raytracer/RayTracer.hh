/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** raytracer
*/

#pragma once

#include <nlohmann/json.hpp>
#include <raytracer/math/Point3D.hh>
#include <raytracer/math/Vector3D.hh>
#include <string_view>

/* return codes */
constexpr int SUCCESS = 0;
constexpr int FAILURE = 84;

/* Help message */
constexpr std::string_view HELP_MSG{
    "USAGE: ./raytracer <SCENE_FILE>\n\tSCENE_FILE: scene configuration\n"};

/* to display first when printing error messages (or any) */
constexpr std::string_view HEADER_MSG{"Raytracer: "};

using njson = nlohmann::json;

namespace raytracer
{
    struct Color {
        public:
            /* ctor / dtor */
            Color() = default;
            Color(int pred, int pgreen, int pblue);
            Color(const Color &) = default;
            Color(Color &&) = default;
            ~Color() = default;

            /* overload operator */
            Color &operator=(const Color &) = default;
            Color &operator=(Color &&) = default;

            /* needed to load config */
            Color(const njson &json);
            Color &operator=(const njson &json);

            /* attributes */
            int red;
            int green;
            int blue;
    };

    struct HitInfos {
        public:
            /* attributes */
            bool is_solution;
            math::Point3D point;
            math::Vector3D normal;
    };
} // namespace raytracer

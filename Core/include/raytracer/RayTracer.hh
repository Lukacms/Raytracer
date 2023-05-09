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
constexpr std::string_view HELP_MSG{"USAGE: ./raytracer <SCENE_FILE> <DISPLAY>\n\tSCENE_FILE: "
                                    "scene configuration\nDISPLAY: -ppm <FILENAME> | -sfml"};

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
            Color &operator*=(double coefficient);

            /* needed to load config */
            Color(const njson &json);
            Color &operator=(const njson &json);

            /* attributes */
            int red;
            int green;
            int blue;
    };

    struct Material {
        public:
            /* Constructor & Destructor */
            Material() = default;
            Material(raytracer::Color color, double pspecular, double preflection);
            Material(const Material &) = default;
            Material(Material &&) = default;
            ~Material() = default;

            /* Overload operator */
            Material &operator=(const Material &) = default;
            Material &operator=(Material &&) = default;

            /* needed to load config */
            Material(const njson &json);
            Material &operator=(const njson &json);

            /* Attributes */
            double specularity;
            double reflection;
            Color material_color;
    };

    struct HitInfos {
        public:
            /* attributes */
            math::Point3D point;
            math::Vector3D normal;
            double specularity;
    };

    struct Pixel {
        public:
            /* attributes */
            Color color{};
            HitInfos infos{};
            math::Point3D coords{};
    };
} // namespace raytracer

/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** raytracer
*/

#pragma once

#include <raytracer/math/Point3D.hh>
#include <raytracer/math/Vector3D.hh>
#include <string_view>

/* return codes */
constexpr int SUCCESS = 0;
constexpr int FAILURE = 84;

/* to display first when printing error messages (or any) */
constexpr std::string_view HEADER_MSG{"Raytracer: "};

struct Color {
    public:
        int red;
        int green;
        int blue;
};

struct HitInfos {

        bool is_solution;
        math::Point3D point;
        math::Vector3D normal;
};

struct Pixel {
        Color color;
        HitInfos infos;
};

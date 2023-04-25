/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** raytracer
*/

#pragma once

#include <string_view>

/* return codes */
constexpr int SUCCESS = 0;
constexpr int FAILURE = 84;

/* to display first when printing error messages (or any) */
constexpr std::string_view HEADER_MSG{"Raytracer: "};

struct Color {
        int red;
        int green;
        int blue;
};

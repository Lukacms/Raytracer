/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** raytracer
*/

#pragma once

#include <raytracer/math/Vector3D.hh>
#include <raytracer/math/Point3D.hh>

constexpr int SUCCESS = 0;
constexpr int FAILURE = 84;

struct Color {
        int red;
        int green;
        int blue;
};

struct HitInfos {
    bool is_solution;
    math::Point3D point;
    math::Vector3D normal;
};

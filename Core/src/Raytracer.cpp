/*
** EPITECH PROJECT, 2023
** src
** File description:
** Raytracer
*/

#include <raytracer/RayTracer.hh>

/* ctor / dtor */
raytracer::Color::Color(int pred, int pgreen, int pblue) : red{pred}, green{pgreen}, blue{pblue} {}

/* njson config */
raytracer::Color::Color(const njson &json)
    : red{json["red"]}, green{json["green"]}, blue{json["blue"]}
{
}

raytracer::Color &raytracer::Color::operator=(const njson &json)
{
    this->red = json.at("red");
    this->green = json.at("green");
    this->blue = json.at("blue");
    return *this;
}

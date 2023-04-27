/*
** EPITECH PROJECT, 2023
** src
** File description:
** Raytracer
*/

#include <raytracer/RayTracer.hh>

/* njson config */
raytracer::Color::Color(const njson &json)
{
    this->red = json.at("red");
    this->green = json.at("green");
    this->blue = json.at("blue");
}

raytracer::Color &raytracer::Color::operator=(const njson &json)
{
    this->red = json.at("red");
    this->green = json.at("green");
    this->blue = json.at("blue");
    return *this;
}

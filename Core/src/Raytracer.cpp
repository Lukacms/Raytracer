/*
** EPITECH PROJECT, 2023
** src
** File description:
** Raytracer
*/

#include <iostream>
#include <raytracer/RayTracer.hh>

/* ctor / dtor */
raytracer::Color::Color(int pred, int pgreen, int pblue) : red{pred}, green{pgreen}, blue{pblue} {}

/* njson config */
raytracer::Color::Color(const njson &json) : red{json["r"]}, green{json["g"]}, blue{json["b"]} {}

raytracer::Color &raytracer::Color::operator=(const njson &json)
{
    this->red = json["r"];
    this->green = json["g"];
    this->blue = json["b"];
    std::cout << json << "\n";
    return *this;
}

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


raytracer::Material::Material(raytracer::Color color, double pspecular, double preflection)
{
    this->material_color.red = color.red;
    this->material_color.green = color.green;
    this->material_color.blue = color.blue;
    this->reflection = preflection;
    this->specularity = pspecular;
}

/* njson config */
raytracer::Color::Color(const njson &json) : red{json["r"]}, green{json["g"]}, blue{json["b"]} {}

raytracer::Color &raytracer::Color::operator=(const njson &json)
{
    this->red = json["r"];
    this->green = json["g"];
    this->blue = json["b"];
    return *this;
}

raytracer::Color &raytracer::Color::operator*=(double coefficient)
{
    this->red = static_cast<int>(this->red * coefficient);
    this->green = static_cast<int>(this->green * coefficient);
    this->blue = static_cast<int>(this->blue * coefficient);
    return *this;
}

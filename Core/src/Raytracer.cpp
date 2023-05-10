/*
** EPITECH PROJECT, 2023
** src
** File description:
** Raytracer
*/

#include <raytracer/RayTracer.hh>

/* ctor / dtor */
raytracer::Color::Color(int pred, int pgreen, int pblue) : red{pred}, green{pgreen}, blue{pblue} {}

raytracer::Material::Material(raytracer::Color pcolor, double pspecular, double preflection)
    : specularity{pspecular}, reflection{preflection}, material_color{pcolor}
{
}

/* njson config */

// Color
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

// Material
raytracer::Material::Material(const njson &json)
    : specularity{json["spec"]}, reflection{json["reflection"]}, material_color{json["color"]}
{
}

raytracer::Material &raytracer::Material::operator=(const njson &json)
{
    this->specularity = json["spec"];
    this->reflection = json["reflection"];
    this->material_color = json["color"];
    return *this;
}

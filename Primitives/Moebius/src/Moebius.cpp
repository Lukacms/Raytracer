/*
** EPITECH PROJECT, 2023
** src
** File description:
** Moebius
*/

#include <Moebius.hh>
#include <raytracer/Ray.hh>
#include <raytracer/RayTracer.hh>

/* ctor */

math::Moebius::Moebius(math::Point3D porigin, double pradius) : radius{std::move(pradius)}
{
    this->m_origin = std::move(porigin);
}

/* methods */

bool math::Moebius::hits(raytracer::Ray & /* ray */, raytracer::HitInfos & /* infos */) const
{
    return true;
}

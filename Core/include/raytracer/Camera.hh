/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Camera
*/

#pragma once

#include <raytracer/Canva.hh>
#include <raytracer/Ray.hh>
#include <raytracer/math/Point3D.hh>

namespace raytracer
{

    class Camera
    {
        public:
            Camera();
            Camera(math::Point3D &origin, raytracer::Canva &canva);
            Camera(const Camera &) = default;
            Camera(Camera &&) = default;
            ~Camera() = default;

            Camera &operator=(const Camera &) = default;
            Camera &operator=(Camera &&);

            raytracer::Ray ray(double canva_x, double canva_y);

        private:
            math::Point3D m_origin{0, 0, -1};
            raytracer::Canva m_canva{};
    };
} // namespace raytracer

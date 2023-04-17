/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Camera
*/

#pragma once

#include <raytracer/Ray.hh>
#include <raytracer/math/Point3D.hh>

namespace RayTracer {

    class Camera {
        public:
            Camera() = default;
            Camera(const Camera&) = default;
            Camera(Camera &&) = default;
            ~Camera() = default;
    
            Camera &operator=(const Camera&) = default;
            Camera &operator=(Camera &&);

            RayTracer::Ray ray(double canva_x, double canva_y);

        private:
            Math::Point3D m_origin{};
    };    
}
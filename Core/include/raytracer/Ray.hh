/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Ray
*/

#pragma once

#include <raytracer/math/Point3D.hh>
#include <raytracer/math/Vector3D.hh>

namespace RayTracer {
    class Ray {
        public:
            Ray() = default;
            Ray(Math::Point3D corigin, Math::Vector3D cdirection);
            Ray(const Ray&) = default;
            Ray(Ray &&) = default;
            ~Ray() = default;
    
            Ray &operator=(const Ray&) = default;
            Ray &operator=(Ray &&);

            Math::Point3D m_origin{};
            Math::Vector3D m_direction{};
    };
}

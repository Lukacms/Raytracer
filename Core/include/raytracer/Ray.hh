/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Ray
*/

#pragma once

#include <raytracer/math/Point3D.hh>
#include <raytracer/math/Vector3D.hh>

namespace raytracer
{

    class Ray
    {
        public:
            Ray() = default;
            Ray(math::Point3D corigin, math::Vector3D cdirection);
            Ray(const Ray &) = default;
            Ray(Ray &&) = default;
            ~Ray() = default;

            Ray &operator=(const Ray &) = default;
            Ray &operator=(Ray &&) = default;

            [[nodiscard]] math::Point3D get_origin() const;
            [[nodiscard]] math::Vector3D get_direction() const;
            void transform(const std::vector<std::vector<double>> &matrix);
            void reset();

        private:
            math::Point3D m_origin{};
            math::Vector3D m_direction{};
            math::Point3D m_origin_backup{};
            math::Vector3D m_direction_backup{};
    };
} // namespace raytracer

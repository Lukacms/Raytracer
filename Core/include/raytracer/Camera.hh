/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Camera
*/

#pragma once

#include <nlohmann/json.hpp>
#include <raytracer/Canva.hh>
#include <raytracer/Ray.hh>
#include <raytracer/math/Point3D.hh>
#include <vector>

using njson = nlohmann::json;

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
            Camera &operator=(Camera &&) = default;

            /* constructor and operators with json */
            Camera(const njson &json);
            Camera &operator=(const njson &json);

            raytracer::Ray ray(double canva_x, double canva_y);
            void transform(std::vector<std::vector<double>> &matrix);
            void reset();
            [[nodiscard]] math::Point3D get_origin() const;

        private:
            math::Point3D m_origin{0, 0, -1};
            math::Point3D m_backup{};
            raytracer::Canva m_canva{};
    };
} // namespace raytracer

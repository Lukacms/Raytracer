/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PpmCreator
*/

#pragma once

#include "raytracer/Core.hh"
#include "raytracer/RayTracer.hh"
#include <string>
#include <vector>

class PpmCreator
{
    public:
        PpmCreator() = delete;
        PpmCreator(PpmCreator const &to_copy) = delete;
        PpmCreator(PpmCreator &&to_move) = delete;
        ~PpmCreator() = default;
        PpmCreator &operator=(PpmCreator const &to_copy) = delete;
        PpmCreator &operator=(PpmCreator &&to_move) = delete;
        static void create_ppm_file(std::vector<Pixel> result, raytracer::Resolution res,
                                    std::string filename);

    private:
        std::vector<Pixel> m_result;
        raytracer::Resolution m_res;
        std::string m_name{"output.ppm"};

        PpmCreator(std::vector<Pixel> &result, raytracer::Resolution &res,
                   std::string &filename) noexcept;

        void create_ppm();
};

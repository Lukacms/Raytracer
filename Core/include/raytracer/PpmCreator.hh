/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PpmCreator
*/

#pragma once

#include <raytracer/Core.hh>
#include <raytracer/RayTracer.hh>
#include <string>
#include <vector>

constexpr std::string_view INVALID_NAME{"PpmException: name too short."};

class PpmCreator
{
    public:
        PpmCreator() = delete;
        PpmCreator(PpmCreator const &to_copy) = delete;
        PpmCreator(PpmCreator &&to_move) = delete;
        ~PpmCreator() = default;
        PpmCreator &operator=(PpmCreator const &to_copy) = delete;
        PpmCreator &operator=(PpmCreator &&to_move) = delete;
        static void create_ppm_file(std::vector<raytracer::Pixel> result, raytracer::Resolution res,
                                    std::string filename);

        class PpmException : public std::exception
        {
            public:
                PpmException(std::string pexcep);
                PpmException(PpmException const &to_copy) = default;
                PpmException(PpmException &&to_move) = default;
                ~PpmException() override = default;
                PpmException &operator=(PpmException const &to_copy) = default;
                PpmException &operator=(PpmException &&to_move) = default;

                [[nodiscard]] const char *what() const noexcept override;

            private:
                std::string excep{};
        };

    private:
        std::vector<raytracer::Pixel> m_result;
        raytracer::Resolution m_res;
        std::string m_name{"output.ppm"};

        PpmCreator(std::vector<raytracer::Pixel> &result, raytracer::Resolution &res,
                   std::string &filename) noexcept;

        void create_ppm();
};

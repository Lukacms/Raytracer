/*
** EPITECH PROJECT, 2023
** src
** File description:
** PpmCreator
*/

#include <cstddef>
#include <fstream>
#include <raytracer/PpmCreator.hh>
#include <stdexcept>
#include <string>
#include <utility>

PpmCreator::PpmCreator(std::vector<raytracer::Pixel> &result, raytracer::Resolution &res,
                       std::string &filename) noexcept
    : m_result(result), m_res(res), m_name(filename)
{
}

void PpmCreator::create_ppm_file(std::vector<raytracer::Pixel> result, raytracer::Resolution res,
                                 std::string name)
{
    PpmCreator creator{result, res, name};

    creator.create_ppm();
}

void PpmCreator::create_ppm()
{
    std::ofstream file{};

    try {
        if (m_name.size() <= 4 || m_name.substr(m_name.size() - 4) != ".ppm")
            throw;
    } catch (std::out_of_range &e) {
        throw e;
    }
    file.open(m_name);
    std::string res{"P3\n" + std::to_string(m_res.x) + " " + std::to_string(m_res.y) + "\n255\n"};
    file << res;
    for (auto result_info : m_result) {
        std::string result{std::to_string(result_info.color.red) + ' ' +
                           std::to_string(result_info.color.green) + ' ' +
                           std::to_string(result_info.color.blue) + '\n'};
        file << result;
    }
}

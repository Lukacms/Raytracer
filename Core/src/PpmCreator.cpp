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

/* ctor / dtor */

PpmCreator::PpmCreator(std::vector<raytracer::Pixel> &result, raytracer::Resolution &res,
                       std::string &filename) noexcept
    : m_result(result), m_res(res), m_name(filename)
{
}

/* methods */

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
            throw PpmException{INVALID_NAME.data()};
    } catch (std::out_of_range &) {
        throw PpmException{INVALID_NAME.data()};
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

/* PpmException */
PpmCreator::PpmException::PpmException(std::string pexcep) : excep{std::move(pexcep)}
{
}

const char *PpmCreator::PpmException::what() const noexcept
{
    return this->excep.c_str();
}

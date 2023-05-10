/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** PpmExecption
*/

#pragma once

#include <stdexcept>

// exception class
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

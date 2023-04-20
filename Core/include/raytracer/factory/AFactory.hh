/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** AFactory
*/

#pragma once

#include <exception>
#include <raytracer/factory/IFactory.hh>
#include <string>

namespace RayTracer
{
    class AFactory : public IFactory
    {
        public:
            AFactory() = default;
            AFactory(const AFactory &) = default;
            AFactory(AFactory &&) = default;
            ~AFactory() = default;

            AFactory &operator=(const AFactory &) = default;
            AFactory &operator=(AFactory &&);

            class FactoryException : public std::exception
            {
                public:
                    FactoryException(std::string perror_msg) : error_msg{std::move(perror_msg)} {}

                    FactoryException(FactoryException const &to_copy) = delete;
                    FactoryException(FactoryException &&to_move) = delete;
                    ~FactoryException() override = default;
                    FactoryException &operator=(FactoryException const &to_copy) = default;

                    [[nodiscard]] const char *what() const noexcept override;

                private:
                    std::string error_msg;
            };
    };
} // namespace RayTracer
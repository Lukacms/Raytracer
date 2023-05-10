/*
** EPITECH PROJECT, 2023
** display
** File description:
** Clock
*/

#pragma once

#include <chrono>

namespace raytracer
{
    constexpr double CLOCK_UPDATE_TIME = 0.1;

    class Clock
    {
        public:
            // basic methods
            Clock() = default;
            Clock(Clock const &to_copy) = default;
            Clock(Clock &&to_move) = default;
            ~Clock() = default;
            Clock &operator=(Clock const &to_copy) = default;
            Clock &operator=(Clock &&to_move) = default;

            // function methods
            [[nodiscard]] std::chrono::duration<double> getElapsedTime();
            [[nodiscard]] double getElapsedTimeInS();
            void reset();

        private:
            std::chrono::time_point<std::chrono::steady_clock> start{
                std::chrono::steady_clock::now()};
            std::chrono::time_point<std::chrono::steady_clock> updated{
                std::chrono::steady_clock::now()};
    };
} // namespace raytracer

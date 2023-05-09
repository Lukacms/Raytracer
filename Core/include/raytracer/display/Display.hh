/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Display
*/

#pragma once

#include <SFML/Window/Event.hpp>
#include <raytracer/RayTracer.hh>
#include <raytracer/display/Window.hh>

namespace raytracer
{
    enum class DisplayStatus { Displaying, Stopped };

    class Display
    {
        public:
            Display() = default;
            Display(Display const &to_copy);
            Display(Display &&to_move);
            ~Display() = default;
            Display &operator=(Display const &to_copy);
            Display &operator=(Display &&to_move);

            void display(const std::vector<Pixel> &pixels);
            DisplayStatus getEvents();

        private:
            /* attributes */
            raytracer::Window window{};
            sf::Event event{};
            std::vector<Pixel> m_pixels;

            /* methods */
            void saveOutput();
    };
} // namespace raytracer

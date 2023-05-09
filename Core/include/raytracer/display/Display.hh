/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Display
*/

#pragma once

#include <SFML/Window/Event.hpp>
#include <raytracer/Core.hh>
#include <raytracer/RayTracer.hh>
#include <raytracer/display/Window.hh>

namespace raytracer
{
    enum class DisplayStatus { Displaying, Stopped };

    enum class WindowStatus { Normal, SelectingName };

    class Display
    {
        public:
            Display(const raytracer::Resolution &pres);
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
            std::vector<Pixel> m_pixels;
            Resolution res{};
            WindowStatus status{WindowStatus::Normal};
            std::string filename{};

            /* methods */
            void saveOutput(sf::Event &event);
    };
} // namespace raytracer

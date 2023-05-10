/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Display
*/

#pragma once

#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <raytracer/Core.hh>
#include <raytracer/RayTracer.hh>
#include <raytracer/display/Window.hpp>

constexpr std::string_view FONT_PATH{"./assets/font/raytracer.ttf"};
constexpr std::string_view TEXT_BASIS{"ENTER NAME PLEASE:\t"};
const sf::Color TEXT_COLOR{255, 255, 255};
const sf::Vector2f TEXT_POS{20, 20};
constexpr unsigned int TEXT_SIZE{12};

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
            std::vector<Pixel> m_pixels{};
            Resolution res{};
            WindowStatus status{WindowStatus::Normal};
            std::string filename{};
            sf::Text t_filename{};
            sf::Font font{};

            /* methods */
            void saveOutput(sf::Event &event);
            void displayPixels();
    };
} // namespace raytracer

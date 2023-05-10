/*
** EPITECH PROJECT, 2023
** display
** File description:
** Window
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window/VideoMode.hpp>

constexpr std::string_view RAYTRACER_WINDOW{"Raytracer"};
const sf::VideoMode RAYTRACER_MODE{800, 600};

namespace raytracer
{
    class Window
    {
        public:
            Window(sf::VideoMode mode = RAYTRACER_MODE,
                   const std::string &name = RAYTRACER_WINDOW.data());
            Window(Window const &to_copy) = delete;
            Window(Window &&to_move) = delete;
            ~Window() = default;
            Window &operator=(Window const &to_copy) = delete;
            Window &operator=(Window &&to_move) = delete;

            void update();
            void close();
            sf::RenderWindow &getWindow();

            template <typename TObject> void draw(TObject obj)
            {
                this->window.draw(obj);
            }

        private:
            sf::RenderWindow window;
    };
} // namespace raytracer

/*
** EPITECH PROJECT, 2023
** display
** File description:
** Window
*/

#include <SFML/Window/VideoMode.hpp>
#include <raytracer/display/Window.hpp>

/* ctor / dtor */
raytracer::Window::Window(sf::VideoMode mode, const std::string &name) : window{mode, name}
{
}

/* methods */
void raytracer::Window::update()
{
    this->window.clear();
}

void raytracer::Window::close()
{
    this->window.close();
}

sf::RenderWindow &raytracer::Window::getWindow()
{
    return this->window;
}

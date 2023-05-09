/*
** EPITECH PROJECT, 2023
** display
** File description:
** Display
*/

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include <raytracer/display/Display.hh>

void raytracer::Display::display(const std::vector<Pixel> &pixels)
{
    sf::RectangleShape r_pixel{sf::Vector2f{1, 1}};

    this->window.update();
    for (const auto &pixel : pixels) {
        r_pixel.setFillColor(sf::Color{static_cast<sf::Uint8>(pixel.color.red),
                                       static_cast<sf::Uint8>(pixel.color.green),
                                       static_cast<sf::Uint8>(pixel.color.blue)});
        r_pixel.setPosition(static_cast<float>(pixel.coords.getX()),
                            static_cast<float>(pixel.coords.getY()));
        this->window.getWindow().draw(r_pixel);
    }
    this->window.getWindow().display();
}

raytracer::DisplayStatus raytracer::Display::getEvents()
{
    sf::Event events;

    while (this->window.getWindow().pollEvent(events)) {
        if (events.type == sf::Event::Closed || events.key.code == sf::Keyboard::Q)
            return DisplayStatus::Stopped;
        if (event.key.code == sf::Keyboard::S) {
            this->saveOutput();
        }
    }
    return DisplayStatus::Displaying;
}

void raytracer::Display::saveOutput() {}

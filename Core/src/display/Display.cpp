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
#include <raytracer/PpmCreator.hh>
#include <raytracer/display/Display.hh>

/* ctor / dtor */
raytracer::Display::Display(const raytracer::Resolution &pres) : res{pres} {}

/* methods */

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
    this->m_pixels = pixels;
}

raytracer::DisplayStatus raytracer::Display::getEvents()
{
    sf::Event events;

    while (this->window.getWindow().pollEvent(events)) {
        if (this->status == WindowStatus::SelectingName)
            this->saveOutput(events);
        if (events.key.code == sf::Keyboard::S)
            this->status = WindowStatus::SelectingName;
        if (events.type == sf::Event::Closed ||
            (events.key.code == sf::Keyboard::Q && this->status == WindowStatus::Normal))
            return DisplayStatus::Stopped;
    }
    return DisplayStatus::Displaying;
}

void raytracer::Display::saveOutput(sf::Event &event)
{
    if (event.key.code == sf::Keyboard::Enter) {
        if (!this->filename.ends_with(".ppm"))
            this->filename += ".ppm";
        this->filename.erase(this->filename.begin(), this->filename.begin() + 1);
        PpmCreator::create_ppm_file(this->m_pixels, this->res, this->filename);
        this->status = WindowStatus::Normal;
        this->filename.erase(this->filename.begin(), this->filename.end());
        return;
    }
    if (event.key.code == sf::Keyboard::Delete)
        this->filename.pop_back();
    else if (event.type == sf::Event::TextEntered)
        this->filename += static_cast<char>(event.text.unicode);
}

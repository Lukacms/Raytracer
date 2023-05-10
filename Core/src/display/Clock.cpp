/*
** EPITECH PROJECT, 2023
** display
** File description:
** Clock
*/

#include <chrono>
#include <raytracer/display/Clock.hh>

std::chrono::duration<double> raytracer::Clock::getElapsedTime()
{
    this->updated = std::chrono::steady_clock::now();

    return updated - start;
}

double raytracer::Clock::getElapsedTimeInS()
{
    auto tmp = this->getElapsedTime();
    tmp.count();
    return tmp.count();
}

/**
 * reset the clock
 */
void raytracer::Clock::reset()
{
    this->start = std::chrono::steady_clock::now();
    this->updated = std::chrono::steady_clock::now();
}

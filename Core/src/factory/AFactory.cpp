/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** AFactory
*/

#include <raytracer/factory/AFactory.hh>

// Constructor & Destructor

// Methods

const char *RayTracer::AFactory::FactoryException::what() const noexcept
{
    return this->error_msg.c_str();
}

/*
** EPITECH PROJECT, 2023
** config
** File description:
** ConfigException
*/

#include <raytracer/config/ConfigFile.hh>

// ctor
raytracer::ConfigFile::ConfigException::ConfigException(std::string pexcep)
    : excep{std::move(pexcep)}
{
}

// override method to have a message describing the exception (why)
const char *raytracer::ConfigFile::ConfigException::what() const noexcept
{
    return this->excep.data();
}

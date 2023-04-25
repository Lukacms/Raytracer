/*
** EPITECH PROJECT, 2023
** config
** File description:
** ConfigFile
*/

#include <raytracer/config/ConfigFile.hh>
#include <string>

// ctor and dtor for class
raytracer::ConfigFile::ConfigFile(std::string pfilepath) : filepath{std::move(pfilepath)}
{
    this->getFullPath();
}

void raytracer::ConfigFile::parse()
{
    // TODO; implement method
}

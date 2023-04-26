/*
** EPITECH PROJECT, 2023
** config
** File description:
** ConfigFile
*/

#include <raytracer/config/ConfigFile.hh>
#include <string>

/* ctor and dtor for class */

raytracer::ConfigFile::ConfigFile(std::string pfilepath) : filepath{std::move(pfilepath)}
{
    this->filepath = this->getFullPath();
}

/* methods */

std::string raytracer::ConfigFile::getFullPath()
{
    std::string fullpath{};

    if (this->filepath.find(FULLPATH_INDIC) != std::string::npos)
        return this->filepath;
    fullpath = DEFAULT_CONFIG_PATH.data() + this->filepath;
    return fullpath;
}

void raytracer::ConfigFile::parse()
{
    // open and read the file given by the filepath
}

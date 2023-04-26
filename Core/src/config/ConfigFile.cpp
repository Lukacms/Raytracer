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

// can't copy either the scene (contains unique ptrs) and the config (don't have a copy constructor)
raytracer::ConfigFile::ConfigFile(raytracer::ConfigFile const &to_copy)
{
    this->filepath = to_copy.filepath;
}

raytracer::ConfigFile &raytracer::ConfigFile::operator=(ConfigFile const &to_copy)
{
    this->filepath = to_copy.filepath;
    return *this;
}

// config does not have a move operator, so can't move it
raytracer::ConfigFile::ConfigFile(raytracer::ConfigFile &&to_move)
{
    this->filepath = std::move(to_move.filepath);
    this->scene = std::move(to_move.scene);
}

raytracer::ConfigFile &raytracer::ConfigFile::operator=(ConfigFile &&to_move)
{
    this->filepath = std::move(to_move.filepath);
    this->scene = std::move(to_move.scene);
    return *this;
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

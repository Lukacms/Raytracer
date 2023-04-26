/*
** EPITECH PROJECT, 2023
** config
** File description:
** ConfigFile
*/

#include <fstream>
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

void raytracer::ConfigFile::initConfig()
{
    std::ifstream ifstream{this->filepath};

    if (!ifstream.is_open())
        throw ConfigFile::ConfigException(INVALID_FILE.data());
    try {
        this->config = njson::parse(ifstream);
    } catch (njson::parse_error &e) {
        throw ConfigFile::ConfigException(std::string{e.what()});
    }
}

void raytracer::ConfigFile::parse()
{
    try {
        this->initConfig();
    } catch (ConfigFile::ConfigException &e) {
        throw e;
    }
}

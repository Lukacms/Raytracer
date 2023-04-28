/*
** EPITECH PROJECT, 2023
** config
** File description:
** ConfigFile
*/

#include <fstream>
#include <iostream>
#include <raytracer/config/ConfigFile.hh>
#include <raytracer/config/Scene.hh>
#include <raytracer/factory/AFactory.hh>
#include <raytracer/factory/LightFactory.hpp>
#include <raytracer/factory/PrimitiveFactory.hpp>
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

raytracer::Scene raytracer::ConfigFile::parse()
{
    try {
        this->initConfig();
    } catch (ConfigFile::ConfigException &e) {
        throw e;
    }
    try {
        this->scene.camera = this->config.at("camera");
        for (auto &primitive : this->config.at("primitives"))
            this->scene.primitives.emplace_back(PrimitiveFactory::createPrimitive(primitive));
        for (auto &light : this->config.at("lights"))
            this->scene.lights.emplace_back(LightFactory::createLight(light));
    } catch (njson::exception &e) {
        throw ConfigFile::ConfigException(std::string{"Couldn't load json: "} + e.what());
    } catch (raytracer::AFactory::FactoryException &e) {
        throw ConfigFile::ConfigException(e.what());
    }
    return std::move(this->scene);
}

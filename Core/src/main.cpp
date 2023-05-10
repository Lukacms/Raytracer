/*
** EPITECH PROJECT, 2023
** src
** File description:
** main
*/

#include <iostream>
#include <raytracer/Core.hh>
#include <raytracer/PpmCreator.hh>
#include <raytracer/config/ArgsConfig.hh>
#include <raytracer/config/ConfigFile.hh>

int main(int argc, const char *argv[])
{
    raytracer::Infos infos{};

    try {
        infos = raytracer::ArgsConfig::getArgs(argc, argv);
    } catch (raytracer::ArgsConfig::ArgsException &e) {
        std::cout << e.what() << "\n";
        return e.what() == HELP_MSG ? SUCCESS : FAILURE;
    }
    try {
        raytracer::Raytracer core{infos};
        core.launch();
    } catch (raytracer::ConfigFile::ConfigException &e) {
        std::cout << HEADER_MSG << e.what() << "\n";
        return FAILURE;
    } catch (PpmCreator::PpmException &e) {
        std::cout << HEADER_MSG << e.what() << "\n";
        return FAILURE;
    }
    return SUCCESS;
}

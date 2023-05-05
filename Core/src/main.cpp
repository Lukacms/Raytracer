/*
** EPITECH PROJECT, 2023
** src
** File description:
** main
*/

#include <iostream>
#include <raytracer/Core.hh>
#include <raytracer/RayTracer.hh>
#include <raytracer/config/ArgsConfig.hh>
#include <raytracer/config/ConfigFile.hh>
#include <raytracer/config/Scene.hh>

int main(int argc, const char *argv[])
{
    raytracer::Scene scene{};
    raytracer::Infos infos{};

    try {
        infos = raytracer::ArgsConfig::getArgs(argc, argv);
    } catch (raytracer::ArgsConfig::ArgsException &e) {
        std::cout << e.what() << "\n";
        return e.what() == HELP_MSG ? SUCCESS : FAILURE;
    }
    try {
        scene = raytracer::ConfigFile::parser(infos.input);
    } catch (raytracer::ConfigFile::ConfigException &e) {
        std::cout << HEADER_MSG << e.what() << "\n";
        return FAILURE;
    }
    raytracer::Raytracer core{scene};
    core.launch();
    return SUCCESS;
}

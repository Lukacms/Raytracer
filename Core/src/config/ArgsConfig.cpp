/*
** EPITECH PROJECT, 2023
** config
** File description:
** ArgsConfig
*/

#include <raytracer/RayTracer.hh>
#include <raytracer/config/ArgsConfig.hh>
#include <sys/stat.h>

/* methods */
raytracer::Infos raytracer::ArgsConfig::getArgs(int argc, const char *const *argv)
{
    Infos infos{};
    struct stat filestats;

    if (!argv)
        throw ArgsException(ARGS_NB_ERROR.data());
    if (argc == 2 && std::string(argv[1]) == HELP_INDIC.data())
        throw ArgsException(HELP_MSG.data());
    if (argc == PPM_NB_ARGS) {
        infos.output = std::string{argv[PPM_NB_ARGS - 1]};
        infos.type = DisplayType::PpmOutput;
    } else if (argc == SFML_NB_ARGS) {
        infos.type = DisplayType::SfmlOutput;
    } else {
        throw ArgsException(ARGS_NB_ERROR.data());
    }
    infos.input = std::string{argv[1]};
    if (stat(infos.input.c_str(), &filestats) < 0)
        throw ArgsException(ARGS_NO_STAT.data());
    infos.input_last_modified = filestats.st_mtime;
    if (!infos.output.empty() && !infos.output.ends_with(".ppm"))
        infos.output += ".ppm";
    return infos;
}

bool raytracer::ArgsConfig::wasFileModified(Infos &infos)
{
    struct stat filestats;

    if (stat(infos.input.c_str(), &filestats) < 0)
        throw ArgsException(ARGS_NO_STAT.data());
    if (filestats.st_mtime > infos.input_last_modified) {
        infos.input_last_modified = filestats.st_mtime;
        return true;
    }
    return false;
}

/* ArgsException */
raytracer::ArgsConfig::ArgsException::ArgsException(std::string perror) : msg{std::move(perror)}
{
}

const char *raytracer::ArgsConfig::ArgsException::what() const noexcept
{
    return msg.data();
}

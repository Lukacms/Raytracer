/*
** EPITECH PROJECT, 2023
** config
** File description:
** ArgsConfig
*/

#include <raytracer/RayTracer.hh>
#include <raytracer/config/ArgsConfig.hh>

/* methods */
raytracer::Infos raytracer::ArgsConfig::getArgs(int argc, const char *const *argv)
{
    Infos infos{};

    if (argc == 2 && std::string(argv[1]) == HELP_INDIC.data()) {
        throw ArgsException(HELP_MSG.data());
    }
    if (argc == PPM_NB_ARGS) {
        infos.output = std::string{argv[PPM_NB_ARGS - 1]};
        infos.type = DisplayType::PpmOutput;
    } else if (argc == SFML_NB_ARGS) {
        infos.type = DisplayType::SfmlOutput;
    } else {
        throw ArgsException(ARGS_NB_ERROR.data());
    }
    infos.input = std::string{argv[1]};
    return infos;
}

/* ArgsException */
raytracer::ArgsConfig::ArgsException::ArgsException(std::string perror) : msg{std::move(perror)} {}

const char *raytracer::ArgsConfig::ArgsException::what() const noexcept
{
    return msg.data();
}

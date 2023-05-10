/*
** EPITECH PROJECT, 2023
** config
** File description:
** ArgsConfig
*/

#pragma once

#include <ctime>
#include <exception>
#include <string>

constexpr int PPM_NB_ARGS{4};
constexpr int SFML_NB_ARGS{3};

constexpr std::string_view ARGS_NB_ERROR{"Must be either 3 or 4 arguments, try -h to see options."};
constexpr std::string_view ARGS_NO_STAT{"Can't find stats of input file."};
constexpr std::string_view HELP_INDIC{"-h"};

namespace raytracer
{
    enum class DisplayType { PpmOutput, SfmlOutput };

    struct Infos {
            DisplayType type{DisplayType::SfmlOutput};
            std::string output{};
            std::string input{};
            std::time_t input_last_modified{};
    };

    class ArgsConfig
    {
        public:
            /* ctor / dtor */
            ArgsConfig() = default;
            ArgsConfig(ArgsConfig const &to_copy) = default;
            ArgsConfig(ArgsConfig &&to_move) = default;
            ~ArgsConfig() = default;

            /* override operators */
            ArgsConfig &operator=(ArgsConfig const &to_copy) = default;
            ArgsConfig &operator=(ArgsConfig &&to_move) = default;

            /* exception */
            class ArgsException : public std::exception
            {
                public:
                    ArgsException(std::string perror);
                    ArgsException(ArgsException const &to_copy) = default;
                    ArgsException(ArgsException &&to_move) = default;
                    ~ArgsException() override = default;
                    ArgsException &operator=(ArgsException const &to_copy) = default;
                    ArgsException &operator=(ArgsException &&to_move) = default;

                    /* override method what of exception */
                    [[nodiscard]] const char *what() const noexcept override;

                private:
                    std::string msg;
            };

            /* methods */
            static Infos getArgs(int argc, const char *const *argv);
            static bool wasFileModified(Infos &infos);

        private:
    };
} // namespace raytracer

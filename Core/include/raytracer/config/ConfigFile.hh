/*
** EPITECH PROJECT, 2023
** config
** File description:
** ConfigFile
*/

#pragma once

#include <exception>
#include <nlohmann/json.hpp>
#include <raytracer/config/Scene.hh>
#include <string>
#include <string_view>

using njson = nlohmann::json;

/* utils to get the file */
constexpr std::string_view DEFAULT_CONFIG_PATH{"assets/configs/"};
constexpr char FULLPATH_INDIC{'/'};

/* exception messages */
constexpr std::string_view INVALID_FILE{"File could not be open."};

namespace raytracer
{
    /* this class is to parse the configuration file containing the informations
     * the goal is to update it in real-time and load the infos to the Core
     */
    class ConfigFile
    {
        public:
            // ctor / dtors
            ConfigFile(std::string pfilepath);
            ConfigFile(ConfigFile const &to_copy) = default;
            ConfigFile(ConfigFile &&to_move) = default;
            ~ConfigFile() = default;
            // operators override
            ConfigFile &operator=(ConfigFile const &to_copy) = default;
            ConfigFile &operator=(ConfigFile &&to_move) = default;

            // methods
            [[nodiscard]] Scene parse();

            // exception class
            class ConfigException : public std::exception
            {
                public:
                    ConfigException(std::string pexcep);
                    ConfigException(ConfigException const &to_copy) = default;
                    ConfigException(ConfigException &&to_move) = default;
                    ~ConfigException() override = default;
                    ConfigException &operator=(ConfigException const &to_copy) = default;
                    ConfigException &operator=(ConfigException &&to_move) = default;

                    [[nodiscard]] const char *what() const noexcept override;

                private:
                    std::string excep{};
            };

        private:
            // attributes
            std::string filepath{};
            raytracer::Scene scene{};
            // nlohmann_json
            njson config{};

            // private methods
            std::string getFullPath();
            void initConfig();
    };
} // namespace raytracer

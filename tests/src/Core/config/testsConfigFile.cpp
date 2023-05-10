/*
** EPITECH PROJECT, 2023
** config
** File description:
** testConfigFile
*/

#include <catch2/catch.hpp>
#include <raytracer/config/ConfigFile.hh>

TEST_CASE("ConfigFile invalid", "invalid filepath")
{
    std::string filepath{"gibberish"};

    REQUIRE_THROWS(raytracer::ConfigFile::parser(filepath));
}

TEST_CASE("Get fullpath", "config file valid")
{
    raytracer::ConfigFile config{"test.json"};

    REQUIRE(config.getFullPath() == "assets/configs/test.json");
}

TEST_CASE("Already a fullpath", "config file valid")
{
    raytracer::ConfigFile config{"assets/configs/test.json"};

    REQUIRE(config.getFullPath() == "assets/configs/test.json");
}

TEST_CASE("Various", "Config file invalid")
{
    REQUIRE_THROWS(raytracer::ConfigFile::parser("tests/assets/invalid.json"));
    REQUIRE_THROWS(raytracer::ConfigFile::parser("tests/assets/no_light.json"));
}

TEST_CASE("Valid", "Config file valid")
{
    REQUIRE_NOTHROW(raytracer::ConfigFile::parser("tests/assets/valid.json"));
}

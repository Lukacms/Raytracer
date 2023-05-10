/*
** EPITECH PROJECT, 2023
** config
** File description:
** testsArgsConfig
*/

#include <array>
#include <catch2/catch.hpp>
#include <raytracer/RayTracer.hh>
#include <raytracer/config/ArgsConfig.hh>

TEST_CASE("Testing help", "-h")
{
    char *const argv[] = {".", "-h"}; // NOLINT

    try {
        REQUIRE_THROWS(raytracer::ArgsConfig::getArgs(2, argv));
    } catch (raytracer::ArgsConfig::ArgsException &e) {
        REQUIRE(e.what() == HELP_MSG.data());
    }
}

TEST_CASE("Testing invalid args", "-h")
{
    REQUIRE_THROWS(raytracer::ArgsConfig::getArgs(0, nullptr));
    REQUIRE_THROWS(raytracer::ArgsConfig::getArgs(7, nullptr));
    // null argv
    REQUIRE_THROWS(raytracer::ArgsConfig::getArgs(2, nullptr));
}

TEST_CASE("Invalid case", "invalid input")
{
    char *const argv[] = {".", "no_exists", "-ppm", "ouais"}; // NOLINT

    try {
        REQUIRE_THROWS(raytracer::ArgsConfig::getArgs(4, argv));
    } catch (raytracer::ArgsConfig::ArgsException &e) {
        REQUIRE(e.what() == ARGS_NO_STAT.data());
    }
}

TEST_CASE("Valid case ppm", "valid input with ppm")
{
    char *const argv[] = {".", "./assets/configs/test.json", "-ppm", "ouais"}; // NOLINT

    raytracer::Infos infos = raytracer::ArgsConfig::getArgs(4, argv);
    REQUIRE_NOTHROW(raytracer::ArgsConfig::getArgs(4, argv));

    REQUIRE(infos.input == argv[1]);
    REQUIRE(infos.type == raytracer::DisplayType::PpmOutput);
}

TEST_CASE("Valid case sfml", "valid input with sfml")
{
    char *const argv[] = {".", "./assets/configs/test.json", "-sfml"}; // NOLINT

    raytracer::Infos infos = raytracer::ArgsConfig::getArgs(3, argv);
    REQUIRE_NOTHROW(raytracer::ArgsConfig::getArgs(3, argv));

    REQUIRE(infos.input == argv[1]);
    REQUIRE(infos.type == raytracer::DisplayType::SfmlOutput);
}

/*
** EPITECH PROJECT, 2023
** factory
** File description:
** testsLightFactory
*/

#include <catch2/catch.hpp>
#include <raytracer/factory/LightFactory.hpp>

TEST_CASE("Build a point")
{
    njson json = njson::parse(R"(
    {
            "type": "point",
            "origin": {
                "x": 2,
                "y": 1,
                "z": 0
            },
            "intensity": 0.3
    }
    )");

    REQUIRE_NOTHROW(raytracer::LightFactory::createLight(json));
}

TEST_CASE("Light not existing")
{
    njson json = njson::parse(R"(
    {
            "type": "gibberish",
            "origin": {
                "x": 2,
                "y": 1,
                "z": 0
            },
            "intensity": 0.3
    }
    )");

    REQUIRE_THROWS(raytracer::LightFactory::createLight(json));
}

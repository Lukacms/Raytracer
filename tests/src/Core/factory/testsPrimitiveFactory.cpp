/*
** EPITECH PROJECT, 2023
** factory
** File description:
** testsPrimitiveFactory
*/

#include <catch2/catch.hpp>
#include <raytracer/factory/PrimitiveFactory.hpp>

TEST_CASE("Build a sphere")
{
    njson json = njson::parse(R"(
        {
            "type": "sphere",
            "origin": {
                "x": 0,
                "y": -5001,
                "z": 0
            },
            "radius": 5000,
            "material": {
                "color": {
                    "r": 255,
                    "g": 255,
                    "b": 0
                },
                "reflection": 0.5,
                "spec": 1000
            }
        }
    )");

    REQUIRE_NOTHROW(raytracer::PrimitiveFactory::createPrimitive(json));
}

TEST_CASE("Build not existing")
{
    njson json = njson::parse(R"(
        {
            "type": "gibberish",
            "origin": {
                "x": 0,
                "y": -5001,
                "z": 0
            },
            "radius": 5000,
            "material": {
                "color": {
                    "r": 255,
                    "g": 255,
                    "b": 0
                },
                "reflection": 0.5,
                "spec": 1000
            }
        }
    )");

    REQUIRE_THROWS(raytracer::PrimitiveFactory::createPrimitive(json));
}

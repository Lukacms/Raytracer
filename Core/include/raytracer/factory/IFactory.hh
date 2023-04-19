/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** IFactory
*/

#pragma once

namespace RayTracer {

    class IFactory {
        public:
            IFactory() = default;
            IFactory(const IFactory&) = default;
            IFactory(IFactory &&) = default;
            ~IFactory() = default;
    
            IFactory &operator=(const IFactory&) = default;
            IFactory &operator=(IFactory &&);
    };
}

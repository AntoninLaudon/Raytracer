/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-raytracer-tom.laiolo
** File description:
** Scene
*/

#pragma once

#include <vector>
#include "IElement.hpp"

namespace Raytracer {
    class Scene {
        public:
            Scene();
            ~Scene();
        protected:
        private:
            std::vector<Raytracer::IElement *> _elements;
    };
}

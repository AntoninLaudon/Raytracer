/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-raytracer-tom.laiolo
** File description:
** Core
*/

#pragma once

#include <string>
#include "Scene.hpp"

namespace Raytracer {
    class Core {
        public:
            Core();
            ~Core();
            void Run();
            void CreateScene(std::string path);
            void Render();
        protected:
        private:
            Raytracer::Scene *_scene;
    };
}

/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-raytracer-tom.laiolo
** File description:
** Core
*/

#pragma once

#include <string>
#include "SceneManager.hpp"

namespace Raytracer {
    class Core {
        public:
            Core();
            ~Core();
            void Run();
            void CreateScene(std::string path);
            std::shared_ptr<Raytracer::SceneManager> GetScene() const { return _scene; };
            void Render();
        protected:
        private:
            std::shared_ptr<Raytracer::SceneManager> _scene;
    };
}

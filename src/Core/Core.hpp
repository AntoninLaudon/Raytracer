/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-raytracer-tom.laiolo
** File description:
** Core
*/

#pragma once

#include <string>
#include "SceneManager.hpp"

class File;
namespace Raytracer {
    class Core {
        public:
            Core();
            ~Core();
            void CreateScene(File file);
            std::shared_ptr<Raytracer::SceneManager> GetScene() const { return _scene; };
            void Render();
            void setFile(File *file);
            File *getFile() const;
        protected:
        private:
            std::shared_ptr<Raytracer::SceneManager> _scene;
            File *_file;
    };
}

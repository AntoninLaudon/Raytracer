/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-raytracer-tom.laiolo
** File description:
** SceneManager
*/

#pragma once

#include "IElement.hpp"
#include "Camera.hpp"
#include "Math.hpp"
#include "Factory.hpp"
#include "LibLoader.hpp"

#include <filesystem>
#include <vector>
#include <libconfig.h++>
#include <stdexcept>
#include <memory>
#include <string.h>
#include <iostream>
#include <utility>

namespace Raytracer {
    class SceneManager {
    public:
        SceneManager(const char *path);
        ~SceneManager();
        void ParseScene();
        void Render();
        void CreateCamera(const libconfig::Setting *elem);
        void CreateElement(const libconfig::Setting *elem, std::shared_ptr<Factory> factory);
        std::string getPath();
    protected:
    private:
        std::string _path;
        std::shared_ptr<Raytracer::Camera> _camera;
        std::vector<Raytracer::IElement*> _elements;
        std::vector<std::shared_ptr<LibLoader>> _loader;
        std::pair<int, int> _size;
    };
};

/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-raytracer-tom.laiolo
** File description:
** SceneManager
*/

#pragma once

#include "IElement.hpp"
#include "Camera.hpp"

#include <vector>
#include <libconfig.h++>
#include <stdexcept>

namespace Raytracer {
    class SceneManager {
    public:
        SceneManager(const char *path);
        void ParseScene();
        IElement *GetCamera(const libconfig::Config *cfg);
        ~SceneManager();
    protected:
    private:
        std::string _path;
        std::vector<Raytracer::IElement *> _elements;
    };
};

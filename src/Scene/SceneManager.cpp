/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-raytracer-tom.laiolo
** File description:
** SceneManager
*/

#include "SceneManager.hpp"

Raytracer::SceneManager::SceneManager(const char *path)
{
    _path = path;
}

Raytracer::SceneManager::~SceneManager()
{
}

void Raytracer::SceneManager::ParseScene()
{
    libconfig::Config cfg;
    try {
        cfg.readFile("scenes/test.cfg");
    } catch (const libconfig::FileIOException &error) {
        std::cerr << "Error while reading file" << std::endl;
        throw std::runtime_error("Error while reading file");
    } catch (const libconfig::ParseException &error) {
        std::cerr << "Error while parsing file, line : " << error.getLine() << " error : " << error.getError() << std::endl;
        throw std::runtime_error("Error while parsing file");
    }
    try {
        _elements.push_back(GetCamera(&cfg));


        //const libconfig::Setting &camera_pos = camera["position"];
        //double x = camera_pos[0];
        //double y = camera_pos[1];
    } catch (const libconfig::ParseException &error) {
        std::cerr << "Error while parsing file, line : " << error.getLine() << " error : " << error.getError() << std::endl;
        throw std::runtime_error("Error while parsing file");
    }
}

Raytracer::IElement *Raytracer::SceneManager::GetCamera(const libconfig::Config *cfg)
{
    new Raytracer::Camera();
    const libconfig::Setting &root = cfg->getRoot();
    const libconfig::Setting &camera = root["camera"];

}
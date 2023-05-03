/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-raytracer-tom.laiolo
** File description:
** Core
*/

#include "Core.hpp"

Raytracer::Core::Core()
{
}

Raytracer::Core::~Core()
{
}

void Raytracer::Core::Run()
{
    std::string path = "scenes/scene1.json";
    CreateScene(path);
    Render();
}

void Raytracer::Core::CreateScene(File file)
{
    _scene = std::make_shared<Raytracer::SceneManager>(file.getfilePath().c_str());
    _scene->ParseScene();
}

void Raytracer::Core::Render()
{
    _scene->Render();
}

/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-raytracer-tom.laiolo
** File description:
** Core
*/

#include "Core.hpp"

Raytracer::Core::Core()
{
   _scene = new Raytracer::Scene("scenes/scene1.json");
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

void Raytracer::Core::CreateScene(std::string path)
{
    path = path;
    //_scene = Raytracer::Scene(path);
}

void Raytracer::Core::Render()
{
}
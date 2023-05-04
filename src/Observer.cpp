/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-raytracer-tom.laiolo
** File description:
** Observer
*/

#include <chrono>
#include <thread>

#include "File.hpp"
#include "Observer.hpp"

Observer::Observer()
{
}

Observer::~Observer()
{
}

void Observer::update(File *file, Raytracer::Core &core)
{
    std::cout << "File " << file->getfilePath() << " has changed" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    try {
        core.CreateScene(*file);
        core.Render();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

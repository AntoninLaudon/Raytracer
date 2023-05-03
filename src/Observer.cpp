/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-raytracer-tom.laiolo
** File description:
** Observer
*/

#include "File.hpp"
#include "Observer.hpp"

Observer::Observer()
{
}

Observer::~Observer()
{
}

void Observer::update(File *file)
{
    std::cout << "File " << file->getfilePath() << " has changed" << std::endl;
}

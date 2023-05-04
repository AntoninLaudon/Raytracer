/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-raytracer-tom.laiolo
** File description:
** main
*/

#include <iostream>
#include <libconfig.h++>
#include "Math.hpp"
#include "Factory.hpp"
#include "Camera.hpp"
#include "Core.hpp"
#include "Generation.hpp"
#include "File.hpp"
#include "Observer.hpp"


int main (int argc, char **argv)
{
    Raytracer::Core core;
    File file ("scenes/test.cfg");
    Observer Observer;
    int first = 0;

    file.attach(&Observer);
    if (argc == 2)
        file.setfilePath(argv[1]);
    while (true)
        if (file.hasChanged() || first == 0) {
            first = 1;
            file.notify(core);
        }
    return 0;
}

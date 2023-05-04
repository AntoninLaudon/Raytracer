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

int main (int argc, char **argv)
{
    Raytracer::Core core;
    try {
        if (argc == 1)
            core.CreateScene("scenes/test.cfg");
        if (argc == 2) {
            if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0) {
                std::cout << "USAGE" << std::endl;
                std::cout << "\t./raytracer [scene]" << std::endl;
                std::cout << "DESCRIPTION" << std::endl;
                std::cout << "\tscene\t\tscene file in .cfg format" << std::endl;
                return 0;
            }
            core.CreateScene(argv[1]);
            core.Render();
        }
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}

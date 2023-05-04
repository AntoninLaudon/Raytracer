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
<<<<<<< HEAD
=======
#include "Sphere.hpp"
#include "Plan.hpp"
>>>>>>> 9721f20 (ADD: start of plan)
#include "Core.hpp"
#include "Generation.hpp"
#include "File.hpp"
#include "Observer.hpp"

int main (int argc, char **argv)
{
    Raytracer::Core core;
    Observer Observer;
    try {
        if (argc == 1) {
            File file ("scenes/test.cfg");
            file.attach(&Observer);
            file.setfilePath("scenes/test.cfg");
            core.setFile(&file);
            core.CreateScene(file);
            core.Render();
        }
        if (argc == 2) {
            if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0) {
                std::cout << "USAGE" << std::endl;
                std::cout << "\t./raytracer [scene]" << std::endl;
                std::cout << "DESCRIPTION" << std::endl;
                std::cout << "\tscene\t\tscene file in .cfg format" << std::endl;
                return 0;
            }
            File file (argv[1]);
            file.attach(&Observer);
            file.setfilePath(argv[1]);
            core.setFile(&file);
            core.CreateScene(file);
            core.Render();
        }
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}

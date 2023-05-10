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
    Observer Observer;
    try {
        if (argc == 1) {
            File file ("scenes/example.cfg");
            file.attach(&Observer);
            file.setfilePath("scenes/example.cfg");
            core.setFile(&file);
            core.CreateScene(file);
            core.Render();
        } else if (argc == 2) {
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
        } else if (argc == 3) {
            if (strcmp(argv[1], "-render") == 0 || strcmp(argv[1], "-r") == 0) {
                File file (argv[2]);
                file.attach(&Observer);
                file.setfilePath(argv[2]);
                core.setFile(&file);
                core.CreateScene(file);
                std::pair<int, int> size = core.GetScene()->getSize();
                PPM::PPM img = PPM::PPM(size.first, size.second);
                std::shared_ptr<std::vector<PPM::RGB>> pixels = core.GetScene()->Render();
                img.bufferToImage(pixels);
                std::string name = "screenshots/render_";
                std::time_t t = std::time(nullptr);
                std::tm tm = *std::localtime(&t);
                name += std::to_string(tm.tm_year + 1900) + "_" + std::to_string(tm.tm_mon + 1) + "_" + std::to_string(tm.tm_mday) + "_" + std::to_string(tm.tm_hour) + "_" + std::to_string(tm.tm_min) + "_" + std::to_string(tm.tm_sec) + ".ppm";
                img.save(name.c_str());
            } else {
                std::cerr << "Invalid argument" << std::endl;
                return 84;
            }
        }
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}

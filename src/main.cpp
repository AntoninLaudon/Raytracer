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
        if (argc == 2)
            core.CreateScene(argv[1]);
        core.Render();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    // Raytracer::Camera cam (Math::Point3D (0, 0, 0), Raytracer::Rectangle3D (Math::Point3D (1, 1, 1), Math::Vector3D (-2, 0, 0), Math::Vector3D (0, -2, 0)));
    // Raytracer::Sphere s ("s1", Math::Point3D (0, 0, 2), Math::Vector3D (0, 0, 0), Math::Vector3D (0, 0, 0), 0.5);
    // Raytracer::Sphere s2 ("s2", Math::Point3D (0, 0, 5), Math::Vector3D (0, 0, 0), Math::Vector3D (0, 0, 0), 2);
    // PPM::PPM img = PPM::PPM(1000, 1000);
    // std::vector<PPM::RGB> pixels;

    // for (double y = 1000; y > 0; y--) {
    //     for (double x = 0; x < 1000; x++) {
    //         double u = x/1000;
    //         double v = y/1000;
    //         Math::Ray r = cam.ray (u, v);
    //         // if (x == 500 && y == 500) {
    //         //     std::cout << "ray: " << r << std::endl;
    //         //     std::cout << *s.hits(r) << std::endl;
    //         // }
    //         if (s.hits(r)) {
    //             // std::cout << "1 hit: " << *s.hits(r) << std::endl;
    //             pixels.push_back(colorFromPoint(*s.hits(r), s, PPM::RGB(255, 0, 0), cam.getOrigin()));
    //         } else if (s2.hits(r)) {
                
    //             // std::cout << "2 hit: " << *s2.hits(r) << std::endl;
    //             pixels.push_back(colorFromPoint(*s2.hits(r), s2, PPM::RGB(0, 0, 255), cam.getOrigin()));
    //         } else {
    //             pixels.push_back(PPM::RGB(0, 0, 0));
    //         }
    //     }
    // }
    // img.bufferToImage(pixels);
    // img.save("img2.ppm");
    return 0;
}

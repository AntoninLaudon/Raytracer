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
#include "Sphere.hpp"
#include "Core.hpp"
#include "Generation.hpp"

PPM::RGB colorFromPoint(Math::Point3D land, Math::Sphere sphere, PPM::RGB color, Math::Point3D origin)
{
    double closest = Math::Vector3D(sphere.getCenter() - origin).length() - sphere.getRadius();
    double farthest = Math::Vector3D(sphere.getCenter() - origin).length();

    double distance = Math::Vector3D(land - origin).length();

    std::cout << "closest: " << closest << std::endl;
    std::cout << "farthest: " << farthest << std::endl;
    std::cout << "distance: " << distance << std::endl;

    double percent = ((distance - closest)) / (farthest - closest);

    return PPM::RGB(color.r * (1 - percent), color.g * (1 - percent), color.b * (1 - percent));

}

int main ()
{
    // Raytracer::Core core;
    // try {
    //     core.CreateScene("scenes/test.cfg");
    //     core.Render();
    // } catch (std::exception &e) {
    //     std::cerr << e.what() << std::endl;
    // }
    Raytracer::Camera cam (Math::Point3D (0, 0, 0), Raytracer::Rectangle3D (Math::Point3D (1, 1, 1), Math::Vector3D (-2, 0, 0), Math::Vector3D (0, -2, 0)));
    Math::Sphere s (Math::Point3D (0, 0, 2), 0.5);
    Math::Sphere s2 (Math::Point3D (7, 5, 7), 1);
    PPM::PPM img = PPM::PPM(1000, 1000);
    std::vector<PPM::RGB> pixels;

    for (double y = 1000; y > 0; y--) {
        for (double x = 0; x < 1000; x++) {
            double u = x/1000;
            double v = y/1000;
            Math::Ray r = cam.ray (u, v);
            // if (x == 500 && y == 500) {
            //     std::cout << "ray: " << r << std::endl;
            //     std::cout << *s.hits(r) << std::endl;
            // }
            if (s.hits(r)) {
                // std::cout << "1 hit: " << *s.hits(r) << std::endl;
                pixels.push_back(colorFromPoint(*s.hits(r), s, PPM::RGB(255, 0, 0), cam.getOrigin()));
            } else if (s2.hits(r)) {
                
                // std::cout << "2 hit: " << *s2.hits(r) << std::endl;
                pixels.push_back(colorFromPoint(*s2.hits(r), s2, PPM::RGB(0, 0, 255), cam.getOrigin()));
            } else {
                pixels.push_back(PPM::RGB(0, 0, 0));
            }
        }
    }
    img.bufferToImage(pixels);
    img.save("img2.ppm");


    return 0;
}

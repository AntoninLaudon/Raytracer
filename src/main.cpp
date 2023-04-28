/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-raytracer-tom.laiolo
** File description:
** main
*/

#include <iostream>
#include "Math.hpp"
#include "Factory.hpp"
#include "Camera.hpp"
#include "Sphere.hpp"
#include "Core.hpp"
#include "Generation.hpp"

int main ()
{
    Raytracer::Camera cam (Math::Point3D (0, 0, 0), Raytracer::Rectangle3D (Math::Point3D (0, 0, 1), Math::Vector3D (1, 0, 0), Math::Vector3D (0, 1, 0)));
    Raytracer::Sphere s ("s", Math::Point3D (0, 0, 2), Math::Vector3D (0, 0, 0), Math::Vector3D (0, 0, 0), 0.5);
    Raytracer::Sphere s2 ("s2", Math::Point3D (7, 5, 7), Math::Vector3D (1, 0, 0), Math::Vector3D (1, 0, 0), 1);
    PPM::PPM img = PPM::PPM(1000, 1000);
    std::vector<PPM::RGB> pixels;

    for (double y = 1000; y > 0; y--) {
        for (double x = 0; x < 1000; x++) {
            double u = x/1000;
            double v = y/1000;
            Math::Ray r = cam.ray (u, v);
            // pixels.push_back(s.hits(r));
            // if (s.hits (r)) {
            //     pixels.push_back(PPM::RGB(255, 0, 0));
            // } else if (s2.hits (r)) {
            //     pixels.push_back(PPM::RGB(0, 0, 255));
            // } else {
            //     pixels.push_back(PPM::RGB(0, 0, 0));
            // }
        }
    }
    img.bufferToImage(pixels);
    img.save("img2.ppm");
    return 0;
}

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
#include "Primitive.hpp"
#include "Light.hpp"
#include "Core.hpp"

int main ()
{
    Raytracer::Camera cam (Math::Point3D (0, 0, 0), Raytracer::Rectangle3D (Math::Point3D (0, 0, 1), Math::Vector3D (1, 0, 0), Math::Vector3D (0, 1, 0)));
    Math::Sphere s (Math::Point3D (0, 0, 2), 0.5);
    Math::Sphere s2 (Math::Point3D (7, 5, 7), 1);
    std::cout << "P3" << std::endl;
    std::cout << "4000 4000 255" << std::endl;
    for (double y = 4000; y > 0; y--) {
        for (double x = 0; x < 4000; x++) {
            double u = x/4000;
            double v = y/4000;
            Math::Ray r = cam.ray (u, v);
            if (s.hits (r)) {
                std::cout << "255 0 0" << std::endl;
            } else if (s2.hits (r)) {
                std::cout << "0 0 255" << std::endl;
            } else {
                std::cout << "0 0 0" << std::endl;
            }
        }
    }
}

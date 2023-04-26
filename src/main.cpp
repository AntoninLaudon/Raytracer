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
    Raytracer::Camera cam (Math::Point3D (1, 0, 0), Raytracer::Rectangle3d (Math::Point3D (0, 0, 0), Math::Vector3D (1, 0, 0), Math::Vector3D (0, 1, 0)));
    Math::Sphere s (Math::Point3D (50, 50, -20), 0.5);
    for (double y = 0; y < 100; y++) {
        for (double x = 0; x < 100; x++) {
            double u = x/100;
            double v = y/100;
            Math::Ray r = cam.ray (u, v);
            if (s.hits (r)) {
                std::cout << "X";
            } else {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}

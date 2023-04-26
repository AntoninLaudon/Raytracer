/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-raytracer-tom.laiolo
** File description:
** main
*/

#include <iostream>
#include "math.hpp"
#include "Factory.hpp"
#include "Camera.hpp"
#include "Primitive.hpp"
#include "Light.hpp"
#include "Core.hpp"

int main()
{
    Raytracer::Rectangle3d srceen (Math::Point3D(1, 1, 1), Math::Vector3D(0, 0, 1), Math::Vector3D(1, 0, 0));
    Raytracer::Camera camera (Math::Point3D(0, 0, 0), srceen);

    std::cout << "Hello, World!" << std::endl;
    std::cout << "origin srceen: " << srceen.getorigin() << std::endl;
    std::cout << "origin camera: " << camera.getScreen().getorigin() << std::endl;
    return 0;
}

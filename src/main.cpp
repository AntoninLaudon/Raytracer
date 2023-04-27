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
#include "Generation.hpp"

int playground()
{
    Factory factory;

    factory.registerObject(Raytracer::CAMERA, Raytracer::Camera::createObject);
    factory.registerObject(Raytracer::PRIMITIVE, Raytracer::Primitive::createObject);
    factory.registerObject(Raytracer::LIGHT, Raytracer::Light::createObject);

    auto camera = factory.createObject(Raytracer::CAMERA, "camera", Math::Vector3D(0, 0, 0), Math::Vector3D(0, 0, 0));
    auto primitive = factory.createObject(Raytracer::PRIMITIVE, "primitive", Math::Vector3D(0, 0, 0), Math::Vector3D(0, 0, 0));
    auto camera2 = factory.createObject(Raytracer::CAMERA, "camera2", Math::Vector3D(3, 3, 3), Math::Vector3D(0, 0, 0));
    auto primitive2 = factory.createObject(Raytracer::PRIMITIVE, "primitive2", Math::Vector3D(3, 3, 3), Math::Vector3D(0, 0, 0));
    auto light = factory.createObject(Raytracer::LIGHT, "light", Math::Vector3D(0, 0, 0), Math::Vector3D(0, 0, 0));

    if (light == nullptr)
        std::cout << "light is null" << std::endl;
    if (camera == nullptr)
        std::cout << "camera is null" << std::endl;
    if (primitive == nullptr)
        std::cout << "primitive is null" << std::endl;
    if (camera2 == nullptr)
        std::cout << "camera2 is null" << std::endl;
    if (primitive2 == nullptr)
        std::cout << "primitive2 is null" << std::endl;

    std::cout << "camera name: " << camera->getName() << " position: " << camera->getPosition() << std::endl;
    std::cout << "primitive name: " << primitive->getName() << " position: " << primitive->getPosition() << std::endl;
    std::cout << "camera2 name: " << camera2->getName() << " position: " << camera2->getPosition() << std::endl;
    std::cout << "primitive2 name: " << primitive2->getName() << " position: " << primitive2->getPosition() << std::endl;
    std::cout << "light name: " << light->getName() << " position: " << light->getPosition() << std::endl;

    PPM::PPM ppm = PPM::PPM(1920, 1080);
    ppm.fill(PPM::RGB(123, 189, 2));
    ppm.save("test.ppm");
    return 0;
}

int main()
{
    return playground();
}

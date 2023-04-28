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
#include "Generation.hpp"

int playground()
{
    Factory factory;

    //factory.registerObject(Raytracer::CAMERA, Raytracer::Camera::);
    factory.registerObject(Raytracer::PRIMITIVE, Raytracer::Primitive::createObject);
    factory.registerObject(Raytracer::LIGHT, Raytracer::Light::createObject);

    //auto camera = factory.createObject(Raytracer::CAMERA, "camera", Math::Vector3D(0, 0, 0), Math::Vector3D(0, 0, 0));
    auto primitive = factory.createObject(Raytracer::PRIMITIVE, "primitive", Math::Vector3D(0, 0, 0), Math::Vector3D(0, 0, 0));
    //auto camera2 = factory.createObject(Raytracer::CAMERA, "camera2", Math::Vector3D(3, 3, 3), Math::Vector3D(0, 0, 0));
    auto primitive2 = factory.createObject(Raytracer::PRIMITIVE, "primitive2", Math::Vector3D(3, 3, 3), Math::Vector3D(0, 0, 0));
    auto light = factory.createObject(Raytracer::LIGHT, "light", Math::Vector3D(0, 0, 0), Math::Vector3D(0, 0, 0));

    if (light == nullptr)
        std::cout << "light is null" << std::endl;
    //if (camera == nullptr)
        std::cout << "camera is null" << std::endl;
    if (primitive == nullptr)
        std::cout << "primitive is null" << std::endl;
    //if (camera2 == nullptr)
        std::cout << "camera2 is null" << std::endl;
    if (primitive2 == nullptr)
        std::cout << "primitive2 is null" << std::endl;

    //std::cout << "camera name: " << camera->getName() << " position: " << camera->getPosition() << std::endl;
    std::cout << "primitive name: " << primitive->getName() << " position: " << primitive->getPosition() << std::endl;
    //std::cout << "camera2 name: " << camera2->getName() << " position: " << camera2->getPosition() << std::endl;
    std::cout << "primitive2 name: " << primitive2->getName() << " position: " << primitive2->getPosition() << std::endl;
    std::cout << "light name: " << light->getName() << " position: " << light->getPosition() << std::endl;

    PPM::PPM ppm = PPM::PPM(1920, 1080);
    ppm.fill(PPM::RGB(123, 189, 2));
    ppm.save("test.ppm");
    return 0;
}

int main ()
{
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
                pixels.push_back(PPM::RGB(255, 0, 0));
            } else if (s2.hits(r)) {
                // std::cout << "2 hit: " << *s2.hits(r) << std::endl;
                pixels.push_back(PPM::RGB(0, 0, 255));
            } else {
                pixels.push_back(PPM::RGB(0, 0, 0));
            }
        }
    }
    img.bufferToImage(pixels);
    img.save("img2.ppm");

    return 0;
}

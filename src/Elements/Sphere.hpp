/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-raytracer-tom.laiolo
** File description:
** Primitive
*/

#pragma once

#include <memory>
#include <vector>
#include "AElement.hpp"
#include "Data.hpp"

namespace Raytracer {
    class Sphere : public AElement{
        public:
            Sphere(const std::string &name, Math::Point3D center, Math::Vector3D rotation, Math::Vector3D direction, double radius = 1);
            ~Sphere();
            void translate(double x, double y, double z);
            void rotate(double x, double y, double z);
            std::shared_ptr<Math::Point3D> hits(const Math::Ray &ray);
            PPM::RGB hits(const Math::Ray &ray);
            static std::shared_ptr <Raytracer::IElement> createObject(Raytracer::Data data) {
                return std::make_shared<Raytracer::Sphere>(data.getName(), data.getCenter(), data.getRotation(), data.getDirection(), data.getDouble());
            }
        private:
            double _radius;
    };
}

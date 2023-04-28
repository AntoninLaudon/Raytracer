/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-raytracer-tom.laiolo
** File description:
** Primitive
*/

#pragma once

#include <memory>
#include "AElement.hpp"

namespace Raytracer {
    class Sphere : public AElement{
        public:
            Sphere(const std::string &name, Math::Point3D center, Math::Vector3D rotation, Math::Vector3D direction, double radius = 1);
            ~Sphere();
            void translate(double x, double y, double z);
            void rotate(double x, double y, double z);
            void clearElement();
            PPM::RGB hits(const Math::Ray &ray);
            static std::shared_ptr <Raytracer::IElement> createObject(const std::string &name, Math::Point3D position, Math::Vector3D rotation, Math::Vector3D direction, double radius = 1) {
                return std::make_shared<Raytracer::Sphere>(name, position, rotation, direction, radius);
            }
        protected:
        private:
            double _radius;
    };
}

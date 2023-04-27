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
            Sphere(const std::string& name, Math::Vector3D& position, Math::Vector3D& rotation);
            ~Sphere();
            void translate(float x, float y, float z);
            //void rotate(float x, float y, float z);
            void clearElement();
            bool hits(const Math::Ray &ray) const;
            static std::shared_ptr <Raytracer::IElement> createObject(const std::string& name, Math::Vector3D& position, Math::Vector3D& rotation) {
                return std::make_shared<Raytracer::Sphere>(name, position, rotation);
            }
        protected:
        private:
    };
}

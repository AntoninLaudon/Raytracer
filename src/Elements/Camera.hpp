/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-raytracer-tom.laiolo
** File description:
** Camera
*/

#pragma once

#include <memory>
#include "AElement.hpp"

namespace Raytracer {
    class Camera {
        public:
            Camera(const std::string& name, Math::Vector3D& position, Math::Vector3D& rotation);
            ~Camera();
            void translate(float x, float y, float z);
            //void rotate(float x, float y, float z);
            void clearElement();
            Math::Point3D Intersect();
            static std::shared_ptr<Raytracer::IElement> createObject(const std::string& name, Math::Vector3D& position, Math::Vector3D& rotation) {
                return std::make_shared<Raytracer::Camera>(name, position, rotation);
            }
        protected:
        private:
            Math::Rectangle3D _rectangle;
    };
}

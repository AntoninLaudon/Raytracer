/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-raytracer-tom.laiolo
** File description:
** IElement
*/

#pragma once

#include <string>

#include "math.hpp"

namespace Raytracer {
    enum ElemType {
        CAMERA,
        PRIMITIVE,
        LIGHT,
        SKYBOX
    };

    class IElement {
        public:
            virtual ~IElement() = default;
            virtual ElemType getType() const = 0;
            virtual std::string getName() const = 0;
            virtual Math::Vector3D getPosition() const = 0;
            virtual void setName(std::string name) = 0;
            virtual void translate(float x, float y, float z) = 0;
            //virtual void rotate(float x, float y, float z) = 0;
            virtual void clearElement() = 0;
            virtual Math::Point3D Intersect() = 0;
        protected:
        private:
            
    };
}

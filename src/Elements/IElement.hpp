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
            IElement();
            ~IElement();
            ElemType getType() const;
            std::string getName() const;
            void setName(std::string name);
            void translate(float x, float y, float z);
            //void rotate(float x, float y, float z);
            void clearElement();
            Math::Point3D Intersect();
        protected:
        private:
            ElemType _type;
            std::string _name;
            Math::Vector3D _position;
            Math::Vector3D _rotation;
    };
}

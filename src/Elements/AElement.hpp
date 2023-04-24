/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-raytracer-tom.laiolo
** File description:
** AElement
*/

#pragma once

#include "IElement.hpp"

namespace Raytracer {

    class AElement : public IElement{
        public:
            ~AElement() = default;
            virtual ElemType getType() const {
                return _type;
            }
            virtual std::string getName() const {
                return _name;
            }
            virtual Math::Vector3D getPosition() const {
                return _position;
            }
            virtual void setName(std::string name) {
                _name = name;
            }
            virtual void translate(float x, float y, float z) = 0;
            //virtual void rotate(float x, float y, float z) = 0;
            virtual void clearElement() = 0;
            virtual Math::Point3D Intersect() = 0;
        protected:
            ElemType _type;
            std::string _name;
            Math::Vector3D _position;
            Math::Vector3D _rotation;
        private:
    };
}

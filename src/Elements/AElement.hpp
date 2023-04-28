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
            virtual Math::Point3D getCenter() const {
                return _center;
            }
            virtual void setName(std::string name) {
                _name = name;
            }
            virtual void translate(double x, double y, double z) = 0;
            virtual void rotate(double x, double y, double z) = 0;
            virtual std::shared_ptr<Math::Point3D> hits(const Math::Ray &ray) = 0;
        protected:
            ElemType _type;
            std::string _name;
            Math::Point3D _center;
            Math::Vector3D _direction;
            Math::Vector3D _rotation;
    };
}

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
            virtual double getDouble() const {
                return _double;
            }
            virtual double getDouble2() const {
                return _double2;
            }
            virtual void setName(std::string name) {
                _name = name;
            }
            virtual PPM::RGB getColor() const {
                return _rgb;
            }
            virtual Math::Vector3D getRotation() {
                return _rotation;
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
            PPM::RGB _rgb;
            double _double;
            double _double2;
    };
}

/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-raytracer-tom.laiolo
** File description:
** Data
*/

#pragma once

#include <string>
#include "Math.hpp"
#include "IElement.hpp"
#include "Camera.hpp"

namespace Raytracer {
    class Data {
        public:
            Data(ElemType type, std::string name, Math::Point3D center, Math::Vector3D direction, Math::Vector3D rotation, double d);
            ~Data();
            ElemType getType();
            std::string getName();
            Math::Point3D getCenter();
            Math::Vector3D getDirection();
            Math::Vector3D getRotation();
            Raytracer::Rectangle3D getScreen();
            double getDouble();
        private:
            ElemType _type;
            std::string _name;
            Math::Point3D _center;
            Math::Vector3D _direction;
            Math::Vector3D _rotation;
            Raytracer::Rectangle3D _screen;
            double _double;
    };
}

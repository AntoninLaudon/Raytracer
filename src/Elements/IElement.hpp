/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-raytracer-tom.laiolo
** File description:
** IElement
*/

#pragma once

#include <string>
#include "Math.hpp"
#include "Generation.hpp"

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
            virtual Math::Point3D getCenter() const = 0;
            virtual void setName(std::string name) = 0;
            virtual void translate(double x, double y, double z) = 0;
            virtual void rotate(double x, double y, double z) = 0;
            virtual PPM::RGB hits() = 0;
    };
}

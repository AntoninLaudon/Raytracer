/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-raytracer-tom.laiolo
** File description:
** IElement
*/

#pragma once

#include <string>
#include <memory>
#include "Math.hpp"
#include "Generation.hpp"

namespace Raytracer {
    enum ElemType {
        NONE,
        CAMERA,
        LIGHT,
        SKYBOX,
        PRIMITIVE,
        SPHERE,
        PLANE,
        CYLINDER,
        TRIANGLE
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
            virtual std::shared_ptr<Math::Point3D> hits(const Math::Ray &ray) = 0;
            virtual double getLuminosity(std::vector<Raytracer::IElement *> &elements, const Math::Point3D &land) const = 0;
            virtual PPM::RGB getColor() const = 0;
    };
}

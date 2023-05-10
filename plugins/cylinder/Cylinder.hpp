/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-raytracer-tom.laiolo
** File description:
** Primitive
*/

#pragma once

#include <memory>
#include <vector>
#include "AElement.hpp"
#include "Data.hpp"

namespace Raytracer {
    class Cylinder : public AElement{
        public:
            Cylinder(const std::string name, Math::Point3D center, Math::Vector3D rotation, PPM::RGB rgb, double radius = 1);
            ~Cylinder();
            void translate(double x, double y, double z);
            void rotate(double x, double y, double z);
            std::shared_ptr<Math::Point3D> hits(const Math::Ray &ray);
            double getLuminosity(std::vector<Raytracer::IElement *> &elements, const Math::Point3D &land) const;
            double getRadius() const {return _radius;}
        private:
            double _radius;
    };
}

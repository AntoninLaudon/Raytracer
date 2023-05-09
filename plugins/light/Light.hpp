/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-raytracer-tom.laiolo
** File description:
** Light
*/

#pragma once

#include <memory>
#include "AElement.hpp"
#include "Data.hpp"

namespace Raytracer {
    class Light : public AElement{
        public:
            Light();
            Light(const std::string name, Math::Point3D center, Math::Vector3D rotation, double radius = 1, double radius2 = 1);
            ~Light();
            void translate(double x, double y, double z);
            void rotate(double x, double y, double z);
            std::shared_ptr<Math::Point3D> hits(const Math::Ray &ray);
            double getLuminosity(std::vector<Raytracer::IElement *> &elements, const Math::Point3D &land) const;
        protected:
        private:
            double _intensity;
    };
}

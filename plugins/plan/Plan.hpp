/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-raytracer-tom.laiolo
** File description:
** Plan
*/

#pragma once

#include <memory>
#include <vector>
#include "AElement.hpp"
#include "Data.hpp"

namespace Raytracer
{
    class Plan : public AElement {
        public:
            Plan(const std::string &name, Math::Point3D center, Math::Vector3D rotation, Math::Vector3D direction1, Math::Vector3D direction2, PPM::RGB rgb);
            ~Plan();
            void translate(double x, double y, double z);
            void rotate(double x, double y, double z);
            std::shared_ptr<Math::Point3D> hits(const Math::Ray &ray);
            double getLuminosity(std::vector<Raytracer::IElement *> &elements, const Math::Point3D &land) const;
        private:
            Math::Vector3D _dir1;
            Math::Vector3D _dir2;
            Math::Vector3D _normal;
    };
} // namespace raytracer



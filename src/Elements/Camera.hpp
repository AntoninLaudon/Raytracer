/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-raytracer-tom.laiolo
** File description:
** Camera
*/

#pragma once

#include <memory>
#include "math.hpp"
namespace Raytracer {

    class Rectangle3d {
        public:
            Rectangle3d();
            Rectangle3d(Math::Point3D origin, Math::Vector3D bottom_side, Math::Vector3D left_side);
            ~Rectangle3d();
            Math::Point3D pointAt(double u, double v);
            Math::Point3D getorigin();
        private:
            Math::Point3D _origin;
            Math::Vector3D _bottom_side;
            Math::Vector3D _left_side;
    };
    class Camera {
        public:
            Camera(Math::Point3D origin, Rectangle3d screen);
            ~Camera();
            Rectangle3d getScreen();
            Math::Ray ray(double u, double v);
        protected:
        private:
            Math::Point3D _origin;
            Rectangle3d _screen;
    };
}

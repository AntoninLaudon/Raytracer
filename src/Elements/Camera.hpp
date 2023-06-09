/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-raytracer-tom.laiolo
** File description:
** Camera
*/

#pragma once

#include <memory>
#include "Math.hpp"
namespace Raytracer {

    class Rectangle3D {
        public:
            Rectangle3D();
            Rectangle3D(Math::Point3D origin, Math::Vector3D bottom_side, Math::Vector3D left_side);
            ~Rectangle3D();
            Math::Point3D pointAt(double u, double v);
            Math::Point3D getorigin();
            void translate(double x, double y, double z);
        private:
            Math::Point3D _origin;
            Math::Vector3D _bottom_side;
            Math::Vector3D _left_side;
    };
    class Camera {
        public:
            Camera(Math::Point3D origin, double fov);
            ~Camera();
            Math::Point3D getOrigin();
            Rectangle3D getScreen();
            Math::Ray ray(double u, double v);
            void translate(double x, double y, double z);
        protected:
        private:
            Rectangle3D _screen;
            Math::Point3D _origin;
            double _fov;
    };
}

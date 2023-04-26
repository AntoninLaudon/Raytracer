/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-raytracer-tom.laiolo
** File description:
** camera
*/

#include "math.hpp"
#include "Camera.hpp"

// Rectangle3D

Raytracer::Rectangle3d::Rectangle3d()
{
    _origin = Math::Point3D(0, 0, 0);
    _bottom_side = Math::Vector3D(0, 0, 0);
    _left_side = Math::Vector3D(0, 0, 0);
}

Raytracer::Rectangle3d::Rectangle3d(Math::Point3D origin, Math::Vector3D width, Math::Vector3D height)
{
    _origin = origin;
    _bottom_side = width;
    _left_side = height;
}

Raytracer::Rectangle3d::~Rectangle3d()
{
}

Math::Point3D Raytracer::Rectangle3d::getorigin()
{
    return _origin;
}

Math::Point3D Raytracer::Rectangle3d::pointAt(double u, double v)
{
    return _origin + _bottom_side * u + _left_side * v;
}

Raytracer::Camera::Camera(Math::Point3D origin, Raytracer::Rectangle3d screen)
{
    _origin = origin;
    _screen = screen;
}

Raytracer::Camera::~Camera()
{
}

Raytracer::Rectangle3d Raytracer::Camera::getScreen()
{
    return _screen;
}

//Math::Ray Raytracer::Camera::ray(double u, double v)
//{
//    Math::Point3D origin = _origin;
//    Math::Vector3D direction = Math::Vector3D(
//        _screen.getA().getX() + u * (_screen.getB().getX() - _screen.getA().getX()),
//        _screen.getA().getY() + v * (_screen.getB().getY() - _screen.getA().getY()),
//        _screen.getA().getZ() + v * (_screen.getB().getZ() - _screen.getA().getZ())
//    );
//    return Math::Ray(origin, direction);
//}
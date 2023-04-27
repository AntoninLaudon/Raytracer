/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-raytracer-tom.laiolo
** File description:
** camera
*/

#include "Math.hpp"
#include "Camera.hpp"

// Rectangle3D

Raytracer::Rectangle3D::Rectangle3D()
{
    _origin = Math::Point3D(0, 0, 0);
    _bottom_side = Math::Vector3D(0, 0, 0);
    _left_side = Math::Vector3D(0, 0, 0);
}

Raytracer::Rectangle3D::Rectangle3D(Math::Point3D origin, Math::Vector3D width, Math::Vector3D height)
{
    _origin = origin;
    _bottom_side = width;
    _left_side = height;
}

Raytracer::Rectangle3D::~Rectangle3D()
{
}

Math::Point3D Raytracer::Rectangle3D::getorigin()
{
    return _origin;
}

Math::Point3D Raytracer::Rectangle3D::pointAt(double u, double v)
{
    return _origin + _bottom_side * u + _left_side * v;
}

Raytracer::Camera::Camera(Math::Point3D origin, Raytracer::Rectangle3D screen)
{
    _origin = origin;
    _screen = screen;
}

Raytracer::Camera::~Camera()
{
}

Raytracer::Rectangle3D Raytracer::Camera::getScreen()
{
    return _screen;
}

Math::Ray Raytracer::Camera::ray(double u, double v)
{
    Math::Point3D point = _screen.pointAt(u, v);
    Math::Vector3D direction (point.getX() - _origin.getX(), point.getY() - _origin.getY(), point.getZ() - _origin.getZ());
    return Math::Ray(_origin, direction);
}

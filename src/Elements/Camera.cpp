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

Raytracer::Camera::Camera(Math::Point3D origin, double fov)
{
    _screen = Rectangle3D(origin, Math::Vector3D(2, 0, 0), Math::Vector3D(0, 9.0/16.0*2.0, 0));
    if (fov < 0 || fov > 180)
        throw std::invalid_argument("fov must be between 0 and 180");
    _fov = fov;

    double minDist = -1.75;
    double maxDist = -0.75;

    double distRange = maxDist - minDist;
    double distRatio = (_fov / 180.0);

    double dist = minDist + (distRange * distRatio);

    if (dist > maxDist) {
        dist = maxDist;
    } else if (dist < minDist) {
        dist = minDist;
    }

    Math::Point3D position = _screen.getorigin();
    position.setX((position.getX() + 1));
    position.setY((position.getY() + 9.0/16.0));
    position.setZ(position.getZ() + dist);

    _origin = position;
}

Raytracer::Camera::~Camera()
{
}

Raytracer::Rectangle3D Raytracer::Camera::getScreen()
{
    return _screen;
}

Math::Point3D Raytracer::Camera::getOrigin()
{
    return _origin;
}

Math::Ray Raytracer::Camera::ray(double u, double v)
{
    Math::Point3D point = _screen.pointAt(u, v);
    Math::Vector3D direction (point.getX() - _origin.getX(), point.getY() - _origin.getY(), point.getZ() - _origin.getZ());
    return Math::Ray(_origin, direction);
}

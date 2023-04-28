/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-raytracer-tom.laiolo
** File description:
** Sphere
*/

#include "Sphere.hpp"

Raytracer::Sphere::Sphere(const std::string &name, Math::Point3D center, Math::Vector3D rotation, Math::Vector3D direction, double radius)
{
    _name = name;
    _center = center;
    _direction = direction;
    _rotation = rotation;
    _radius = radius;
    _type = PRIMITIVE;
}

Raytracer::Sphere::~Sphere()
{
}

void Raytracer::Sphere::translate(double x, double y, double z)
{
    _center.setX(_center.getX() + x);
    _center.setY(_center.getY() + y);
    _center.setZ(_center.getZ() + z);
}

void Raytracer::Sphere::rotate(double x, double y, double z)
{
    _rotation.setX(_rotation.getX() + x);
    _rotation.setY(_rotation.getY() + y);
    _rotation.setZ(_rotation.getZ() + z);
}

std::shared_ptr<Math::Point3D> Raytracer::Sphere::hits(const Math::Ray &ray)
{
    Math::Point3D a = ray.getOrigin();
    Math::Vector3D u = ray.getDirection();
    // _center;
    // _radius;

    // pow(x - _center.getX()) + pow(y - _center.getY()) + pow(z - _center.getZ()) = pow(_radius);

    // pow(a.getX() + u.getX() * t - _center.getX()) + pow(a.getY() + u.getY() * t - _center.getY()) + pow(a.getZ() + u.getZ() * t - _center.getZ()) = pow(_radius);

    // pow(a.getX() + u.getX() * t - _center.getX()) + pow(a.getY() + u.getY() * t - _center.getY()) + pow(a.getZ() + u.getZ() * t - _center.getZ()) = pow(_radius);
    //take the line before and replace the pow(x) by (x * x)
    // 
    return std::make_shared<Math::Point3D>(0, 0, 0);
}

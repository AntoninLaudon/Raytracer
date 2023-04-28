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

void Raytracer::Sphere::clearElement()
{
}

PPM::RGB Raytracer::Sphere::hits(const Math::Ray &ray)
{
    Math::Point3D origin = ray.getOrigin();
    Math::Vector3D direction = ray.getDirection();
    Math::Vector3D oc = origin - _center;
    Math::Vector3D pv (oc.getY() * direction.getZ() - oc.getZ() * direction.getY(),
                       oc.getZ() * direction.getX() - oc.getX() * direction.getZ(),
                       oc.getX() * direction.getY() - oc.getY() * direction.getX());
    
    if (pv.length() / direction.length() > _radius)
        return PPM::RGB(0, 0, 0);
    return PPM::RGB(255, 255, 255);
}

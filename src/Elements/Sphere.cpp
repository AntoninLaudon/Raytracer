/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-raytracer-tom.laiolo
** File description:
** Sphere
*/

#include "Sphere.hpp"

Raytracer::Sphere::Sphere(
    const std::string &name, Math::Vector3D &position, Math::Vector3D &rotation)
{
    _name = name;
    _position = position;
    _rotation = rotation;
    _type = PRIMITIVE;
}

Raytracer::Sphere::~Sphere()
{
}

void Raytracer::Sphere::translate(float x, float y, float z)
{
    _position.setX(_position.getX() + x);
    _position.setY(_position.getY() + y);
    _position.setZ(_position.getZ() + z);
}

void Raytracer::Sphere::clearElement()
{
}

bool Math::Sphere::hits(const Math::Ray &ray) const
{
    Math::Point3D origin = ray.getOrigin();
    Math::Vector3D direction = ray.getDirection();
    Math::Vector3D oc = origin - _center;
    Math::Vector3D pv (oc.getY() * direction.getZ() - oc.getZ() * direction.getY(),
                       oc.getZ() * direction.getX() - oc.getX() * direction.getZ(),
                       oc.getX() * direction.getY() - oc.getY() * direction.getX());
    
    if (pv.length() / direction.length() > _radius)
        return false;
    return true;
}

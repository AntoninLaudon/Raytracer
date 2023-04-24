/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-raytracer-tom.laiolo
** File description:
** Primitive
*/

#include "Primitive.hpp"

Raytracer::Primitive::Primitive(
    const std::string& name, Math::Vector3D& position, Math::Vector3D& rotation)
{
    _name = name;
    _position = position;
    _rotation = rotation;
    _type = PRIMITIVE;
}

Raytracer::Primitive::~Primitive()
{
}

void Raytracer::Primitive::translate(float x, float y, float z)
{
    _position.setX(_position.getX() + x);
    _position.setY(_position.getY() + y);
    _position.setZ(_position.getZ() + z);
}

void Raytracer::Primitive::clearElement()
{
}

Math::Point3D Raytracer::Primitive::Intersect()
{
    return Math::Point3D();
}

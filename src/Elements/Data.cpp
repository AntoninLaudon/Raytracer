/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-raytracer-tom.laiolo
** File description:
** data
*/

#include "Data.hpp"

Raytracer::Data::Data(ElemType type, std::string name, Math::Point3D center, Math::Vector3D direction, Math::Vector3D rotation, double d)
{
    _type = type;
    _name = name;
    _center = center;
    _direction = direction;
    _rotation = rotation;
    _double = d;
}

Raytracer::Data::~Data()
{
}

Raytracer::ElemType Raytracer::Data::getType()
{
    return _type;
}

std::string Raytracer::Data::getName()
{
    return _name;
}

Math::Point3D Raytracer::Data::getCenter()
{
    return _center;
}

Math::Vector3D Raytracer::Data::getDirection()
{
    return _direction;
}

Math::Vector3D Raytracer::Data::getRotation()
{
    return _rotation;
}

Raytracer::Rectangle3D Raytracer::Data::getScreen()
{
    return _screen;
}

double Raytracer::Data::getDouble()
{
    return _double;
}

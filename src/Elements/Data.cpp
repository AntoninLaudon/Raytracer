/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-raytracer-tom.laiolo
** File description:
** data
*/

#include "Data.hpp"

Raytracer::Data::Data(ElemType type, std::string name, Math::Point3D center, Math::Vector3D direction1, Math::Vector3D direction2, Math::Vector3D rotation, double d, double d2, PPM::RGB rgb)
{
    _type = type;
    _name = name;
    _center = center;
    _direction1 = direction1;
    _direction2 = direction2;
    _rotation = rotation;
    _double = d;
    _double2 = d2;
    _rgb = rgb;
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

Math::Vector3D Raytracer::Data::getDirection1()
{
    return _direction1;
}

Math::Vector3D Raytracer::Data::getDirection2()
{
    return _direction2;
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

double Raytracer::Data::getDouble2()
{
    return _double2;
}

PPM::RGB Raytracer::Data::getRGB()
{
    return _rgb;
}

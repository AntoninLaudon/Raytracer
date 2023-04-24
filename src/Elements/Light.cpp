/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-raytracer-tom.laiolo
** File description:
** Light
*/

#include "Light.hpp"

Raytracer::Light::Light(const std::string& name, Math::Vector3D& position, Math::Vector3D& rotation)
{
    _name = name;
    _position = position;
    _rotation = rotation;
    _type = LIGHT;
}

Raytracer::Light::~Light()
{

}

void Raytracer::Light::translate(float x, float y, float z)
{
    _position.setX(_position.getX() + x);
    _position.setY(_position.getY() + y);
    _position.setZ(_position.getZ() + z);
}

void Raytracer::Light::clearElement()
{

}

Math::Point3D Raytracer::Light::Intersect()
{
    return Math::Point3D();
}

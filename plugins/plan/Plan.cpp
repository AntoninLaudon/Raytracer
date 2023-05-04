/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-raytracer-tom.laiolo
** File description:
** Plan
*/

#include "Plan.hpp"

Raytracer::Plan::Plan(const std::string &name, Math::Point3D center, Math::Vector3D rotation, Math::Vector3D dir1, Math::Vector3D dir2)
{
    _name = name;
    _center = center;
    _rotation = rotation;
    _dir1 = dir1;
    _dir2 = dir2;
    _normal = _dir1.cross(_dir2);
}

Raytracer::Plan::~Plan()
{
}

void Raytracer::Plan::translate(double x, double y, double z)
{
    _center.setX(_center.getX() + x);
    _center.setY(_center.getY() + y);
    _center.setZ(_center.getZ() + z);
}

void Raytracer::Plan::rotate(double x, double y, double z)
{
    _rotation.setX(_rotation.getX() + x);
    _rotation.setY(_rotation.getY() + y);
    _rotation.setZ(_rotation.getZ() + z);
}

std::shared_ptr<Math::Point3D> Raytracer::Plan::hits(const Math::Ray &ray)
{
    Math::Point3D origin = ray.getOrigin();
    Math::Vector3D direction = ray.getDirection();

    double a = origin.getX();
    double b = origin.getY();
    double c = origin.getZ();

    double u = direction.getX();
    double v = direction.getY();
    double w = direction.getZ();

    double x = _normal.getX();
    double y = _normal.getY();
    double z = _normal.getZ();

    double d = -(_normal.getX() * _center.getX() + _normal.getY() * _center.getY() + _normal.getZ() * _center.getZ());
    double t = (-a * x - b * y - c * z - d) / (u * x + v * y + w * z);

    if (t == t)
        return std::make_shared<Math::Point3D>(a + u * t, b + v * t, c + w * t);
    return nullptr;
}

extern "C" Raytracer::Plan *createPlan(const std::string &name, Math::Point3D center, Math::Vector3D rotation, Math::Vector3D dir1, Math::Vector3D dir2)
{
    return new Raytracer::Plan(name, center, rotation, dir1, dir2);
}

extern "C" Raytracer::ElemType getType()
{
    return Raytracer::PLAN;
}

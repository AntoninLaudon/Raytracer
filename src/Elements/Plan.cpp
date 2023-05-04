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
{(void)ray;
    /**
     * TODO
     * 1. Get the normal of the plan (cross product of dir1 and dir2)
     * 2. Récupérer l'équation du plan (ax + by + cz + d = 0) : https://www.youtube.com/watch?v=s4xqI6IPQBY
     * 3. Récupérer l'équation de la droite (x = x0 + at, y = y0 + bt, z = z0 + ct)
     * 4. Résoudre l'équation du plan avec l'équation de la droite (https://www.youtube.com/watch?v=QJYmyhnaaek)
    */
   return nullptr;
}

extern "C" Raytracer::Plan *createPlan(const std::string &name, Math::Point3D center, Math::Vector3D rotation, Math::Vector3D dir1, Math::Vector3D dir2)
{
    return new Raytracer::Plan(name, center, rotation, dir1, dir2);
}

extern "C" Raytracer::ElemType getTypePlan()//TODO: change getTypePlan to getType
{
    return Raytracer::PLAN;
}

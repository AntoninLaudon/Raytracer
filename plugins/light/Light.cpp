/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-raytracer-tom.laiolo
** File description:
** Light
*/

#include "Light.hpp"

Raytracer::Light::Light()
{
    _name = "Light";
    _center = Math::Point3D(0, 0, 0);
    _rotation = Math::Vector3D(0, 0, 0);
    _type = LIGHT;
    _intensity = 1;
    _rgb = PPM::RGB(0, 0, 0);
}

Raytracer::Light::Light(const std::string name, Math::Point3D center, Math::Vector3D rotation, PPM::RGB rgb, double intensity)
{
    _name = name;
    _center = center;
    _rotation = rotation;
    _type = LIGHT;
    _intensity = intensity;
    _rgb = rgb;
}

Raytracer::Light::~Light()
{

}

void Raytracer::Light::translate(double x, double y, double z)
{
    _center.setX(_center.getX() + x);
    _center.setY(_center.getY() + y);
    _center.setZ(_center.getZ() + z);
}

void Raytracer::Light::rotate(double x, double y, double z)
{
    _rotation.setX(_rotation.getX() + x);
    _rotation.setY(_rotation.getY() + y);
    _rotation.setZ(_rotation.getZ() + z);
}

double Raytracer::Light::getLuminosity(std::vector<Raytracer::IElement *> &elements, const Math::Point3D &land) const
{
    elements = elements;
    
    return land.getX() * 0.0;
}

std::shared_ptr<Math::Point3D> Raytracer::Light::hits(const Math::Ray &ray)
{
    ray.getOrigin();
    return nullptr;
}

extern "C" Raytracer::IElement *createObject(Raytracer::Data data) {
    std::cout << "Creating Light : " << data.getName() << std::endl;
    return new Raytracer::Light(data.getName(), data.getCenter(), data.getRotation(), data.getRGB(), data.getDouble());
}

extern "C" Raytracer::ElemType getType() {
    return Raytracer::LIGHT;
}

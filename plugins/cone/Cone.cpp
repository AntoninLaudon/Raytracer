/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-raytracer-tom.laiolo
** File description:
** Cone
*/

#include "Cone.hpp"

Raytracer::Cone::Cone(const std::string name, Math::Point3D center, Math::Vector3D rotation, Math::Vector3D direction, PPM::RGB rgb, double radius)
{
    _name = name;
    _center = center;
    _direction = direction;
    _rotation = rotation;
    _radius = radius;
    _type = PRIMITIVE;
    _rgb = rgb;
}

Raytracer::Cone::~Cone()
{
}

void Raytracer::Cone::translate(double x, double y, double z)
{
    _center.setX(_center.getX() + x);
    _center.setY(_center.getY() + y);
    _center.setZ(_center.getZ() + z);
}

void Raytracer::Cone::rotate(double x, double y, double z)
{
    _rotation.setX(_rotation.getX() + x);
    _rotation.setY(_rotation.getY() + y);
    _rotation.setZ(_rotation.getZ() + z);
}

std::shared_ptr<Math::Point3D> Raytracer::Cone::hits(const Math::Ray &ray)
{
    Math::Point3D origin = ray.getOrigin();
    Math::Vector3D direction = ray.getDirection();

    double a = origin.getX();
    double b = origin.getY();
    double c = origin.getZ();

    double u = direction.getX();
    double v = direction.getY();
    double w = direction.getZ();

    double h = _center.getX();
    double i = _center.getY();
    double j = _center.getZ();

    double r = _radius;

    double t1 = ((-a * u - b * v - c * w + h * u + i * v + j * w) / (pow(u, 2) + pow(v, 2) + pow(w, 2))) - sqrt((-pow(a, 2) * pow(v, 2) - pow(a, 2) * pow(w, 2) + 2 * a * b * u * v + 2 * a * c * u * w + 2 * a * h * pow(v, 2) + 2 * a * h * pow(w, 2) - 2 * a * i * u * v - 2 * a * j * u * w - pow(b, 2) * pow(u, 2) - pow(b, 2) * pow(w, 2) + 2 * b * c * v * w - 2 * b * h * u * v + 2 * b * i * pow(u, 2) + 2 * b * i * pow(w, 2) - 2 * b * j * v * w - pow(c, 2) * pow(u, 2) - pow(c, 2) * pow(v, 2) - 2 * c * h * u * w - 2 * c * i * v * w + 2 * c * j * pow(u, 2) + 2 * c * j * pow(v, 2) - pow(h, 2) * pow(v, 2) - pow(h, 2) * pow(w, 2) + 2 * h * i * u * v + 2 * h * j * u * w - pow(i, 2) * pow(u, 2) - pow(i, 2) * pow(w, 2) + (2 * i * j * v * w) - pow(j, 2) * pow(u, 2) - pow(j, 2) * pow(v, 2) + pow(r, 2) * pow(u, 2) + pow(r, 2) * pow(v, 2) + pow(r, 2) * pow(w, 2)) / pow((pow(u, 2) + pow(v, 2) + pow(w, 2)), 2));
    double t2 = ((-a * u - b * v - c * w + h * u + i * v + j * w) / (pow(u, 2) + pow(v, 2) + pow(w, 2))) + sqrt((-pow(a, 2) * pow(v, 2) - pow(a, 2) * pow(w, 2) + 2 * a * b * u * v + 2 * a * c * u * w + 2 * a * h * pow(v, 2) + 2 * a * h * pow(w, 2) - 2 * a * i * u * v - 2 * a * j * u * w - pow(b, 2) * pow(u, 2) - pow(b, 2) * pow(w, 2) + 2 * b * c * v * w - 2 * b * h * u * v + 2 * b * i * pow(u, 2) + 2 * b * i * pow(w, 2) - 2 * b * j * v * w - pow(c, 2) * pow(u, 2) - pow(c, 2) * pow(v, 2) - 2 * c * h * u * w - 2 * c * i * v * w + 2 * c * j * pow(u, 2) + 2 * c * j * pow(v, 2) - pow(h, 2) * pow(v, 2) - pow(h, 2) * pow(w, 2) + 2 * h * i * u * v + 2 * h * j * u * w - pow(i, 2) * pow(u, 2) - pow(i, 2) * pow(w, 2) + (2 * i * j * v * w) - pow(j, 2) * pow(u, 2) - pow(j, 2) * pow(v, 2) + pow(r, 2) * pow(u, 2) + pow(r, 2) * pow(v, 2) + pow(r, 2) * pow(w, 2)) / pow((pow(u, 2) + pow(v, 2) + pow(w, 2)), 2));

    //std::cout << "origin : " << origin << std::endl;
    //std::cout << "direction : " << direction << std::endl;
    //std::cout << "t1 : " << t1 << std::endl;
    //std::cout << "t2 : " << t2 << std::endl << std::endl;

    Math::Point3D p1 = origin + direction * t1;
    Math::Point3D p2 = origin + direction * t2;

    if (t1 == t1 && t2 == t2) {
        p1.setColor(_rgb);
        p2.setColor(_rgb);
        double d1 = Math::Vector3D(origin - p1).length();
        double d2 = Math::Vector3D(origin - p2).length();

        if (d1 < d2) {
            return std::make_shared<Math::Point3D>(p1);
        } else {
            return std::make_shared<Math::Point3D>(p2);
        }
    }

    if (t1 == t1) {
        p1.setColor(_rgb);
        return std::make_shared<Math::Point3D>(p1);
    }
    if (t2 == t2) {
        p2.setColor(_rgb);
        return std::make_shared<Math::Point3D>(p2);
    }
    return nullptr;
}

extern "C" Raytracer::IElement *createObject(Raytracer::Data data) {
    std::cout << "Creating cone : " << data.getName() << std::endl;
    return new Raytracer::Cone(data.getName(), data.getCenter(), data.getRotation(), data.getDirection(), data.getRGB(), data.getDouble());
}

extern "C" Raytracer::ElemType getType() {
    return Raytracer::CONE;
}

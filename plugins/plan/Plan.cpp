/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-raytracer-tom.laiolo
** File description:
** Plan
*/

#include "Plan.hpp"

Raytracer::Plan::Plan(const std::string &name, Math::Point3D center, Math::Vector3D rotation, Math::Vector3D dir1, Math::Vector3D dir2, PPM::RGB rgb)
{
    _name = name;
    _center = center;
    _rotation = rotation;
    _dir1 = dir1;
    _dir2 = dir2;
    _normal = _dir1.cross(_dir2);
    _rgb = rgb;
    _type = PLANE;
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

    if (t == t && t > 0) {
        Math::Point3D pt(a + u * t, b + v * t, c + w * t);
        if (pt == pt) {
            pt.setColor(_rgb);
            return std::make_shared<Math::Point3D> (pt);
        }
    }
    return nullptr;
}

double Raytracer::Plan::getLuminosity(std::vector<Raytracer::IElement *> &elements, const Math::Point3D &land) const
{
    double luminosity = 0.1;
    int nbrLights = 0;
    double dot = 0;

    for (auto &element : elements) {
        if (element->getType() == Raytracer::LIGHT) {
            nbrLights++;
            
            Math::Vector3D landToLight((element->getCenter().getX() - land.getX()), (element->getCenter().getY() - land.getY()), (element->getCenter().getZ() - land.getZ()));
            landToLight.normalize();
            dot = landToLight.dot(element->getRotation());
            if (-dot < 1 / (180 / (180 - element->getDouble2())) && element->getRotation() != Math::Vector3D(0, 0, 0))
                continue;

            landToLight = {land - element->getCenter()};
            landToLight.normalize();
            dot = landToLight.dot(_normal);
            for (auto &primitive : elements) {
                if (primitive->getType() >= Raytracer::PRIMITIVE && primitive->getName() != _name) {
                    std::shared_ptr<Math::Point3D> hit = primitive->hits(Math::Ray(land, element->getCenter() - land));
                    if (hit != nullptr) {
                        if (Math::Vector3D(land.getX() - hit->getX(), land.getY() - hit->getY(), land.getZ() - hit->getZ()).length() > Math::Vector3D(land.getX() - element->getCenter().getX(), land.getY() - element->getCenter().getY(), land.getZ() - element->getCenter().getZ()).length())
                            continue;
                        dot = 0;
                        break;
                    }
                }
            }
            if (dot < 0)
                dot = 0;
            luminosity += dot;
        }
    }
    if (nbrLights == 0)
        return luminosity;
    luminosity = luminosity < 0.1 ? 0.1 : luminosity;
    if (luminosity == luminosity)
        return luminosity;
    return 0.1;

}

extern "C" Raytracer::Plan *createObject(Raytracer::Data data)
{
    std::cout << "Creating plan : " << data.getName() << std::endl;
    return new Raytracer::Plan(data.getName(), data.getCenter(), data.getRotation(), data.getDirection1(), data.getDirection2(), data.getRGB());
}

extern "C" Raytracer::ElemType getType()
{
    return Raytracer::PLANE;
}

/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-raytracer-tom.laiolo
** File description:
** Triangle
*/

#include "Triangle.hpp"

Raytracer::Triangle::Triangle(const std::string name, Math::Point3D center, Math::Vector3D rotation, Math::Vector3D vector1, Math::Vector3D vector2, PPM::RGB rgb)
{
    _name = name;
    _center = center;
    _rotation = rotation;
    _type = TRIANGLE;
    _vector1 = vector1;
    _vector2 = vector2;
    _rgb = rgb;
}

Raytracer::Triangle::~Triangle()
{
}

void Raytracer::Triangle::translate(double x, double y, double z)
{
    _center.setX(_center.getX() + x);
    _center.setY(_center.getY() + y);
    _center.setZ(_center.getZ() + z);
}

void Raytracer::Triangle::rotate(double x, double y, double z)
{
    _rotation.setX(_rotation.getX() + x);
    _rotation.setY(_rotation.getY() + y);
    _rotation.setZ(_rotation.getZ() + z);
}

double Raytracer::Triangle::getLuminosity(std::vector<Raytracer::IElement *> &elements, const Math::Point3D &land) const
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
            dot = landToLight.dot(_vector1.cross(_vector2));
            dot /= 16;
            std::cout << dot << std::endl;
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
            luminosity += dot;
        }
    }
    if (nbrLights == 0)
        return luminosity;
    luminosity /= nbrLights;

    if (luminosity < 0.1)
        luminosity = 0.1;
    
    if (luminosity == luminosity) {
        return luminosity;
    }
    return 0.1;
}

std::shared_ptr<Math::Point3D> Raytracer::Triangle::hits(const Math::Ray &ray)
{
    Math::Point3D origin = ray.getOrigin();
    Math::Vector3D direction = ray.getDirection();

    Math::Vector3D tvec = origin - _center;
    Math::Vector3D pvec = direction.cross(_vector2);
    double det = _vector1.dot(pvec);

    if (det > -0.000001 && det < 0.000001)
        return nullptr;

    double inv_det = 1.0 / det;
    double u = tvec.dot(pvec) * inv_det;
    if (u < 0.0 || u > 1.0)
        return nullptr;

    Math::Vector3D qvec = tvec.cross(_vector1);
    double v = direction.dot(qvec) * inv_det;
    if (v < 0.0 || u + v > 1.0)
        return nullptr;
    
    double t = _vector2.dot(qvec) * inv_det;
    if (t > 0.000001) {
        Math::Point3D point = origin + direction * t;
        point.setColor(_rgb);
        return std::make_shared<Math::Point3D>(point);
    }
    return nullptr;
}

extern "C" Raytracer::IElement *createObject(Raytracer::Data data) {
    std::cout << "Creating Triangle : " << data.getName() << std::endl;
    return new Raytracer::Triangle(data.getName(), data.getCenter(), data.getRotation(), data.getDirection1(), data.getDirection2(), data.getRGB());
}

extern "C" Raytracer::ElemType getType() {
    return Raytracer::TRIANGLE;
}

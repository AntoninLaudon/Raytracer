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

double Raytracer::Cone::getLuminosity(std::vector<Raytracer::IElement *> &elements, const Math::Point3D &land) const
{
    double luminosity = 0.1;
    int nbrLights = 0;
    double dot = 0;

    for (auto &element : elements) {
        if (element->getType() == Raytracer::LIGHT) {
            nbrLights++;
            Math::Vector3D centerland = _center - land;
            double x = centerland.length() * cos(_radius);
            Math::Point3D Z1 = _center + (x * _rotation);
            Math::Point3D Z2 = _center + (x * _rotation * -1);
            
            Math::Vector3D centerToLight((_center.getX() - element->getCenter().getX()), (_center.getY() - element->getCenter().getY()), (_center.getZ() - element->getCenter().getZ()));
            Math::Vector3D centerToLand1((Z1.getX() - land.getX()), (Z1.getY() - land.getY()), (Z1.getZ() - land.getZ()));
            Math::Vector3D centerToLand2((Z2.getX() - land.getX()), (Z2.getY() - land.getY()), (Z2.getZ() - land.getZ()));
            if (centerToLand1.length() < centerToLand2.length()) {
                centerToLand1.normalize();
                centerToLight.normalize();
                dot = centerToLand1.dot(centerToLight);
            } else {
                centerToLand2.normalize();
                centerToLight.normalize();
                dot = centerToLand2.dot(centerToLight);
            }

            for (auto &primitive : elements) {
                if (primitive->getType() == Raytracer::PRIMITIVE && primitive->getName() != _name) {
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
    luminosity = luminosity < 0.1 ? 0.1 : luminosity;
    if (luminosity == luminosity)
        return luminosity;
    return 0.1;
}

std::shared_ptr<Math::Point3D> Raytracer::Cone::hits(const Math::Ray &ray)
{
    Math::Point3D p = ray.getOrigin();
    Math::Point3D pa = _center;
    Math::Vector3D va = _rotation;
    va.normalize();
    Math::Vector3D v = ray.getDirection();
    double a = _radius;

    Math::Vector3D tmp1 = v - va * (v.dot(va));
    Math::Vector3D tmp2 = p - pa - va * (p - pa).dot(va);

    double A = pow(cos(a), 2) * tmp1.dot(tmp1) - pow(sin(a), 2) * pow(v.dot(va), 2);
    double B = 2 * pow(cos(a), 2) * tmp1.dot(tmp2) - 2 * pow(sin(a), 2) * v.dot(va) * (p - pa).dot(va);
    double C = pow(cos(a), 2) * tmp2.dot(tmp2) - pow(sin(a), 2) * pow((p - pa).dot(va), 2);

    double delta = pow(B, 2) - 4 * A * C;

    if (delta < 0)
        return nullptr;
    double k1 = (-B - sqrt(delta)) / (2 * A);
    double k2 = (-B + sqrt(delta)) / (2 * A);
    Math::Point3D p1 = p + v * k1;
    Math::Point3D p2 = p + v * k2;
    p1.setColor(_rgb);
    p2.setColor(_rgb);
    if (k1 < 0 && k2 < 0)
        return nullptr;
    if (k1 < 0)
        return std::make_shared<Math::Point3D>(p2);
    if (k2 < 0)
        return std::make_shared<Math::Point3D>(p1);
    if (k1 < k2)
        return std::make_shared<Math::Point3D>(p1);
    return std::make_shared<Math::Point3D>(p2);
}

extern "C" Raytracer::IElement *createObject(Raytracer::Data data) {
    std::cout << "Creating cone : " << data.getName() << std::endl;
    return new Raytracer::Cone(data.getName(), data.getCenter(), data.getRotation(), data.getDirection1(), data.getRGB(), data.getDouble());
}

extern "C" Raytracer::ElemType getType() {
    return Raytracer::CONE;
}

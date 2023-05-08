/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-raytracer-tom.laiolo
** File description:
** Sphere
*/

#include "Sphere.hpp"

Raytracer::Sphere::Sphere(const std::string name, Math::Point3D center, Math::Vector3D rotation, PPM::RGB rgb, double radius)
{
    _name = name;
    _center = center;
    _rotation = rotation;
    _radius = radius;
    _type = SPHERE;
    _rgb = rgb;
}

Raytracer::Sphere::~Sphere()
{
}

void Raytracer::Sphere::translate(double x, double y, double z)
{
    _center.setX(_center.getX() + x);
    _center.setY(_center.getY() + y);
    _center.setZ(_center.getZ() + z);
}

void Raytracer::Sphere::rotate(double x, double y, double z)
{
    _rotation.setX(_rotation.getX() + x);
    _rotation.setY(_rotation.getY() + y);
    _rotation.setZ(_rotation.getZ() + z);
}

double Raytracer::Sphere::getLuminosity(std::vector<Raytracer::IElement *> &elements, const Math::Point3D &land) const
{
    double luminosity = 0.1;
    int nbrLights = 0;
    double dot = 0;

    for (auto &element : elements) {
        if (element->getType() == Raytracer::LIGHT) {
            nbrLights++;
            Math::Vector3D centerToLight((_center.getX() - element->getCenter().getX()), (_center.getY() - element->getCenter().getY()), (_center.getZ() - element->getCenter().getZ()));
            Math::Vector3D centerToLand((_center.getX() - land.getX()), (_center.getY() - land.getY()), (_center.getZ() - land.getZ()));
            centerToLand.normalize();
            centerToLight.normalize();
            dot = centerToLand.dot(centerToLight);

            for (auto &primitive : elements) {
                if (primitive->getType() >= Raytracer::PRIMITIVE && primitive->getName() != _name) {
                    std::shared_ptr<Math::Point3D> hit = primitive->hits(Math::Ray(land, element->getCenter() - land));
                    // std::shared_ptr<Math::Point3D> hit = primitive->hits(Math::Ray(element->getCenter(), land - element->getCenter()));
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

std::shared_ptr<Math::Point3D> Raytracer::Sphere::hits(const Math::Ray &ray)
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

    double apow = pow(a, 2);
    double bpow = pow(b, 2);
    double cpow = pow(c, 2);
    double upow = pow(u, 2);
    double vpow = pow(v, 2);
    double wpow = pow(w, 2);
    double hpow = pow(h, 2);
    double ipow = pow(i, 2);
    double jpow = pow(j, 2);
    double rpow = pow(r, 2);

    double t1 = ((-a * u - b * v - c * w + h * u + i * v + j * w) / (upow + vpow + wpow)) - sqrt((-apow * vpow - apow * wpow + 2 * a * b * u * v + 2 * a * c * u * w + 2 * a * h * vpow + 2 * a * h * wpow - 2 * a * i * u * v - 2 * a * j * u * w - bpow * upow - bpow * wpow + 2 * b * c * v * w - 2 * b * h * u * v + 2 * b * i * upow + 2 * b * i * wpow - 2 * b * j * v * w - cpow * upow - cpow * vpow - 2 * c * h * u * w - 2 * c * i * v * w + 2 * c * j * upow + 2 * c * j * vpow - hpow * vpow - hpow * wpow + 2 * h * i * u * v + 2 * h * j * u * w - ipow * upow - ipow * wpow + (2 * i * j * v * w) - jpow * upow - jpow * vpow + rpow * upow + rpow * vpow + rpow * wpow) / pow((upow + vpow + wpow), 2));
    double t2 = ((-a * u - b * v - c * w + h * u + i * v + j * w) / (upow + vpow + wpow)) + sqrt((-apow * vpow - apow * wpow + 2 * a * b * u * v + 2 * a * c * u * w + 2 * a * h * vpow + 2 * a * h * wpow - 2 * a * i * u * v - 2 * a * j * u * w - bpow * upow - bpow * wpow + 2 * b * c * v * w - 2 * b * h * u * v + 2 * b * i * upow + 2 * b * i * wpow - 2 * b * j * v * w - cpow * upow - cpow * vpow - 2 * c * h * u * w - 2 * c * i * v * w + 2 * c * j * upow + 2 * c * j * vpow - hpow * vpow - hpow * wpow + 2 * h * i * u * v + 2 * h * j * u * w - ipow * upow - ipow * wpow + (2 * i * j * v * w) - jpow * upow - jpow * vpow + rpow * upow + rpow * vpow + rpow * wpow) / pow((upow + vpow + wpow), 2));

    if (t1 == t1 && t2 == t2) {
        Math::Point3D p1 = origin + direction * t1;
        Math::Point3D p2 = origin + direction * t2;
        p1.setColor(_rgb);
        p2.setColor(_rgb);
        double d1 = Math::Vector3D(origin - p1).length();
        double d2 = Math::Vector3D(origin - p2).length();
        if (d1 < d2 && t1 > 0) {
            return std::make_shared<Math::Point3D>(p1);
        } else if (t2 > 0) {
            return std::make_shared<Math::Point3D>(p2);
        } else {
            return nullptr;
        }
    }

    if (t1 == t1 && t1 > 0) {
        Math::Point3D p1 = origin + direction * t1;
        p1.setColor(_rgb);
        return std::make_shared<Math::Point3D>(p1);
    }
    if (t2 == t2 && t2 > 0) {
        Math::Point3D p2 = origin + direction * t2;
        p2.setColor(_rgb);
        return std::make_shared<Math::Point3D>(p2);
    }
    return nullptr;
}

extern "C" Raytracer::IElement *createObject(Raytracer::Data data) {
    std::cout << "Creating sphere : " << data.getName() << std::endl;
    return new Raytracer::Sphere(data.getName(), data.getCenter(), data.getRotation(), data.getRGB(), data.getDouble());
}

extern "C" Raytracer::ElemType getType() {
    return Raytracer::SPHERE;
}

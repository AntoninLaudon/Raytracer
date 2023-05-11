/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-raytracer-tom.laiolo
** File description:
** Light
*/

#include "AmbientLight.hpp"

Raytracer::Light::Light()
{
    _name = "Light";
    _center = Math::Point3D(0, 0, 0);
    _rotation = Math::Vector3D(0, 0, 0);
    _type = LIGHT;
    _intensity = 1;
    _rgb = PPM::RGB(255, 255, 255);
    _double = 1;
    _double2 = 1;
}

Raytracer::Light::Light(const std::string name, Math::Point3D center, double radius, PPM::RGB rgb)
{
    _name = name;
    _center = center;
    _rotation = Math::Vector3D(0, 0, 0);
    _type = LIGHT;
    _intensity = 1;
    _rgb = rgb;
    _double = radius;
    _double2 = 0.0;
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
    (void)elements;
    (void)land;

    return 1;
}

std::shared_ptr<Math::Point3D> Raytracer::Light::hits(const Math::Ray &ray)
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
    double r = _double;
    
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
    std::cout << "Creating Ambient Light : " << data.getName() << std::endl;
    return new Raytracer::Light(data.getName(), data.getCenter(), data.getDouble(), data.getRGB());
}

extern "C" Raytracer::ElemType getType() {
    return Raytracer::AMBIENTLIGHT;
}

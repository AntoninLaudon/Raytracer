/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-bsraytracer-antonin.laudon
** File description:
** math
*/

#include "math.hpp"

// Vector3D

Math::Vector3D::Vector3D(double x, double y, double z) : _x(x), _y(y), _z(z)
{
}

Math::Vector3D::~Vector3D()
{
}

double Math::Vector3D::length() const
{
    return sqrt(pow(_x, 2) + pow(_y, 2) + pow(_z, 2));
}

// Point3D

Math::Point3D::Point3D(double x, double y, double z) : _x(x), _y(y), _z(z)
{
}

Math::Point3D::~Point3D()
{
}

Math::Ray::Ray(Math::Point3D origin, Math::Vector3D direction) : _origin(origin), _direction(direction)
{
}

Math::Ray::~Ray()
{
}

double Math::Vector3D::getX() const
{
    return _x;
}

double Math::Vector3D::getY() const
{
    return _y;
}

double Math::Vector3D::getZ() const
{
    return _z;
}

void Math::Vector3D::setX(double x)
{
    _x = x;
}

void Math::Vector3D::setY(double y)
{
    _y = y;
}

void Math::Vector3D::setZ(double z)
{
    _z = z;
}

double Math::Point3D::getX() const
{
    return _x;
}

double Math::Point3D::getY() const
{
    return _y;
}

double Math::Point3D::getZ() const
{
    return _z;
}

void Math::Point3D::setX(double x)
{
    _x = x;
}

void Math::Point3D::setY(double y)
{
    _y = y;
}

void Math::Point3D::setZ(double z)
{
    _z = z;
}

Math::Point3D Math::Ray::getOrigin() const
{
    return _origin;
}

Math::Vector3D Math::Ray::getDirection() const
{
    return _direction;
}

void Math::Ray::setOrigin(Math::Point3D &origin)
{
    _origin = origin;
}

void Math::Ray::setDirection(Math::Vector3D &direction)
{
    _direction = direction;
}

Math::Vector3D operator+(const Math::Vector3D &v1, const Math::Vector3D &v2)
{
    return Math::Vector3D(v1.getX() + v2.getX(), v1.getY() + v2.getY(), v1.getZ() + v2.getZ());
}
Math::Vector3D operator+(const Math::Vector3D &v1, const double scalar)
{
    return Math::Vector3D(v1.getX() + scalar, v1.getY() + scalar, v1.getZ() + scalar);
}
Math::Vector3D operator+(const double scalar, const Math::Vector3D &v1)
{
    return Math::Vector3D(v1.getX() + scalar, v1.getY() + scalar, v1.getZ() + scalar);
}

Math::Vector3D operator-(const Math::Vector3D &v1, const Math::Vector3D &v2)
{
    return Math::Vector3D(v1.getX() - v2.getX(), v1.getY() - v2.getY(), v1.getZ() - v2.getZ());
}
Math::Vector3D operator-(const Math::Vector3D &v1, const double scalar)
{
    return Math::Vector3D(v1.getX() - scalar, v1.getY() - scalar, v1.getZ() - scalar);
}
Math::Vector3D operator-(const double scalar, const Math::Vector3D &v1)
{
    return Math::Vector3D(scalar - v1.getX(), scalar - v1.getY(), scalar - v1.getZ());
}

Math::Vector3D operator*(const Math::Vector3D &v1, const Math::Vector3D &v2)
{
    return Math::Vector3D(v1.getX() * v2.getX(), v1.getY() * v2.getY(), v1.getZ() * v2.getZ());
}
Math::Vector3D operator*(const Math::Vector3D &v1, const double scalar)
{
    return Math::Vector3D(v1.getX() * scalar, v1.getY() * scalar, v1.getZ() * scalar);
}
Math::Vector3D operator*(const double scalar, const Math::Vector3D &v1)
{
    return Math::Vector3D(v1.getX() * scalar, v1.getY() * scalar, v1.getZ() * scalar);
}

Math::Vector3D operator/(const Math::Vector3D &v1, const Math::Vector3D &v2)
{
    return Math::Vector3D(v1.getX() / v2.getX(), v1.getY() / v2.getY(), v1.getZ() / v2.getZ());
}
Math::Vector3D operator/(const Math::Vector3D &v1, const double scalar)
{
    return Math::Vector3D(v1.getX() / scalar, v1.getY() / scalar, v1.getZ() / scalar);
}

void operator+=(Math::Vector3D &v1, const Math::Vector3D &v2)
{
    v1.setX(v1.getX() + v2.getX());
    v1.setY(v1.getY() + v2.getY());
    v1.setZ(v1.getZ() + v2.getZ());
}
void operator+=(Math::Vector3D &v1, const double scalar)
{
    v1.setX(v1.getX() + scalar);
    v1.setY(v1.getY() + scalar);
    v1.setZ(v1.getZ() + scalar);
}

void operator-=(Math::Vector3D &v1, const Math::Vector3D &v2)
{
    v1.setX(v1.getX() - v2.getX());
    v1.setY(v1.getY() - v2.getY());
    v1.setZ(v1.getZ() - v2.getZ());
}
void operator-=(Math::Vector3D &v1, const double scalar)
{
    v1.setX(v1.getX() - scalar);
    v1.setY(v1.getY() - scalar);
    v1.setZ(v1.getZ() - scalar);
}

void operator*=(Math::Vector3D &v1, const Math::Vector3D &v2)
{
    v1.setX(v1.getX() * v2.getX());
    v1.setY(v1.getY() * v2.getY());
    v1.setZ(v1.getZ() * v2.getZ());
}
void operator*=(Math::Vector3D &v1, const double scalar)
{
    v1.setX(v1.getX() * scalar);
    v1.setY(v1.getY() * scalar);
    v1.setZ(v1.getZ() * scalar);
}

void operator/=(Math::Vector3D &v1, const Math::Vector3D &v2)
{
    v1.setX(v1.getX() / v2.getX());
    v1.setY(v1.getY() / v2.getY());
    v1.setZ(v1.getZ() / v2.getZ());
}
void operator/=(Math::Vector3D &v1, const double scalar)
{
    v1.setX(v1.getX() / scalar);
    v1.setY(v1.getY() / scalar);
    v1.setZ(v1.getZ() / scalar);
}

void operator+(Math::Point3D &p1, const Math::Point3D &p2)
{
    p1.setX(p1.getX() + p2.getX());
    p1.setY(p1.getY() + p2.getY());
    p1.setZ(p1.getZ() + p2.getZ());
}
void operator+(Math::Point3D &p1, const double scalar)
{
    p1.setX(p1.getX() + scalar);
    p1.setY(p1.getY() + scalar);
    p1.setZ(p1.getZ() + scalar);
}

void operator-(Math::Point3D &p1, const Math::Point3D &p2)
{
    p1.setX(p1.getX() - p2.getX());
    p1.setY(p1.getY() - p2.getY());
    p1.setZ(p1.getZ() - p2.getZ());
}
void operator-(Math::Point3D &p1, const double scalar)
{
    p1.setX(p1.getX() - scalar);
    p1.setY(p1.getY() - scalar);
    p1.setZ(p1.getZ() - scalar);
}

void operator*(Math::Point3D &p1, const Math::Point3D &p2)
{
    p1.setX(p1.getX() * p2.getX());
    p1.setY(p1.getY() * p2.getY());
    p1.setZ(p1.getZ() * p2.getZ());
}
void operator*(Math::Point3D &p1, const double scalar)
{
    p1.setX(p1.getX() * scalar);
    p1.setY(p1.getY() * scalar);
    p1.setZ(p1.getZ() * scalar);
}

void operator/(Math::Point3D &p1, const Math::Point3D &p2)
{
    p1.setX(p1.getX() / p2.getX());
    p1.setY(p1.getY() / p2.getY());
    p1.setZ(p1.getZ() / p2.getZ());
}
void operator/(Math::Point3D &p1, const double scalar)
{
    p1.setX(p1.getX() / scalar);
    p1.setY(p1.getY() / scalar);
    p1.setZ(p1.getZ() / scalar);
}

std::ostream &operator<<(std::ostream &os, const Math::Vector3D &v)
{
    os << "(" << v.getX() << ", " << v.getY() << ", " << v.getZ() << ")";
    return os;
}

std::ostream &operator<<(std::ostream &os, const Math::Point3D &p)
{
    os << "(" << p.getX() << ", " << p.getY() << ", " << p.getZ() << ")";
    return os;
}

std::ostream &operator<<(std::ostream &os, const Math::Ray &r)
{
    os << "O:" << r.getOrigin() << " D:" << r.getDirection();
    return os;
}

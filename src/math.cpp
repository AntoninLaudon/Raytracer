/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-bsraytracer-antonin.laudon
** File description:
** math
*/

#include "math.hpp"

// Vector3D ################################################################################################################

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

double Math::Vector3D::dot(const Math::Vector3D &v) const
{
    return _x * v.getX() + _y * v.getY() + _z * v.getZ();
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

Math::Vector3D operator+(const Math::Vector3D &v1, const Math::Vector3D &v2)
{
    return Math::Vector3D(v1.getX() + v2.getX(), v1.getY() + v2.getY(), v1.getZ() + v2.getZ());
}
Math::Vector3D operator+(const Math::Vector3D &v1, const double &scalar)
{
    return Math::Vector3D(v1.getX() + scalar, v1.getY() + scalar, v1.getZ() + scalar);
}
Math::Vector3D operator+(const double &scalar, const Math::Vector3D &v1)
{
    return Math::Vector3D(v1.getX() + scalar, v1.getY() + scalar, v1.getZ() + scalar);
}

Math::Vector3D operator-(const Math::Vector3D &v1, const Math::Vector3D &v2)
{
    return Math::Vector3D(v1.getX() - v2.getX(), v1.getY() - v2.getY(), v1.getZ() - v2.getZ());
}
Math::Vector3D operator-(const Math::Vector3D &v1, const double &scalar)
{
    return Math::Vector3D(v1.getX() - scalar, v1.getY() - scalar, v1.getZ() - scalar);
}
Math::Vector3D operator-(const double &scalar, const Math::Vector3D &v1)
{
    return Math::Vector3D(scalar - v1.getX(), scalar - v1.getY(), scalar - v1.getZ());
}

Math::Vector3D operator*(const Math::Vector3D &v1, const Math::Vector3D &v2)
{
    return Math::Vector3D(v1.getX() * v2.getX(), v1.getY() * v2.getY(), v1.getZ() * v2.getZ());
}
Math::Vector3D operator*(const Math::Vector3D &v1, const double &scalar)
{
    return Math::Vector3D(v1.getX() * scalar, v1.getY() * scalar, v1.getZ() * scalar);
}
Math::Vector3D operator*(const double &scalar, const Math::Vector3D &v1)
{
    return Math::Vector3D(v1.getX() * scalar, v1.getY() * scalar, v1.getZ() * scalar);
}

Math::Vector3D operator/(const Math::Vector3D &v1, const Math::Vector3D &v2)
{
    if (v2.getX() == 0 || v2.getY() == 0 || v2.getZ() == 0)
        throw std::invalid_argument("Division by zero");
    return Math::Vector3D(v1.getX() / v2.getX(), v1.getY() / v2.getY(), v1.getZ() / v2.getZ());
}
Math::Vector3D operator/(const Math::Vector3D &v1, const double &scalar)
{
    if (scalar == 0)
        throw std::invalid_argument("Division by zero");
    return Math::Vector3D(v1.getX() / scalar, v1.getY() / scalar, v1.getZ() / scalar);
}
Math::Vector3D operator/(const double &scalar, const Math::Vector3D &v1)
{
    if (v1.getX() == 0 || v1.getY() == 0 || v1.getZ() == 0)
        throw std::invalid_argument("Division by zero");
    return Math::Vector3D(scalar / v1.getX(), scalar / v1.getY(), scalar / v1.getZ());
}

Math::Vector3D operator-(const Math::Vector3D &v1)
{
    return Math::Vector3D(-v1.getX(), -v1.getY(), -v1.getZ());
}

void operator+=(Math::Vector3D &v1, const Math::Vector3D &v2)
{
    v1.setX(v1.getX() + v2.getX());
    v1.setY(v1.getY() + v2.getY());
    v1.setZ(v1.getZ() + v2.getZ());
}
void operator+=(Math::Vector3D &v1, const double &scalar)
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
void operator-=(Math::Vector3D &v1, const double &scalar)
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
void operator*=(Math::Vector3D &v1, const double &scalar)
{
    v1.setX(v1.getX() * scalar);
    v1.setY(v1.getY() * scalar);
    v1.setZ(v1.getZ() * scalar);
}

void operator/=(Math::Vector3D &v1, const Math::Vector3D &v2)
{
    if (v2.getX() == 0 || v2.getY() == 0 || v2.getZ() == 0)
        throw std::invalid_argument("Division by zero");
    v1.setX(v1.getX() / v2.getX());
    v1.setY(v1.getY() / v2.getY());
    v1.setZ(v1.getZ() / v2.getZ());
}
void operator/=(Math::Vector3D &v1, const double &scalar)
{
    if (scalar == 0)
        throw std::invalid_argument("Division by zero");
    v1.setX(v1.getX() / scalar);
    v1.setY(v1.getY() / scalar);
    v1.setZ(v1.getZ() / scalar);
}

bool operator==(const Math::Vector3D &v1, const Math::Vector3D &v2)
{
    return v1.getX() == v2.getX() && v1.getY() == v2.getY() && v1.getZ() == v2.getZ();
}
bool operator!=(const Math::Vector3D &v1, const Math::Vector3D &v2)
{
    return !(v1 == v2);
}

std::ostream &operator<<(std::ostream &os, const Math::Vector3D &v)
{
    os << "(" << v.getX() << ", " << v.getY() << ", " << v.getZ() << ")";
    return os;
}

// Point3D #################################################################################################################

Math::Point3D::Point3D(double x, double y, double z) : _x(x), _y(y), _z(z)
{
}

Math::Point3D::~Point3D()
{
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

Math::Point3D operator+(const Math::Point3D &v1, const Math::Point3D &p1)
{
    return Math::Point3D(p1.getX() + v1.getX(), p1.getY() + v1.getY(), p1.getZ() + v1.getZ());
}
Math::Point3D operator+(const Math::Point3D &p1, const double &scalar)
{
    return Math::Point3D(p1.getX() + scalar, p1.getY() + scalar, p1.getZ() + scalar);
}
Math::Point3D operator+(const double &scalar, const Math::Point3D &p1)
{
    return Math::Point3D(p1.getX() + scalar, p1.getY() + scalar, p1.getZ() + scalar);
}
Math::Point3D operator+(const Math::Point3D &p1, const Math::Vector3D &v1)
{
    return Math::Point3D(p1.getX() + v1.getX(), p1.getY() + v1.getY(), p1.getZ() + v1.getZ());
}
Math::Point3D operator+(const Math::Vector3D &v1, const Math::Point3D &p1)
{
    return Math::Point3D(p1.getX() + v1.getX(), p1.getY() + v1.getY(), p1.getZ() + v1.getZ());
}

Math::Point3D operator-(const Math::Point3D &p1, const Math::Point3D &p2)
{
    return Math::Point3D(p1.getX() - p2.getX(), p1.getY() - p2.getY(), p1.getZ() - p2.getZ());
}
Math::Point3D operator-(const Math::Point3D &p1, const double &scalar)
{
    return Math::Point3D(p1.getX() - scalar, p1.getY() - scalar, p1.getZ() - scalar);
}
Math::Point3D operator-(const double &scalar, const Math::Point3D &p1)
{
    return Math::Point3D(scalar - p1.getX(), scalar - p1.getY(), scalar - p1.getZ());
}

Math::Point3D operator*(const Math::Point3D &p1, const Math::Point3D &p2)
{
    return Math::Point3D(p1.getX() * p2.getX(), p1.getY() * p2.getY(), p1.getZ() * p2.getZ());
}
Math::Point3D operator*(const double &scalar, const Math::Point3D &p1)
{
    return Math::Point3D(p1.getX() * scalar, p1.getY() * scalar, p1.getZ() * scalar);
}
Math::Point3D operator*(const Math::Point3D &p1, const double &scalar)
{
    return Math::Point3D(p1.getX() * scalar, p1.getY() * scalar, p1.getZ() * scalar);
}

Math::Point3D operator/(const Math::Point3D &p1, const Math::Point3D &p2)
{
    if (p2.getX() == 0 || p2.getY() == 0 || p2.getZ() == 0)
        throw std::invalid_argument("Division by zero");
    return Math::Point3D(p1.getX() / p2.getX(), p1.getY() / p2.getY(), p1.getZ() / p2.getZ());
}
Math::Point3D operator/(const Math::Point3D &p1, const double &scalar)
{
    if (scalar == 0)
        throw std::invalid_argument("Division by zero");
    return Math::Point3D(p1.getX() / scalar, p1.getY() / scalar, p1.getZ() / scalar);
}
Math::Point3D operator/(const double &scalar, const Math::Point3D &p1)
{
    if (p1.getX() == 0 || p1.getY() == 0 || p1.getZ() == 0)
        throw std::invalid_argument("Division by zero");
    return Math::Point3D(scalar / p1.getX(), scalar / p1.getY(), scalar / p1.getZ());
}

Math::Point3D operator-(const Math::Point3D &p1)
{
    return Math::Point3D(-p1.getX(), -p1.getY(), -p1.getZ());
}

void operator+=(Math::Point3D &p1, const Math::Point3D &p2)
{
    p1.setX(p1.getX() + p2.getX());
    p1.setY(p1.getY() + p2.getY());
    p1.setZ(p1.getZ() + p2.getZ());
}
void operator+=(Math::Point3D &p1, const double &scalar)
{
    p1.setX(p1.getX() + scalar);
    p1.setY(p1.getY() + scalar);
    p1.setZ(p1.getZ() + scalar);
}
void operator+=(Math::Point3D &p1, const Math::Vector3D &v1)
{
    p1.setX(p1.getX() + v1.getX());
    p1.setY(p1.getY() + v1.getY());
    p1.setZ(p1.getZ() + v1.getZ());
}

void operator-=(Math::Point3D &p1, const Math::Point3D &p2)
{
    p1.setX(p1.getX() - p2.getX());
    p1.setY(p1.getY() - p2.getY());
    p1.setZ(p1.getZ() - p2.getZ());
}
void operator-=(Math::Point3D &p1, const double &scalar)
{
    p1.setX(p1.getX() - scalar);
    p1.setY(p1.getY() - scalar);
    p1.setZ(p1.getZ() - scalar);
}

void operator*=(Math::Point3D &p1, const Math::Point3D &p2)
{
    p1.setX(p1.getX() * p2.getX());
    p1.setY(p1.getY() * p2.getY());
    p1.setZ(p1.getZ() * p2.getZ());
}
void operator*=(Math::Point3D &p1, const double &scalar)
{
    p1.setX(p1.getX() * scalar);
    p1.setY(p1.getY() * scalar);
    p1.setZ(p1.getZ() * scalar);
}

void operator/=(Math::Point3D &p1, const Math::Point3D &p2)
{
    if (p2.getX() == 0 || p2.getY() == 0 || p2.getZ() == 0)
        throw std::invalid_argument("Division by zero");
    p1.setX(p1.getX() / p2.getX());
    p1.setY(p1.getY() / p2.getY());
    p1.setZ(p1.getZ() / p2.getZ());
}
void operator/=(Math::Point3D &p1, const double &scalar)
{
    if (scalar == 0)
        throw std::invalid_argument("Division by zero");
    p1.setX(p1.getX() / scalar);
    p1.setY(p1.getY() / scalar);
    p1.setZ(p1.getZ() / scalar);
}

bool operator==(const Math::Point3D &p1, const Math::Point3D &p2)
{
    return p1.getX() == p2.getX() && p1.getY() == p2.getY() && p1.getZ() == p2.getZ();
}
bool operator!=(const Math::Point3D &p1, const Math::Point3D &p2)
{
    return !(p1 == p2);
}

std::ostream &operator<<(std::ostream &os, const Math::Point3D &p)
{
    os << "(" << p.getX() << ", " << p.getY() << ", " << p.getZ() << ")";
    return os;
}

// Ray #####################################################################################################################

Math::Ray::Ray(Math::Point3D origin, Math::Vector3D direction) : _origin(origin), _direction(direction)
{
}

Math::Ray::~Ray()
{
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

std::ostream &operator<<(std::ostream &os, const Math::Ray &r)
{
    os << "O:" << r.getOrigin() << " D:" << r.getDirection();
    return os;
}

Math::Sphere::Sphere(Math::Point3D center, double radius)
{
    _center = center;
    _radius = radius;
}

Math::Sphere::~Sphere()
{

}

Math::Point3D Math::Sphere::getCenter() const
{
    return _center;
}

double Math::Sphere::getRadius() const
{
    return _radius;
}

void Math::Sphere::setCenter(Point3D &center)
{
    _center = center;
}

void Math::Sphere::setRadius(double radius)
{
    _radius = radius;
}

bool Math::Sphere::hits(const Math::Ray &ray) const
{
    // Return true if the ray hits the sphere
    if (ray.getOrigin() == _center)
        return true;
    return false;
}

/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-bsraytracer-antonin.laudon
** File description:
** math
*/

#ifndef MATH_HPP_
#define MATH_HPP_

#include <cmath>
#include <iostream>

namespace Math {
    class Vector3D {
        public:
            Vector3D(double x = 0, double y = 0, double z = 0);
            ~Vector3D();
            double length() const;
            double dot(const Vector3D &v) const;
            double getX() const;
            double getY() const;
            double getZ() const;
            void setX(double x);
            void setY(double y);
            void setZ(double z);
        private:
            double _x;
            double _y;
            double _z;
        protected:
    };

    class Point3D {
        public:
            Point3D(double x = 0, double y = 0, double z = 0);
            ~Point3D();
            double getX() const;
            double getY() const;
            double getZ() const;
            void setX(double x);
            void setY(double y);
            void setZ(double z);
        private:
            double _x;
            double _y;
            double _z;
        protected:
    };

    class Ray {
        public:
            Ray(Point3D origin, Vector3D direction);
            ~Ray();
            Point3D getOrigin() const;
            Vector3D getDirection() const;
            void setOrigin(Point3D &origin);
            void setDirection(Vector3D &direction);
        private:
            Point3D _origin;
            Vector3D _direction;
        protected:
    };

}

// Vector3D

Math::Vector3D operator+(const Math::Vector3D &v1, const Math::Vector3D &v2);
Math::Vector3D operator+(const Math::Vector3D &v1, const double &d);
Math::Vector3D operator+(const double &d, const Math::Vector3D &v1);

Math::Vector3D operator-(const Math::Vector3D &v1, const Math::Vector3D &v2);
Math::Vector3D operator-(const Math::Vector3D &v1, const double &d);
Math::Vector3D operator-(const double &d, const Math::Vector3D &v1);

Math::Vector3D operator*(const Math::Vector3D &v1, const Math::Vector3D &v2);
Math::Vector3D operator*(const Math::Vector3D &v1, const double &d);
Math::Vector3D operator*(const double &d, const Math::Vector3D &v1);

Math::Vector3D operator/(const Math::Vector3D &v1, const Math::Vector3D &v2);
Math::Vector3D operator/(const Math::Vector3D &v1, const double &d);
Math::Vector3D operator/(const double &d, const Math::Vector3D &v1);

Math::Vector3D operator-(const Math::Vector3D &v);

void operator+=(Math::Vector3D &v1, const Math::Vector3D &v2);
void operator+=(Math::Vector3D &v1, const double &d);

void operator-=(Math::Vector3D &v1, const Math::Vector3D &v2);
void operator-=(Math::Vector3D &v1, const double &d);

void operator*=(Math::Vector3D &v1, const Math::Vector3D &v2);
void operator*=(Math::Vector3D &v1, const double &d);

void operator/=(Math::Vector3D &v1, const Math::Vector3D &v2);
void operator/=(Math::Vector3D &v1, const double &d);

bool operator==(const Math::Vector3D &v1, const Math::Vector3D &v2);
bool operator!=(const Math::Vector3D &v1, const Math::Vector3D &v2);

std::ostream &operator<<(std::ostream &os, const Math::Vector3D &v);

// Point3D

Math::Point3D operator+(const Math::Point3D &p1, const Math::Point3D &p2);
Math::Point3D operator+(const Math::Point3D &p1, const double &d);
Math::Point3D operator+(const double &d, const Math::Point3D &p1);
Math::Point3D operator+(const Math::Point3D &p1, const Math::Vector3D &v1);
Math::Point3D operator+(const Math::Vector3D &v1, const Math::Point3D &p1);

Math::Point3D operator-(const Math::Point3D &p1, const Math::Point3D &p2);
Math::Point3D operator-(const Math::Point3D &p1, const double &d);
Math::Point3D operator-(const double &d, const Math::Point3D &p1);

Math::Point3D operator*(const Math::Point3D &p1, const Math::Point3D &p2);
Math::Point3D operator*(const Math::Point3D &p1, const double &d);
Math::Point3D operator*(const double &d, const Math::Point3D &p1);

Math::Point3D operator/(const Math::Point3D &p1, const Math::Point3D &p2);
Math::Point3D operator/(const Math::Point3D &p1, const double &d);
Math::Point3D operator/(const double &d, const Math::Point3D &p1);

Math::Point3D operator-(const Math::Point3D &p);

void operator+=(Math::Point3D &p1, const Math::Point3D &p2);
void operator+=(Math::Point3D &p1, const double &d);
void operator+=(Math::Point3D &p1, const Math::Vector3D &v1);

void operator-=(Math::Point3D &p1, const Math::Point3D &p2);
void operator-=(Math::Point3D &p1, const double &d);

void operator*=(Math::Point3D &p1, const Math::Point3D &p2);
void operator*=(Math::Point3D &p1, const double &d);

void operator/=(Math::Point3D &p1, const Math::Point3D &p2);
void operator/=(Math::Point3D &p1, const double &d);

bool operator==(const Math::Point3D &p1, const Math::Point3D &p2);
bool operator!=(const Math::Point3D &p1, const Math::Point3D &p2);

std::ostream &operator<<(std::ostream &os, const Math::Point3D &p);

// Ray

std::ostream &operator<<(std::ostream &os, const Math::Ray &r);

#endif /* !MATH_HPP_ */

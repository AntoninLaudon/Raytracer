/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-raytracer-tom.laiolo
** File description:
** main
*/

#include "math.hpp"

int main()
{
   std::cout << "========== Vector ==========" << std::endl;
   Math::Vector3D v1(1, 2, 3);
   Math::Vector3D v2(4, 5, 6);
   Math::Vector3D v3(0, 0, 0);
   std::cout << "v1: " << v1 << std::endl;
   std::cout << "v2: " << v2 << std::endl;


   std::cout << "-> operator +" << std::endl;

   v3 = v1 + v2;
   printf("%s",(v3 == Math::Vector3D(5, 7, 9)) ? " " : "#");
   std::cout << " v1 + v2: \t" << v3 << "\t should be: 5 7 9" << std::endl;

   v3 = v1 + 5;
   printf("%s",(v3 == Math::Vector3D(6, 7, 8)) ? " " : "#");
   std::cout << " v1 + 5: \t" << v3 << "\t should be: 6 7 8" << std::endl;

   v3 = 5 + v1;
   printf("%s",(v3 == Math::Vector3D(6, 7, 8)) ? " " : "#");
   std::cout << " 5 + v1: \t" << v3 << "\t should be: 6 7 8" << std::endl;


   std::cout << "-> operator -" << std::endl;

   v3 = v1 - v2;
   printf("%s", (v3 == Math::Vector3D(-3, -3, -3)) ? " " : "#");
   std::cout << " v1 - v2: \t" << v3 << "\t should be: -3 -3 -3" << std::endl;

   v3 = v1 - 5;
   printf("%s", (v3 == Math::Vector3D(-4, -3, -2)) ? " " : "#");
   std::cout << " v1 - 5: \t" << v3 << "\t should be: -4 -3 -2" << std::endl;

   v3 = 5 - v1;
   printf("%s", (v3 == Math::Vector3D(4, 3, 2)) ? " " : "#");
   std::cout << " 5 - v1: \t" << v3 << "\t should be: 4 3 2" << std::endl;

   v3 = -v1;
   printf("%s", (v3 == Math::Vector3D(-1, -2, -3)) ? " " : "#");
   std::cout << " -v1: \t\t" << v3 << "\t should be: -1 -2 -3" << std::endl;

   std::cout << "-> operator *" << std::endl;

   v3 = v1 * v2;
   printf("%s", (v3 == Math::Vector3D(4, 10, 18)) ? " " : "#");
   std::cout << " v1 * v2: \t" << v3 << "\t should be: 4 10 18" << std::endl;

   v3 = v1 * 5;
   printf("%s", (v3 == Math::Vector3D(5, 10, 15)) ? " " : "#");
   std::cout << " v1 * 5: \t" << v3 << "\t should be: 5 10 15" << std::endl;

   v3 = 5 * v1;
   printf("%s", (v3 == Math::Vector3D(5, 10, 15)) ? " " : "#");
   std::cout << " 5 * v1: \t" << v3 << "\t should be: 5 10 15" << std::endl;


   std::cout << "-> operator /" << std::endl;

   v3 = v1 / v2;
   printf("%s", (v3 == Math::Vector3D(0.25, 0.4, 0.5)) ? " " : "#");
   std::cout << " v1 / v2: \t" << v3 << "\t should be: 0.25 0.4 0.5" << std::endl;

   v3 = v1 / 5;
   printf("%s", (v3 == Math::Vector3D(0.2, 0.4, 0.6)) ? " " : "#");
   std::cout << " v1 / 5: \t" << v3 << "\t should be: 0.2 0.4 0.6" << std::endl;

   v3 = 5 / v1;
   printf("%s", (v3 == Math::Vector3D(5, 2.5, 1.6666666666666667)) ? " " : "#");
   std::cout << " 5 / v1: \t" << v3 << "\t should be: 5 2.5 1.6666666666666667" << std::endl;


   std::cout << "-> operator +=" << std::endl;

   v3 = v1;
   v3 += v2;
   printf("%s", (v3 == Math::Vector3D(5, 7, 9)) ? " " : "#");
   std::cout << " v1 += v2: \t" << v3 << "\t should be: 5 7 9" << std::endl;

   v3 = v1;
   v3 += 5;
   printf("%s", (v3 == Math::Vector3D(6, 7, 8)) ? " " : "#");
   std::cout << " v1 += 5: \t" << v3 << "\t should be: 6 7 8" << std::endl;


   std::cout << "-> operator -=" << std::endl;

   v3 = v1;
   v3 -= v2;
   printf("%s", (v3 == Math::Vector3D(-3, -3, -3)) ? " " : "#");
   std::cout << " v1 -= v2: \t" << v3 << "\t should be: -3 -3 -3" << std::endl;

   v3 = v1;
   v3 -= 5;
   printf("%s", (v3 == Math::Vector3D(-4, -3, -2)) ? " " : "#");
   std::cout << " v1 -= 5: \t" << v3 << "\t should be: -4 -3 -2" << std::endl;


   std::cout << "-> operator *=" << std::endl;

   v3 = v1;
   v3 *= v2;
   printf("%s", (v3 == Math::Vector3D(4, 10, 18)) ? " " : "#");
   std::cout << " v1 *= v2: \t" << v3 << "\t should be: 4 10 18" << std::endl;

   v3 = v1;
   v3 *= 5;
   printf("%s", (v3 == Math::Vector3D(5, 10, 15)) ? " " : "#");
   std::cout << " v1 *= 5: \t" << v3 << "\t should be: 5 10 15" << std::endl;


   std::cout << "-> operator /=" << std::endl;

   v3 = v1;
   v3 /= v2;
   printf("%s", (v3 == Math::Vector3D(0.25, 0.4, 0.5)) ? " " : "#");
   std::cout << " v1 /= v2: \t" << v3 << "\t should be: 0.25 0.4 0.5" << std::endl;

   v3 = v1;
   v3 /= 5;
   printf("%s", (v3 == Math::Vector3D(0.2, 0.4, 0.6)) ? " " : "#");
   std::cout << " v1 /= 5: \t" << v3 << "\t should be: 0.2 0.4 0.6" << std::endl;


   std::cout << "-> operator ==" << std::endl;

   printf("%s", (v1 == v2) ? "#" : " ");
   std::cout << " v1 == v2: \t" << (v1 == v2) << "\t should be: 0" << std::endl;

   printf("%s", (v1 == v1) ? " " : "#");
   std::cout << " v1 == v1: \t" << (v1 == v1) << "\t should be: 1" << std::endl;


   std::cout << "-> operator !=" << std::endl;

   printf("%s", (v1 != v2) ? " " : "#");
   std::cout << " v1 != v2: \t" << (v1 != v2) << "\t should be: 1" << std::endl;

   printf("%s", (v1 != v1) ? "#" : " ");
   std::cout << " v1 != v1: \t" << (v1 != v1) << "\t should be: 0" << std::endl;


   std::cout << "========== Points ==========" << std::endl;
   Math::Point3D p1(1, 2, 3);
   Math::Point3D p2(4, 5, 6);
   Math::Point3D p3(0, 0, 0);
   std::cout << "p1: " << p1 << std::endl;
   std::cout << "p2: " << p2 << std::endl;


   std::cout << "-> operator +" << std::endl;

   p3 = p1 + p2;
   printf("%s",(p3 == Math::Point3D(5, 7, 9)) ? " " : "#");
   std::cout << " p1 + p2: \t" << p3 << "\t should be: 5 7 9" << std::endl;

   p3 = p1 + 5;
   printf("%s",(p3 == Math::Point3D(6, 7, 8)) ? " " : "#");
   std::cout << " p1 + 5: \t" << p3 << "\t should be: 6 7 8" << std::endl;

   p3 = 5 + p1;
   printf("%s",(p3 == Math::Point3D(6, 7, 8)) ? " " : "#");
   std::cout << " 5 + p1: \t" << p3 << "\t should be: 6 7 8" << std::endl;


   std::cout << "-> operator -" << std::endl;

   p3 = p1 - p2;
   printf("%s", (p3 == Math::Point3D(-3, -3, -3)) ? " " : "#");
   std::cout << " p1 - p2: \t" << p3 << "\t should be: -3 -3 -3" << std::endl;

   p3 = p1 - 5;
   printf("%s", (p3 == Math::Point3D(-4, -3, -2)) ? " " : "#");
   std::cout << " p1 - 5: \t" << p3 << "\t should be: -4 -3 -2" << std::endl;

   p3 = 5 - p1;
   printf("%s", (p3 == Math::Point3D(4, 3, 2)) ? " " : "#");
   std::cout << " 5 - p1: \t" << p3 << "\t should be: 4 3 2" << std::endl;

   p3 = -p1;
   printf("%s", (p3 == Math::Point3D(-1, -2, -3)) ? " " : "#");
   std::cout << " -p1: \t\t" << p3 << "\t should be: -1 -2 -3" << std::endl;

   std::cout << "-> operator *" << std::endl;

   p3 = p1 * p2;
   printf("%s", (p3 == Math::Point3D(4, 10, 18)) ? " " : "#");
   std::cout << " p1 * p2: \t" << p3 << "\t should be: 4 10 18" << std::endl;

   p3 = p1 * 5;
   printf("%s", (p3 == Math::Point3D(5, 10, 15)) ? " " : "#");
   std::cout << " p1 * 5: \t" << p3 << "\t should be: 5 10 15" << std::endl;

   p3 = 5 * p1;
   printf("%s", (p3 == Math::Point3D(5, 10, 15)) ? " " : "#");
   std::cout << " 5 * p1: \t" << p3 << "\t should be: 5 10 15" << std::endl;


   std::cout << "-> operator /" << std::endl;

   p3 = p1 / p2;
   printf("%s", (p3 == Math::Point3D(0.25, 0.4, 0.5)) ? " " : "#");
   std::cout << " p1 / p2: \t" << p3 << "\t should be: 0.25 0.4 0.5" << std::endl;

   p3 = p1 / 5;
   printf("%s", (p3 == Math::Point3D(0.2, 0.4, 0.6)) ? " " : "#");
   std::cout << " p1 / 5: \t" << p3 << "\t should be: 0.2 0.4 0.6" << std::endl;

   p3 = 5 / p1;
   printf("%s", (p3 == Math::Point3D(5, 2.5, 1.6666666666666667)) ? " " : "#");
   std::cout << " 5 / p1: \t" << p3 << "\t should be: 5 2.5 1.6666666666666667" << std::endl;


   std::cout << "-> operator +=" << std::endl;

   p3 = p1;
   p3 += p2;
   printf("%s", (p3 == Math::Point3D(5, 7, 9)) ? " " : "#");
   std::cout << " p1 += p2: \t" << p3 << "\t should be: 5 7 9" << std::endl;

   p3 = p1;
   p3 += 5;
   printf("%s", (p3 == Math::Point3D(6, 7, 8)) ? " " : "#");
   std::cout << " p1 += 5: \t" << p3 << "\t should be: 6 7 8" << std::endl;


   std::cout << "-> operator -=" << std::endl;

   p3 = p1;
   p3 -= p2;
   printf("%s", (p3 == Math::Point3D(-3, -3, -3)) ? " " : "#");
   std::cout << " p1 -= p2: \t" << p3 << "\t should be: -3 -3 -3" << std::endl;

   p3 = p1;
   p3 -= 5;
   printf("%s", (p3 == Math::Point3D(-4, -3, -2)) ? " " : "#");
   std::cout << " p1 -= 5: \t" << p3 << "\t should be: -4 -3 -2" << std::endl;


   std::cout << "-> operator *=" << std::endl;

   p3 = p1;
   p3 *= p2;
   printf("%s", (p3 == Math::Point3D(4, 10, 18)) ? " " : "#");
   std::cout << " p1 *= p2: \t" << p3 << "\t should be: 4 10 18" << std::endl;

   p3 = p1;
   p3 *= 5;
   printf("%s", (p3 == Math::Point3D(5, 10, 15)) ? " " : "#");
   std::cout << " p1 *= 5: \t" << p3 << "\t should be: 5 10 15" << std::endl;


   std::cout << "-> operator /=" << std::endl;

   p3 = p1;
   p3 /= p2;
   printf("%s", (p3 == Math::Point3D(0.25, 0.4, 0.5)) ? " " : "#");
   std::cout << " p1 /= p2: \t" << p3 << "\t should be: 0.25 0.4 0.5" << std::endl;

   p3 = p1;
   p3 /= 5;
   printf("%s", (p3 == Math::Point3D(0.2, 0.4, 0.6)) ? " " : "#");
   std::cout << " p1 /= 5: \t" << p3 << "\t should be: 0.2 0.4 0.6" << std::endl;


   std::cout << "-> operator ==" << std::endl;

   printf("%s", (p1 == p2) ? "#" : " ");
   std::cout << " p1 == p2: \t" << (p1 == p2) << "\t should be: 0" << std::endl;

   printf("%s", (p1 == p1) ? " " : "#");
   std::cout << " p1 == p1: \t" << (p1 == p1) << "\t should be: 1" << std::endl;


   std::cout << "-> operator !=" << std::endl;

   printf("%s", (p1 != p2) ? " " : "#");
   std::cout << " p1 != p2: \t" << (p1 != p2) << "\t should be: 1" << std::endl;

   printf("%s", (p1 != p1) ? "#" : " ");
   std::cout << " p1 != p1: \t" << (p1 != p1) << "\t should be: 0" << std::endl;


   return 0;
}
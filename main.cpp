/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-raytracer-tom.laiolo
** File description:
** main
*/

#include "math.hpp"

int main()
{
    Math::Vector3D vector(1, 2, 3);
    Math::Vector3D vector2(3, 1, 0);
    Math::Point3D point(1, 2, 3);
    Math::Ray ray(point, vector);
    std::cout << "Vector: " << vector << std::endl;
    std::cout << "Vector2: " << vector2 << std::endl;
    std::cout << "Point: " << point << std::endl;
    std::cout << "Ray: " << ray << std::endl;

    Math::Vector3D vector3 = vector + vector2;
    std::cout << "Vector3: " << vector3 << std::endl;
    Math::Vector3D vector4 = vector2 + 3;
    std::cout << "Vector4: " << vector4 << std::endl;
    Math::Vector3D vector5 = 3 + vector2;
    std::cout << "Vector5: " << vector5 << std::endl;

    Math::Vector3D vector6 = vector - vector2;
    std::cout << "Vector6: " << vector6 << std::endl;
    Math::Vector3D vector7 = vector2 - 3;
    std::cout << "Vector7: " << vector7 << std::endl;
    Math::Vector3D vector8 = 3 - vector2;
    std::cout << "Vector8: " << vector8 << std::endl;

    Math::Vector3D vector9 = vector * vector2;
    std::cout << "Vector9: " << vector9 << std::endl;
    Math::Vector3D vector10 = vector2 * 3;
    std::cout << "Vector10: " << vector10 << std::endl;
    Math::Vector3D vector11 = 3 * vector2;
    std::cout << "Vector11: " << vector11 << std::endl;

    Math::Vector3D vector12 = vector / vector2;
    std::cout << "Vector12: " << vector12 << std::endl;
    Math::Vector3D vector13 = vector2 / 3;
    std::cout << "Vector13: " << vector13 << std::endl;

    vector += vector2;
    std::cout << "Vector + Vector2: " << vector << std::endl;
    vector += 3;
    std::cout << "Vector + 3: " << vector << std::endl;

    vector -= 3;
    std::cout << "Vector - 3: " << vector << std::endl;
    vector -= vector2;
    std::cout << "Vector - Vector2: " << vector << std::endl;

    vector *= 3;
    std::cout << "Vector * 3: " << vector << std::endl;
    vector *= vector2;
    std::cout << "Vector * Vector2: " << vector << std::endl;

    vector /= vector2;
    std::cout << "Vector / Vector2: " << vector << std::endl;
    vector /= 3;
    std::cout << "Vector / 3: " << vector << std::endl;
    
    return 0;
}
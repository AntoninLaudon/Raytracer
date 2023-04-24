/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-raytracer-tom.laiolo
** File description:
** Factory
*/

#pragma once

#include <map>
#include <memory>
#include <string>

#include "IElement.hpp"

class Factory {
    typedef std::shared_ptr<Raytracer::IElement> (*CreateFunction)(const std::string& name, Math::Vector3D& position, Math::Vector3D& rotation);
    public:
        Factory();
        ~Factory();
        std::shared_ptr<Raytracer::IElement> createObject(Raytracer::ElemType, std::string name, Math::Vector3D position, Math::Vector3D rotation);
        void registerObject(Raytracer::ElemType, CreateFunction cf);
        void unregisterObject(Raytracer::ElemType);
    protected:
    private:
        std::map<Raytracer::ElemType, CreateFunction> _map;
};

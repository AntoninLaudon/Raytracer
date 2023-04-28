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
#include "Data.hpp"

class Factory {
    typedef std::shared_ptr<Raytracer::IElement> (*CreateFunction)(Raytracer::Data data);
    public:
        Factory();
        ~Factory();
        std::shared_ptr<Raytracer::IElement> createObject(Raytracer::Data data);
        void registerObject(Raytracer::ElemType, CreateFunction cf);
        void unregisterObject(Raytracer::ElemType);
    protected:
    private:
        std::map<Raytracer::ElemType, CreateFunction> _map;
};

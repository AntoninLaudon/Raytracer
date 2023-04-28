/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-raytracer-tom.laiolo
** File description:
** Factory
*/

#include <functional>
#include <map>
#include <memory>
#include <string>
#include <type_traits>
#include "Factory.hpp"

Factory::Factory()
{
}

Factory::~Factory()
{
}

void Factory::registerObject(Raytracer::ElemType type, CreateFunction cf) {
    _map[type] = cf;
}

void Factory::unregisterObject(Raytracer::ElemType type) {
    auto it = _map.find(type);
    if (it != _map.end()) {
        _map.erase(it);
    }
}

std::shared_ptr<Raytracer::IElement> Factory::createObject(Raytracer::Data data) {
    auto it = _map.find(data.getType());
    if (it != _map.end()) {
        return it->second(data);
    }
    return nullptr;
}

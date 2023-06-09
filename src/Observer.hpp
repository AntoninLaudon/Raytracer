/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-raytracer-tom.laiolo
** File description:
** Observer
*/

#pragma once

#include "Core.hpp"

class File;

class Observer {
    public:
        Observer();
        ~Observer();
        void update(File *file, Raytracer::Core &core);
    protected:
    private:
};

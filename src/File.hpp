/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-raytracer-tom.laiolo
** File description:
** File
*/

#pragma once

#include <iostream>
#include <filesystem>
#include <chrono>
#include <string>
#include <vector>
#include "Observer.hpp"
#include "Core.hpp"

class File {
public:
    File(std::string path);
    ~File();
    void setfilePath(std::string path);
    std::string getfilePath();
    bool hasChanged();
    bool truePath();
    void attach(Observer* observer);
    void detach(Observer* observer);
    void notify(Raytracer::Core &core);
private:
    std::string filePath;
    std::filesystem::file_time_type lastModifiedTime;
    std::vector<Observer*> _observers;
};

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

class File {
public:
    File(std::string path);
    ~File();
    bool hasChanged();
    std::string getfilePath();
    void attach(Observer* observer);
    void detach(Observer* observer);
    void notify();
private:
    std::string filePath;
    std::filesystem::file_time_type lastModifiedTime;
    std::vector<Observer*> _observers;
};

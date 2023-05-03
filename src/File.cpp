/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-raytracer-tom.laiolo
** File description:
** File
*/

#include "File.hpp"

File::File(std::string path) : filePath(path)
{
    lastModifiedTime = std::filesystem::last_write_time(filePath);
}

File::~File()
{
}

bool File::hasChanged()
{
    std::filesystem::file_time_type newModifiedTime = std::filesystem::last_write_time(filePath);
    if (newModifiedTime != lastModifiedTime) {
        lastModifiedTime = newModifiedTime;
        return true;
    } else {
        return false;
    }
}

std::string File::getfilePath()
{
    return filePath;
}

void File::attach(Observer* observer)
{
    _observers.push_back(observer);
}
void File::detach(Observer* observer) {
    _observers.erase(std::remove(_observers.begin(), _observers.end(), observer), _observers.end());
}
void File::notify() {
    for (auto& observer : _observers) {
        observer->update(this);
    }
}

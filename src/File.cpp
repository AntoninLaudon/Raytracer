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
    observers_.push_back(observer);
}
void File::detach(Observer* observer) {
    observers_.erase(std::remove(observers_.begin(), observers_.end(), observer), observers_.end());
}
void File::notify() {
    for (auto& observer : observers_) {
        observer->update(this);
    }
}

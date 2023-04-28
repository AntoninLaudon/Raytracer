/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-raytracer-tom.laiolo
** File description:
** SceneManager
*/

#include "SceneManager.hpp"

Raytracer::SceneManager::SceneManager(const char *path)
{
    _path = path;
}

Raytracer::SceneManager::~SceneManager()
{
}

void Raytracer::SceneManager::ParseScene()
{
    libconfig::Config cfg;
    Factory factory;
    try {
        cfg.readFile(_path.c_str());
    } catch (const libconfig::FileIOException &error) {
        std::cerr << "Error while reading file" << std::endl;
        throw std::runtime_error("Error while reading file");
    } catch (const libconfig::ParseException &error) {
        std::cerr << "Error while parsing file, line : " << error.getLine() << " error : " << error.getError() << std::endl;
        throw std::runtime_error("Error while parsing file");
    }
    try {
        //Add all plugins of .so files in the factory
        std::cout << "Loading plugins..." << std::endl;
        //Add all elements of the scene in the vector
        for (auto &elem : cfg.getRoot()) {
            if (strcmp(elem.getName(), "camera") == 0) {
                std::cout << "Loading camera..." << std::endl;
                CreateCamera(&elem);
            }
            //factory.createObject()
        }
        
    } catch (const libconfig::ParseException &error) {
        std::cerr << "Error while parsing file, line : " << error.getLine() << " error : " << error.getError() << std::endl;
        throw std::runtime_error("Error while parsing file");
    }
}

void Raytracer::SceneManager::CreateCamera(const libconfig::Setting *elem)
{
    const libconfig::Setting &camera_pos = elem->lookup("camera_position");
    const libconfig::Setting &screen_pos = elem->lookup("screen_position");
    const libconfig::Setting &screen_bottom = elem->lookup("screen_bottom");
    const libconfig::Setting &screen_left = elem->lookup("screen_left");
    double x = camera_pos[0];
    double y = camera_pos[1];
    double z = camera_pos[2];
    double sx = screen_pos[0];
    double sy = screen_pos[1];
    double sz = screen_pos[2];
    double sbx = screen_bottom[0];
    double sby = screen_bottom[1];
    double sbz = screen_bottom[2];
    double slx = screen_left[0];
    double sly = screen_left[1];
    double slz = screen_left[2];
    _camera = std::make_shared<Raytracer::Camera>(Math::Point3D(x, y, z), Raytracer::Rectangle3D(Math::Point3D(sx, sy, sz), Math::Vector3D(sbx, sby, sbz), Math::Vector3D(slx, sly, slz)));
    std::cout << "Camera loaded" << std::endl;
}

void Raytracer::SceneManager::Render()
{
    std::cout << "Rendering..." << std::endl;
    std::vector<PPM::RGB> pixels;
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            //pixels.push_back(_camera->ray(i, j));
            pixels.push_back(PPM::RGB(255, 0, 0));
        }
    }
    PPM::PPM img = PPM::PPM(1000, 1000);
    img.bufferToImage(pixels);
    img.save("screenshots/test.ppm");
}
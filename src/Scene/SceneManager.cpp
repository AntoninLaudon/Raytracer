/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-raytracer-tom.laiolo
** File description:
** SceneManager
*/

#include <chrono>
#include <thread>
#include "SceneManager.hpp"

Raytracer::SceneManager::SceneManager(const char *path)
{
    _path = path;
    _size.first = 100;
    _size.second = 100;
}

Raytracer::SceneManager::~SceneManager()
{
    size_t size = _elements.size();
    for (size_t i = 0; i < size; i++) {
        delete _elements[i];
    }
}

void Raytracer::SceneManager::ParseScene()
{
    libconfig::Config cfg;
    std::shared_ptr<Factory> factory = std::make_shared<Factory>();
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

        for (const auto &file : std::filesystem::directory_iterator("plugins/")) {
            if (file.path().extension() == ".so") {
                std::shared_ptr<LibLoader> loader = std::make_shared<LibLoader>();
                if (loader->Open(file.path().string())) {
                    _loader.push_back(loader);
                    auto type = reinterpret_cast<Raytracer::ElemType (*)()>(loader->GetSymbol("getType"))();
                    auto create = reinterpret_cast<Raytracer::IElement* (*)(Raytracer::Data)>(loader->GetSymbol("createObject"));
                    if (type && create)
                        factory->registerObject(type, create);
                }
            }
        }
        for (auto &elem : cfg.getRoot()) {
            if (strcmp(elem.getName(), "camera") == 0) {
                std::cout << "Loading camera..." << std::endl;
                CreateCamera(&elem);
            } else {
                CreateElement(&elem, factory);
            }
        }
    } catch (const libconfig::ParseException &error) {
        std::cerr << "Error while parsing file, line : " << error.getLine() << " error : " << error.getError() << std::endl;
        throw std::runtime_error("Error while parsing file");
    }
}

void Raytracer::SceneManager::CreateCamera(const libconfig::Setting *elem)
{
    const libconfig::Setting &camera_pos = elem->lookup("camera_position");
    const libconfig::Setting &camera_fov = elem->lookup("fov");
    double x = camera_pos[0];
    double y = camera_pos[1];
    double z = camera_pos[2];
    double fov = camera_fov[0];
    _camera = std::make_shared<Raytracer::Camera>(Math::Point3D(x, y, z), fov);
    std::cout << "Camera loaded" << std::endl;
}

void Raytracer::SceneManager::RenderLine(std::vector<PPM::RGB> &pixels, double y, int sizeBatch)
{
    Math::Vector3D tmp(0, 0, 0);
    std::vector<std::shared_ptr<Math::Point3D>> p;
    size_t size = _elements.size();
    Math::Point3D shortest(0, 0, 0);
    double shortestDist = -1;
    int y2 = y;
    for (int i = 0; i < sizeBatch; i++)
        for (double x = 0; x < _size.first; x++) {
            y = y2 + i;
            double u = x / _size.first;
            double v = y / _size.second;
            Math::Ray r = _camera->ray(u, v);
            p.clear();
            for (size_t i = 0; i < size; i++) {
                std::shared_ptr<Math::Point3D> tmp = _elements[i]->hits(r);
                if (tmp) {
                    tmp.get()->setLuminosity(_elements[i]->getLuminosity(_elements, *tmp.get()));
                    p.push_back(tmp);
                }
            }
            for (size_t i = 0; i < p.size(); i++) {
                tmp = _camera->getOrigin() - *p[i].get();
                if (shortestDist == -1 || shortestDist > tmp.length()) {
                    shortestDist = tmp.length();
                    shortest = *p[i];
                }
            }
            if (shortestDist != -1) {
                pixels[(int)y * _size.first + (int)x] = shortest.getColor() * shortest.getLuminosity();
                shortestDist = -1;
            } else {
                pixels[(int)y * _size.first + (int)x] = PPM::RGB(0, 0, 0);
        }
    }
}

std::shared_ptr<std::vector<PPM::RGB>> Raytracer::SceneManager::Render()
{
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    std::cout << "Rendering..." << std::endl;
    PPM::PPM img = PPM::PPM(_size.first, _size.second);
    std::vector<PPM::RGB> pixels = std::vector<PPM::RGB>(_size.first * _size.second);
    std::vector<std::thread> threads;
    int nbry = _size.second / std::thread::hardware_concurrency();
    for (size_t i = 0; i < std::thread::hardware_concurrency(); i++) {
        std::thread t(&SceneManager::RenderLine, this, std::ref(pixels), i * nbry, nbry);
        threads.push_back(std::move(t));
    }
    for (auto &t : threads)
        t.join();
    img.bufferToImage(std::make_shared<std::vector<PPM::RGB>>(pixels));
    //Create a string with the name : screenshots/screen_[year]_[month]_[day]_[hour]_[minute]_[second].ppm
    std::string name = "screenshots/screen_";
    std::time_t t = std::time(nullptr);
    std::tm tm = *std::localtime(&t);
    name += std::to_string(tm.tm_year + 1900) + "_" + std::to_string(tm.tm_mon + 1) + "_" + std::to_string(tm.tm_mday) + "_" + std::to_string(tm.tm_hour) + "_" + std::to_string(tm.tm_min) + "_" + std::to_string(tm.tm_sec) + ".ppm";
    _path = name;
    img.save(name.c_str());
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Done, took: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "ms" << std::endl;
    return std::make_shared<std::vector<PPM::RGB>>(pixels);
}

void Raytracer::SceneManager::CreateElement(const libconfig::Setting *elem, std::shared_ptr<Factory> factory)
{
    Raytracer::ElemType type = Raytracer::NONE;
    for (auto &elements : *elem) {
        for (int i = 0; i < elements.getLength(); i++) {
            Math::Point3D center = {0, 0, 0};
            Math::Vector3D direction = {0, 0, 0};
            Math::Vector3D direction2 = {0, 0, 0};
            Math::Vector3D rotation = {0, 0, 0};
            double d = 0;
            double d2 = 0;
            PPM::RGB color = {0, 0, 0};
            std::string name;
            if (strcmp(elements.getName(), "spheres") == 0)
                type = Raytracer::SPHERE;
            if (strcmp(elements.getName(), "planes") == 0)
                type = Raytracer::PLANE;
            if (strcmp(elements.getName(), "cylinders") == 0)
                type = Raytracer::CYLINDER;
            if (strcmp(elements.getName(), "triangles") == 0)
                type = Raytracer::TRIANGLE;
            if (strcmp(elements.getName(), "cones") == 0)
                type = Raytracer::CONE;
            if (strcmp(elements.getName(), "ambientlights") == 0)
                type = Raytracer::AMBIENTLIGHT;
            if (strcmp(elements.getName(), "directionallights") == 0)
                type = Raytracer::DIRECTIONALLIGHT;
            if (strcmp(elements.getName(), "spotlights") == 0)
                type = Raytracer::SPOTLIGHT;
            if (strcmp(elements.getName(), "resolution") == 0) {
                _size.first = elements.lookup("x");
                _size.second = elements.lookup("y");
                return;
            }
            if (elements[i].exists("center")) {
                const libconfig::Setting &center_elem = elements[i].lookup("center");
                center = {center_elem[0], center_elem[1], center_elem[2]};
            }
            if (elements[i].exists("direction")) {
                const libconfig::Setting &direction_elem = elements[i].lookup("direction");
                direction = {direction_elem[0], direction_elem[1], direction_elem[2]};
            }
            if (elements[i].exists("direction2")) {
                const libconfig::Setting &direction2_elem = elements[i].lookup("direction2");
                direction2 = {direction2_elem[0], direction2_elem[1], direction2_elem[2]};
            }
            if (elements[i].exists("rotation")) {
                const libconfig::Setting &rotation_elem = elements[i].lookup("rotation");
                rotation = {rotation_elem[0], rotation_elem[1], rotation_elem[2]};
            }
            if (elements[i].exists("double")) {
                const libconfig::Setting &double_elem = elements[i].lookup("double");
                d = double_elem;
            }
            if (elements[i].exists("double2")) {
                const libconfig::Setting &double2_elem = elements[i].lookup("double2");
                d2 = double2_elem;
            }
            if (elements[i].exists("name")) {
                elements[i].lookupValue("name", name);
            }
            if (elements[i].exists("color")) {
                //Set the color in color variable in RGB format
                unsigned int r = elements[i].lookup("color.r");
                unsigned int g = elements[i].lookup("color.g");
                unsigned int b = elements[i].lookup("color.b");
                if (r > 255 || g > 255 || b > 255)
                    throw std::runtime_error("Color value must be between 0 and 255");
                color = {(unsigned char)r, (unsigned char)g, (unsigned char)b};
            }
            if (type == NONE) {
                std::cerr << "Error: type not found: " << name << std::endl;
                continue;
            }
            Raytracer::Data data(type, name, center, direction, direction2, rotation, d, d2, color);
            Raytracer::IElement *element = factory->createObject(data);
            if (element == nullptr)
                throw std::runtime_error("Error: element not created");
            _elements.push_back(element);
        }
    }
}

std::string Raytracer::SceneManager::getPath()
{
    return _path;
}

void Raytracer::SceneManager::setPath(std::string path)
{
    _path = path;
}

std::vector<Raytracer::IElement*> Raytracer::SceneManager::getElements()
{
    return _elements;
}

std::pair<int, int> Raytracer::SceneManager::getSize() {
   return _size;
}

std::shared_ptr<Raytracer::Camera> Raytracer::SceneManager::getCamera() {
    return _camera;
}

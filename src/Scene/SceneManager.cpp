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
    PPM::PPM img = PPM::PPM(_size.first, _size.second);
    std::vector<PPM::RGB> pixels;
    std::vector<std::shared_ptr<Math::Point3D>> p;
    Math::Point3D shortest(0, 0, 0);
    size_t size = _elements.size();
    double shortestDist = -1;
    for (double y = _size.second; y > 0; y--) {
        for (double x = 0; x < _size.first; x++) {
            double u = x/_size.first;
            double v = y/_size.second;
            if (!_camera)
                std::cout << "t null chris" << std::endl;
            Math::Ray r = _camera->ray(u, v);
            p.clear();
            for (size_t i = 0; i < size; i++) {
                std::shared_ptr<Math::Point3D> tmp = _elements[i]->hits(r);
                if (tmp) {
                    p.push_back(tmp);
                }
            }
            for (size_t i = 0; i < p.size(); i++) {
                Math::Vector3D tmp = _camera->getOrigin() - *p[i].get();
                if (shortestDist == -1 || shortestDist > tmp.length()) {
                    shortestDist = tmp.length();
                    shortest = *p[i];
                }
            }
            if (shortestDist != -1) {
                pixels.push_back(shortest.getColor());
                shortestDist = -1;
            } else {
                pixels.push_back(PPM::RGB(0, 0, 0));
            }
        }
    }
    img.bufferToImage(pixels);
    //Create a string with the name : screenshots/screen_[year]_[month]_[day]_[hour]_[minute]_[second].ppm
    std::string name = "screenshots/screen_";
    std::time_t t = std::time(nullptr);
    std::tm tm = *std::localtime(&t);
    name += std::to_string(tm.tm_year + 1900) + "_" + std::to_string(tm.tm_mon + 1) + "_" + std::to_string(tm.tm_mday) + "_" + std::to_string(tm.tm_hour) + "_" + std::to_string(tm.tm_min) + "_" + std::to_string(tm.tm_sec) + ".ppm";
    _path = name;
    img.save(name.c_str());
    std::cout << "Done" << std::endl;
}

void Raytracer::SceneManager::CreateElement(const libconfig::Setting *elem, std::shared_ptr<Factory> factory)
{
    Raytracer::ElemType type = Raytracer::NONE;
    for (auto &elements : *elem) {
        for (int i = 0; i < elements.getLength(); i++) {
            Math::Point3D center = {0, 0, 0};
            Math::Vector3D direction = {0, 0, 0};
            Math::Vector3D rotation = {0, 0, 0};
            double d = 0;
            PPM::RGB color = {0, 0, 0};
            std::string name;
            if (strcmp(elements.getName(), "spheres") == 0)
                type = Raytracer::SPHERE;
            if (strcmp(elements.getName(), "lights") == 0)
                type = Raytracer::LIGHT;
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
            if (elements[i].exists("rotation")) {
                const libconfig::Setting &rotation_elem = elements[i].lookup("rotation");
                rotation = {rotation_elem[0], rotation_elem[1], rotation_elem[2]};
            }
            if (elements[i].exists("double")) {
                const libconfig::Setting &double_elem = elements[i].lookup("double");
                d = double_elem;
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
            Raytracer::Data data(type, name, center, direction, rotation, d, color);
            Raytracer::IElement *element = factory->createObject(data);
            _elements.push_back(element);
        }
    }
}

std::string Raytracer::SceneManager::getPath()
{
    return _path;
}

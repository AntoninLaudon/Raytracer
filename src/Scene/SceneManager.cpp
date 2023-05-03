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
                LibLoader loader;
                if (loader.Open(file.path().string())) {
                    _loader.push_back(loader);
                    auto type = reinterpret_cast<Raytracer::ElemType (*)()>(loader.GetSymbol("getType"))();
                    auto create = reinterpret_cast<std::shared_ptr<Raytracer::IElement> (*)(Raytracer::Data)>(loader.GetSymbol("createObject"));
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
        for (size_t i = 0; i < _elements.size(); i++) {
            std::cout << _elements[i]->getName() << std::endl;
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
    std::cout << "Done" << std::endl;
}

void Raytracer::SceneManager::CreateElement(const libconfig::Setting *elem, std::shared_ptr<Factory> factory)
{
    Raytracer::ElemType type = Raytracer::NONE;
    for (auto &elements : *elem) {
        std::cout << elements.getName() << std::endl;
        if (strcmp(elements.getName(), "spheres") == 0) {
            std::cout << "oui" << std::endl;
            type = Raytracer::SPHERE;
        }
        Math::Point3D center = {0, 0, 0};
        Math::Vector3D direction = {0, 0, 0};
        Math::Vector3D rotation = {0, 0, 0};
        double d = 0;
        std::string name = "";
        if (elements[0].exists("center")) {
            const libconfig::Setting &center_elem = elements[0].lookup("center");
            center = {center_elem[0], center_elem[1], center_elem[2]};
        }
        if (elements[0].exists("direction")) {
            const libconfig::Setting &direction_elem = elements[0].lookup("direction");
            direction = {direction_elem[0], direction_elem[1], direction_elem[2]};
        }
        if (elements[0].exists("rotation")) {
            const libconfig::Setting &rotation_elem = elements[0].lookup("rotation");
            rotation = {rotation_elem[0], rotation_elem[1], rotation_elem[2]};
        }
        if (elements[0].exists("double")) {
            const libconfig::Setting &double_elem = elements[0].lookup("double");
            d = double_elem;
        }
        if (elements[0].exists("name")) {
            name = elements[0].lookup("name").getName();
        }
        Raytracer::Data data(type, name, center, direction, rotation, d);
        std::cout << "data: \n\ttype:" << data.getType() << "\n\tname:" << data.getName() << "\n\tcenter:" << data.getCenter() << "\n\tdirection:" << data.getDirection() << "\n\trotation:" << data.getRotation() << "\n\tdouble:" << data.getDouble() << std::endl;
        std::shared_ptr<Raytracer::IElement> element = factory->createObject(data);
        if (!element)
            std::cout << "Element not created" << std::endl;
        if (!element->getName().empty())
            std::cout << "Element name: " << element->getName() << std::endl;
        _elements.push_back(element);
    }
}
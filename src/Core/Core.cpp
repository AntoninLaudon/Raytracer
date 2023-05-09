/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-raytracer-tom.laiolo
** File description:
** Core
*/

#include "Core.hpp"
#include "File.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

Raytracer::Core::Core()
{

}

Raytracer::Core::~Core()
{
}

void Raytracer::Core::CreateScene(File file)
{
    _scene = std::make_shared<Raytracer::SceneManager>(file.getfilePath().c_str());
    _scene->ParseScene();
}

void Raytracer::Core::Render()
{
    _scene->Render();
    int text_color = true;
    int code = 0;
    std::fstream file(_scene->getPath(), std::ios::in);
    std::string line;
    std::string w;
    std::string h;
    int width;
    int height;
    std::shared_ptr<libconfig::Config> config = std::make_shared<libconfig::Config>();
    if (file.is_open()) {
        std::getline(file, line);
        std::getline(file, w);
        std::getline(file, h);
        width = std::stoi(w);
        height = std::stoi(h);
    } else
        throw std::runtime_error("Error while opening file");
    sf::RenderWindow window(sf::VideoMode(width, height), "Raytracer");
    sf::String playerInput;
    sf::Text playerText;
    sf::Clock clock;
    sf::Time time;
    playerInput = "> ";
    playerText.setString(playerInput);
    playerText.setPosition(20,20);
    sf::Font font;
    font.loadFromFile("res/Arial.ttf");
    playerText.setFont(font);
    playerText.setCharacterSize(24);
    playerText.setFillColor(sf::Color::White);
    sf::Uint8 *pix = new sf::Uint8[width*height*4];
    sf::Texture texture;
    texture.create(width, height); 
    sf::Sprite sprite(texture);
    for(int i = 0, j = 0; i < width*height*4; i += 4, j++) {
        std::getline(file, line);
        std::string r;
        std::string g;
        std::string b;
        r = line.substr(0, line.find(" "));
        line.erase(0, line.find(" ") + 1);
        g = line.substr(0, line.find(" "));
        line.erase(0, line.find(" ") + 1);
        b = line.substr(0, line.find(" "));
        pix[i] = std::stoi(r);
        pix[i+1] = std::stoi(g);
        pix[i+2] = std::stoi(b);
        pix[i+3] = 255;
        if (j % width == 0) {
            texture.update(pix);
            window.clear();
            window.draw(sprite);
            window.display();
        }
    }
    file.close();
    texture.update(pix);
    while (window.isOpen()) {
        time = clock.getElapsedTime();
        sf::Event event;
        if (window.pollEvent(event) && time.asMilliseconds() > 30) {
            if (!text_color)
                playerText.setFillColor(sf::Color::White);
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                code = ExecuteCommand(playerInput, config);
                if (code == 2) {
                    std::cout << "Exiting..." << std::endl;
                    window.close();
                    return;
                }
                playerInput = "> ";
                playerText.setString(playerInput);
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) && playerInput.getSize() > 2) {
                playerInput.erase(playerInput.getSize() - 1, 1);
                playerText.setString(playerInput);
                clock.restart();
            } else if (event.type == sf::Event::TextEntered && !sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
                playerInput += event.text.unicode;
                playerText.setString(playerInput);
            }
        }
        if (time.asMilliseconds() > 700 && playerInput.getSize() == 2) {
            clock.restart();
            if (text_color)
                playerText.setFillColor(sf::Color::Transparent);
            else
                playerText.setFillColor(sf::Color::White);
            text_color = !text_color;
        }
        if (_file->hasChanged()) {
            window.close();
            _file->notify(*this);
            return;
        } 
        window.clear();
        window.draw(sprite);
        window.draw(playerText);
        window.display();
    }
    delete[] pix;
}

void Raytracer::Core::setFile(File *file)
{
    _file = file;
}

File *Raytracer::Core::getFile() const
{
    return _file;
}

int Raytracer::Core::ExecuteCommand(std::string command, std::shared_ptr<libconfig::Config> config)
{
    config->readFile(_file->getfilePath().c_str());
    command = command.substr(2);
    if (command == "exit") {
        return 2;
    } else if (command == "help") {
        std::cout << "Available commands:" << std::endl;
        std::cout << "\texit\t\tExit the program" << std::endl;
        std::cout << "\ttranslate {name} {x} {y} {z}\tTranslate an element" << std::endl;
        std::cout << "\thelp\t\tDisplay this help" << std::endl;
        std::cout << "\tlist\t\tList all elements" << std::endl;
    } else if (strncmp(command.c_str(), "translate", 9) == 0) {
        //Go to the configuration file and change the position of the element with the given name where command is : translate name x y z
        std::string name = command.substr(10, command.find(" ", 10) - 10);
        std::string x = command.substr(10 + name.size() + 1, command.find(" ", 10 + name.size() + 1) - (10 + name.size() + 1));
        std::string y = command.substr(10 + name.size() + 1 + x.size() + 1, command.find(" ", 10 + name.size() + 1 + x.size() + 1) - (10 + name.size() + 1 + x.size() + 1));
        std::string z = command.substr(10 + name.size() + 1 + x.size() + 1 + y.size() + 1, command.find(" ", 10 + name.size() + 1 + x.size() + 1 + y.size() + 1) - (10 + name.size() + 1 + x.size() + 1 + y.size() + 1));
        for (auto &elem : _scene->getElements()) {
            if (elem->getName() == name) {
                std::cout << "Translating " << name << " by x:" << x << " y:" << y << " z:" << z << std::endl;
                if (elem->getType() == Raytracer::SPHERE) {
                    elem->translate(std::stof(x), std::stof(y), std::stof(z));
                    libconfig::Setting& spheres = config->lookup("primitives.spheres");
                    for (auto &sphere : spheres) {
                        if (strcmp(sphere.lookup("name"), name.c_str()) == 0) {
                            sphere.lookup("center.x") = elem->getCenter().getX();
                            sphere.lookup("center.y") = elem->getCenter().getY();
                            sphere.lookup("center.z") = elem->getCenter().getZ();
                        }
                    }
                } else if (elem->getType() == Raytracer::PLANE) {
                    elem->translate(std::stof(x), std::stof(y), std::stof(z));
                    libconfig::Setting& planes = config->lookup("primitives.planes");
                    for (auto &plane : planes) {
                        if (strcmp(plane.lookup("name"), name.c_str()) == 0) {
                            plane.lookup("center.x") = elem->getCenter().getX();
                            plane.lookup("center.y") = elem->getCenter().getY();
                            plane.lookup("center.z") = elem->getCenter().getZ();
                        }
                    }
                } else if (elem->getType() == Raytracer::CYLINDER) {
                    elem->translate(std::stof(x), std::stof(y), std::stof(z));
                    libconfig::Setting& cylinders = config->lookup("primitives.cylinders");
                    for (auto &cylinder : cylinders) {
                        if (strcmp(cylinder.lookup("name"), name.c_str()) == 0) {
                            cylinder.lookup("center.x") = elem->getCenter().getX();
                            cylinder.lookup("center.y") = elem->getCenter().getY();
                            cylinder.lookup("center.z") = elem->getCenter().getZ();
                        }
                    }
                } else if (elem->getType() == Raytracer::TRIANGLE) {
                    elem->translate(std::stof(x), std::stof(y), std::stof(z));
                    libconfig::Setting& triangles = config->lookup("primitives.triangles");
                    for (auto &triangle : triangles) {
                        if (strcmp(triangle.lookup("name"), name.c_str()) == 0) {
                            triangle.lookup("center.x") = elem->getCenter().getX();
                            triangle.lookup("center.y") = elem->getCenter().getY();
                            triangle.lookup("center.z") = elem->getCenter().getZ();
                        }
                    }
                } else if (elem->getType() == Raytracer::LIGHT) {
                    elem->translate(std::stof(x), std::stof(y), std::stof(z));
                    libconfig::Setting& lights = config->lookup("lights.lights");
                    for (auto &light : lights) {
                        if (strcmp(light.lookup("name"), name.c_str()) == 0) {
                            light.lookup("center.x") = elem->getCenter().getX();
                            light.lookup("center.y") = elem->getCenter().getY();
                            light.lookup("center.z") = elem->getCenter().getZ();
                        }
                    }
                }
            }
        }
        config->writeFile(_file->getfilePath().c_str());
        return 0;
    } else if (strncmp(command.c_str(), "rotate", 6) == 0) {
        std::cout << "Rotating" << std::endl;
        //Go to the configuration file and change the rotate of the element with the given name where command is : rotate name x y z
        std::string name = command.substr(7, command.find(" ", 7) - 7);
        std::string x = command.substr(7 + name.size() + 1, command.find(" ", 7 + name.size() + 1) - (7 + name.size() + 1));
        std::string y = command.substr(7 + name.size() + 1 + x.size() + 1, command.find(" ", 7 + name.size() + 1 + x.size() + 1) - (7 + name.size() + 1 + x.size() + 1));
        std::string z = command.substr(7 + name.size() + 1 + x.size() + 1 + y.size() + 1, command.find(" ", 7 + name.size() + 1 + x.size() + 1 + y.size() + 1) - (7 + name.size() + 1 + x.size() + 1 + y.size() + 1));
        for (auto &elem : _scene->getElements()) {
            if (elem->getName() == name) {
                std::cout << "Rotating " << name << " by x:" << x << " y:" << y << " z:" << z << std::endl;
                if (elem->getType() == Raytracer::SPHERE) {
                    elem->rotate(std::stof(x), std::stof(y), std::stof(z));
                    libconfig::Setting& spheres = config->lookup("primitives.spheres");
                    for (auto &sphere : spheres) {
                        if (strcmp(sphere.lookup("name"), name.c_str()) == 0) {
                            sphere.lookup("rotation.x") = elem->getCenter().getX();
                            sphere.lookup("rotation.y") = elem->getCenter().getY();
                            sphere.lookup("rotation.z") = elem->getCenter().getZ();
                        }
                    }
                } else if (elem->getType() == Raytracer::PLANE) {
                    elem->rotate(std::stof(x), std::stof(y), std::stof(z));
                    libconfig::Setting& planes = config->lookup("primitives.planes");
                    for (auto &plane : planes) {
                        if (strcmp(plane.lookup("name"), name.c_str()) == 0) {
                            plane.lookup("rotation.x") = elem->getCenter().getX();
                            plane.lookup("rotation.y") = elem->getCenter().getY();
                            plane.lookup("rotation.z") = elem->getCenter().getZ();
                        }
                    }
                } else if (elem->getType() == Raytracer::CYLINDER) {
                    elem->rotate(std::stof(x), std::stof(y), std::stof(z));
                    libconfig::Setting& cylinders = config->lookup("primitives.cylinders");
                    for (auto &cylinder : cylinders) {
                        if (strcmp(cylinder.lookup("name"), name.c_str()) == 0) {
                            cylinder.lookup("rotation.x") = elem->getCenter().getX();
                            cylinder.lookup("rotation.y") = elem->getCenter().getY();
                            cylinder.lookup("rotation.z") = elem->getCenter().getZ();
                        }
                    }
                } else if (elem->getType() == Raytracer::TRIANGLE) {
                    elem->rotate(std::stof(x), std::stof(y), std::stof(z));
                    libconfig::Setting& triangles = config->lookup("primitives.triangles");
                    for (auto &triangle : triangles) {
                        if (strcmp(triangle.lookup("name"), name.c_str()) == 0) {
                            triangle.lookup("rotation.x") = elem->getCenter().getX();
                            triangle.lookup("rotation.y") = elem->getCenter().getY();
                            triangle.lookup("rotation.z") = elem->getCenter().getZ();
                        }
                    }
                } else if (elem->getType() == Raytracer::LIGHT) {
                    elem->rotate(std::stof(x), std::stof(y), std::stof(z));
                    libconfig::Setting& lights = config->lookup("lights.lights");
                    for (auto &light : lights) {
                        if (strcmp(light.lookup("name"), name.c_str()) == 0) {
                            light.lookup("rotation.x") = elem->getCenter().getX();
                            light.lookup("rotation.y") = elem->getCenter().getY();
                            light.lookup("rotation.z") = elem->getCenter().getZ();
                        }
                    }
                }
            }
        }
        config->writeFile(_file->getfilePath().c_str());
        return 0;
    } else if (strncmp(command.c_str(), "resolution", 10) == 0) {
        std::string w = command.substr(11, command.find(" ", 11) - 11);
        std::string h = command.substr(11 + w.size() + 1, command.find(" ", 11 + w.size() + 1) - (11 + w.size() + 1));
        std::cout << "Changing resolution to " << w << "x" << h << std::endl;
        config->lookup("options.resolution.x") = std::stoi(w);
        config->lookup("options.resolution.y") = std::stoi(h);
        config->writeFile(_file->getfilePath().c_str());
        return 0;
    } else if (command == "list") {
        std::cout << "Elements:" << std::endl;
        for (auto &elem : _scene->getElements()) {
            std::cout << "\t" << elem->getName() << ", position : { x:" << elem->getCenter().getX() << ", y:" << elem->getCenter().getY() << ", z:" << elem->getCenter().getZ() << "}, rotation : { x:" << elem->getRotation().getX() << ", y:" << elem->getRotation().getY() << ", z:" << elem->getRotation().getZ() << "}" << std::endl;
        }
        return 0;
    } else {
        std::cout << "Unknown command" << std::endl;
    }
    return 0;
}
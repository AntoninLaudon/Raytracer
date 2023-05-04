/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-raytracer-tom.laiolo
** File description:
** Core
*/

#include "Core.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

Raytracer::Core::Core()
{
}

Raytracer::Core::~Core()
{
}

void Raytracer::Core::Run()
{
    std::string path = "scenes/scene1.json";
    CreateScene(path);
    Render();
}

void Raytracer::Core::CreateScene(std::string path)
{
    _scene = std::make_shared<Raytracer::SceneManager>(path.c_str());
    _scene->ParseScene();
}

void Raytracer::Core::Render()
{
    _scene->Render();
    std::fstream file(_scene->getPath(), std::ios::in);
    std::string line;
    std::string w;
    std::string h;
    int width;
    int height;
    if (file.is_open()) {
        std::getline(file, line);
        std::getline(file, w);
        std::getline(file, h);
        width = std::stoi(w);
        height = std::stoi(h);
    } else
        throw std::runtime_error("Error while opening file");
    sf::RenderWindow window(sf::VideoMode(width, height), "Raytracer");
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
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
            window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
                window.clear();
                window.display();
                std::cout << "Enter pressed" << std::endl;
                _scene->Render();
                sf::Uint8 *new_pix = new sf::Uint8[width*height*4];
                sf::Texture new_texture;
                new_texture.create(width, height);
                sprite.setTexture(new_texture);
                std::fstream file(_scene->getPath(), std::ios::in);
                std::string line;
                std::string w;
                std::string h;
                int width;
                int height;
                if (file.is_open()) {
                    std::getline(file, line);
                    std::getline(file, w);
                    std::getline(file, h);
                    width = std::stoi(w);
                    height = std::stoi(h);
                } else
                    throw std::runtime_error("Error while opening file");
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
                    new_pix[i] = std::stoi(r);
                    new_pix[i+1] = std::stoi(g);
                    new_pix[i+2] = std::stoi(b);
                    new_pix[i+3] = 255;
                    if (j % width == 0) {
                        new_texture.update(new_pix);
                        window.clear();
                        window.draw(sprite);
                        window.display();
                    }
                }
                new_texture.update(new_pix);
            }
        }
    }
}

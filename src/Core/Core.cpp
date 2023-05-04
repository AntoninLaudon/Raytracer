/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-raytracer-tom.laiolo
** File description:
** Core
*/

#include "Core.hpp"
#include "File.hpp"
#include "Textfield.hpp"

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
    sf::TextField textField(20);
    textField.setPosition(200, 200);
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
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
            } else if (event.type == sf::Event::MouseButtonReleased) {
                auto pos = sf::Mouse::getPosition(window);
                textField.setFocus(false);
                if (textField.contains(sf::Vector2f(pos)))
                    textField.setFocus(true);
            } else
                textField.handleInput(event);
        }
        if (_file->hasChanged()) {
            window.close();
            _file->notify(*this);
        }
        window.clear();
        window.draw(sprite);
        window.draw(textField);
        window.display();
    }
}

void Raytracer::Core::setFile(File *file)
{
    _file = file;
}

File *Raytracer::Core::getFile() const
{
    return _file;
}
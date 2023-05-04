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
    int text_color = true;
    int code = 0;
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
                code = ExecuteCommand(playerInput);
                if (code == 1) {
                    window.close();
                    std::cout << "Saving..." << std::endl;
                    _scene->setPath(_file->getfilePath());
                    std::cout << _scene->getPath() << std::endl;
                    _scene->ParseScene();
                    return Render();
                } else if (code == 2) {
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
        }
        window.clear();
        window.draw(sprite);
        window.draw(playerText);
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

int Raytracer::Core::ExecuteCommand(std::string command)
{
    command = command.substr(2);
    if (command == "save") {
        return 1;
    } else if (command == "exit") {
        return 2;
    } else if (command == "help") {
        std::cout << "Available commands:" << std::endl;
        std::cout << "\tsave\t\tSave the current scene" << std::endl;
        std::cout << "\texit\t\tExit the program" << std::endl;
        std::cout << "\ttranslate {name} {x} {y} {z}\tTranslate an element" << std::endl;
        std::cout << "\thelp\t\tDisplay this help" << std::endl;
    } else if (strncmp(command.c_str(), "translate", 9) == 0) {
        //Go to the configuration file and change the position of the element with the given name where command is : translate name x y z
        std::string name = command.substr(10, command.find(" ", 10) - 10);
        std::string x = command.substr(10 + name.size() + 1, command.find(" ", 10 + name.size() + 1) - (10 + name.size() + 1));
        std::string y = command.substr(10 + name.size() + 1 + x.size() + 1, command.find(" ", 10 + name.size() + 1 + x.size() + 1) - (10 + name.size() + 1 + x.size() + 1));
        std::string z = command.substr(10 + name.size() + 1 + x.size() + 1 + y.size() + 1, command.find(" ", 10 + name.size() + 1 + x.size() + 1 + y.size() + 1) - (10 + name.size() + 1 + x.size() + 1 + y.size() + 1));
        std::cout << "Translating " << name << " by x : " << x << " y : " << y << " z : " << z << std::endl;
        return 0;
    } else {
        std::cout << "Unknown command" << std::endl;
    }
    return 0;
}
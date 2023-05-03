/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-raytracer-tom.laiolo
** File description:
** test
*/

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
    std::fstream file("img2.ppm", std::ios::in);
    std::string line;
    std::string w;
    std::string h;
    int width;
    int height;
    int counter = 0;

    if (file.is_open()) {
        std::getline(file, line);
        std::getline(file, w);
        std::getline(file, h);
        width = std::stoi(w);
        height = std::stoi(h);
    } else
        return 84;
    sf::RenderWindow window(sf::VideoMode(width, height), "My window");
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
        }
        window.clear();
        window.draw(sprite);
        window.display();
    }
    return 0;
}
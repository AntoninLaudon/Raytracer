/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-raytracer-tom.laiolo
** File description:
** Textfield
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <string>

namespace sf {
    class TextField : public sf::Transformable, public sf::Drawable {
        public:
            TextField(unsigned int maxChars);
            ~TextField();
            const std::string getText() const;
            void setPosition(float x, float y);
            bool contains(sf::Vector2f point) const;
            void setFocus(bool focus);
            void handleInput(sf::Event e);
            void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        private:
            unsigned int _size;
            sf::Font _font;
            std::string _text;
            bool _hasfocus;
            sf::RectangleShape _rect;
    };
}

/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-raytracer-tom.laiolo
** File description:
** Textfield
*/

#include "Textfield.hpp"

sf::TextField::TextField(unsigned int maxChars)
{
    _size = maxChars;
    _hasfocus = false;
    _font.loadFromFile("res/Arial.ttf");
    _rect.setOutlineThickness(2);
    _rect.setFillColor(sf::Color::White);
    _rect.setOutlineColor(sf::Color(0,0,0));
    _rect.setPosition(this->getPosition());
}

sf::TextField::~TextField()
{
}

const std::string sf::TextField::getText() const
{
    return _text;
}

void sf::TextField::setPosition(float x, float y)
{
    sf::Transformable::setPosition(x, y);
    _rect.setPosition(x, y);
}

bool sf::TextField::contains(sf::Vector2f point) const
{
    return _rect.getGlobalBounds().contains(point);
}

void sf::TextField::setFocus(bool focus)
{
    _hasfocus = focus;
    if (focus)
        _rect.setOutlineColor(sf::Color::Blue);
    else
        _rect.setOutlineColor(sf::Color(127, 127, 127));
}

void sf::TextField::handleInput(sf::Event e)
{
    if (!_hasfocus || e.type != sf::Event::TextEntered)
        return;
    if (e.text.unicode == 8) {
        _text = _text.substr(0, _text.size() - 1);
    } else if (_text.size() < _size) {
        _text += e.text.unicode;
    }
}

void sf::TextField::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(_rect, states);
}

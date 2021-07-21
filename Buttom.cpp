//
// Created by DELL on 16.06.2021.
//


#include "Buttom.h"

Buttom::Buttom(std::string text, sf::Font &font) {

    button.setSize({200, 100});

    //set up width adn height
    button.setFillColor(sf::Color(200,200,200));
    this->text.setString(text);
    this->text.setFont(font);
    this->text.setFillColor(sf::Color::Black);
    this->text.setOrigin(this->text.getGlobalBounds().width / 2, 0);
}

void Buttom::setPosition(sf::Vector2f point) {
    button.setPosition(point);

    //center the text
    float xPosition = (this->button.getGlobalBounds().width / 2);
    float yPosition = (this->button.getGlobalBounds().height / 2);
    text.setPosition(point.x + xPosition, point.y + yPosition);
}

void Buttom::drawTo(sf::RenderWindow &window) {
    window.draw(button);
    window.draw(text);
}

bool Buttom::isMouseOver(sf::RenderWindow &window) {
    if (this->button.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
        return true;
    }
    else return false;
}
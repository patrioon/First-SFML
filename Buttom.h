//
// Created by DELL on 16.06.2021.
//

#ifndef PROJEKT_001_BUTTOM_H
#define PROJEKT_001_BUTTOM_H

#include <SFML/Graphics.hpp>

class Buttom {
private:

    sf::RectangleShape button;
    sf::Color color;
    sf::Text text;

public:

    Buttom(std::string text, sf::Font &font);
    void setPosition(sf::Vector2f point);

    void drawTo(sf::RenderWindow &window);
    bool isMouseOver(sf::RenderWindow &window);
};


#endif //PROJEKT_001_BUTTOM_H

//
// Created by Chandler Desforges on 5/1/24.
//

#ifndef SFML_PONG_MENU_H
#define SFML_PONG_MENU_H

#include "GameLogic.h"
#include <iostream>
#include <filesystem>
#include <mach-o/dyld.h>

class Menu
{

public:
    static sf::Text start;
    static sf::Text p1score;
    static sf::Text p2score;
    static sf::Font retro;

public:
    explicit Menu(sf::Vector2<unsigned int> windowSize);
    static void setFont(std::string fontLocation);
    void update();

};


#endif //SFML_PONG_MENU_H

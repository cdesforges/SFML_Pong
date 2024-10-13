//
// Created by Chandler Desforges on 4/29/24.
//

#ifndef SFML_PONG_PLAYER_H
#define SFML_PONG_PLAYER_H

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>



class Player
{
private:
    sf::RectangleShape m_playerShape;
    sf::Vector2f m_position;
    sf::Vector2f m_direction;
    double m_speed;

public:
    Player(sf::Vector2f size, sf::Vector2f positionIn, double speedIn);
    sf::Vector2f getPosition();
    sf::RectangleShape getShape();
    void moveUp();
    void moveDown();
    void update(sf::Time dt);
};

#endif //SFML_PONG_PLAYER_H

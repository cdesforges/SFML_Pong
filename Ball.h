//
// Created by Chandler Desforges on 4/30/24.
//

#ifndef SFML_PONG_BALL_H
#define SFML_PONG_BALL_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Ball {

private:
    sf::RectangleShape m_ballShape;
    sf::Vector2f m_position;
    sf::Vector2f m_direction;
    double m_speed;
    double m_startSpeed;

public:
    Ball(sf::Vector2f size, double startSpeed, sf::Vector2f startDirection, sf::Vector2f startPosition);
    sf::Vector2f getPosition();
    sf::RectangleShape getShape();
    void bounceBounds();
    void bouncePaddle();
    void resetToCenter();
    bool intersects(const sf::RectangleShape& paddle);
    void update(sf::Time dt);
};


#endif //SFML_PONG_BALL_H

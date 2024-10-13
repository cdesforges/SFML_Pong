//
// Created by Chandler Desforges on 4/30/24.
//

#include "Ball.h"
#include <iostream>

Ball::Ball(sf::Vector2f size, double startSpeed, sf::Vector2f startDirection, sf::Vector2f startPosition)
{
    m_position = startPosition;
    m_startSpeed = startSpeed;
    m_direction = startDirection;

    m_speed = m_startSpeed;

    m_ballShape.setSize(size);
    m_ballShape.setFillColor(sf::Color::White);
    m_ballShape.setPosition(m_position);

//    std::cout << "Start position x = " << m_position.x << std::endl;
//    std::cout << "Start position y = " << m_position.y << std::endl;
}

sf::Vector2f Ball::getPosition()
{
    return m_ballShape.getPosition();
}

sf::RectangleShape Ball::getShape()
{
    return m_ballShape;
}

void Ball::bounceBounds()
{
    m_direction.y = -m_direction.y;
}

void Ball::bouncePaddle()
{
    m_direction.x = -m_direction.x;
    m_speed += 30;
}

void Ball::resetToCenter()
{
    m_position = sf::Vector2f(595, 395);  // Assuming 595, 395 is the center
    m_ballShape.setPosition(m_position);  // Ensure the shape is also moved to the center

//
    m_speed = m_startSpeed; // reset to start speed

    // std::cout << "Ball reset to center with position: " << m_position.x << ", " << m_position.y << std::endl;
}

bool Ball::intersects(const sf::RectangleShape& paddle)
{
    sf::FloatRect ballBounds = m_ballShape.getGlobalBounds();
    sf::FloatRect paddleBounds = paddle.getGlobalBounds();

    return ballBounds.intersects(paddleBounds);
}

void Ball::update(sf::Time dt)
{
    m_position.x += m_direction.x * m_speed * dt.asSeconds();
    m_position.y += m_direction.y * m_speed * dt.asSeconds();

//    std::cout << "Updating position: (" << m_position.x << ", " << m_position.y << ")" << " with dt: " << dt.asSeconds() << std::endl;

    m_ballShape.setPosition(m_position);
}
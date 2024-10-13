//
// Created by Chandler Desforges on 4/29/24.
//

#include "Player.h"

Player::Player(sf::Vector2f size, sf::Vector2f startPosition, double startSpeed)
{
    m_position = startPosition;
    m_direction = sf::Vector2f(0,0);
    m_speed = startSpeed;

    m_playerShape.setSize(size);
    m_playerShape.setFillColor(sf::Color::White);
    m_playerShape.setPosition(m_position);
}

sf::Vector2f Player::getPosition()
{
    return m_playerShape.getPosition();
}

sf::RectangleShape Player::getShape()
{
    return m_playerShape;
}

void Player::moveUp()
{
    m_position.y -= m_speed;
    m_playerShape.setPosition(m_position);
}

void Player::moveDown()
{
    m_position.y += m_speed;
    m_playerShape.setPosition(m_position);
}

void Player::update(sf::Time dt)
{
    m_position.x += m_direction.x * m_speed * dt.asSeconds();
    m_position.y += m_direction.y * m_speed * dt.asSeconds();

    m_playerShape.setPosition(m_position);
}
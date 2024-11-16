//
// Created by Chandler Desforges on 4/30/24.
//

#include "BallModel.h"

BallModel::BallModel(sf::Vector2f size, sf::Vector2f initialPosition)
: m_size(size), m_position(initialPosition)
{}

const sf::Vector2f& BallModel::getSize() const
{
    return m_size;
}

const sf::Vector2f& BallModel::getPosition() const
{
    return m_position;
}

const sf::Vector2f& BallModel::getVelocity() const
{
    return m_velocity;
}

void BallModel::setSize(const sf::Vector2f& size)
{
    m_size = size;
}

void BallModel::setPosition(const sf::Vector2f& position)
{
    m_position = position;
}

void BallModel::setVelocity(const sf::Vector2f& velocity)
{
    m_velocity = velocity;
}

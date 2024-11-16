//
// Created by Chandler Desforges on 11/14/24.
//

#include "Ball.h"
#include <iostream>

Ball::Ball()
: Ball({10,10}, {0,0})
{}

Ball::Ball(const sf::Vector2f& initialPosition)
: Ball({10,10}, initialPosition)
{}

Ball::Ball(const sf::Vector2f& size, const sf::Vector2f& initialPosition)
: m_model(size, initialPosition), m_view(size, initialPosition), m_controller(m_model, m_view)
{}

const sf::Vector2f& Ball::getPosition() const
{
    return m_model.getPosition();
}

const sf::Vector2f& Ball::getVelocity() const
{
    return m_model.getVelocity();
}

void Ball::setPosition(const sf::Vector2f& position)
{
    m_model.setPosition(position);
}

void Ball::setVelocity(const sf::Vector2f& velocity)
{
    m_model.setVelocity(velocity);
}

sf::FloatRect Ball::getGlobalBounds() const
{
    return m_view.getGlobalBounds();
}

void Ball::collisionReaction(const Collidable& other)
{
    std::cout << "got here\n";

    m_controller.collisionReaction(other);

}

void Ball::eventHandler(sf::Event& event)
{
    // nothing to see here
}

void Ball::update(sf::Time& dt)
{
    m_controller.update(dt);
}

void Ball::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    window.draw(m_view);
}

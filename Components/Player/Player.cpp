//
// Created by Chandler Desforges on 11/14/24.
//

#include "Player.h"

Player::Player()
: Player({10,100}, {0,0})
{}

Player::Player(const sf::Vector2f& initialPosition)
: Player({10, 100}, initialPosition)
{}

Player::Player(const sf::Vector2f& size, const sf::Vector2f& initialPosition)
: m_paddle(size, initialPosition)
{}

void Player::setPosition(const sf::Vector2f& position)
{
    m_paddle.setPosition(position);
}

void Player::setControls(const sf::Keyboard::Key& up, const sf::Keyboard::Key& down)
{
    m_controls.up = up;
    m_controls.down = down;

    m_paddle.setControls(m_controls);
}

sf::FloatRect Player::getGlobalBounds() const
{
    return m_paddle.getGlobalBounds();
}

void Player::collisionReaction(const Collidable& other)
{
    // do nothing
}

void Player::eventHandler(sf::Event& event)
{
    m_paddle.eventHandler(event);
}

void Player::update(sf::Time& dt)
{
    m_paddle.update(dt);
}

void Player::draw(sf::RenderTarget& window, sf::RenderStates state) const
{
    window.draw(m_paddle);
}

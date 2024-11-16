//
// Created by Chandler Desforges on 11/14/24.
//

#include "BallController.h"

BallController::BallController(BallModel& model, BallView& view)
: m_model(model), m_view(view)
{}

void BallController::collisionReaction(const Collidable& other)
{
    // for readability
    float ball_top = m_view.getGlobalBounds().top;
    float ball_bottom = m_view.getGlobalBounds().top + m_view.getGlobalBounds().height;
    float ball_left = m_view.getGlobalBounds().left;
    float ball_right = m_view.getGlobalBounds().left + m_view.getGlobalBounds().width;

    float other_top = other.getGlobalBounds().top;
    float other_bottom = other.getGlobalBounds().top + other.getGlobalBounds().height;
    float other_left = other.getGlobalBounds().left;
    float other_right = other.getGlobalBounds().left + other.getGlobalBounds().width;

    // Top collision
    if (ball_top < other_bottom && ball_bottom > other_bottom && m_model.getVelocity().y < 0)
    {
        m_model.setVelocity({m_model.getVelocity().x, -m_model.getVelocity().y});
        return; // Prevent further checks in this frame
    }

    // Bottom collision
    if (ball_bottom > other_top && ball_top < other_top && m_model.getVelocity().y > 0)
    {
        m_model.setVelocity({m_model.getVelocity().x, -m_model.getVelocity().y});
        return;
    }

    // Left collision
    if (ball_left < other_right && ball_right > other_right && m_model.getVelocity().x < 0)
    {
        m_model.setVelocity({-m_model.getVelocity().x, m_model.getVelocity().y});
        return;
    }

    // Right collision
    if (ball_right > other_left && ball_left < other_left && m_model.getVelocity().x > 0)
    {
        m_model.setVelocity({-m_model.getVelocity().x, m_model.getVelocity().y});
        return;
    }
}

void BallController::update(sf::Time& dt)
{
    // update ball's position
    sf::Vector2f new_position;

    new_position.x = m_model.getPosition().x + m_model.getVelocity().x * dt.asSeconds();
    new_position.y = m_model.getPosition().y + m_model.getVelocity().y * dt.asSeconds();

    m_model.setPosition(new_position);

    // update view based on model
    m_view.update(m_model);
}

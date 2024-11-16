//
// Created by Chandler Desforges on 11/14/24.
//

#ifndef SFML_PONG_BALL_H
#define SFML_PONG_BALL_H

#include "BallModel.h"
#include "BallView.h"
#include "BallController.h"
#include "../Component.h"
#include "../../Collision/Collidable.h"

class Ball : public Component, public Collidable
{
private:
    BallModel m_model;
    BallView m_view;
    BallController m_controller;

public:
    Ball();
    explicit Ball(const sf::Vector2f& initialPosition);
    Ball(const sf::Vector2f& size, const sf::Vector2f& initialPosition);

    // getters
    const sf::Vector2f& getPosition() const;
    const sf::Vector2f& getVelocity() const;

    // setters
    void setPosition(const sf::Vector2f& position);
    void setVelocity(const sf::Vector2f& velocity);

    // inherited
    sf::FloatRect getGlobalBounds() const override;
    void collisionReaction(const Collidable& other) override;
    void eventHandler(sf::Event &event) override;
    void update(sf::Time &dt) override;
    void draw(sf::RenderTarget &window, sf::RenderStates states) const override;
};


#endif //SFML_PONG_BALL_H

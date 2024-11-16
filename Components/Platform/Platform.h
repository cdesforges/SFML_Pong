//
// Created by Chandler Desforges on 11/14/24.
//

#ifndef SFML_PONG_PLATFORM_H
#define SFML_PONG_PLATFORM_H


#include <SFML/Graphics.hpp>
#include "PlatformModel.h"
#include "../Component.h"
#include "PlatformView.h"
#include "PlatformController.h"
#include "../Player/PlayerControls.h"
#include "../../Collision/Collidable.h"

class Platform : public Component, public Collidable
{
protected:
    PlatformModel m_model;
    PlatformView m_view;
    PlatformController m_controller;

public:
    Platform();
    Platform(sf::Vector2f size, sf::Vector2f initialPosition);

    // setters
    void setControls(const PlayerControls& controls);
    void setPosition(const sf::Vector2f& position);

    // inherited
    sf::FloatRect getGlobalBounds() const override;
    void collisionReaction(const Collidable& other) override;
    void eventHandler(sf::Event& event) override;
    void update(sf::Time &dt) override;
    void draw(sf::RenderTarget& window, sf::RenderStates state) const override;
};


#endif //SFML_PONG_PLATFORM_H

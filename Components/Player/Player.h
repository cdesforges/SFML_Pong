//
// Created by Chandler Desforges on 11/14/24.
//

#ifndef SFML_PONG_PLAYER_H
#define SFML_PONG_PLAYER_H


#include <SFML/Graphics.hpp>
#include "../Component.h"
#include "../Paddle/Paddle.h"
#include "PlayerControls.h"
#include "../../Collision/Collidable.h"

class Player : public Component, public Collidable
{
private:
    int m_score = 0;
    Paddle m_paddle;
    PlayerControls m_controls;

public:
    Player();
    explicit Player(const sf::Vector2f& initialPosition);
    Player(const sf::Vector2f& size, const sf::Vector2f& initialPosition);

    // getters
    int getScore() const {return m_score;};

    // setters
    void setScore(int score) {m_score = score;};
    void setControls(const sf::Keyboard::Key& up, const sf::Keyboard::Key& down);
    void setPosition(const sf::Vector2f& position);

    // inherited
    sf::FloatRect getGlobalBounds() const override;
    void collisionReaction(const Collidable& other) override;
    void eventHandler(sf::Event& event) override;
    void update(sf::Time& dt) override;
    void draw(sf::RenderTarget& window, sf::RenderStates state) const override;
};


#endif //SFML_PONG_PLAYER_H

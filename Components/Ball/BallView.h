//
// Created by Chandler Desforges on 11/4/24.
//

#ifndef SFML_PONG_BALLVIEW_H
#define SFML_PONG_BALLVIEW_H


#include <SFML/Graphics.hpp>
#include "BallModel.h"

class BallView : public sf::Drawable
{
private:
    sf::RectangleShape m_ballShape;

public:
    BallView(const sf::Vector2f& size, const sf::Vector2f& initialPosition);

    // getters
    sf::FloatRect getGlobalBounds() const;

    void update(const BallModel& model);

    // inherited
    void draw(sf::RenderTarget& window, sf::RenderStates state) const override;
};


#endif //SFML_PONG_BALLVIEW_H

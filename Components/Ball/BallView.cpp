//
// Created by Chandler Desforges on 11/4/24.
//

#include "BallView.h"

BallView::BallView(const sf::Vector2f& size, const sf::Vector2f& initialPosition)
: m_ballShape(size)
{
    m_ballShape.setOrigin({size.x / 2, size.y / 2});
    m_ballShape.setPosition(initialPosition);
}

sf::FloatRect BallView::getGlobalBounds() const
{
    return m_ballShape.getGlobalBounds();
}

void BallView::update(const BallModel& model)
{
    m_ballShape.setPosition(model.getPosition());
}

void BallView::draw(sf::RenderTarget& window, sf::RenderStates state) const
{
    window.draw(m_ballShape);
}

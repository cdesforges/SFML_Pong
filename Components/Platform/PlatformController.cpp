//
// Created by Chandler Desforges on 11/14/24.
//

#include "PlatformController.h"

PlatformController::PlatformController(PlatformModel& model, PlatformView& view)
: m_model(model), m_view(view)
{}

void PlatformController::eventHandler(sf::Event event)
{
    // check for keyboard input
    if(event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == m_controls.up)
            m_model.setVelocity({0, -500});
        else if (event.key.code == m_controls.down)
            m_model.setVelocity({0, 500});
    }
    else if(event.type == sf::Event::KeyReleased)
        if(event.key.code == m_controls.up || event.key.code == m_controls.down)
            m_model.setVelocity({0,0});
}

void PlatformController::setControls(const PlayerControls& controls)
{
    m_controls = controls;
}

void PlatformController::update(sf::Time& dt)
{
    // update the model position based on it's velocity
    sf::Vector2f new_position;

    new_position.x = m_model.getPosition().x + m_model.getVelocity().x * dt.asSeconds();
    new_position.y = m_model.getPosition().y + m_model.getVelocity().y * dt.asSeconds();

    m_model.setPosition(new_position);

    // update the view object based on the new model values
    m_view.update(m_model);
}

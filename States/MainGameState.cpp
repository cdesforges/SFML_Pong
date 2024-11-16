//
// Created by Chandler Desforges on 11/14/24.
//

#include "MainGameState.h"

MainGameState::MainGameState(sf::RenderWindow& window, StateManager& stateManager)
: State(window, stateManager),
m_p1({20, (float)i_window.getSize().y / 2}),
m_p2({(float)i_window.getSize().x - 20, (float)i_window.getSize().y / 2}),
m_ball({(float)i_window.getSize().x / 2, (float)i_window.getSize().y / 2}),
m_ceiling({(float)i_window.getSize().x, 10}, {(float)i_window.getSize().x / 2,5}),
m_floor({(float)i_window.getSize().x, 10}, {(float)i_window.getSize().x / 2,(float)i_window.getSize().y - 5}),
m_leftWall({10, (float)i_window.getSize().y}, {5, (float)i_window.getSize().y / 2}),
m_rightWall({10, (float)i_window.getSize().y}, {(float)i_window.getSize().x - 5, (float)i_window.getSize().y / 2})
{
    initialize();
}

void MainGameState::initialize()
{
    m_p1.setControls(sf::Keyboard::Key::Q, sf::Keyboard::Key::A);
    m_p2.setControls(sf::Keyboard::Key::P, sf::Keyboard::Key::L);

    m_gameComponents.push_back(&m_p1);
    m_gameComponents.push_back(&m_p2);
    m_gameComponents.push_back(&m_ball);
    m_gameComponents.push_back(&m_ceiling);
    m_gameComponents.push_back(&m_floor);
    m_gameComponents.push_back(&m_leftWall);
    m_gameComponents.push_back(&m_rightWall);
}

std::vector<Collidable*> MainGameState::getCollidableObjects()
{
    std::vector<Collidable*> res;

    for(auto& comp : m_gameComponents)
        if(auto* collidable = dynamic_cast<Collidable*>(comp))
            res.push_back(collidable);

    return res;
}

void MainGameState::eventHandler(sf::Event& event)
{
    for(auto& component : m_gameComponents)
        component->eventHandler(event);
}

void MainGameState::update(sf::Time& dt)
{
    // handle collisions
    Collision::resolveCollisions(getCollidableObjects());

    for(auto& component : m_gameComponents)
        component->update(dt);
}

void MainGameState::draw()
{
    for(auto& component : m_gameComponents)
        i_window.draw(*component);
}

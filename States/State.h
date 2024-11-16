//
// Created by Chandler Desforges on 11/14/24.
//

#ifndef SFML_PONG_STATE_H
#define SFML_PONG_STATE_H

#include <SFML/Graphics.hpp>

class StateManager;

class State
{
protected:
    StateManager& i_stateManager;
    sf::RenderWindow& i_window;

public:
    State(sf::RenderWindow& window, StateManager& stateManager)
    : i_window(window), i_stateManager(stateManager){};

    virtual ~State() = default;

    virtual void eventHandler(sf::Event& event) = 0;
    virtual void update(sf::Time& dt) = 0;
    virtual void draw() = 0;
};


#endif //SFML_PONG_STATE_H

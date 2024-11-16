//
// Created by Chandler Desforges on 11/14/24.
//

#ifndef SFML_PONG_PONG_H
#define SFML_PONG_PONG_H


#include <SFML/Graphics.hpp>
#include "States/StateManager.h"
#include "States/MenuState.h"
#include "States/MainGameState.h"
#include "States/State.h"

class Pong
{
private:
    sf::RenderWindow m_window;
    StateManager m_stateManager;
    sf::Time m_dt;
    sf::Clock m_clock;
    sf::Time m_FIXED_TIMESTEP;
    sf::Time m_accumulator = sf::Time::Zero;

public:
    Pong();

    void initialize();

    void run();
};


#endif //SFML_PONG_PONG_H

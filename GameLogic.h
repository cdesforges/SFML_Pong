//
// Created by Chandler Desforges on 4/30/24.
//

#ifndef SFML_PONG_GAMELOGIC_H
#define SFML_PONG_GAMELOGIC_H

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Player.h"
#include "Menu.h"


class GameLogic
{

private:
    static int m_p1Score;
    static int m_p2Score;
    static bool gameStart;
    static int ball_speed;

    // define constants for debounce duration and key repeat delay
    static const sf::Time debounceDuration;
    static const sf::Time keyRepeatDelay;

    // create clock and related variables
    static sf::Clock debounceTimer;
    static bool keyWasPressed;


public:
    GameLogic();
    static void run();
    static void userControls(Ball &ball, Player &p1, Player &p2, bool &gameStart);
    static void ballEvents(Ball &ball, Player &p1, Player &p2, bool &gameStart);
    static int getp1Score();
    static int getp2Score();
    static void pauseGame();
};

#endif //SFML_PONG_GAMELOGIC_H

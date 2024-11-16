//
// Created by Chandler Desforges on 11/14/24.
//

#ifndef SFML_PONG_PLAYERCONTROLS_H
#define SFML_PONG_PLAYERCONTROLS_H

#include <SFML/Window/Keyboard.hpp>

struct PlayerControls
{
    sf::Keyboard::Key up = sf::Keyboard::Key::Unknown;
    sf::Keyboard::Key down = sf::Keyboard::Key::Unknown;

    sf::Keyboard::Key pause = sf::Keyboard::Key::Space;
    sf::Keyboard::Key quit = sf::Keyboard::Key::Escape;
};
#endif //SFML_PONG_PLAYERCONTROLS_H

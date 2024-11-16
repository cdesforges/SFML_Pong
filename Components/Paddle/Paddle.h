//
// Created by Chandler Desforges on 11/15/24.
//

#ifndef SFML_PONG_PADDLE_H
#define SFML_PONG_PADDLE_H

#include "../Platform/Platform.h"

class Paddle : public Platform
{
public:
    Paddle(const sf::Vector2f& size, const sf::Vector2f& initialPosition) : Platform(size, initialPosition){};
};


#endif //SFML_PONG_PADDLE_H

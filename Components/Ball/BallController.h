//
// Created by Chandler Desforges on 11/14/24.
//

#ifndef SFML_PONG_BALLCONTROLLER_H
#define SFML_PONG_BALLCONTROLLER_H


#include "BallModel.h"
#include "BallView.h"
#include "../../Collision/Collidable.h"
#include "../Wall/Wall.h"
#include <iostream>

class BallController
{
private:
    BallModel& m_model;
    BallView& m_view;

public:
    BallController(BallModel& model, BallView& view);

    void collisionReaction(const Collidable& other);

    void update(sf::Time& dt);
};


#endif //SFML_PONG_BALLCONTROLLER_H

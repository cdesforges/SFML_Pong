//
// Created by Chandler Desforges on 11/14/24.
//

#ifndef SFML_PONG_PLATFORMCONTROLLER_H
#define SFML_PONG_PLATFORMCONTROLLER_H


#include <SFML/Graphics.hpp>
#include "PlatformView.h"
#include "PlatformModel.h"
#include "../Player/PlayerControls.h"

class PlatformController
{
protected:
    PlatformModel& m_model;
    PlatformView& m_view;
    PlayerControls m_controls;

public:
    PlatformController(PlatformModel& model, PlatformView& view);
    void setControls(const PlayerControls& controls);

    void eventHandler(sf::Event event);
    void update(sf::Time& dt);
};


#endif //SFML_PONG_PLATFORMCONTROLLER_H

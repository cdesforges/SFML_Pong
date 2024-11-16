//
// Created by Chandler Desforges on 11/14/24.
//

#ifndef SFML_PONG_MAINGAMESTATE_H
#define SFML_PONG_MAINGAMESTATE_H


#include "State.h"
#include "../Components/Player/Player.h"
#include "../Components/Ball/Ball.h"
#include "../Collision/Collision.h"
#include "../Components/Wall/Wall.h"

class MainGameState : public State
{
private:
    Player m_p1;
    Player m_p2;
    Ball m_ball;
    Wall m_ceiling;
    Wall m_floor;
    Wall m_leftWall;
    Wall m_rightWall;
    std::vector<Component*> m_gameComponents;

public:
    explicit MainGameState(sf::RenderWindow& window, StateManager& stateManager);
    ~MainGameState() override = default;

    void initialize();

    // getters
    std::vector<Collidable*> getCollidableObjects();

    void eventHandler(sf::Event &event) override;
    void update(sf::Time &dt) override;
    void draw() override;
};


#endif //SFML_PONG_MAINGAMESTATE_H

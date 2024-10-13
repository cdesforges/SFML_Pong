//
// Created by Chandler Desforges on 4/30/24.
//

#include "GameLogic.h"

int GameLogic::m_p1Score = 0;
int GameLogic::m_p2Score = 0;
bool GameLogic::gameStart = false;
int GameLogic::ball_speed = 300;
sf::Clock GameLogic::debounceTimer;
bool GameLogic::keyWasPressed = false;  // Track whether the key was already pressed



GameLogic::GameLogic()
= default;

void GameLogic::run()
{
    // clock and dt
    sf::Time dt;
    sf::Clock clock;


    // enable anti aliasing
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    // create RenderWindow object
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Pong", sf::Style::Default);
    window.setFramerateLimit(120); // call it once, after creating the window

    // define shapes to be drawn
    Player p1(sf::Vector2f(10, 100), sf::Vector2f(100, 100), 5);
    Player p2(sf::Vector2f(10, 100), sf::Vector2f(1100, 600), 5);
    Ball ball(sf::Vector2f(10,10), ball_speed, sf::Vector2f(1,1), sf::Vector2f(595, 395));

    // define stopped screen elements
    Menu menu(window.getSize());



    // run the program as long as the window is open
    while (window.isOpen())
    {

        // delta time
        dt = clock.restart();

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;

        // while there are pending events...
        while (window.pollEvent(event))
        {
            // check the type of the event...
            switch (event.type)
            {
                // window closed
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::KeyPressed:
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                    {
                        window.close();
                    }

                    // we don't process other types of events
                default:
                    break;
            }
        }

        // Check for pause input with debouncing
        GameLogic::pauseGame();

        // clear the window with black color
        window.clear(sf::Color::Black);

        // user controls
        GameLogic::userControls(ball, p1, p2, gameStart);

        // ball events
        GameLogic::ballEvents(ball, p1, p2, gameStart);

        // update positions
        if (gameStart)
        {
            ball.update(dt);
            p1.update(dt);
            p2.update(dt);
        }
        else
        {
            menu.update();
        }

        // draw everything here...
        window.draw(ball.getShape());
        window.draw(p1.getShape());
        window.draw(p2.getShape());

        // Draw start text and score if game is stopped
        if (!gameStart)
        {
            window.draw(Menu::start);
            window.draw(Menu::p1score);
            window.draw(Menu::p2score);
        }

        // display the current frame
        window.display();
    }
}

void GameLogic::userControls(Ball &ball, Player &p1, Player &p2, bool &gameStart)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && p1.getPosition().y > 0)
    {
        p1.moveUp();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && p1.getPosition().y < 700)
    {
        p1.moveDown();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P) && p2.getPosition().y > 0)
    {
        p2.moveUp();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::L) && p2.getPosition().y < 700)
    {
        p2.moveDown();
    }
}

void GameLogic::ballEvents(Ball &ball, Player &p1, Player &p2, bool &gameStart)
{
    // player 1 collision
    if (ball.intersects(p1.getShape()))
    {
        ball.bouncePaddle();
    }
    // Check collision with Player 2
    if (ball.intersects(p2.getShape()))
    {
        ball.bouncePaddle();
    }
    // top and bottom
    else if (ball.getPosition().y > 790 || ball.getPosition().y < 0)
    {
        ball.bounceBounds();
    }
    // point scored
    else if (ball.getPosition().x < 0)
    {
        ball.resetToCenter();
        m_p2Score++;
        gameStart = false;
    }
    else if (ball.getPosition().x > 1200)
    {
        ball.resetToCenter();
        m_p1Score++;
        gameStart = false;
    }
}



int GameLogic::getp1Score()
{
    return m_p1Score;
}

int GameLogic::getp2Score()
{
    return m_p2Score;
}

void GameLogic::pauseGame()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
    {
        if (!keyWasPressed)  // Check if this is a new key press
        {
            if (debounceTimer.getElapsedTime() > sf::milliseconds(200))  // Check for debounce delay
            {
                gameStart = !gameStart;  // Toggle the game state
                debounceTimer.restart();  // Reset the timer
                keyWasPressed = true;  // Mark the key as pressed
            }
        }
    }
    else
    {
        keyWasPressed = false;  // Reset the key pressed flag when the key is released
    }
}
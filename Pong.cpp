//
// Created by Chandler Desforges on 11/14/24.
//

#include "Pong.h"


Pong::Pong()
: m_window({1280, 720}, "Pong", sf::Style::Default),
  m_stateManager(m_window)
{
    initialize();
}

void Pong::initialize()
{
    m_FIXED_TIMESTEP = sf::seconds(1.f/600.f);
    m_window.setFramerateLimit(60);
    m_stateManager.push(new MainGameState(m_window, m_stateManager));
}

void Pong::run()
{
    // main loop
    while(m_window.isOpen())
    {
        // update delta time
        m_dt = m_clock.restart();
        m_accumulator += m_dt;

        sf::Event event{};

        // check for user events
        while(m_window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                m_window.close();

            m_stateManager.getCurrent()->eventHandler(event);
        }

        // update game components
        while(m_accumulator >= m_FIXED_TIMESTEP)
        {
            m_stateManager.getCurrent()->update(m_FIXED_TIMESTEP);
            m_accumulator -= m_FIXED_TIMESTEP;
        }

//        m_stateManager.getCurrent()->update(m_dt);

        // clear the window
        m_window.clear();


        // draw everything
        m_stateManager.getCurrent()->draw();

        // display the window
        m_window.display();
    }
}

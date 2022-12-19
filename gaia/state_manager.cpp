#include "state_manager.h"

state_manager::state_manager()
{
    window* w = new window;
    m_window = std::shared_ptr<window>(w);
    gaia::cities* c = new  gaia::cities;
    m_cities = std::shared_ptr<gaia::cities>(c);
}

void state_manager::runLoop()
{
    while (true)
    {
        if (m_runPogram)
        {
            if (!runInput())
            {
                return;
            }
            
        }
        if (m_runPogram)
        {
            runSimulate();
        }
        m_runPogram = false;
        if (m_window->isKeyDown(sf::Keyboard::Enter))
        {
            m_runPogram = true;
        }
        if (m_window->isEventType(sf::Event::Closed) ||
            m_window->isKeyDown(sf::Keyboard::Escape))
        {
            return;
        }
        m_window->pollEvents();
       
    }
}

void state_manager::runSimulate()
{
    simulator simulateState(m_window, m_cities);
}

bool state_manager::runInput()
{
    input inputState(m_window, m_cities);
    return inputState.run();
}

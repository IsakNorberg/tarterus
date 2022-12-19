#include "input.h"

input::input(std::shared_ptr<window> window,
			 std::shared_ptr<gaia::cities> cities)
{
	m_window = window;
	m_cities = cities;
	m_cities->clerCitis();
	m_window->clearBuffer();
}

bool input::run()
{
	while (true)
	{

		while (m_window->pollEvents())
		{

			if (m_window->isEventType(sf::Event::MouseButtonReleased) &&
				m_window->isMuseKeyDown(sf::Mouse::Left))
			{
				sf::Vector2f musePosition = m_window->getMusePosition();
				m_cities->addCity(city((int)musePosition.x, (int)musePosition.y));
				m_window->addToRenderBuffer(draw_city(musePosition));
			}

			if (m_window->isEventType(sf::Event::Closed) ||
				m_window->isKeyDown(sf::Keyboard::Escape))
			{
				return false;
			}
			m_window->renderTheBuffer();
			if (m_window->isKeyDown(sf::Keyboard::Enter) &&
				m_cities->size() >= 3)
			{
				return true;
				
			}
		}
	}
	return false;
}


#include <iostream>
#include <SFML/Graphics.hpp>
#include "magicNumbers.h"
#include "gaia.h"
#include "window.h"
#include "draw_city.h"
#include "cities.h"
#include "path.h"

int main()
{
	window activWindow;
	gaia::cities* temp = new gaia::cities;
	std::shared_ptr<gaia::cities> cities(temp);


	while (activWindow.isOpen())
	{
		while (activWindow.pollEvents())
		{

			if (activWindow.isEventType(sf::Event::MouseButtonReleased) &&
				activWindow.isMuseKeyDown(sf::Mouse::Left))
			{
				sf::Vector2f musePosition = activWindow.getMusePosition();
				cities->addCity(city(musePosition.x, musePosition.y));
				activWindow.addToRenderBuffer(draw_city(musePosition));
			}

			if (activWindow.isEventType(sf::Event::Closed) ||
				activWindow.isKeyDown(sf::Keyboard::Escape))
			{
				return 0;
			}
			activWindow.renderTheBuffer();
			if (activWindow.isKeyDown(sf::Keyboard::Enter))
			{
				//activWindow.clearBuffer();
				gaia::gaia* myTSP = new gaia::gaia(cities);
				std::unique_ptr<gaia::gaia> TSP(myTSP);
				gaia::path bestPath = TSP->run();
				activWindow.addToRenderBuffer(convertToDrawPath(bestPath));
				//cities->clerCitis();
			}
		}
	}
	//nästa steg göre en state manager för detta med en INPUT och EN SIMULATE om är typ som gia nu 
	//göre stats istellet
	// visa denn bästa för varge genaration
	// först ta input sen enter
	// sen visa den bästa lösnigen l
	// sen tryck ender igen för att göra det igen
	//gör cities statisk

}


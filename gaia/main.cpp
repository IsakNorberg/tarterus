
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
				gaia::gaia* myTSP = new gaia::gaia(cities);
				std::unique_ptr<gaia::gaia> TSP(myTSP);
				gaia::path bestPath = TSP->run();

			}
		}
	}
	//n�sta steg g�re en state manager f�r detta med en INPUT och EN SIMULATE om �r typ som gia nu
	// Implaentara en egen render buffer som tar en window pointer och sen har line och cities 
	// och overlodes add op  buffer samt ta vort �verfl�dig line och city
	//g�re stats istellet
	// g�r path grafic <---- denna nu
	// visa denn b�sta f�r varge genaration
	// f�rst ta input sen enter
	// sen visa den b�sta l�snigen 
	// sen tryck ender igen f�r att g�ra det igen
	//g�r cities statisk

}


#include "draw_city.h"

draw_city::draw_city(sf::Vector2f position)
{	
	m_body.setPosition(position);
	m_body.setRadius(RADIUS);
	m_body.setFillColor(sf::Color::Red);
}

sf::CircleShape draw_city::getObject()
{
	return m_body;
}

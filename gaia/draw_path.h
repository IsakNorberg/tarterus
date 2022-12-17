#pragma once
#include "SFML/Graphics.hpp"

class draw_path
{
	sf::Color m_color = sf::Color::Green;
	sf::VertexArray m_path;

public:
	draw_path(sf::Vector2f pointA, sf::Vector2f pointB);
	sf::VertexArray getObject();
};
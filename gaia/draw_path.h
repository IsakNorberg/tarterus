#pragma once
#include "SFML/Graphics.hpp"
#include "path.h"

class draw_path
{
	sf::Color m_color = sf::Color::Green;
	sf::VertexArray m_path;

public:
	draw_path(sf::Vector2f pointA, sf::Vector2f pointB);
	sf::VertexArray getObject();
};
sf::Vector2f toSfVector(position p);
std::vector<draw_path> convertToDrawPath(gaia::path path);

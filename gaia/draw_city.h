#pragma once
#include <SFML/Graphics.hpp>
#include <memory>


constexpr int RADIUS = 10;

class draw_city 
{
	sf::CircleShape m_body;
public:
	draw_city(sf::Vector2f position);
	sf::CircleShape getObject();
};
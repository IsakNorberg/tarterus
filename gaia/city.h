#pragma once

#include "SFML/Graphics.hpp"
struct city
{
public:
	city();
	city(int x, int y);

	int getId();
	void setId(int id);

	int getX();
	void setX(int x);

	int getY();
	void setY(int y);
	sf::Vector2f getXY();


	void setXY(int x, int y);
private:
	int m_id;
	int m_x;
	int m_y;

	int m_score;
};
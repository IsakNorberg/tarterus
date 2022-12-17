#include "city.h"

city::city() : m_id(0), m_x(0), m_y(0), m_score(0)
{
}

city::city(int x, int y) :m_id(0), m_x(x), m_y(y), m_score(0)
{
}

int city::getId()
{
	return m_id;
}

void city::setId(int id)
{
	m_id = id;
}

int city::getX()
{
	return m_x;
}

void city::setX(int x)
{
	m_x = x;
}

int city::getY()
{
	return m_y;
}

void city::setY(int y)
{
	m_y = y;
}

sf::Vector2f city::getXY()
{
	return {m_x, m_y};
}

void city::setXY(int x, int y)
{
	m_x = x;
	m_y = y;
}

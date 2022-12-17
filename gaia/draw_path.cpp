#include "draw_path.h"

draw_path::draw_path(sf::Vector2f pointA, sf::Vector2f pointB): m_path(sf::Lines, 2)
{
	sf::Vertex a(pointA);
	a.color = m_color;
	sf::Vertex b(pointB);
	b.color = m_color;
	m_path.append(a);
	m_path.append(b);
}

sf::VertexArray draw_path::getObject()
{
	return m_path;
}

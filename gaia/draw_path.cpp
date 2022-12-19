#include "draw_path.h"

draw_path::draw_path(sf::Vector2f pointA, sf::Vector2f pointB) : m_path(sf::Lines, 2)
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

std::vector<draw_path> convertToDrawPath(gaia::path path)
{
	std::vector<draw_path> outVector = {};
	sf::Vector2f a = toSfVector(path.getPosition(path.firstCity()));
	sf::Vector2f b = toSfVector(path.getPosition(path.lastCity()));

	outVector.push_back(draw_path(a, b));
	for (int i = 0; i < path.size() - 1; i++)
	{
		a = toSfVector(path.getPosition(path.cityAtIndex(i)));
		b = toSfVector(path.getPosition(path.cityAtIndex(i+1)));
		
		outVector.push_back(draw_path(a, b));
	}
	return outVector;
}

sf::Vector2f toSfVector(position p)
{
	return {p.x,p.y};
}

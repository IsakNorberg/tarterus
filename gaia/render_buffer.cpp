#include "render_buffer.h"

void render_buffer::addToBuffer(draw_city city)
{	
	m_cities.push_back(city);
}

void render_buffer::addToBuffer(std::vector<draw_path> paths)
{	
	m_paths = paths;
}

void render_buffer::clear()
{
	m_cities.clear();
	m_paths.clear();
}

void render_buffer::clerPaths()
{	
	m_paths.clear();
}

void render_buffer::renderBuffer(sf::RenderWindow& window)
{
	std::for_each(m_cities.begin(), m_cities.end(), [&](draw_city object)
	{
		window.draw(object.getObject());

	});
	std::for_each(m_paths.begin(), m_paths.end(), [&](draw_path object)
	{
		window.draw(object.getObject());

	});
}

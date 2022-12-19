#include "render_buffer.h"

void render_buffer::addToBuffer(draw_city city)
{	
	m_cities.push_back(city);
}

void render_buffer::addToBuffer(std::vector<draw_path> paths)
{	
	m_paths = paths;
}

bool render_buffer::pathEmpty()
{
	return m_paths.empty();
}

void render_buffer::clear()
{
	if (!m_cities.empty())
	{
		m_cities.clear();
	}
	clerPaths();
}
	

void render_buffer::clerPaths()
{	
	if (!m_paths.empty())
	{
		m_paths.clear();
	}
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

#pragma once
#include <vector>

#include "SFML/Graphics.hpp"
#include "draw_city.h"
#include "draw_path.h"
class render_buffer
{
	std::vector<draw_city> m_cities;
	std::vector<draw_path> m_paths;

public:
	void addToBuffer(draw_city city);
	void addToBuffer(std::vector<draw_path> paths);
	bool pathEmpty();
	void clear();
	void clerPaths();
	void renderBuffer(sf::RenderWindow& window);
};
#pragma once
#include <memory>
#include "window.h"
#include "cities.h"
class input
{
	std::shared_ptr<window> m_window;
	std::shared_ptr<gaia::cities> m_cities;
	
public:
	input(std::shared_ptr<window> window,
		  std::shared_ptr<gaia::cities> cities);
	bool run();
};
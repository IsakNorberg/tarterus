#pragma once
#include <execution>
#include <memory>
#include "cities.h"
#include "paths.h"
#include "window.h"
#include "draw_path.h"


class simulator
{
	std::shared_ptr<window> m_window;
	std::shared_ptr<gaia::cities> m_cities;
	int m_runTimes;
	gaia::paths m_paths;
	float firstBest;
	void printGen();
	void run();
public:
	simulator(std::shared_ptr<window> window, std::shared_ptr<gaia::cities> cities);

};

gaia::paths sort(gaia::paths p);


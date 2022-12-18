#pragma once
#include <execution>
#include <memory>
#include "cities.h"
#include "paths.h"


class simulator
{
	std::shared_ptr<gaia::cities> m_cities;
	int m_runTimes;
	gaia::paths m_paths;
	float firstBest;
	void printGen();
public:
	simulator(std::shared_ptr<gaia::cities> cities);
	gaia::path run();

};

gaia::paths sort(gaia::paths p);


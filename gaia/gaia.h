#pragma once
#include <execution>
#include <memory>
#include "cities.h"
#include "paths.h"


namespace gaia
{
	class gaia
	{
		std::shared_ptr<cities> m_cities;
		int m_runTimes;
		paths m_paths;
		float firstBest;
		void printGen();
	public:
		gaia(std::shared_ptr<cities> cities);
		path run();

	};

	paths sort(paths p);
}


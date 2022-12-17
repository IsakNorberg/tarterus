#pragma once
#include <execution>
#include <memory>
#include "cities.h"
#include "paths.h"
#include "draw_path.h"

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
std::vector<draw_path> convertToDrawPath(gaia::path path);

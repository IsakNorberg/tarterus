#pragma once

#include <vector>
#include <execution>
#include "path.h"
#include "cities.h"
#include "seedRand.h"


namespace gaia
{
	constexpr int RATIO_FOR_SURVIVOR = 2; // Do not change

	class paths
	{
		std::vector<path> m_paths;
		std::shared_ptr<cities> m_cities;
		path repair(path mypath, int start, int stop);
	public:

		paths(std::shared_ptr<cities> cities);
		std::vector<path> getVectorOfPaths();
		void setVectorOfPaths(std::vector<path> paths);
		
		void printBest() const noexcept;
		void mateBest();
		void addRandom();
		void printBestArry();
		float getBestLength() const noexcept;
	};
	paths calcLengh(paths myPaths);
}
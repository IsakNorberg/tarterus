#pragma once
#include "magicNumbers.h"
#include "seedRand.h"

#include "cities.h"
#include "city.h"
#include <vector>
#include <algorithm>
#include <ranges>
#include <memory>

namespace gaia
{
	class path
	{
		std::shared_ptr<cities> m_cities;
		std::vector<int> getRandomPath();
		//cities m_cities;
	public:
		path(const path& rhs) = default;
		path& operator=(const path& rhs) = default;
		path(path&& rhs) = default;
		path& operator=(path&& rhs) = default;

		path(std::shared_ptr<cities> cities);
		std::vector<int> m_path = {};
		float m_length;
		void calcLength();
	};
}
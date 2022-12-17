#pragma once
#include "magicNumbers.h"
#include "seedRand.h"

#include "SFML/Graphics.hpp"
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
	public:

		path(std::shared_ptr<cities> cities);
		std::vector<int> m_path = {};
		float m_length;
		void calcLength();
		sf::Vector2f getPosition(int cityIndex);
		int lastCity();
		int firstCity();
	};
}
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
		std::vector<int> m_path = {};
		float m_length;
	public:
		path(std::shared_ptr<cities> cities);
		
		void calcLength();
		position getPosition(int cityIndex);
		int lastCity();
		int firstCity();
		int size();
		int cityAtIndex(int index);
		void setCityAtindex(int index, int cityNumber);
		float getLength();
		std::vector<int> getPath();
	};

}
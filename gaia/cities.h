#pragma once

#include <stdexcept>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include "city.h"
namespace gaia
{
	class cities
	{
		std::vector<city> m_cities = {};
	public:
		cities();
		void addCity(city city);
		void clerCitis();
		city getCity(int cityIndex);
		int size();
		float getDistanceBetweenCites(int cityA, int cityB) noexcept;
	};
}

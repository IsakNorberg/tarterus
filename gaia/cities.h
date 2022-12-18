#pragma once

#include <stdexcept>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include "magicNumbers.h"
#include "city.h"
namespace gaia
{
	class cities
	{
		static std::vector<city> m_cities;
	public:
		cities();
		static void addCity(city city);
		static void clerCitis();
		static city getCity(int cityIndex);
		static int size();
		float getDistanceBetweenCites(int cityA, int cityB) noexcept;
	};
}

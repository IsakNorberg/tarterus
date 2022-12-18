#include "cities.h"

namespace gaia
{
	cities::cities()
	{
		
	}

	void cities::addCity(city city)
	{
		city.setId(m_lastId++);
		m_cities.push_back(city);
	}

	void cities::clerCitis()
	{
		if (!m_cities.empty())
		{
			m_cities.clear();
		}
		m_lastId = 0;
	}

	int cities::size()
	{
		return m_cities.size();
	}

	city cities::getCity(int cityIndex)
	{
		return m_cities[cityIndex];
	}

	float cities::getDistanceBetweenCites(int cityA, int cityB) noexcept
	{
		float x = std::abs(m_cities[cityA].getX() - m_cities[cityB].getX());
		float y = std::abs(m_cities[cityA].getY() - m_cities[cityB].getY());
		x = std::pow(x, 2);
		y = std::pow(y, 2);
		float returnValue = std::sqrt(x + y);

		return returnValue;
	}
}
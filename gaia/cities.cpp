#include "cities.h"

namespace gaia
{
	cities::cities()
	{
		/*m_cities.resize(size());
		
		std::for_each(m_cities.begin(), m_cities.end(), [&](city& c)
		{
			c.setId(m_lastId++);
		});

		for (city& city : m_cities)
		{
			switch (city.getId())
			{
				case 0: city.setXY(5, 8); break;
				case 1: city.setXY(-7, 2); break;
				case 2: city.setXY(14, 30); break;
				case 3: city.setXY(4, 6); break;
				case 4: city.setXY(28, -9); break;
				case 5: city.setXY(-1, -6); break;
				case 6: city.setXY(0, 4); break;
				case 7: city.setXY(9, 9); break;
				case 8: city.setXY(5, 30); break;
				case 9: city.setXY(-20, 8); break;
				case 10: city.setXY(16, 9); break;
				case 11: city.setXY(14, 15); break;
				case 12: city.setXY(5, -5); break;
				case 13: city.setXY(4, 2); break;
				case 14: city.setXY(9, 12); break;
				case 15: city.setXY(3, -7); break;
				case 16: city.setXY(-2, 6); break;
				case 17: city.setXY(-8, 33); break;
				case 18: city.setXY(1, 6); break;
				case 19: city.setXY(0, 4); break;

				default:city.setXY(0, 0); break;
			}
		}*/
	}

	void cities::addCity(city city)
	{
		city.setId(m_lastId++);
		m_cities.push_back(city);
	}

	void cities::clerCitis()
	{
		m_cities.clear();
		m_lastId = 0;
	}

	int cities::size()
	{
		return m_cities.size();
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
#include "path.h"
namespace gaia
{
	std::vector<int> path::getRandomPath()
	{
		std::vector<int> outVector;
		std::vector<int> genaratedNumbers;
		genaratedNumbers.resize(m_cities->size());
		int genNum = 0;
		bool same = false;
		int randNum = 0;
		for (int i = 0; i < m_cities->size(); i++)
		{
			do
			{
				randNum = getRandomNumber(m_cities->size());
				same = false;
				for (int j = 0; j < genNum; j++)
				{
					if (randNum == genaratedNumbers[j])
					{
						same = true;
						break;
					}
				}
			} while (same);
			genaratedNumbers[genNum++] = randNum;
			outVector.push_back(randNum);
		}
	
		return outVector;
	}

	path::path(std::shared_ptr<cities> cities) : m_length(0.0f)
	{
		m_cities = cities;
		m_path = getRandomPath();
	}

	void path::calcLength()
	{
		m_length = 0;
		m_length = m_cities->getDistanceBetweenCites(m_path[m_path.size()-1], m_path[0]);

		for (int i = 0; i < m_cities->size() - 1; i++)
		{
			m_length = m_length + m_cities->getDistanceBetweenCites(m_path[i], m_path[i + 1]);
		}

	}
	sf::Vector2f path::getPosition(int cityIndex)
	{
		return m_cities->getCity(cityIndex).getXY();
	}
	int path::lastCity()
	{
		return m_path[m_path.size() -1];
	}
	int path::firstCity()
	{
		return m_path[0];
	}
}

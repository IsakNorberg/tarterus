#include "seedRand.h"
namespace gaia
{
	int getRandomNumber(int toNmber)
	{
		static time_t* seed = 0;
		static int m_seed = (int)time(seed);
		srand(m_seed++);
		
		return rand() % toNmber;
	}
}
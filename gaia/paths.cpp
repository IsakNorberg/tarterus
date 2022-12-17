#include "paths.h"

namespace gaia
{
    path paths::repair(path mypath, int start, int stop)
    {
        std::vector<int> duplicatesList;
        duplicatesList.resize(m_cities->size());
        int numberOfDuplicatesN = 0;
        path tempP(m_cities);
        tempP = mypath;
        int placeHolder = -1;
        for (int j = 0; j < m_cities->size(); j++)
        {
            if (j == start)
            {
                j = stop;

            }
            for (int i = start; i < stop; i++)
            {
                if (mypath.m_path[i] == mypath.m_path[j])
                {
                    mypath.m_path[j] = placeHolder;
                    duplicatesList[numberOfDuplicatesN] = j;
                    numberOfDuplicatesN++;
                }
            }
        }

        std::vector<bool> numbersIncluded;
        numbersIncluded.resize(m_cities->size());

        for (int i = 0; i < m_cities->size(); i++)
        {
            if (mypath.m_path[i] != placeHolder)
            {
                int temp = mypath.m_path[i];
                numbersIncluded[temp] = true;
            }
        }

        std::vector<int> missingNumbersList;
        missingNumbersList.resize(m_cities->size());
        int numberOfMissingNumbersN = 0;
        for (int i = 0; i < m_cities->size(); i++)
        {
            if (!numbersIncluded[i])
            {
                missingNumbersList[numberOfMissingNumbersN] = i;
                numberOfMissingNumbersN++;
            }
        }

        for (int i = 0; i < numberOfMissingNumbersN; i++)
        {
            mypath.m_path[duplicatesList[i]] = missingNumbersList[i];
        }
        return mypath;
    }

    paths::paths(std::shared_ptr<cities> cities)
    {
        m_cities = cities;
        while (m_paths.size() < AMUNT_OF_PATHS)
        {
            path newPath(cities);
            m_paths.push_back(newPath);
        }
    }

    std::vector<path> paths::getVectorOfPaths()
    {
        return m_paths;
    }

    void paths::setVectorOfPaths(std::vector<path> paths)
    {
        m_paths = paths;
    }

    paths calcLengh(paths myPaths)
    {
        std::vector<path> vectorOfPaths = myPaths.getVectorOfPaths();
        std::for_each(std::execution::par_unseq, vectorOfPaths.begin(), vectorOfPaths.end(), [](path& p)
        {
            p.calcLength();
        });
   
        myPaths.setVectorOfPaths(vectorOfPaths);
        return myPaths;
    }

    void paths::printBest() const noexcept
    {
        std::printf("The best and worst result for this generation is: ");
        std::printf("%f, ", m_paths[0].m_length);
        std::printf("%f ", m_paths[AMUNT_OF_PATHS - 1].m_length);
    }

    void paths::mateBest()
    {
        int start = 0;
        int stop = 0;
        path newOne(m_cities);
        path newTwo(m_cities);
        int offset = AMUNT_OF_PATHS / RATIO_FOR_SURVIVOR;
        while (start < MIN_SAME_GEN || start + MIN_SWOP_SIZE >= m_cities->size())
        {
            start = getRandomNumber(m_cities->size());
        }
        while (stop < start + MIN_SWOP_SIZE)
        {
            stop = getRandomNumber(m_cities->size());
        }

        for (int i = 0; i < AMUNT_OF_PATHS / RATIO_FOR_SURVIVOR; i = i + 2)
        {
            newOne = m_paths[i];
            newTwo = m_paths[i + 1];
            for (int j = start; j < stop; j++)
            {
                newOne.m_path[j] = m_paths[i + 1].m_path[j];
                newTwo.m_path[j] = m_paths[i].m_path[j];
            }
            m_paths[i + offset] = newOne;
            m_paths[i + 1 + offset] = newTwo;

            m_paths[i + offset] = repair(m_paths[i + offset], start, stop);
            m_paths[i + 1 + offset] = repair(m_paths[i + 1 + offset], start, stop);
        }

    }

    void paths::addRandom()
    {
        for (int i = 0; i < AMUNT_OF_NEW_RANDOM_ADDED; i++)
        {
            m_paths[AMUNT_OF_PATHS - 1 - i] = path(m_cities);
        }
 
    }

    void paths::printBestArry()
    {
        printf("The best path ");
        for (int myInt : m_paths[0].m_path)
        {
            printf("%d ", myInt);
        }
    }

    float paths::getBestLength() const noexcept
    {
        return m_paths[0].m_length;
    }

}
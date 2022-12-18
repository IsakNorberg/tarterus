#include "gaia.h"
#include <cstdio>

 
simulator::simulator(std::shared_ptr<gaia::cities> cities) : m_runTimes(0), firstBest(0), m_paths(cities)
{
    m_cities = cities;
}

gaia::path simulator::run()
{
    
    while (m_runTimes < AMUNT_OF_GENERATIONS)
    {
        m_paths = calcLengh(m_paths);
        m_paths = sort(m_paths);
        m_paths.printBest();
        printGen();
        m_paths.mateBest();
        m_paths.addRandom();
        m_runTimes++;
    }
    m_paths.printBestArry();
    return m_paths.getFirst();
}

void simulator::printGen()
{
    if (m_runTimes == 0)
    {
        firstBest = m_paths.getBestLength();
    }

    float ofBest = 0.0f;
    printf("gen: ");
    printf("%d ", m_runTimes + 1);
    ofBest = m_paths.getBestLength() / firstBest;
    printf("%.2f \n", ofBest);
}
gaia::paths sort(gaia::paths p)
{
    std::vector<gaia::path> newPathsVector = p.getVectorOfPaths();
    std::sort(std::execution::par_unseq, newPathsVector.begin(), newPathsVector.end(), [](gaia::path lhs, gaia::path rhs)
    {
        return lhs.getLength() < rhs.getLength();
    });
    gaia::paths newPaths = p;
    newPaths.setVectorOfPaths(newPathsVector);
    return newPaths;
}



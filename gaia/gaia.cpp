#include "gaia.h"
#include <cstdio>

namespace gaia
{ 
gaia::gaia(std::shared_ptr<cities> cities) : m_runTimes(0), firstBest(0), m_paths(cities)
{
    m_cities = cities;
}

path gaia::run()
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

void gaia::printGen()
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
paths sort(paths p)
{
    std::vector<path> newPathsVector = p.getVectorOfPaths();
    std::sort(std::execution::par_unseq, newPathsVector.begin(), newPathsVector.end(), [](path lhs, path rhs)
    {
        return lhs.m_length < rhs.m_length;
    });
    paths newPaths = p;
    newPaths.setVectorOfPaths(newPathsVector);
    return newPaths;
}
}

std::vector<draw_path> convertToDrawPath(gaia::path path)
{
    
    draw_path first(path.getPosition(path.firstCity()), path.getPosition(path.lastCity()));
    return std::vector<draw_path>();
}

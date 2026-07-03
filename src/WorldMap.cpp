#include "WorldMap.h"

WorldMap::WorldMap(int mapWidth, int mapHeight, int mapTileSize)
    : width(mapWidth),
    height(mapHeight),
    tileSize(mapTileSize),
    level(generateLevel())
{}

std::vector<int> WorldMap::generateLevel(){
    const std::vector<int> level =
    {
        0, 0, 0, 0, 75, 75, 75, 75, 75, 75, 75, 75, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 75, 75, 75, 75, 75, 75, 75, 75, 0, 0, 0,
        0, 0, 0, 0, 0, 75, 75, 75, 75, 75, 75, 75, 75, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 75, 75, 75, 75, 75, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    };

    return level;
}

const std::vector<int>& WorldMap::getLevel() const // eventually want to randomly generate map but for now manually set it
{
    return level;
}

bool WorldMap::isWalkable(int tileX, int tileY) const
{
    if (tileX < 0 || tileY < 0 || tileX >= width || tileY >= height)
        return false;

    int index = tileY * width + tileX;

    return level[index] != 75;
}

int WorldMap::getTile(int tileX, int tileY)
{
    if (tileX < 0 || tileY < 0 || tileX >= width || tileY >= height)
        return -1;

    return level[(tileY * width)+tileX];
}
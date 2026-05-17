#pragma once

#include <vector>

class WorldMap {
    public:
        WorldMap(int mapWidth, int mapHeight, int mapTileSize, const std::vector<int> mapLevel);

        int width;
        int height;
        int tileSize;
        const std::vector<int> level;
        
        bool isWalkable(tileX, tileY);
        int getTile();  
}


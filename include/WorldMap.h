#pragma once

#include <vector>

class WorldMap {
    public:
        WorldMap(int mapWidth, int mapHeight, int mapTileSize);

        int width;
        int height;
        int tileSize;
        const std::vector<int> level;
        
        bool isWalkable(int tileX, int tileY);
        int getTile(int tileX, int tileY);  
        std::vector<int> generateLevel();
        const std::vector<int>& getLevel() const;
};


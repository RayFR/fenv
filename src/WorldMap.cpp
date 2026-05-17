#include "WorldMap.h"

bool WorldMap::isWalkable(int tileX, int tileY) 
{
    bool walkable;
    int tile = (tileY * width)+tileX; 
    if(tile == 75) {walkable = false;}
    else {walkable;}
    return walkable;
}
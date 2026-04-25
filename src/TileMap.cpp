#include "TileMap.h"
#include <iostream>

bool TileMap::load(const std::string& tilesetPath,
                   sf::Vector2u tileSize,
                   const std::vector<int>& tiles,
                   unsigned int width,
                   unsigned int height)
{
    // checks valid path
    if (!m_tileset.loadFromFile(tilesetPath))
    {
        // std::cerr is an error output
        std::cerr << "Failed to load tileset: " << tilesetPath << '\n';
        return false;
    }

    // ensures given tile vector is correct size defined in w/h
    if (tiles.size() != width * height)
    {
        std::cerr << "Tile data size does not match width * height\n";
        return false;
    }

    // prepares the vertex array (vertex array is a list of vertices)
    m_vertices.clear(); // removes old geometry if map was prev loaded
    m_vertices.setPrimitiveType(sf::PrimitiveType::Triangles); 
    m_vertices.resize(width * height * 6); // because 1 tile(square) is 6 vertices (2 triangles) you * 6

    const unsigned int tilesPerRow = m_tileset.getSize().x / tileSize.x; // how many tile images fit across one row of tileset

    // loop through every tile
    for (unsigned int x = 0; x < width; ++x)
    {
        for (unsigned int y = 0; y < height; ++y)
        {
            const int tileNumber = tiles[x + y * width]; // gets int from map vector 

            const unsigned int tu = tileNumber % tilesPerRow; // column
            const unsigned int tv = tileNumber / tilesPerRow; // row

            // screen position
            const float left   = static_cast<float>(x * tileSize.x);
            const float top    = static_cast<float>(y * tileSize.y);
            const float right  = static_cast<float>((x + 1) * tileSize.x);
            const float bottom = static_cast<float>((y + 1) * tileSize.y);

            // texture position
            const float texLeft   = static_cast<float>(tu * tileSize.x);
            const float texTop    = static_cast<float>(tv * tileSize.y);
            const float texRight  = static_cast<float>((tu + 1) * tileSize.x);
            const float texBottom = static_cast<float>((tv + 1) * tileSize.y);
            
            // starting location in array for the tile's 6 vertices
            // pointer for triangle data - Each tile has 2 triangles, which means there are 6 vertices per tile.
            sf::Vertex* triangle = &m_vertices[(x + y * width) * 6];

            // Triangle 1
            triangle[0].position = sf::Vector2f(left, top);
            triangle[1].position = sf::Vector2f(right, top);
            triangle[2].position = sf::Vector2f(right, bottom);

            triangle[0].texCoords = sf::Vector2f(texLeft, texTop);
            triangle[1].texCoords = sf::Vector2f(texRight, texTop);
            triangle[2].texCoords = sf::Vector2f(texRight, texBottom);

            // Triangle 2
            triangle[3].position = sf::Vector2f(left, top);
            triangle[4].position = sf::Vector2f(right, bottom);
            triangle[5].position = sf::Vector2f(left, bottom);

            triangle[3].texCoords = sf::Vector2f(texLeft, texTop);
            triangle[4].texCoords = sf::Vector2f(texRight, texBottom);
            triangle[5].texCoords = sf::Vector2f(texLeft, texBottom);
        }
    }

    return true;
}

void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // apply both transform and textures now to the tilemap - then draw everything to screen with the vertices and states 
    states.transform *= getTransform();
    states.texture = &m_tileset;
    target.draw(m_vertices, states);
}
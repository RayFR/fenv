#pragma once // prevents the file from being included multiple times

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

// drawable allows draw() calls + transformable gives the TileMap pos, rot, scale
class TileMap : public sf::Drawable, public sf::Transformable
{
public: // other files have access to these 
    bool load(const std::string& tilesetPath,
              sf::Vector2u tileSize,
              const std::vector<int>& tiles,
              unsigned int width,
              unsigned int height);

private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
};


#include <SFML/Graphics.hpp>
#include <vector>
#include "TileMap.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode({512, 256}), "TileMap");

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

    TileMap map;
    if (!map.load("../assets/sprites/tileset.png", sf::Vector2u(32, 32), level, 16, 8))
        return 1;

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        window.draw(map);
        window.display();
    }

    return 0;
}
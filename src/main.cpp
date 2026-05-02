#include <SFML/Graphics.hpp>
#include <vector>
#include "TileMap.h"
#include "Organism.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode({512, 256}), "Ecosystem");
    
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

    Organism organism({100.f, 100.f}, 0);

    sf::Clock clock;

    while (window.isOpen())
    {
        float dt = clock.restart().asSeconds(); // returns time since last call - resets clock back to 0

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        
        organism.update(dt);

        window.clear();
        window.draw(map);
        window.display();
    }

    return 0;
}
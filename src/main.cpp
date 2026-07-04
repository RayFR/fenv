#include <SFML/Graphics.hpp>
#include <vector>
#include "TileMap.h"
#include "Organism.h"
#include "Animal.h"
#include "Chicken.h"
#include "Fox.h"
#include "WorldMap.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode({512, 256}), "Ecosystem");
    int levelWidth = 16;
    int levelHeight = 8; 
    int tileSize = 32;
    
    TileMap tileMap;
    WorldMap level(levelWidth, levelHeight, tileSize);
    
    if (!tileMap.load("../assets/sprites/tileset.png", sf::Vector2u(tileSize, tileSize), level.getLevel(), levelWidth, levelHeight))
        return 1;

    sf::Texture chickenTexture;
    sf::Texture foxTexture;
    foxTexture.loadFromFile("../assets/sprites/fox.PNG");
    if (!chickenTexture.loadFromFile("../assets/sprites/chicken.PNG")) {
        return 1;
    } else {
        chickenTexture.loadFromFile("../assets/sprites/chicken.PNG");
    };

    Chicken chicken({100.f, 100.f}, 1, 2, 2.f, Animal::Diet::Herbivore, chickenTexture);
    Fox fox();

    sf::Clock clock;

    while (window.isOpen())
    {
        float dt = clock.restart().asSeconds(); // returns time since last call - resets clock back to 0

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        
        chicken.update(dt, level, fox);

        window.clear();
        window.draw(tileMap);
        window.draw(chicken.getSprite());
        window.display();
    }

    return 0;
}
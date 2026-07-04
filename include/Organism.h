#pragma once // prevents multiple includes

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <cmath>
#include "WorldMap.h"


class Organism {
    public:
        Organism(sf::Vector2f startPos, int startTrophicLevel);

        virtual ~Organism() = default; // destructor runs when object is destroyed

        virtual void update(float dt, const WorldMap& world);

        sf::Vector2i getPosition(int tileSize) const;
        float distanceTo(const Organism& other) const;

    protected: // only children can modify
        sf::Vector2f position;
        float health;
        bool alive;
        int trophicLevel;
        float hunger; 
        float thirst;
        
};
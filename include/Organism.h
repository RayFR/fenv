#pragma once // prevents multiple includes

#include <SFML/System/Vector2.hpp>

class Organism {
    protected: // only children can modify
        sf::Vector2f position;
        float health;
        bool alive;

        float hunger; 
        float thirst;

        
};
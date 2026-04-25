#pragma once // prevents multiple includes

#include <SFML/System/Vector2.hpp>


class Organism {
    public:
        Organism(sf::Vector2f startPos);

        virtual ~Organism() = default; // destructor runs when object is destroyed

        virtual void update(float dt);

    protected: // only children can modify
        sf::Vector2f position;
        float health;
        bool alive;

        float hunger; 
        float thirst;

};
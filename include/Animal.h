#pragma once

#include "Organism.h"
#include <SFML/System/Vector2.hpp>

class Animal : public Organism {
    public:
        Animal(sf::Vector2f startPos, int startTrophicLevel);

        void update(float dt) override; // overrides the parent procedure

    protected:
        float speed;
        float vision;
        float attackDmg;
        bool lookingForMate; 

    
};
#pragma once

#include "Organism.h"
#include <SFML/System/Vector2.hpp>

class Animal : public Organism {
    public:
        enum class Diet
        {
            Carnivore, Herbivore, Omnivore
        };

        Animal(sf::Vector2f startPos, int startTrophicLevel, int startSpeed, float startAttackDmg, Diet dietType);

        void update(float dt) override; // overrides the parent procedure
        
        void move(float dt);
        void search();
        void flee();
        void attack(float dt);
        Animal reproduce();

    protected:
        int speed;
        int vision;
        float attackDmg;
        bool lookingForMate; 
        Diet diet;
};
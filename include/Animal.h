#pragma once

#include "Organism.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Animal : public Organism {
    public:
        enum class Diet
        {
            Carnivore, Herbivore, Omnivore
        };

        enum class State
        {
            Idle,
            Wandering,
            Searching,
            Chasing,
            Fleeing,
            Eating
        };

        Animal(sf::Vector2f startPos, int startTrophicLevel, int startSpeed, float startAttackDmg, Diet dietType, sf::Texture& fileTexture);

        void update(float dt) override; // overrides the parent procedure
        
        void move(float dt);
        void wander();
        void search();
        void fleeFrom();
        void attack(float dt);
        // Animal reproduce();
        const sf::Sprite& getSprite() const;

    protected:
        int speed;
        int vision;
        float attackDmg;
        bool lookingForMate; 
        Diet diet;
        sf::Texture texture;
        sf::Sprite sprite;
        State state;
        sf::Vector2i targetTile;
};
#pragma once // prevents multiple includes

#include "Animal.h"

class Chicken : public Animal {
    public:
        
        Chicken(sf::Texture& texture);
        void update(float dt, const WorldMap& world, const Organism& predator) override;
};
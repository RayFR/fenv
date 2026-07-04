#pragma once

#include "Animal.h"

class Fox : public Animal {
    public:
        
        Fox(sf::Texture texture);
        void update(float dt, const WorldMap& world, const Organism& prey) override;
};
#include "Organism.h"

Organism::Organism(sf::Vector2f startPosition) // constructor
{
    position = startPosition;
    health = 100.f;
    alive = true;
    hunger = 0.f;
    thirst = 0.f;
}

// dt = delta time -> how much time has passed since the last frame/update 
void Organism::update(float dt) {
    hunger += 5.f * dt;
    thirst += 8.f * dt;

    if (hunger >= 100.f || thirst >= 100.f)
    {
        health -= 10.f * dt;
    }

    if (health <= 0.f) {
        alive = false; 
    }
}
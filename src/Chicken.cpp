#include "Chicken.h"

Chicken::Chicken()
    : Animal({100.f, 100.f},
        1,
        2,
        1.f,
        Diet::Herbivore,
        texture)
{}

void Chicken::update(float dt, const WorldMap& world, const Organism& predator)
{
    Organism::update(dt, world);

    float distToFox = distanceTo(predator.getPosition());

    if (distToFox < vision)
    {
        fleeFrom(predator.getPosition(), dt, world);
    }
    else
    {
        wander(dt, world);
    }

    sprite.setPosition(position);
}
#include "Chicken.h"

Chicken::Chicken()
    : Animal({100.f, 100.f}.
        1,
        2,
        1.f,
        Diet::Herbivore)
{}

void Chicken::update(float dt, const WorldMap& world, const Fox& fox)
{
    Organism::update(dt);

    float distToFox = distanceTo(position, fox.getPosition());

    if (distToFox < vision)
    {
        fleeFrom(fox.getPosition(), dt, world);
    }
    else
    {
        wander(dt, world);
    }

    sprite.setPosition(position);
}
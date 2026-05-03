#include "Animal.h"

Animal::Animal(sf::Vector2f startPosition, int startTrophicLevel, int startSpeed, float startAttackDmg, Diet dietType)
    : Organism(startPosition, startTrophicLevel)
{
    speed = startSpeed;
    diet = dietType;
    attackDmg = startAttackDmg;
    vision = 2;
    lookingForMate = false;
}
#include "Animal.h"

Animal::Animal(sf::Vector2f startPosition, int startTrophicLevel, int startSpeed, float startAttackDmg, Diet dietType, sf::Texture fileTexture)
    : Organism(startPosition, startTrophicLevel)
{
    speed = startSpeed;
    diet = dietType;
    attackDmg = startAttackDmg;
    vision = 2;
    lookingForMate = false;
    texture = fileTexture;
};

void Animal::update(float dt)
{
    Organism::update(dt);
    move(dt);
}

void Animal::move(float dt)
{
    position.x += speed * dt;
}

void Animal::search()
{

}

void Animal::flee()
{

}

void Animal::attack(float dt)
{

}

Animal Animal::reproduce()
{

}

const sf::Sprite& Animal::getSprite() const{
    return sprite;
}



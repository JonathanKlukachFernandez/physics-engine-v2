#include "Entity.h"

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*visualPtr, this->getTransform());
}

void Entity::Update()
{
    // physics
    if (getPosition().x < 0 || getPosition().x > 1280 - 100) Velocity.x *= -1;
    if (getPosition().y < 0 || getPosition().y > 720 - 100) Velocity.y *= -1;

    setPosition(getPosition() + Velocity); 
}


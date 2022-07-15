#pragma once
#include <iostream>
#include "Vector.h"
#include <SFML/Graphics.hpp>

class Entity : public sf::Drawable, public sf::Transformable
{

public:
	Entity()=default;

	void Update();
	std::unique_ptr<sf::Drawable> visualPtr;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	sf::Vector2f Velocity;

};
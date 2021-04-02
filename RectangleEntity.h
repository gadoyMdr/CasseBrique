#pragma once
#include "Entity.h"
class RectangleEntity : public Entity
{
public :
	RectangleEntity();
	RectangleEntity(sf::Color color, sf::Vector2f size, sf::Vector2f pos);
	~RectangleEntity();

	void ReactToCollision(sf::Vector2f from, sf::Vector2f offset) override;
};


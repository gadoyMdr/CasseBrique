#pragma once
#include "Entity.h"
class RectangleEntity : public Entity
{
public :
	RectangleEntity(sf::Color color, sf::Vector2f size, sf::Vector2f pos);
	~RectangleEntity();

	void ReactToCollision(CollisionFrom from, sf::Vector2f offset) override;
};


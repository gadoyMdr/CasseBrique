#pragma once
#include "Entity.h"
class RoundEntity : public Entity
{
public :
	RoundEntity(sf::Color color, float size, sf::Vector2f pos);
	~RoundEntity();

	virtual void ReactToCollision(CollisionFrom from, sf::Vector2f offset) override;
};

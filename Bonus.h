#pragma once
#include <SFML/Graphics.hpp>
#include "RoundEntity.h"

class Bonus : public RoundEntity
{
public :
	Bonus(sf::Color color, sf::Vector2f pos);
	~Bonus();

	virtual void BeginBonus() = 0;
	virtual void EndBonus() = 0;

	void ReactToCollision(sf::Vector2f from, sf::Vector2f offset) override;
};


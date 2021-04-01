#pragma once
#include "Bonus.h"

class MultipleBonus : Bonus
{
public:
	MultipleBonus(sf::Vector2f pos);
	~MultipleBonus();

	void BeginBonus() override;
	void EndBonus() override;

	void OnHit(Entity& other) override;
};


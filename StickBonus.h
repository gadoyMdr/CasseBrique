#pragma once
#include "Bonus.h"
#include "Player.h"

class StickBonus : public Bonus
{

public :
	StickBonus(sf::Vector2f pos);
	~StickBonus();

	void BeginBonus() override;
	void EndBonus() override;

	void OnHit(Entity& other) override;
};


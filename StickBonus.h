#pragma once
#include "Bonus.h"
class StickBonus : public Bonus
{
public :
	StickBonus(sf::Vector2f pos);
	~StickBonus();

	void BeginBonus();
	void EndBonus();

	void Update() override;
	void OnHit(Entity& other) override;
};


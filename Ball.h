#pragma once
#include "RoundEntity.h"

class Ball : public RoundEntity
{
private:
	sf::Vector2f offset;
	sf::Vector2f posWithoutOffset;

public :
	Ball();
	Ball(sf::Vector2f pos);
	Ball(sf::Vector2f pos, float size);

	~Ball();

	virtual void ReactToCollision(sf::Vector2f from, sf::Vector2f offset) override;

	void OnTriggerChildrenUpdate() override;
	void OnMadeChildOf(GameObject* other) override;
	void Move() override;
};


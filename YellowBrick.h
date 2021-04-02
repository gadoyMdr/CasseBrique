#pragma once

#include "Brick.h"

class YellowBrick : public Brick
{
public : 
	YellowBrick();
	YellowBrick(sf::Vector2f pos);
	YellowBrick(sf::Vector2f pos, sf::Vector2f size);
	void Damage() override;
};


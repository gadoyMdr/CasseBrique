#pragma once

#include "RectangleEntity.h"
#include <SFML/Graphics.hpp>

class Player : public RectangleEntity
{
private :
	float speed;
public :
	Player(float speed, sf::Vector2f size);
	~Player();
	
	void Update() override;
	void ReactToCollision(sf::Vector2f from, sf::Vector2f offset) override;

	void ProcessInputs();
	void Move(sf::Vector2f dir);
	bool CheckPosition(sf::Vector2f* dir);
};


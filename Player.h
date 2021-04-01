#pragma once

#include "RectangleEntity.h"
#include <SFML/Graphics.hpp>

class Player : public RectangleEntity
{
private :
	float speed;
	int health;

public :
	Player(float speed, sf::Vector2f size);
	~Player();
	
	void ReduceHealth();
	void Update() override;
	void ReactToCollision(sf::Vector2f from, sf::Vector2f offset) override;
	int GetHealth();

	void ProcessInputs();
	void Move(sf::Vector2f dir);
	bool CheckPosition(sf::Vector2f* dir);
};


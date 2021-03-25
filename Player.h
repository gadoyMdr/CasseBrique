#pragma once

#include "Entity.h"
#include <SFML/Graphics.hpp>

class Player : public Entity
{
private :
	float speed;
public :
	Player(float speed, sf::Vector2f size);
	~Player();
	
	void Update();

	void ProcessInputs();
	void Move(sf::Vector2f dir);
	bool CheckPosition(sf::Vector2f* dir);
};


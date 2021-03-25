#pragma once

#include "Entity.h"
#include <SFML/Graphics.hpp>

class Brick : public Entity
{
private:
	int health;

public :
	Brick();
	Brick(int w, int x, int health);
	Brick(int w, int x, sf::Color color, int health);

	~Brick();

	int GetHealth();
	void SetHealth(int i);

	void OnHit() override;

	void Damage();
	void Update();
};


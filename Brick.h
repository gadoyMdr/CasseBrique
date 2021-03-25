#pragma once

#include "Entity.h"
#include <SFML/Graphics.hpp>

class Brick : public Entity
{
private:
	int health;
	int startHealth;
public :
	Brick();
	Brick(sf::Vector2f pos);
	Brick(sf::Vector2f size, int health, sf::Vector2f pos);
	Brick(sf::Vector2f size, sf::Color color, int health, sf::Vector2f pos);

	~Brick();

	int GetHealth();
	int GetStartHealth();
	void SetHealth(int i);

	void OnHit() override;

	void SetHealthColor();
	void Damage();
	void Update();
};


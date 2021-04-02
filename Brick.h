#pragma once

#include "RectangleEntity.h"
#include <SFML/Graphics.hpp>

class Brick : public RectangleEntity
{

protected :
	int health;
private:
	
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

	void OnHit(Entity& other) override;
	void ReactToCollision(sf::Vector2f from, sf::Vector2f offset) override;

	void SetHealthColor	();
	virtual void Damage();
	
};


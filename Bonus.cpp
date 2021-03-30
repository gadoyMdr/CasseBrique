#include "Bonus.h"
#include <iostream>

Bonus::Bonus(sf::Color color, sf::Vector2f pos) : RoundEntity(color, 18, pos) {

}

Bonus::~Bonus() {

}

void Bonus::ReactToCollision(CollisionFrom from, sf::Vector2f offset) {
	
}

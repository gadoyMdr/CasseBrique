#include "StickBonus.h"

StickBonus::StickBonus(sf::Vector2f pos) : Bonus(sf::Color(3,215,252,255), pos){}

StickBonus::~StickBonus(){}

void StickBonus::BeginBonus() {

}

void StickBonus::EndBonus() {

}

void StickBonus::Update() {
	Entity::Update();
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

	}
}

void StickBonus::OnHit(Entity& other) {
	MakeChildOf(&other);
}
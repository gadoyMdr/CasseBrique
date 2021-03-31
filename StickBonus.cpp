#include "StickBonus.h"
#include "GameManager.h"
#include <iostream>

StickBonus::StickBonus(sf::Vector2f pos) : Bonus(sf::Color(3,215,252,255), pos){}

StickBonus::~StickBonus(){}

void StickBonus::BeginBonus() {

}

void StickBonus::EndBonus() {

}

void StickBonus::OnHit(Entity& other) {
	GameManager::GetInstance()->GetPlayer()->SetCollisionType(CollisionType::Sticky);
	toDestroy = true;
}
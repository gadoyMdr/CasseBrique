#include "MultipleBonus.h"
#include "GameManager.h"
#include "Ball.h"
#include "Utils.h"
#include "Global.h"

MultipleBonus::MultipleBonus(sf::Vector2f pos) : Bonus(sf::Color(252, 186, 3, 255), pos) {}

MultipleBonus::~MultipleBonus() {}

void MultipleBonus::BeginBonus() {

}

void MultipleBonus::EndBonus() {

}

void MultipleBonus::OnHit(Entity& other) {
	
	int balls = 5;
	int offset = 80;

	for (int i = 1; i <= balls; i++) {
		Ball* b = new Ball(sf::Vector2f((float)(i * offset), 630));
		b->SetDirection(sf::Vector2f(-0.3, -1));
		b->SetSpeed(350);
		GameManager::GetInstance()->AddBall(b);
	}

	toDestroy = true;
}
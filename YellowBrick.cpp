#include "YellowBrick.h"
#include "Global.h"
#include "Ball.h"
#include "GameManager.h"

YellowBrick::YellowBrick() {

}

YellowBrick::YellowBrick(sf::Vector2f pos) : Brick(Global::baseBriqueSize, sf::Color(255, 216, 20, 255), 4, pos){}

YellowBrick::YellowBrick(sf::Vector2f pos, sf::Vector2f size) : Brick(size, sf::Color(255, 216, 20, 255), 4, pos) {}

void YellowBrick::Damage() {
	health--;

	if (health <= 0) {
		toDestroy = true;

		int balls = 5;
		int offset = 50;

		for (int i = 1; i <= balls; i++) {
			Ball* b = new Ball(sf::Vector2f((float)(i * offset), 630));
			b->SetDirection(sf::Vector2f(-0.3, -1));
			b->SetSpeed(350);
			GameManager::GetInstance()->AddBall(b);
		}
	}
}

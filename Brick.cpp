#include "Brick.h"
#include "Global.h"
#include "Utils.h"


Brick::Brick() : RectangleEntity(Global::themeColor, Global::baseBriqueSize, sf::Vector2f(0,0)), health(1) {}

Brick::Brick(sf::Vector2f pos) : RectangleEntity(Global::themeColor, Global::baseBriqueSize, pos), health(1), startHealth(1) {}

Brick::Brick(sf::Vector2f size, int _health, sf::Vector2f pos) : RectangleEntity(Global::themeColor, size, pos), health(_health), startHealth(_health) {}

Brick::Brick(sf::Vector2f size, sf::Color color, int _health, sf::Vector2f pos) : RectangleEntity(color, size, pos), health(_health), startHealth(_health){}

Brick::~Brick() {

}

int Brick::GetHealth() {
	return health;
}

int Brick::GetStartHealth() {
	return startHealth;
}

void Brick::SetHealth(int i) {
	health = i;
}

void Brick::OnHit(Entity& other) {
	Damage();
	SetHealthColor();
}

void Brick::Damage() {
	health--;

	if (health <= 0)
		toDestroy = true;
}

void Brick::ReactToCollision(CollisionFrom from, sf::Vector2f offset) {
	RectangleEntity::ReactToCollision(from, offset);
}

void Brick::SetHealthColor() {
	SetColor(Utils::LerpColor(GetColor(), sf::Color::White, health / startHealth));
}

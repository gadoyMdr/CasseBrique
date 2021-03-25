#include "Brick.h"
#include "Global.h"



Brick::Brick() : Entity("Brique", Tag::Rectangle, new sf::RectangleShape(Global::baseBriqueSize), sf::Color::White, sf::Vector2f(0, 0)), health(1) {}

Brick::Brick(sf::Vector2f pos) : Entity("Brique", Tag::Rectangle, new sf::RectangleShape(Global::baseBriqueSize), Global::themeColor, sf::Vector2f(pos.x, pos.y)), health(1) {}

Brick::Brick(sf::Vector2f size, int _health, sf::Vector2f pos) : Entity("Brique", Tag::Rectangle, new sf::RectangleShape(sf::Vector2f(size.x, size.y)), sf::Color::Blue, pos), health(_health) {}

Brick::Brick(sf::Vector2f size, sf::Color color, int _health, sf::Vector2f pos) : Entity("Brique", Tag::Rectangle, new sf::RectangleShape(sf::Vector2f(size.x, size.y)), color, pos), health(_health){}

Brick::~Brick() {

}

int Brick::GetHealth() {
	return health;
}

void Brick::SetHealth(int i) {
	health = i;
}

void Brick::OnHit() {
	Damage();
}

void Brick::Damage() {
	health--;

	if (health <= 0)
		toDestroy = true;
}

void Brick::Update() {
	Entity::Draw();
}

#include "Brick.h"

Brick::Brick() : Entity("Brique", Tag::Rectangle, new sf::RectangleShape(sf::Vector2f(20, 20)), sf::Color::White), health(1) {

}

Brick::Brick(int w, int h, int _health) : Entity("Brique", Tag::Rectangle, new sf::RectangleShape(sf::Vector2f(w, h)), sf::Color::Blue), health(_health) {

}

Brick::Brick(int w, int h, sf::Color color, int _health) : Entity("Brique", Tag::Rectangle, new sf::RectangleShape(sf::Vector2f(w, h)), color), health(_health){

}

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

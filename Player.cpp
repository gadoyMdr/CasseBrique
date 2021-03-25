#include "Player.h"
#include "Global.h"

Player::Player(float _speed, sf::Vector2f s) : Entity("Player", Tag::Rectangle, new sf::RectangleShape(sf::Vector2f(s.x, s.y)), Global::themeColor, sf::Vector2f(Global::window.getDefaultView().getSize().x / 2, Global::window.getDefaultView().getSize().y - 100)), speed(_speed){}

Player::~Player(){}

void Player::Update() {
	ProcessInputs();

	Entity::Update();
}

void Player::ProcessInputs() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		Move(sf::Vector2f(-1, 0));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		Move(sf::Vector2f(1, 0));
}

void Player::Move(sf::Vector2f dir) {
	SetPosition(GetPosition() + dir * speed);
}
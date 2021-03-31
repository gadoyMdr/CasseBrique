#include "Player.h"
#include "Global.h"

Player::Player(float _speed, sf::Vector2f s) : RectangleEntity(Global::themeColor, s, sf::Vector2f(Global::window.getDefaultView().getSize().x / 2, Global::window.getDefaultView().getSize().y - 100)), speed(_speed){}

Player::~Player(){}

void Player::Update() {
	ProcessInputs();

	RectangleEntity::Update();
}

void Player::ReactToCollision(sf::Vector2f from, sf::Vector2f offset) {

}

void Player::ProcessInputs() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		Move(sf::Vector2f(-1, 0));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		Move(sf::Vector2f(1, 0));
}

void Player::Move(sf::Vector2f dir) {
	sf::Vector2f temp(GetPosition() + dir * speed * Global::deltaTime);

	if(CheckPosition(&temp))
		SetPosition(temp);
}

bool Player::CheckPosition(sf::Vector2f* pos) {
	float maxX = Global::window.getDefaultView().getSize().x - GetShape()->getLocalBounds().width;
	float minX = 0 + GetShape()->getLocalBounds().width;

	return pos->x < maxX&& pos->x > minX;
}
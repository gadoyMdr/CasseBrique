#include "Player.h"
#include "Global.h"
#include <iostream>
#include "GameManager.h"


Player::Player(float _speed, float s) : RoundEntity(sf::Color(101, 252, 71, 255), s, sf::Vector2f(Global::window.getDefaultView().getSize().x / 2, Global::window.getDefaultView().getSize().y - 50)), speed(_speed), health(2){}

Player::Player(float _speed, sf::Vector2f s) : RectangleEntity(sf::Color(101, 252, 71, 255), s, sf::Vector2f(Global::window.getDefaultView().getSize().x / 2, Global::window.getDefaultView().getSize().y - 50)), speed(_speed), health(2) {}

Player::~Player(){}

void Player::Update() {
	if (GameManager::GetInstance()->isGameOver) return;

	ProcessInputs();
	Entity::Draw();
	

	GameObject::Update();
}

void Player::ReactToCollision(sf::Vector2f from, sf::Vector2f offset) {

}

void Player::ReduceHealth() {
	health--;
}

int Player::GetHealth() {
	return health;
}

void Player::ProcessInputs() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		Move(sf::Vector2f(-1, 0));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		Move(sf::Vector2f(1, 0));
}

void Player::Move(sf::Vector2f dir) {
	sf::Vector2f temp(Entity::GetPosition() + dir * speed * Global::deltaTime);

	if(CheckPosition(&temp))
		Entity::SetPosition(temp);
}

bool Player::CheckPosition(sf::Vector2f* pos) {
	float maxX = Global::window.getDefaultView().getSize().x - Entity::GetShape()->getLocalBounds().width;
	float minX = 0 + Entity::GetShape()->getLocalBounds().width;

	return pos->x < maxX&& pos->x > minX;
}
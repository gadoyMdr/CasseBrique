#include "Ball.h"
#include "Global.h"
#include "Utils.h"

Ball::Ball(float radius, float edges, sf::Color color) {
	circleShape = sf::CircleShape(radius, edges);
	circleShape.setFillColor(color);
	circleShape.setOrigin(circleShape.getLocalBounds().width / 2, circleShape.getLocalBounds().height / 2);
}

Ball::~Ball(){}

void Ball::Draw() {
	Global::window.draw(circleShape);
}

void Ball::SimulatePhysics() {
	CheckCollisions();
	Move();
}

void Ball::CheckCollisions() {

}

void Ball::Move() {
	SetPosition(GetPosition() + direction * speed * Global::deltaTime);
}

sf::Vector2f Ball::GetPosition() {
	return circleShape.getPosition();
}

void Ball::SetPosition(sf::Vector2f position) {
	circleShape.setPosition(position);
}

void Ball::SetDirection(sf::Vector2f _direction) {
	direction =  Utils::Normalize(_direction);
}

void Ball::SetSpeed(float _speed) {
	speed = _speed;
}

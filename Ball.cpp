#include "Ball.h"
#include "Global.h"
#include "GameManager.h"
#include "Player.h"
#include <iostream>

Ball::Ball() : RoundEntity(Global::themeColor, 20, sf::Vector2f(300, 300)){}
Ball::Ball(sf::Vector2f pos) : RoundEntity(Global::themeColor, 20, pos) {}
Ball::Ball(sf::Vector2f pos, float size) : RoundEntity(Global::themeColor, size, sf::Vector2f(300, 300)) {}

Ball::~Ball(){}

void Ball::ReactToCollision(sf::Vector2f from, sf::Vector2f offset) {
    RoundEntity::ReactToCollision(from, offset);
}

void Ball::OnTriggerChildrenUpdate() {
    SetPosition(GameManager::GetInstance()->GetPlayer()->GetPosition() - offset);
}

void Ball::OnMadeChildOf(GameObject* other) {
    offset = GameManager::GetInstance()->GetPlayer()->GetPosition() - GetPosition();
}

void Ball::Update() 
{
    Entity::Update();
}

void Ball::SetPosition(const sf::Vector2f pos)
{
    Entity::SetPosition(pos);
}

void Ball::SetDirection(const sf::Vector2f direction)
{
    Entity::SetDirection(direction);
}

void Ball::Move() {
    if (parent != nullptr) return;
    
    Entity::Move();
}

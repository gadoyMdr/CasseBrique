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
    std::cout << "dddd" << std::endl;
    SetPosition(GetPosition() + offset);
}

void Ball::OnMadeChildOf(GameObject* other) {
    offset = GameManager::GetInstance()->GetPlayer()->GetPosition() - GetPosition();
}

void Ball::Move() {
    if (parent != nullptr) return;
    //SetPosition(GetPosition() - offset);
    Entity::Move();
    //posWithoutOffset = GetPosition();
}

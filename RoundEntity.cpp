#include "RoundEntity.h"

RoundEntity::RoundEntity(sf::Color color, float size, sf::Vector2f pos) : Entity("RoundEntity", Tag::Ball, new sf::CircleShape(size), color, pos){}

RoundEntity::~RoundEntity(){}

void RoundEntity::ReactToCollision(sf::Vector2f from, sf::Vector2f offset) {
    SetPosition(GetPosition() - offset);

    if (from.x != 0)
        SetDirection(sf::Vector2f(GetDirection().x * -1, GetDirection().y));
    else
        SetDirection(sf::Vector2f(GetDirection().x, GetDirection().y * -1));
}             
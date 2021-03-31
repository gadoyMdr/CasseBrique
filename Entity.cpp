#include "Entity.h"
#include "Global.h"
#include "Utils.h"

Entity::Entity(const std::string& _name, Tag _tag, sf::Shape* _shape, sf::Color color, sf::Vector2f pos, CollisionType type) : GameObject(name, _tag) {
    shape = _shape;
    shape->setFillColor(color);
    shape->setOrigin(shape->getLocalBounds().width / 2, shape->getLocalBounds().height / 2);
    shape->setPosition(pos);

    collisionType = type;
}

Entity::~Entity() {

}

sf::Shape* Entity::GetShape() {
    return shape;
}

sf::Vector2f Entity::GetDirection() {
    return direction;
}

sf::Vector2f Entity::GetPosition(){
    return shape->getPosition();
}

float Entity::GetSpeed() {
    return speed;
}

CollisionType Entity::GetCollisionType() {
    return collisionType;
}

sf::Color Entity::GetColor() {
    return shape->getFillColor();
}

void Entity::SetColor(sf::Color* color) {
    shape->setFillColor(*color);
}

void Entity::SetPosition(const sf::Vector2f pos) {
    shape->setPosition(pos);
}

void Entity::SetDirection(const sf::Vector2f _direction) {
    direction = Utils::Normalize(_direction);
}

void Entity::SetSpeed(const float _speed) {
    speed = _speed;
}


void Entity::Update() {
    GameObject::Update();
    Move();
    Draw();
}

void Entity::OnTriggerChildrenUpdate() {

}

void Entity::SetCollisionType(CollisionType _collisionType) {
    collisionType = _collisionType;
}

void Entity::OnHit(Entity& other){}

void Entity::Draw() {
    Global::window.draw(*shape);
}

void Entity::Move() {
    if(parent == nullptr)
        SetPosition(GetPosition() + direction * speed * Global::deltaTime);
}


#include "GameObject.h"
#include <string>
#include <vector>
#include <iostream>

#include "Utils.h"
#include "Global.h"
#include "Component.h"

using namespace std;

GameObject::GameObject() {
    name = "Empty";
    shape = new sf::CircleShape(10, 10);
    tag = Tag::Ball;
}

GameObject::GameObject(const std::string& _name, Tag _tag, sf::Shape* _shape, sf::Color color) {
    shape = _shape;
    shape->setFillColor(color);
    shape->setOrigin(shape->getLocalBounds().width / 2, shape->getLocalBounds().height / 2);

    name = _name;
    tag = _tag;
}

void GameObject::AddComponent(Component* c) {
    components.push_back(c);
    c->SetParentGO(this);
}


sf::Vector2f GameObject::GetPosition() 
{ 
    return shape->getPosition(); 
}

sf::Shape* GameObject::GetShape() {
    return shape;
}

void GameObject::SetPosition(const sf::Vector2f pos) { 
    shape->setPosition(pos); 
}

void GameObject::SetDirection(const sf::Vector2f _direction) {
    direction = Utils::Normalize(_direction);
}

void GameObject::SetSpeed(const float _speed) {
    speed = _speed;
}

void GameObject::Draw() {
    Global::window.draw(*shape);
}

void GameObject::CheckCollisions(GameObject* go) {

    if(go->tag == Tag::Ball)

    if (go->GetShape()->getGlobalBounds().intersects(shape->getGlobalBounds())) {
        shape->setFillColor(sf::Color::Cyan);
    }



}

void GameObject::Move() {
    SetPosition(GetPosition() + direction * speed * Global::deltaTime);
}

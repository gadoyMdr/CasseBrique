#include "GameObject.h"
#include <string>
#include <vector>
#include <iostream>

#include "Utils.h"
#include "Global.h"
#include "Component.h"
#include <math.h>

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

sf::Vector2f GameObject::GetDirection() {
    return direction;
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

    if (tag == Tag::Ball && go->tag == Tag::Rectangle) {
        sf::CircleShape* circle = (sf::CircleShape*) shape;
        sf::Vector2f distanceFromMiddles = GetPosition() - go->GetPosition();
        sf::Vector2f localGoExtends = sf::Vector2f(go->GetShape()->getLocalBounds().width / 2.0, go->GetShape()->getLocalBounds().height / 2.0);
        sf::Vector2f closestPointOnGO = go->GetPosition() + Utils::Clamp(distanceFromMiddles, -localGoExtends, localGoExtends);
        sf::Vector2f lineToClosestPoint = closestPointOnGO - GetPosition();
        float length = sqrt((lineToClosestPoint.x * lineToClosestPoint.x) + (lineToClosestPoint.y *lineToClosestPoint.y));



        float penetrationDistance = circle->getRadius() - length;
        sf::Vector2f offsetNeeded = Utils::Dunno(lineToClosestPoint, circle->getRadius()) * penetrationDistance;

        float bigger = circle->getRadius() - fmax(abs(lineToClosestPoint.x), abs(lineToClosestPoint.y));

        if (lineToClosestPoint.x < 0 || lineToClosestPoint.y < 0)
            bigger *= -1;

        if (abs(lineToClosestPoint.x) > 0) offsetNeeded = sf::Vector2f(bigger, 0);
        else offsetNeeded = sf::Vector2f(0, bigger);
        


        sf::Vector2f compass[] = {
        sf::Vector2f(0.0f, 1.0f),	// down
        sf::Vector2f(1.0f, 0.0f),	// right
        sf::Vector2f(0.0f, -1.0f),	// up
        sf::Vector2f(-1.0f, 0.0f)	// left
        };
        float max = 0.0f;
        int best_match = -1;
        for (int i = 0; i < 4; i++)
        {
            float dot_product = Utils::Dot(Utils::Normalize(Utils::Normalize(lineToClosestPoint)), compass[i]);
            if (dot_product > max)
            {
                max = dot_product;
                best_match = i;
            }
        }
        
        


        if (length < circle->getRadius()) {
            SetPosition(GetPosition() - offsetNeeded);

            if (best_match == 1 || best_match == 3)
                SetDirection(sf::Vector2f(GetDirection().x * -1, GetDirection().y));
            else
                SetDirection(sf::Vector2f(GetDirection().x, GetDirection().y * -1));
        }
    }

    if (go->GetShape()->getGlobalBounds().intersects(shape->getGlobalBounds())) {
        shape->setFillColor(sf::Color::Cyan);
    }



}

void GameObject::Move() {
    SetPosition(GetPosition() + direction * speed * Global::deltaTime);
}

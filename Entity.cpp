#include "Entity.h"
#include "Global.h"
#include "Utils.h"

Entity::Entity(const std::string& _name, Tag _tag, sf::Shape* _shape, sf::Color color, sf::Vector2f pos) : GameObject(name, _tag) {
    shape = _shape;
    shape->setFillColor(color);
    shape->setOrigin(shape->getLocalBounds().width / 2, shape->getLocalBounds().height / 2);
    shape->setPosition(pos);
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
    Move();
    CheckCollisions();
    Draw();
}

void Entity::OnHit(){}

void Entity::Draw() {
    Global::window.draw(*shape);
}

void Entity::CheckCollisions() {

    for (MonoBehavior* mono : MonoBehavior::GetAllMonobehaviors())
    {
        Entity* go = dynamic_cast<Entity*>(mono);
        if (go != nullptr) {

            

            if (tag == Tag::Ball && go->tag == Tag::Rectangle) {

                if (mono == this)
                    return;

                sf::CircleShape* circle = (sf::CircleShape*)shape;

                sf::Vector2f distanceFromMiddles = GetPosition() - go->GetPosition();
                sf::Vector2f localGoExtends = sf::Vector2f(go->GetShape()->getLocalBounds().width / 2.0, go->GetShape()->getLocalBounds().height / 2.0);
                sf::Vector2f closestPointOnGO = go->GetPosition() + Utils::Clamp(distanceFromMiddles, -localGoExtends, localGoExtends);
                sf::Vector2f lineToClosestPoint = closestPointOnGO - GetPosition();
                float length = sqrt((lineToClosestPoint.x * lineToClosestPoint.x) + (lineToClosestPoint.y * lineToClosestPoint.y));



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
                    go->OnHit();

                    SetPosition(GetPosition() - offsetNeeded);

                    if (best_match == 1 || best_match == 3)
                        SetDirection(sf::Vector2f(GetDirection().x * -1, GetDirection().y));
                    else
                        SetDirection(sf::Vector2f(GetDirection().x, GetDirection().y * -1));
                }
            }
        }
    }
}

void Entity::Move() {
    SetPosition(GetPosition() + direction * speed * Global::deltaTime);
}


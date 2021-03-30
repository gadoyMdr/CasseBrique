#pragma once
#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include "Enums.h"

class Entity : public GameObject
{

public :
	enum class CollisionFrom {
		Down,
		Right,
		Up,
		Left
	};

protected :

	

	CollisionFrom collisionFrom;

	CollisionType collisionType;

private :
	sf::Shape* shape;
	sf::Vector2f direction;
	float speed;

public :
	

	Entity(const std::string& name, Tag _tag, sf::Shape* _shape, sf::Color color, sf::Vector2f pos, CollisionType type = CollisionType::Simple);
	~Entity();


	sf::Vector2f GetDirection();
	sf::Shape* GetShape();
	float GetSpeed();
	sf::Vector2f GetPosition();
	sf::Color GetColor();

	void SetPosition(const sf::Vector2f pos);
	void SetDirection(const sf::Vector2f direction);
	void SetSpeed(const float speed);
	void SetColor(sf::Color* color);

	virtual void OnHit(Entity& other);

	void Update();

	void Move();
	void CheckCollisions();
	virtual void ReactToCollision(CollisionFrom from, sf::Vector2f offset) = 0;
	virtual void Draw();

	virtual void OnTriggerChildrenUpdate() override;
};


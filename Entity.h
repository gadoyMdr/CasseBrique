#pragma once
#include "GameObject.h"
#include <SFML/Graphics.hpp>

class Entity : public GameObject
{
private :
	sf::Shape* shape;
	sf::Vector2f direction;
	float speed;

public :
	Entity(const std::string& name, Tag _tag, sf::Shape* _shape, sf::Color color, sf::Vector2f pos);
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

	virtual void OnHit();

	void Update();

	void Move();
	void CheckCollisions();
	void Draw();
};


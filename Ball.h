#pragma once

#include <SFML/Graphics.hpp>

class Ball
{
private :
	sf::CircleShape circleShape;

	sf::Vector2f direction;
	float speed;

	void Move();
	void CheckCollisions();

public :

	Ball(float radius, float edges, sf::Color color);
	~Ball();

	void SetDirection(sf::Vector2f direction);
	void SetSpeed(float speed);
	void SetPosition(sf::Vector2f position);


	sf::Vector2f GetPosition();

	void SimulatePhysics();
	void Draw();
};


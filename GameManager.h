#pragma once

#include "MonoBehavior.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include "RoundEntity.h"

class GameManager : public MonoBehavior
{
private :
	static GameManager* instance;
	GameManager();

	//GameRelated
	sf::Sprite backGroundSprite;
	sf::Texture backGroundTexture;
	std::vector<RoundEntity*> balls;

public :
	GameManager(GameManager& other) = delete;
	void operator=(const GameManager&) = delete;

	static GameManager* GetInstance();

	void AddBall(RoundEntity* ball);
	void RemoveBall(RoundEntity* ball);
	std::vector<RoundEntity*>* GetBalls();

	void StartNewGame();
	void InitializeGame();
	void CreateBackGround();
	void FirstSpawn();

	void Update();
};


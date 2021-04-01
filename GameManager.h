#pragma once

#include "MonoBehavior.h"
#include <SFML/Graphics.hpp>
#include <vector>

class Player;
class RoundEntity;

class GameManager : public MonoBehavior
{
private :
	static GameManager* instance;
	GameManager();

	//GameRelated
	sf::Sprite backGroundSprite;
	sf::Texture backGroundTexture;

	std::vector<RoundEntity*> balls;
	Player* player;

public :
	GameManager(GameManager& other) = delete;
	void operator=(const GameManager&) = delete;

	static GameManager* GetInstance();

	void SetPlayer(Player* player);
	void AddBall(RoundEntity* ball);

	void RemoveBall(RoundEntity* ball);

	Player* GetPlayer();
	std::vector<RoundEntity*>* GetBalls();

	void StartNewGame();
	void InitializeGame();
	void CreateBackGround();
	void FirstSpawn();
	void CheckEveryCollisions();
	void CheckForUserClick();
	void ReleaseStickyCollisions();
	void Update();
};


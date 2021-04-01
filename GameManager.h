#pragma once

#include "MonoBehavior.h"
#include <SFML/Graphics.hpp>
#include <vector>

class Player;
class Ball;

class GameManager : public MonoBehavior
{
private :
	static GameManager* instance;
	GameManager();

	//GameRelated
	sf::Sprite backGroundSprite;
	sf::Texture backGroundTexture;

	std::vector<Ball*> balls;
	Player* player;
	

public :
	bool isGameOver;

	GameManager(GameManager& other) = delete;
	void operator=(const GameManager&) = delete;

	static GameManager* GetInstance();

	void SetPlayer(Player* player);
	void AddBall(Ball* ball);

	void RemoveBall(Ball* ball);

	Player* GetPlayer();
	std::vector<Ball*> GetBalls();

	void StartNewGame();
	void InitializeGame();
	void CreateBackGround();
	void FirstSpawn();
	void CheckEveryCollisions();
	void CheckForUserClick();
	void ReleaseStickyCollisions();
	void CheckBallsPosition();
	void Update();
	void PlayerLoseHealth();

	void EndGame();
	void ResetPlayer();
	void SpawnNewBall();
	void OnBallsLost();	//hilarious
};


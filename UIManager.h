#pragma once

#include "MonoBehavior.h"
#include "Player.h"
#include "GameManager.h"
#include <SFML/Graphics.hpp>
#include <vector>

class Player;
class Ball;
class GameManager;

class UIManager : public MonoBehavior
{
private:
	static UIManager* instance;
	UIManager();


	//
	sf::Vector2f hpSpawnCoord;
	std::vector<sf::Sprite> lifeSprites;
	float xCoord;
	float yCoord;
	sf::Sprite lifeSprite;
	sf::Texture lifeTexture;
	std::vector<Ball*> balls;
	Player* player;

	sf::Text text;
	sf::Font font;

public:
	UIManager(UIManager& other) = delete;
	void operator=(const UIManager&) = delete;

	static UIManager* GetInstance();

	Player* GetPlayer();
	void SetPlayer(Player* _player);
	std::vector<Ball*>* GetBalls();
	void ShowGameOver();

	void InitializeUi();

	void Update();

	void DrawLife();
};


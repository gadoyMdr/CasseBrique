#pragma once

#include "MonoBehavior.h"
#include <SFML/Graphics.hpp>

class GameManager : public MonoBehavior
{
private :
	static GameManager* instance;
	GameManager();

	//GameRelated
	sf::Sprite backGroundSprite;
	sf::Texture backGroundTexture;

public :
	GameManager(GameManager& other) = delete;
	void operator=(const GameManager&) = delete;

	static GameManager* GetInstance();

	void StartNewGame();
	void InitializeGame();
	void CreateBackGround();
	void FirstSpawn();

	void Update();
};


#include "GameManager.h"
#include "Global.h"
#include "Player.h"
#include "Brick.h"

GameManager* GameManager::instance = nullptr;

GameManager::GameManager() {
    toDestroy = false;
}

GameManager* GameManager::GetInstance() {
    if (instance == nullptr) {
        instance = new GameManager();
    }
    return instance;
}

void GameManager::Update() {
    Global::window.draw(backGroundSprite);
}

void GameManager::StartNewGame() {
    InitializeGame();
}

void GameManager::InitializeGame() {
    CreateBackGround();
    FirstSpawn();
}

void GameManager::CreateBackGround() {
    backGroundTexture.loadFromFile("Textures/background.png");
    backGroundTexture.setSmooth(true);

    backGroundSprite.setTexture(backGroundTexture);
    backGroundSprite.setScale(sf::Vector2f(0.7, 0.7));
    backGroundSprite.setColor(Global::backGroundColor);
}

void GameManager::FirstSpawn() {
    int paddingX = 100;
    int paddingY = 50;
    int offsetx = 150;
    int offsety = 100;

    for (int j = 0; j < 3; j++)
        for (int i = 0; i < 5; i++) {
            Brick* l = new Brick(sf::Vector2f(i * offsetx + paddingX, j * offsety + paddingY));
            l->SetHealth(5);
        }

    Entity* go = new Entity("Ball", Tag::Ball, new sf::CircleShape(20, 50), Global::themeColor, sf::Vector2f(300, 350));
    go->SetDirection(sf::Vector2f(1, 1));
    go->SetSpeed(350);

    new Player(0.25, sf::Vector2f(80, 18));

    new Entity("Rectangle", Tag::Rectangle, new sf::RectangleShape(sf::Vector2f(40, 4000)), Global::themeColor, sf::Vector2f(0, 0));

    new Entity("Rectangle", Tag::Rectangle, new sf::RectangleShape(sf::Vector2f(4000, 40)), Global::themeColor, sf::Vector2f(0, 0));

    new Entity("Rectangle", Tag::Rectangle, new sf::RectangleShape(sf::Vector2f(40, 4000)), Global::themeColor, sf::Vector2f(800, 0));

}

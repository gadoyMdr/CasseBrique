#include "GameManager.h"
#include "Global.h"
#include "Player.h"
#include "Brick.h"
#include "StickBonus.h"
#include "Utils.h"


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

void GameManager::AddBall(RoundEntity* ball) {
    balls.push_back(ball);
}

void GameManager::RemoveBall(RoundEntity* ball) {
    balls.erase(std::remove(balls.begin(), balls.end(), ball), balls.end());
}

std::vector<RoundEntity*>* GameManager::GetBalls() {
    return &balls;
}

void GameManager::Update() {
    CheckEveryCollisions();
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

void GameManager::SetPlayer(Player* _player) {
    player = _player;
}

Player* GameManager::GetPlayer() {
    return player;
}

void GameManager::CheckEveryCollisions() {
    

    for (MonoBehavior* monoA : MonoBehavior::GetAllMonobehaviors())
    {
        Entity* a = dynamic_cast<Entity*>(monoA);

        if (a == nullptr)
            continue;
        
        for (MonoBehavior* monoB : MonoBehavior::GetAllMonobehaviors())
        {
            Entity* b = dynamic_cast<Entity*>(monoB);
            if (b == nullptr)
                continue;
            
            if (Utils::CheckCollision(*a, *b)) {
                break;
            }
        }
        
    }
}

void GameManager::FirstSpawn() {
    StickBonus * l = new StickBonus(sf::Vector2f(500, 500));
    

    int paddingX = 100;
    int paddingY = 50;
    int offsetx = 150;
    int offsety = 100;

    for (int j = 0; j < 3; j++)
        for (int i = 0; i < 5; i++) {
            Brick* l = new Brick(sf::Vector2f(i * offsetx + paddingX, j * offsety + paddingY));
            l->SetHealth(4);
        }



    RoundEntity* go = new RoundEntity(Global::themeColor, 20, sf::Vector2f(300, 350));
    go->SetDirection(sf::Vector2f(1, 1));
    go->SetSpeed(350);

    AddBall(go);

    SetPlayer(new Player(500, sf::Vector2f(80, 18)));

    new RectangleEntity(Global::themeColor, sf::Vector2f(40, 4000), sf::Vector2f(0, 0));

    new RectangleEntity(Global::themeColor, sf::Vector2f(4000, 40), sf::Vector2f(0, 0));

    new RectangleEntity(Global::themeColor, sf::Vector2f(40, 4000), sf::Vector2f(800, 0));

}

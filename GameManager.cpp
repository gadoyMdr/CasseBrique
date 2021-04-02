#include "GameManager.h"
#include "Global.h"
#include "RoundPlayer.h"
#include "Brick.h"
#include "StickBonus.h"
#include "Utils.h"
#include "Ball.h"
#include "MultipleBonus.h"
#include "UIManager.h"

using namespace std;

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

void GameManager::AddBall(Ball* ball) {
    balls.push_back(ball);
}

void GameManager::RemoveBall(Ball* ball) {
    balls.erase(std::remove(balls.begin(), balls.end(), ball), balls.end());
}

std::vector<Ball*> GameManager::GetBalls() {
    return balls;
}

void GameManager::Update() {
    CheckEveryCollisions();
    CheckForUserClick();
    CheckBallsPosition();
    Global::window.draw(backGroundSprite);
}

void GameManager::PlayerLoseHealth() {
    player->ReduceHealth();

    if (player->GetHealth() <= 0) {
        EndGame();
    }
}

void GameManager::EndGame() {
    UIManager::GetInstance()->ShowGameOver();
    isGameOver = true;
}

void GameManager::CheckBallsPosition() {
    bool isOkay = false;
    int max = 60;
    if (balls.size() == 0)return;

    for (Ball* ball : balls) {
        sf::Vector2f pos = ball->GetPosition();

        if (pos.x < Global::window.getDefaultView().getSize().x + max &&
            pos.x > 0 - max &&
            pos.y < Global::window.getDefaultView().getSize().y + max &&
            pos.y > 0 - max) {

            isOkay = true;
        }
    }

    if (!isOkay) {
        OnBallsLost();
    }
}

void GameManager::OnBallsLost() {
    ResetPlayer();
    SpawnNewBall();
    PlayerLoseHealth();
}

void GameManager::ResetPlayer() {
    player->Entity::SetPosition(sf::Vector2f(Global::window.getDefaultView().getSize().x / 2, Global::window.getDefaultView().getSize().y - 100));
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
            if (b == nullptr || a == b)
                continue;
            
            if (Utils::CheckCollision(*a, *b)) {
                break;
            }
        }
        
    }
}

void GameManager::CheckForUserClick() {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        
        ReleaseStickyCollisions();
    }
}

void GameManager::ReleaseStickyCollisions() {
    for (MonoBehavior* mono : all) {
        Entity* a = dynamic_cast<Entity*>(mono);

        if (a == nullptr)
            continue;

        if (a->GetCollisionType() == CollisionType::Sticky) {
            a->SetCollisionType(CollisionType::Simple);

            for (GameObject* go : a->GetChildren()) {
                Entity* l = dynamic_cast<Entity*>(go);
                l->Free();
                sf::Vector2i m = sf::Mouse::getPosition(Global::window);
                l->SetDirection(Utils::Normalize(sf::Vector2f(m.x, m.y) - l->GetPosition()));
            }

            a->Free();
        }
            
    }
}

void GameManager::SpawnNewBall() {
    Ball* ball = new Ball(sf::Vector2f(player->Entity::GetPosition().x, player->Entity::GetPosition().y - 120));
    ball->SetDirection(sf::Vector2f(0,1));
    ball->SetSpeed(350);

    AddBall(ball);
}

void GameManager::FirstSpawn() {
    int paddingX = 100;
    int paddingY = 50;
    int offsetx = 150;
    int offsety = 100;

    for (int j = 0; j < 3; j++)
        for (int i = 0; i < 5; i++) {
            Brick* l = new Brick(sf::Vector2f(i * offsetx + paddingX, j * offsety + paddingY));
            l->SetHealth(4);
        }

    //Player* p = new Player(300, sf::Vector2f(80, 18));
    Player* p = new Player(300, 40);
    SetPlayer(p);
    SpawnNewBall();

    new StickBonus(p->Entity::GetPosition());
    new StickBonus(sf::Vector2f(400, 105));
    new MultipleBonus(sf::Vector2f(200, 200));
    new MultipleBonus(sf::Vector2f(600, 200));

    new RectangleEntity(Global::themeColor, sf::Vector2f(40, 4000), sf::Vector2f(0, 0));

    new RectangleEntity(Global::themeColor, sf::Vector2f(4000, 40), sf::Vector2f(0, 0));

    new RectangleEntity(Global::themeColor, sf::Vector2f(40, 4000), sf::Vector2f(800, 0));

}

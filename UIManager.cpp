#include "UIManager.h"
#include "Global.h"
#include "Player.h"
#include "Brick.h"
#include "Utils.h"
#include "Ball.h"

using namespace std;

UIManager* UIManager::instance = nullptr;

UIManager::UIManager() {
    toDestroy = false;
}

UIManager* UIManager::GetInstance() {
    if (instance == nullptr) {
        instance = new UIManager();
    }
    return instance;
}

void UIManager::Update() {
    DrawLife();
    Global::window.draw(text);
}

void UIManager::InitializeUi() {
    lifeTexture.loadFromFile("Textures/life.png");
    lifeSprite.setTexture(lifeTexture);
    lifeSprite.setScale(0.1, 0.1);
    xCoord = Global::window.getSize().x * 0.1;
    yCoord = Global::window.getSize().y * 0.9;
    lifeSprite.setColor(Global::themeColor);
    /*hpSpawnCoord.x = Global::window.getSize().x * 0.1;
    hpSpawnCoord.y = Global::window.getSize().y * 0.9;*/


    for (size_t i = 0; i < 5; i++)
    {
        /*sf::Sprite s = sf::Sprite();

        s.setTexture(lifeTexture);
        s.setScale(0.1, 0.1);*/

        //lifeSprites.push_back(s);
    }
}

void UIManager::SetPlayer(Player* _player) {
    player = _player;
}

Player* UIManager::GetPlayer() {
    return player;
}

std::vector<Ball*>* UIManager::GetBalls() {
    return &balls;
}

void UIManager::ShowGameOver() {
    
    if (!font.loadFromFile("Textures/simple.ttf")) {
        std::cout << "fnuck" << std::endl;
    }

    text.setFont(font); // font is a sf::Font

    text.setString("Game Over");

    text.setCharacterSize(120); // in pixels, not points!

    text.setFillColor(sf::Color(214,34,34, 255));

    text.setPosition(sf::Vector2f(200, 200));


    text.setStyle(sf::Text::Bold);
}

void UIManager::DrawLife() {

    xCoord = Global::window.getSize().x * 0.1;
    yCoord = Global::window.getSize().y * 0.9;
    Player* player = GameManager::GetInstance()->GetPlayer();

    //ici check < player health -1 car on le fait 1 fois avant le for
    for (size_t i = 0; i < player->GetHealth(); i++)
    {
        lifeSprite.setPosition(xCoord, yCoord);
        Global::window.draw(lifeSprite);
        xCoord = xCoord + 75;
    }
}
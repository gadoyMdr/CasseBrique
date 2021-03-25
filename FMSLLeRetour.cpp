
#include "Global.h"
#include <iostream>
#include "Entity.h"
#include <vector>
#include "Utils.h"
#include "Brick.h"
#include "Player.h"

int main()
{
    sf::Clock deltaClock;
    sf::Sprite sprite;

    sf::Texture t;
    t.loadFromFile("Textures/background.png");
    sprite.setTexture(t);
    t.setSmooth(true);
    sprite.setScale(sf::Vector2f(0.7, 0.7));
    sprite.setColor(Global::backGroundColor);
    

    Entity* go = new Entity("Ball", Tag::Ball, new sf::CircleShape(20, 50), Global::themeColor, sf::Vector2f(300, 300));
    go->SetDirection(sf::Vector2f(1, 1));
    go->SetSpeed(350);


    int paddingX = 100;
    int paddingY = 50;
    int offsetx = 150;
    int offsety = 100;

    for (int j = 0; j < 3; j++)
        for (int i = 0; i < 5; i++) {
            Brick* l = new Brick(sf::Vector2f(i * offsetx + paddingX, j * offsety + paddingY));
            l->SetHealth(5);
        }
            
        
    new Player(0.25, sf::Vector2f(80, 18));
    

    new Entity("Rectangle", Tag::Rectangle, new sf::RectangleShape(sf::Vector2f(40, 4000)), Global::themeColor, sf::Vector2f(0, 0));

    new Entity("Rectangle", Tag::Rectangle, new sf::RectangleShape(sf::Vector2f(4000, 40)), Global::themeColor, sf::Vector2f(0, 0));

    new Entity("Rectangle", Tag::Rectangle, new sf::RectangleShape(sf::Vector2f(40, 4000)), Global::themeColor, sf::Vector2f(800, 0));

    new Entity("Rectangle", Tag::Rectangle, new sf::RectangleShape(sf::Vector2f(4000, 40)), Global::themeColor, sf::Vector2f(0, 600));


    // Start the game loop
    while (Global::window.isOpen())
    {

        // Process events
        sf::Event event;
        while (Global::window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                Global::window.close();
        }
        // Clear screen
        Global::window.clear(sf::Color::White);

        Global::window.draw(sprite);

        for (MonoBehavior* mono : MonoBehavior::GetAllMonobehaviors()) {
            mono->Update();
            if (mono->toDestroy)
                mono->Destroy();
        }

        

        // Update the window
        Global::window.display();
        
        Global::deltaTime = deltaClock.getElapsedTime().asSeconds();
        deltaClock.restart();
    }
    return EXIT_SUCCESS;
}

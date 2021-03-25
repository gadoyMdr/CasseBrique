
#include "Global.h"
#include <iostream>
#include "Entity.h"
#include <vector>
#include "Utils.h"
#include "Brick.h"

int main()
{
    sf::Clock deltaClock;
   

    Entity* go = new Entity("Ball", Tag::Ball, new sf::CircleShape(20, 50), sf::Color::Blue);
    go->SetDirection(sf::Vector2f(1, 1));
    go->SetSpeed(1000);
    go->SetPosition(sf::Vector2f(80, 80));

    Brick* br = new Brick(40, 60, 2);
    br->SetPosition(sf::Vector2f(450, 200));

    Entity* go2 = new Entity("Rectangle", Tag::Rectangle, new sf::RectangleShape(sf::Vector2f(40, 4000)), sf::Color::Blue);
    go2->SetPosition(sf::Vector2f(0, 0));

    Entity* go3 = new Entity("Rectangle", Tag::Rectangle, new sf::RectangleShape(sf::Vector2f(4000, 40)), sf::Color::Blue);
    go3->SetPosition(sf::Vector2f(0, 0));

    Entity* go4 = new Entity("Rectangle", Tag::Rectangle, new sf::RectangleShape(sf::Vector2f(40, 4000)), sf::Color::Blue);
    go4->SetPosition(sf::Vector2f(800, 0));

    Entity* go5 = new Entity("Rectangle", Tag::Rectangle, new sf::RectangleShape(sf::Vector2f(4000, 40)), sf::Color::Blue);
    go5->SetPosition(sf::Vector2f(0, 600));


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
        Global::window.clear();



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

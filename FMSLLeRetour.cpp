
#include "Global.h"
#include <iostream>
#include "Entity.h"
#include <vector>
#include "Utils.h"

int main()
{
    sf::Clock deltaClock;
   

    Entity go = Entity("Ball", Tag::Ball, new sf::CircleShape(20, 50), sf::Color::Blue);
    go.SetDirection(sf::Vector2f(1, 1));
    go.SetSpeed(7000);
    go.SetPosition(sf::Vector2f(80, 80));

    Entity go1 = Entity("Rectangle", Tag::Rectangle, new sf::RectangleShape(sf::Vector2f(40,40)), sf::Color::Blue);
    go1.SetPosition(sf::Vector2f(450, 200));

    Entity go2 = Entity("Rectangle", Tag::Rectangle, new sf::RectangleShape(sf::Vector2f(40, 4000)), sf::Color::Blue);
    go2.SetPosition(sf::Vector2f(0, 0));

    Entity go3 = Entity("Rectangle", Tag::Rectangle, new sf::RectangleShape(sf::Vector2f(4000, 40)), sf::Color::Blue);
    go3.SetPosition(sf::Vector2f(0, 0));

    Entity go4 = Entity("Rectangle", Tag::Rectangle, new sf::RectangleShape(sf::Vector2f(40, 4000)), sf::Color::Blue);
    go4.SetPosition(sf::Vector2f(800, 0));

    Entity go5 = Entity("Rectangle", Tag::Rectangle, new sf::RectangleShape(sf::Vector2f(4000, 40)), sf::Color::Blue);
    go5.SetPosition(sf::Vector2f(0, 600));


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
        }

        // Update the window
        Global::window.display();
        
        Global::deltaTime = deltaClock.getElapsedTime().asSeconds();
        deltaClock.restart();
    }
    return EXIT_SUCCESS;
}


#include "Ball.h"
#include "Global.h"
#include <cstdlib>
#include <iostream>
#include <ctime>
#include "GameObject.h"
#include <vector>
#include "Utils.h"

int main()
{
    sf::Clock deltaClock;
    
    std::vector<GameObject*> objects;

    for (int i = 0; i < 1; i++) {
        GameObject go = GameObject("Ball", Tag::Ball, new sf::CircleShape(20, 50), sf::Color::Blue);
        go.SetDirection(sf::Vector2f(1,1));
        go.SetSpeed(7000);
        go.SetPosition(sf::Vector2f(80, 80));

        objects.push_back(&go);
    }

    

    GameObject go1 = GameObject("Rectangle", Tag::Rectangle, new sf::RectangleShape(sf::Vector2f(40,40)), sf::Color::Blue);
    go1.SetPosition(sf::Vector2f(450, 200));

    GameObject go2 = GameObject("Rectangle", Tag::Rectangle, new sf::RectangleShape(sf::Vector2f(40, 4000)), sf::Color::Blue);
    go2.SetPosition(sf::Vector2f(0, 0));

    GameObject go3 = GameObject("Rectangle", Tag::Rectangle, new sf::RectangleShape(sf::Vector2f(4000, 40)), sf::Color::Blue);
    go3.SetPosition(sf::Vector2f(0, 0));

    GameObject go4 = GameObject("Rectangle", Tag::Rectangle, new sf::RectangleShape(sf::Vector2f(40, 4000)), sf::Color::Blue);
    go4.SetPosition(sf::Vector2f(800, 0));

    GameObject go5 = GameObject("Rectangle", Tag::Rectangle, new sf::RectangleShape(sf::Vector2f(4000, 40)), sf::Color::Blue);
    go5.SetPosition(sf::Vector2f(0, 600));

    objects.push_back(&go4);
    objects.push_back(&go5);
    objects.push_back(&go3);
    objects.push_back(&go2);
    
    objects.push_back(&go1);

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

        for (int i = 0; i < objects.size(); i++) {
            objects[i]->Draw();
        }
        
        for (int i = 0; i < objects.size(); i++) {
            objects[i]->Move();
            for (int j = 0; j < objects.size(); j++) {
                if(objects[i] != objects[j])
                    objects[i]->CheckCollisions(objects[j]);
            }
        }

        // Update the window
        Global::window.display();
        
        Global::deltaTime = deltaClock.getElapsedTime().asSeconds();
        deltaClock.restart();
    }
    return EXIT_SUCCESS;
}

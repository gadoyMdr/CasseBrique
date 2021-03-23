
#include "Ball.h"
#include "Global.h"
#include <iostream>
#include "GameObject.h"
#include <vector>

int main()
{
    sf::Clock deltaClock;
    
    std::vector<GameObject*> objects;

    GameObject go = GameObject("Ball", Tag::Ball, new sf::CircleShape(20,50), sf::Color::Blue);

    go.SetDirection(sf::Vector2f(1, 0));
    go.SetSpeed(350);
    go.SetPosition(sf::Vector2f(0, 200));

    GameObject go1 = GameObject("Ball", Tag::Ball, new sf::CircleShape(20, 50), sf::Color::Blue);

    go1.SetDirection(sf::Vector2f(-1, 0));
    go1.SetSpeed(350);
    go1.SetPosition(sf::Vector2f(600, 200));

    objects.push_back(&go);
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

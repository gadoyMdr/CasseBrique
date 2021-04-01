
#include "Global.h"
#include "GameManager.h"
#include "UIManager.h"

#include <stdlib.h>
#include <time.h>
#include <stdio.h>


int main()
{
    sf::Clock deltaClock;

    GameManager::GetInstance()->StartNewGame();
    UIManager::GetInstance()->InitializeUi();

    srand((unsigned)time(NULL));

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

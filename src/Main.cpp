#include <SFML/Graphics.hpp>
#include "Scenes/Scene.hpp"
#include "Scenes/Game.hpp"

int main()
{
    // Create the window
    sf::RenderWindow window(sf::VideoMode(1280, 720), "cpp-rpg", sf::Style::Titlebar | sf::Style::Close);

    // The Active Scene
    Scene *scene = new Game(window);

    // Delta time clock
    sf::Clock clock;
    while (window.isOpen())
    {
        // Check for close event
        sf::Event e;
        while (window.pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
            {
                scene->close();
                window.close();
            }
            // Pass events to the scene
            scene->handleEvent(e);
        }

        scene->update(clock.restart());

        window.clear(sf::Color(20, 20, 20));
        // draw
        scene->draw();

        window.display();
    }
    return 0;
}
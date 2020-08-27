#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "double.h"

void update(int& t, sf::RenderWindow& window)
{
    std::cout << "update" << std::endl;
    sf::Font font;
    if (!font.loadFromFile("C:\\Projects\\Logo\\Logo\\arial.ttf"))
        return;
    sf::Text text(std::to_string(t), font, 50);
    //window.draw(text);
    //window.display();
}

int main()
{
    //std::cout << (Double(1) == Double(1)) << std::endl;

    sf::Clock clock;

    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("C:\\Projects\\Logo\\Logo\\cute_image.png"))
        return EXIT_FAILURE; 
    sf::Sprite sprite(texture);
    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile("C:\\Projects\\Logo\\Logo\\arial.ttf"))
        return EXIT_FAILURE;
    //sf::Text text("Hello SFML", font, 50);
    // Load a music to play
    //sf::Music music;
    //if (!music.openFromFile("C:\\Projects\\Logo\\Logo\\music.ogg"))
        //return EXIT_FAILURE;
    // Play the music
    //music.play();
    // Start the game loop

    int t = 0;

    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Clear screen
        window.clear();
        // Draw the sprite
        window.draw(sprite);
        // Draw the string
        window.draw(sf::Text(std::to_string(t), font, 50));
        // Update the window
        window.display();
        //std::cout << "while" << std::endl;
        sf::Time elapsed = clock.getElapsedTime();
        //std::cout << Double(elapsed.asSeconds()) << std::endl;
        if (Double(elapsed.asSeconds()) == Double(1))
        {
            std::cout << "elapsed" << std::endl;

            clock.restart();
            update(t, window);
            ++t;
        }
    }
    return EXIT_SUCCESS;;
}
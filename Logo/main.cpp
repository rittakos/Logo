#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include<thread>

#include "double.h"

void write(std::string str, sf::RenderWindow& window, sf::Vector2i pos)
{
    sf::Font font;
    if (!font.loadFromFile("C:\\Projects\\Logo\\Logo\\arial.ttf"))
        return;
    sf::Text text(str, font, 50);
    text.setPosition(pos.x, pos.y);
    window.draw(text);
}


int main()
{
    sf::Vector2i pos(0, 0);

    sf::CircleShape circle(50);
    circle.setFillColor(sf::Color::Magenta);
    circle.setPosition(pos.x, pos.y);
    


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
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                pos.y -= 5;
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                pos.y += 5;
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                pos.x -= 5;
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                pos.x += 5;
        }
        // Clear screen
        window.clear();
        // Draw the sprite
        window.draw(sprite);
        circle.setPosition(pos.x, pos.y);
        window.draw(circle);
        // Draw the strin
        // Update the window
        //std::cout << "while" << std::endl;
        sf::Time elapsed = clock.getElapsedTime();
        //std::cout << Double(elapsed.asSeconds()) << std::endl;
        write(std::to_string(clock.getElapsedTime().asSeconds()), window, sf::Vector2i(0, 0));
        //write(std::to_string(t), window, sf::Vector2i(100, 100));
        window.display();
    }

    return EXIT_SUCCESS;;
}
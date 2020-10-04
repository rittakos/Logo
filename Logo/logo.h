#ifndef LOGO_H
#define LOGO_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "paper.h"
#include "window.h"

class Logo
{
public:
	Logo(int width = 800, int height = 600, std::string title = "Logo") 
	{

		window = std::unique_ptr<sf::RenderWindow>(new sf::RenderWindow(sf::VideoMode(width, height), title));
		backgroundPath = "C:\\Projects\\Logo\\Logo\\cute_image.png";
		currentPaperId = 0;
	}

	int run()
	{
        sf::Clock clock;


        while (window->isOpen())
        {
            sf::Event event;
            while (window->pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window->close();
            }
			
			display();
        }

        return EXIT_SUCCESS;
	}

	void SetCurrnetPaper(Paper paper)
	{

	}

	int display()
	{

		sf::Texture texture;
		if (!texture.loadFromFile(backgroundPath))
			return EXIT_FAILURE;
		sf::Sprite sprite(texture);

		window->clear();

		window->draw(sprite);
		papers[currentPaperId].draw(window);

		window->display();
	}
private:
	std::unique_ptr<sf::RenderWindow> window;

	std::string backgroundPath;

	int currentPaperId;
	std::vector<Paper> papers;
};

#endif
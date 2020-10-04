#ifndef WINDOW_H
#define WINDOW_H

#include <SFML/Graphics.hpp>

class Window
{
public:
	Window()
	{

	}

	Window(const Window& other)
	{

	}

	Window operator= (const Window& other)
	{

	}

	Window(int width, int height, std::string title) : width_ { width }, height_{ height }, title_{ title }
	{

	}

private:
	sf::RenderWindow renderWindow_;

	int width_;
	int height_;
	std::string title_;
};

#endif

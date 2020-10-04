#ifndef PAPER_H
#define PAPER_H

#include "drawable.h"
#include "turtle.h"
#include <string>
#include <SFML/Graphics.hpp>

class Paper final : public Drawable
{
public:
	Paper()
	{
		//++numOfPapers_;
		//name_ = "paper" + std::to_string(numOfPapers_);
	}

	virtual void draw(std::unique_ptr<sf::RenderWindow>& window) final
	{
		sf::RectangleShape paperShape(sf::Vector2f(100, 100));
		paperShape.setFillColor(sf::Color::White);
		window->draw(paperShape);

		Turtle turtle;
		turtle.draw(window);
	}

private:
	static int numOfPapers_;
	std::string name_;

	
};


#endif

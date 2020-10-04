#ifndef TURTLE_H
#define TURTLE_H

#include <SFML/Graphics.hpp>
#include "drawable.h"

class Turtle final : public Drawable
{
public:

	Turtle()
	{
		turtleShape_ = sf::RectangleShape(sf::Vector2f(10, 10));
		position_ = sf::Vector2f(10, 10);
		color_ = sf::Color::Green;
	}

	void draw(std::unique_ptr<sf::RenderWindow>& window) final
	{
		update();
		window->draw(turtleShape_);
	}

private:
	void update()
	{
		turtleShape_.setPosition(position_);
		turtleShape_.setFillColor(color_);
	}

	sf::RectangleShape turtleShape_;
	sf::Vector2f position_;
	sf::Color color_;
};

#endif

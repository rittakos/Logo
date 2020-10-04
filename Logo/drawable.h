#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <SFML/Graphics.hpp>

class Drawable
{
public:
	virtual void draw(std::unique_ptr<sf::RenderWindow>& window) = 0;
};


#endif

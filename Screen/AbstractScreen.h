#pragma once

#include <SFML/Graphics.hpp>

class AbstractScreen
{
public:
	AbstractScreen();
	virtual void update()=0;
	virtual void draw()=0;
	~AbstractScreen();
protected:
	sf::RenderWindow* window;
};


#pragma once

#include <SFML/Graphics.hpp>

class EventManager
{
public:
	static void initialize(sf::Window*);
	static sf::Event pullEvent();

private:
	static sf::Window* window;
};


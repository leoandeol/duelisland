#pragma once

#include <stack>
#include <SFML/Graphics.hpp>
#include "../Screen/AbstractScreen.h"
#include "../Screen/GameScreen.h"

class ScreenManager
{
public:
	ScreenManager(sf::RenderWindow*);
	void initialize();
	void update();
	void draw();
	~ScreenManager();

private:
		std::stack<AbstractScreen*> screens;
		sf::RenderWindow* window;
};


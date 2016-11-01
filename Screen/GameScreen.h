#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include "AbstractScreen.h"

class GameScreen :
	public AbstractScreen
{
public:
	GameScreen(sf::RenderWindow*);
	virtual void update();
	virtual void draw();
	~GameScreen();

private:
	sf::View view;
};

#endif

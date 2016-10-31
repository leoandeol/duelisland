#include "GameScreen.h"



GameScreen::GameScreen(sf::RenderWindow* w)
{
	window = w;
	view = sf::View(sf::FloatRect(0, 0, 1920, 1080));
	w->setView(view);
}

void GameScreen::update()
{

}

void GameScreen::draw()
{
    
}


GameScreen::~GameScreen()
{
}

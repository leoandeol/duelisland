#include "ScreenManager.h"

ScreenManager::ScreenManager(sf::RenderWindow* w)
{
	window = w;
	screens.push(new GameScreen(w));
}

void ScreenManager::update()
{
	screens.top()->update();
}

void ScreenManager::draw()
{
	screens.top()->draw();
}

ScreenManager::~ScreenManager()
{

}

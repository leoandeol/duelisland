#include "EventManager.h"

sf::Window* EventManager::window;

void EventManager::initialize(sf::Window* w)
{
	window = w;
}


sf::Event EventManager::pullEvent()
{
	sf::Event event;
	/*while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
			window.close();
	}*/
	EventManager::window->pollEvent(event);
	return event;
}

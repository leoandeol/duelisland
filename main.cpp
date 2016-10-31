#include <SFML/Graphics.hpp>
#include "Manager/ScreenManager.h"
#include "Manager/EventManager.h"
#include <thread>
#include "Tool/Animation.h"
#include "Manager/ResourceManager.h"

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 0;

	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Duel Island", sf::Style::None, settings);
	ScreenManager* sm = new ScreenManager(&window);
	EventManager::initialize(&window);

	sf::Texture icon = *ResourceManager::loadTexture("Data/Textures/icon.png");
	window.setIcon(8,8,(icon.copyToImage()).getPixelsPtr());
	//TODO: loading screen

	// Starts directly
	//std::thread update_thread(&ScreenManager::update, sm);

	while (window.isOpen())
	{
		window.clear();
		sm->update();
		sm->draw();
		window.display();
	}

	return 0;
}

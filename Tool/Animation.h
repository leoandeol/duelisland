#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "../Manager/ResourceManager.h"

class Animation
{
public:
	Animation(std::string&, int&, sf::Time = sf::seconds(0.2f));
	void update(sf::Time&);
	void draw(sf::RenderWindow*);
	~Animation();

private:
	sf::Sprite* sprite;
	// ALL IN MICROSEC
	sf::Time elapsed;
	sf::Time tick;
	int currentAnim;
	int spriteNb;
	int width;
};


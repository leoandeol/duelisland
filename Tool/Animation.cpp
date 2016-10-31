#include "Animation.h"

Animation::Animation(std::string& path, int& nb, sf::Time time)
{
	sprite->setTexture(*ResourceManager::loadTexture(path));
	width = sprite->getTextureRect().width / nb;
	spriteNb = nb;
	currentAnim = 0;
	elapsed = sf::microseconds(0);
	tick = time;

}

void Animation::update(sf::Time& delta)
{
	elapsed += delta;
	while (elapsed >= tick) 
	{
		elapsed -= tick;
		currentAnim = currentAnim >= (spriteNb - 1) ? 0 : currentAnim + 1;
	}
}

void Animation::draw(sf::RenderWindow* window)
{
	window->draw(*sprite);
}

Animation::~Animation()
{
}

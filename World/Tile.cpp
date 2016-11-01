#include "Tile.h"

Tile(TileType t,sf::Vector2i pos)
{
	texture=ResourceManager::getTexture("Data/Textures/Tilesets/terrain.png");
	this.type=t;
	this.hitbox=sf::IntRect(pos.x,pos.y,8,8);
	switch (this.type)
	{
	case TileType.Grass:
		sourceRectangle = sf::IntRect(0, 0, 8, 8);
		break;
	case TileType.Sand:
		sourceRectangle = sf::IntRect(8, 0, 8, 8);
		break;
	case TileType.Water:
		sourceRectangle = sf::IntRect(16, 0, 8, 8);
		break;
	}
	sprite.setTexture(*texture);
	sprite.setTextureRect(sourceRectangle);
	sprite.setPosition(pos);
}

void Tile::draw(sf::RenderWindow* window)
{
	window->draw(sprite);
}

void Tile::setType(TileType t)
{
	this.type=t;
}

TileType Tile::getType()
{
	return type;
}

sf::Intrect Tile::getHitbox()
{
	return hitbox;
}

Tile::~Tile()
{

}

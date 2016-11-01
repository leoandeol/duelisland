#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>
#include "../Manager/ResourceManager.h"

enum TileType {
	Grass,
	Sand,
	Water
}

class Tile {
 public:
	Tile(TileType,sf::Vector2i);
	void draw(sf::RenderWindow*);
	void setType(TileType);
	TileType getType();
	sf::Intrect getHitbox();
	~Tile();
 private:
	sf::IntRect sourceRectlange;
	TileType type;
	sf::IntRect hitbox;
	sf::Texture* texture;
	sf::Sprite sprite;
}

#endif

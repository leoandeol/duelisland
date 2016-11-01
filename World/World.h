#ifndef WORLD_H
#define WORLD_H

#include <stdlib.h>
#include <time.h>
#include <vector>
#include <math.h>
#include <SFML/Graphics.hpp>
#include "Tile.h"

public class World
{
 public:
	World();
	void update(sf::Time);
	void draw(sf::RenderWindow*,sf::FloatRect);
	Tile*** getTiles();
	EntityBlock*** getBlocks();
	Tile* getClosestTile(sf::Vector2f);
	EntityBlock* getClosestBlock(sf::Vector2f);
	~World();
 private:
	Tile*** tiles;
	EntityBlock*** blocks;
	std::vector<Item> items;
}

#endif

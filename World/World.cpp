#include "World.h"

World::World()
{
	srand(time(NULL));
	Tiles = new Tile**[120];
	blocks = new EntityBlock**[120];
	for (int x = 0; x < 120; x++)
	{
		tiles[x] = new Tile*[120];
		blocks[x] = new EntityBlock*[120];
		for (int y = 0; y < 120; y++)
		{
			tiles[x][y] = new Tile(TileType.Grass, new Vector2(x, y));
			blocks[x][y] = null;
		}
	}
	for (int x = 0; x < 40; x++)
	{
		for (int y = 0; y < 120; y++)
		{
			tiles[x][y] = new Tile(TileType.Water, new Vector2(x, y));
		}
	}
	for (int x = 0; x < 120; x++)
	{
		for (int y = 0; y < 40; y++)
		{
			tiles[x][y] = new Tile(TileType.Water, new Vector2(x, y));
		}
	}
	for (int x = 80; x < 120; x++)
	{
		for (int y = 0; y < 120; y++)
		{
			tiles[x][y] = new Tile(TileType.Water, new Vector2(x, y));
		}
	}
	for (int x = 0; x < 120; x++)
	{
		for (int y = 80; y < 120; y++)
		{
			tiles[x][y] = new Tile(TileType.Water, new Vector2(x, y));
		}
	}
	for (int x = 40; x < 80; x++)
	{
		for (int y = 40; y < 80; y++)
		{
			TileType tmp = TileType.Grass;
			int factor = 0;
			switch ((int)tiles[x - 1][y]->Type)
			{
			case 0:
				factor += 6;
				break;
			case 1:
				factor += 4;
				break;
			case 2:
				factor += 2;
				break;
			}
			switch ((int)tiles[x][y - 1]->Type)
			{
			case 0:
				factor += 6;
				break;
			case 1:
				factor += 4;
				break;
			case 2:
				factor += 2;
				break;
			}
			switch ((int)tiles[x - 1][y - 1]->Type)
			{
			case 0:
				factor += 6;
				break;
			case 1:
				factor += 4;
				break;
			case 2:
				factor += 2;
				break;
			}
			int a = rand()%factor;
			if (a != 0)
			{
				int b = (rand()%3)+1;
				switch (b)
				{
				case 1:
					tmp = tiles[x - 1][y]->Type;
					break;
				case 2:
					tmp = tiles[x][y - 1]->Type;
					break;
				case 3:
					tmp = tiles[x - 1][y - 1]->Type;
					break;
				}
			}
			else
			{
				switch (rand()%6)
				{
				case 0:
				case 1:
				case 2:
					tmp = TileType.Grass;
					break;
				case 3:
				case 4:
					tmp = TileType.Sand;
					break;
				case 5:
					tmp = TileType.Water;
					break;
				default:
					tmp = TileType.Grass;
					break;
				}
			}
			tiles[x][y] = new Tile(tmp, new Vector2(x, y));
		}
	} 
	for (int x = 40; x < 80; x++)
	{
		for (int y = 40; y < 80; y++)
		{
			if(tiles[x][y]->Type == TileType.Grass)
			{
				int a = (rand()%29)+1;
				if (a == 4)
					blocks[x][y] = new EntityTree(new Vector2(x, y));
				else if (a == 2)
					blocks[x][y] = new EntityStone(new Vector2(x, y));
				else if (a == 3)
					blocks[x][y] = new EntityFlowers(new Vector2(x, y));
			}
			else if (tiles[x][y]->Type == TileType.Sand)
			{
				int a = (rand()%14)+1;
				if (a == 1)
					blocks[x][y] = new EntityCactus(new Vector2(x, y));
			}
		}
	}
}
//TODO update & draw
void World::update(sf::Time delta)
{
	for (int x = (int)((camera.Pos.X / 8) - (Math.Round((double)(1280 / 8))) / 8);
		 x < (int)((camera.Pos.X / 8) + (Math.Round((double)(1280 / 8))) / 8); x++)
	{
		for (int y = (int)((camera.Pos.Y / 8) - (Math.Round((double)(720 / 8))) / 8);
			 y < (int)((camera.Pos.Y / 8) + (Math.Round((double)(720 / 8))) / 8); y++)
		{
                    
			if(x >= 0 && x < 120 && y >= 0 && y < 120)
			{
				if (blocks[x][y] != null && blocks[x][y].Life <= 0)
				{
					delete blocks[x][y];
				}
				else if (blocks[x][y] != null)
				{
					blocks[x][y]->update(delta);
				}
			}
		}
	}
	for(Item item : items)
	{
		item.update();
	}
}

void World::draw(sf::RenderWindow* window,sf::FloatRect viewport)
{
	for (int x = (int)((camera.Pos.X / 8) - (round((double)(1280 / 8))) / 8);
		 x < (int)((camera.Pos.X / 8) + (round((double)(1280 / 8))) / 8); x++)
	{
		for (int y = (int)((camera.Pos.Y / 8) - (round((double)(720 / 8))) / 8);
			 y < (int)((camera.Pos.Y / 8) + (round((double)(720 / 8))) / 8); y++)
		{
			if(x >= 0 && x < 120 && y >= 0 && y < 120)
			{
				tiles[x][y]->draw(window);
			}
		}
	}
	for(Item item : items)
	{
		item.draw(window);
	}
	for (int x = (int)((camera.Pos.X / 8) - (round((double)(1280 / 8))) / 8);
		 x < (int)((camera.Pos.X / 8) + (round((double)(1280 / 8))) / 8); x++)
	{
		for (int y = (int)((camera.Pos.Y / 8) - (round((double)(720 / 8))) / 8);
			 y < (int)((camera.Pos.Y / 8) + (round((double)(720 / 8))) / 8); y++)
		{
			if(x >= 0 && x < 120 && y >= 0 && y < 120)
			{
				if (x >= 0 && x <= 120 && y >= 0 && y <= 120 && blocks[x][y] != null)
				{
					BlockEntities[x][y]->draw(window);
				}
			}
		}
	}
}

Tile*** World::getTiles()
{
	return tiles;
}

EntityBlock*** World::getBlocks()
{
	return blocks;
}

Tile* World::getClosestTile(sf::Vector2f pos)
{
return tiles[(int)round(pos.x)][(int)round(pos.y)];
}

EntityBlock* World::getClosestBlock(sf::Vector2f pos)
{
return blocks[(int)round(pos.x)][(int)round(pos.y)];
}

World::~World()
{

}

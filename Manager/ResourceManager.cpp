#include "ResourceManager.h"

std::map<std::string, sf::Texture*> ResourceManager::textures;

sf::Texture* ResourceManager::loadTexture(const std::string &path) 
{
	if (textures.find(path) == textures.end())
	{
		sf::Texture* texture = new sf::Texture();
		if(!texture->loadFromFile(path))
		{
			std::string tmp = "Error while loading : ";
			tmp.append(path);
			LogManager::Write(tmp);
		}
		textures[path] = texture;
	}
	return textures[path];
}

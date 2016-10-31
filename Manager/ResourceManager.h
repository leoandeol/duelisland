#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <map>
#include <SFML/Graphics.hpp>
#include <string>
#include "LogManager.h"

class ResourceManager
{

public:
	static sf::Texture* loadTexture(const std::string&);

private:
	static std::map<std::string, sf::Texture*> textures;
	
};

#endif

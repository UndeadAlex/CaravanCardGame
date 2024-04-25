#include "Card.h"
#include "TextureManager.h"

Card::Card()
{

}

Card::Card(sf::Vector2f position, sf::Vector2f size, std::string cardTextureID)
{
	setOrigin(getLocalBounds().getSize() / 2.0f);
	setPosition(position);
	setSize(size);

	// TODO - Create texture atlas class
	sf::Texture* tmp = TextureManager::GetTexture(cardTextureID);
	if(tmp!=nullptr)
		setTexture(tmp);
}

Card::~Card()
{

}

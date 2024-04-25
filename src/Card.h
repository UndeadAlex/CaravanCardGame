#ifndef CARD_H
#define CARD_H

#include <SFML\Graphics.hpp>
#include <string>

class Card : public sf::RectangleShape
{
public:
	Card();
	Card(sf::Vector2f position, sf::Vector2f size, std::string cardTextureID = "");
	virtual ~Card();
};

#endif
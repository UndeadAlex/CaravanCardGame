#include <SFML/Graphics.hpp>
#include "GameRandom.h"
#include "GameConstants.h"
#include "Card.h"
#include <vector>
#include <string>
#include <stdio.h>
#include "TextureManager.h"

void LoadAllTextures();

int main()
{
	sf::RenderWindow window(sf::VideoMode(GameConstants::WINDOW_WIDTH, GameConstants::WINDOW_HEIGHT), "Caravan | Status: TODO");
	
	std::vector<Card> m_cards(5);

	LoadAllTextures();
	std::vector<std::string> m_textureNames = { "spade_ace", "spade_two", "spade_three", "spade_four", "spade_five", "spade_six", "spade_seven", "spade_eight", "spade_nine", "spade_ten", "spade_jack", "spade_queen", "spade_king" };

	for (const Card& card : m_cards)
	{
		sf::Vector2f tmpPos = GameRandom::RandVector2f(sf::Vector2f(GameConstants::WINDOW_WIDTH, GameConstants::WINDOW_HEIGHT));
		Card tmpCard(tmpPos, sf::Vector2f(315.0f, 440.0f), m_textureNames[GameRandom::Randint(m_textureNames.size()-1)]);
		m_cards.push_back(tmpCard);
	}

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		for (const Card& card : m_cards)
		{
			window.draw(card);
		}
		window.display();
	}

	return 0;
}


void LoadAllTextures()
{
	int error = 0;

	error += TextureManager::LoadTextureSub("assets\\textures\\8BitDeckAssets.png", "spade_ace", sf::IntRect(456, 142, 33, 45));
	error += TextureManager::LoadTextureSub("assets\\textures\\8BitDeckAssets.png", "spade_two", sf::IntRect(36, 142, 33, 45));
	error += TextureManager::LoadTextureSub("assets\\textures\\8BitDeckAssets.png", "spade_three", sf::IntRect(71, 142, 33, 45));
	error += TextureManager::LoadTextureSub("assets\\textures\\8BitDeckAssets.png", "spade_four", sf::IntRect(106, 142, 33, 45));
	error += TextureManager::LoadTextureSub("assets\\textures\\8BitDeckAssets.png", "spade_five", sf::IntRect(141, 142, 33, 45));
	error += TextureManager::LoadTextureSub("assets\\textures\\8BitDeckAssets.png", "spade_six", sf::IntRect(176, 142, 33, 45));
	error += TextureManager::LoadTextureSub("assets\\textures\\8BitDeckAssets.png", "spade_seven", sf::IntRect(211, 142, 33, 45));
	error += TextureManager::LoadTextureSub("assets\\textures\\8BitDeckAssets.png", "spade_eight", sf::IntRect(246, 142, 33, 45));
	error += TextureManager::LoadTextureSub("assets\\textures\\8BitDeckAssets.png", "spade_nine", sf::IntRect(281, 142, 33, 45));
	error += TextureManager::LoadTextureSub("assets\\textures\\8BitDeckAssets.png", "spade_ten", sf::IntRect(316, 142, 33, 45));
	error += TextureManager::LoadTextureSub("assets\\textures\\8BitDeckAssets.png", "spade_jack", sf::IntRect(351, 142, 33, 45));
	error += TextureManager::LoadTextureSub("assets\\textures\\8BitDeckAssets.png", "spade_queen", sf::IntRect(386, 142, 33, 45));
	error += TextureManager::LoadTextureSub("assets\\textures\\8BitDeckAssets.png", "spade_king", sf::IntRect(421, 142, 33, 45));

	if (error > 0)
		printf("Failed to load %d textures.", error);
}